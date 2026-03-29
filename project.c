#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define DATA_FILE "EMP.DAT"
#define TEMP_FILE "TEMP.DAT"
#define NAME_LEN 40

typedef struct {
    char name[NAME_LEN];
    int age;
    float salary;
} Employee;

static void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

static bool validateAge(int age) {
    return age > 0 && age <= 120;
}

static bool validateSalary(float salary) {
    return salary >= 0;
}

static bool validateName(const char *name) {
    if (!name || strlen(name) == 0) return false;
    for (int i = 0; name[i]; i++) {
        if (!isalpha((unsigned char)name[i]) && name[i] != ' ' && name[i] != '-') return false;
    }
    return true;
}

static char *strcasestr_local(const char *haystack, const char *needle) {
    if (!haystack || !needle || !*needle) return (char *)haystack;
    
    const char *h = haystack;
    const char *n = needle;
    
    while (*h) {
        const char *h_start = h;
        const char *n_start = n;
        
        while (*h && *n && tolower((unsigned char)*h) == tolower((unsigned char)*n)) {
            h++;
            n++;
        }
        
        if (!*n) return (char *)h_start;
        
        h = h_start + 1;
        n = n_start;
    }
    
    return NULL;
}

static void printEmployee(const Employee *e) {
    printf("%-20s | %-6d | %-12.2f\n", e->name, e->age, e->salary);
}

static FILE *openFile(const char *mode) {
    return fopen(DATA_FILE, mode);
}

static void addEmployee(FILE *fp) {
    Employee e;
    char another = 'Y';
    int result;

    while (another == 'Y' || another == 'y') {
        memset(&e, 0, sizeof(e));
        
        printf("\nEnter employee name: ");
        if (!fgets(e.name, NAME_LEN, stdin)) {
            clearInputBuffer();
            continue;
        }
        trimNewline(e.name);

        if (!validateName(e.name)) {
            printf("Error: Invalid name. Use only letters, spaces, and hyphens.\n");
            continue;
        }

        printf("Enter age: ");
        result = scanf("%d", &e.age);
        clearInputBuffer();
        if (result != 1 || !validateAge(e.age)) {
            printf("Error: Please enter a valid age (1-120).\n");
            continue;
        }

        printf("Enter basic salary: ");
        result = scanf("%f", &e.salary);
        clearInputBuffer();
        if (result != 1 || !validateSalary(e.salary)) {
            printf("Error: Please enter a valid salary (>= 0).\n");
            continue;
        }

        fprintf(fp, "%s,%d,%.2f\n", e.name, e.age, e.salary);
        printf("Record added successfully.\n");

        printf("Add another record? (Y/N): ");
        result = scanf("%c", &another);
        clearInputBuffer();
        if (result != 1) {
            another = 'N';
        }
    }
}

static void listEmployees(FILE *fp) {
    Employee e;
    int count = 0;
    char line[256];

    rewind(fp);
    
    if (fgets(line, sizeof(line), fp) != NULL) {
        printf("\n%s", line);
    }
    
    printf("--------------------------------------------------\n");

    while (fscanf(fp, " %39[^,],%d,%f", e.name, &e.age, &e.salary) == 3) {
        printEmployee(&e);
        count++;
    }

    if (count == 0) {
        printf("No records found.\n");
    } else {
        printf("--------------------------------------------------\n");
        printf("Total employees: %d\n", count);
    }
    printf("Press Enter to continue...");
    getchar();
}

static void modifyEmployee(FILE *fp) {
    Employee e;
    FILE *temp;
    char empname[NAME_LEN];
    int found = 0;
    char line[256];

    printf("\nEnter the name of the employee to modify: ");
    if (!fgets(empname, NAME_LEN, stdin)) {
        clearInputBuffer();
        return;
    }
    trimNewline(empname);

    temp = fopen(TEMP_FILE, "w");
    if (!temp) {
        printf("Error: Cannot create temporary file.\n");
        return;
    }

    rewind(fp);
    
    if (fgets(line, sizeof(line), fp) != NULL) {
        fprintf(temp, "%s", line);
    }
    
    while (fscanf(fp, " %39[^,],%d,%f", e.name, &e.age, &e.salary) == 3) {
        if (strcasecmp(e.name, empname) == 0) {
            found = 1;
            printf("\nCurrent record:\n");
            printf("%-20s | %-6s | %-12s\n", "NAME", "AGE", "SALARY");
            printf("--------------------------------------------------\n");
            printEmployee(&e);

            printf("\nEnter new name: ");
            if (!fgets(e.name, NAME_LEN, stdin)) {
                clearInputBuffer();
                fclose(temp);
                return;
            }
            trimNewline(e.name);

            if (!validateName(e.name)) {
                printf("Error: Invalid name.\n");
                fclose(temp);
                return;
            }

            printf("Enter new age: ");
            while (scanf("%d", &e.age) != 1 || !validateAge(e.age)) {
                printf("Error: Enter valid age (1-120): ");
                clearInputBuffer();
            }
            clearInputBuffer();

            printf("Enter new salary: ");
            while (scanf("%f", &e.salary) != 1 || !validateSalary(e.salary)) {
                printf("Error: Enter valid salary (>= 0): ");
                clearInputBuffer();
            }
            clearInputBuffer();
        }
        fprintf(temp, "%s,%d,%.2f\n", e.name, e.age, e.salary);
    }

    fclose(fp);
    fclose(temp);

    remove(DATA_FILE);
    rename(TEMP_FILE, DATA_FILE);
    fp = fopen(DATA_FILE, "r+");
    if (!fp) {
        printf("Error: Failed to reopen data file.\n");
        return;
    }

    if (found) {
        printf("\nRecord modified successfully.\n");
    } else {
        printf("\nRecord not found.\n");
    }
}

