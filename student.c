#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_SUB  5

// --------- Nested Structure ---------
typedef struct {
    char name[MAX_NAME];
    float gpa;
} Academic;

// --------- Main Structure ---------
typedef struct {
    int roll;
    char name[MAX_NAME];
    int age;
    Academic record;   // Nested structure
} Student;

Student *students = NULL;
int count = 0;

// --------- Function Prototypes ---------
void addStudent();
void displayStudents();
void searchStudent();
void sortByGPA();
void saveToFile();
void loadFromFile();
void menu();

// --------- Add Student ---------
void addStudent() {
    students = realloc(students, (count + 1) * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Age: ");
    scanf("%d", &students[count].age);

    printf("Enter Course Name: ");
    scanf(" %[^\n]", students[count].record.name);

    printf("Enter GPA: ");
    scanf("%f", &students[count].record.gpa);

    count++;
    printf("Student Added Successfully!\n");
}

// --------- Display Students ---------
void displayStudents() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nRoll: %d", students[i].roll);
        printf("\nName: %s", students[i].name);
        printf("\nAge: %d", students[i].age);
        printf("\nCourse: %s", students[i].record.name);
        printf("\nGPA: %.2f\n", students[i].record.gpa);
    }
}

// --------- Search Student ---------
void searchStudent() {
    int roll, found = 0;
    printf("Enter Roll to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\nStudent Found:\n");
            printf("Name: %s\n", students[i].name);
            printf("GPA: %.2f\n", students[i].record.gpa);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student Not Found.\n");
}

// --------- Sort by GPA (Bubble Sort) ---------
void sortByGPA() {
    Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].record.gpa < students[j + 1].record.gpa) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Students Sorted by GPA (Descending).\n");
}

// --------- Save to File ---------
void saveToFile() {
    FILE *fp = fopen("students.dat", "wb");
    if (fp == NULL) {
        printf("File Error!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(students, sizeof(Student), count, fp);

    fclose(fp);
    printf("Data Saved to File.\n");
}

// --------- Load from File ---------
void loadFromFile() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No existing file found.\n");
        return;
    }

    fread(&count, sizeof(int), 1, fp);

    students = malloc(count * sizeof(Student));
    fread(students, sizeof(Student), count, fp);

    fclose(fp);
    printf("Data Loaded from File.\n");
}

// --------- Menu ---------
void menu() {
    int choice;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Sort by GPA\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: sortByGPA(); break;
            case 5: saveToFile(); break;
            case 6: loadFromFile(); break;
            case 7:
                free(students);
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
}

// --------- Main Function ---------
int main() {
    menu();
    return 0;
}