static void deleteEmployee(FILE **fp) {
    Employee e;
    FILE *temp;
    char empname[NAME_LEN];
    char line[256];
    int deleted = 0;

    printf("\nEnter the name of the employee to delete: ");
    if (!fgets(empname, NAME_LEN, stdin)) {
        clearInputBuffer();
        return;
    }
    trimNewline(empname);

    temp = fopen(TEMP_FILE, "w");
    if (!temp) {
        printf("Error: Cannot create temporary file.\n");
        return;
    }

    rewind(*fp);
    
    if (fgets(line, sizeof(line), *fp) != NULL) {
        fprintf(temp, "%s", line);
    }
    
    while (fscanf(*fp, " %39[^,],%d,%f", e.name, &e.age, &e.salary) == 3) {
        if (strcasecmp(e.name, empname) != 0) {
            fprintf(temp, "%s,%d,%.2f\n", e.name, e.age, e.salary);
        } else {
            deleted = 1;
        }
    }

    fclose(*fp);
    fclose(temp);

    if (deleted) {
        remove(DATA_FILE);
        rename(TEMP_FILE, DATA_FILE);
        *fp = fopen(DATA_FILE, "r+");
        if (!*fp) {
            printf("Error: Failed to reopen data file.\n");
            return;
        }
        printf("\nRecord deleted successfully.\n");
    } else {
        remove(TEMP_FILE);
        *fp = fopen(DATA_FILE, "r+");
        printf("\nRecord not found.\n");
    }
}

static void searchEmployee(FILE *fp) {
    Employee e;
    char searchTerm[NAME_LEN];
    int count = 0;
    char line[256];

    printf("\nEnter name to search: ");
    if (!fgets(searchTerm, NAME_LEN, stdin)) {
        clearInputBuffer();
        return;
    }
    trimNewline(searchTerm);

    if (strlen(searchTerm) == 0) {
        printf("Error: Search term cannot be empty.\n");
        return;
    }

    rewind(fp);
    
    if (fgets(line, sizeof(line), fp) != NULL) {
        printf("\n%s", line);
    }
    
    printf("--------------------------------------------------\n");

    while (fscanf(fp, " %39[^,],%d,%f", e.name, &e.age, &e.salary) == 3) {
        if (strcasestr_local(e.name, searchTerm)) {
            printEmployee(&e);
            count++;
        }
    }

    if (count == 0) {
        printf("No matching records found.\n");
    } else {
        printf("--------------------------------------------------\n");
        printf("Found %d matching employee(s).\n", count);
    }
    printf("Press Enter to continue...");
    getchar();
}

static void displayMenu(void) {
    printf("\n=== Employee Management System ===\n");
    printf("1. Add Employee\n");
    printf("2. List All Employees\n");
    printf("3. Search Employee\n");
    printf("4. Modify Employee\n");
    printf("5. Delete Employee\n");
    printf("0. Exit\n");
    printf("Your Choice: ");
}

static void writeHeader(FILE *fp) {
    fprintf(fp, "Name,Age,Salary\n");
}

int main(void) {
    FILE *fp;
    char choice;
    long size;

    fp = openFile("rb+");
    if (fp) {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);
        fclose(fp);
        
        if (size == 0) {
            fp = openFile("wb+");
            if (fp) {
                writeHeader(fp);
            }
        } else {
            fp = openFile("r+");
        }
    } else {
        fp = openFile("wb+");
        if (fp) {
            writeHeader(fp);
        }
    }
    
    if (!fp) {
        printf("Error: Cannot open or create data file.\n");
        return 1;
    }

    while (1) {
        displayMenu();
        choice = (char)getchar();
        clearInputBuffer();

        switch (choice) {
            case '1':
                addEmployee(fp);
                break;
            case '2':
                listEmployees(fp);
                break;
            case '3':
                searchEmployee(fp);
                break;
            case '4':
                modifyEmployee(fp);
                break;
            case '5':
                deleteEmployee(&fp);
                break;
            case '0':
                fclose(fp);
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
