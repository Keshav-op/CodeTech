#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Structure to define a student
typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grades[3];
    float average;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to add a student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Capacity reached.\n");
        return;
    }

    Student s;
    printf("Enter student ID: ");
    scanf("%d", &s.id);
    printf("Enter student name: ");
    scanf(" %[^\n]s", s.name);
    printf("Enter 3 grades: ");
    s.grades[0] = s.grades[1] = s.grades[2] = 0; // Initialize grades
    scanf("%f %f %f", &s.grades[0], &s.grades[1], &s.grades[2]);
    s.average = (s.grades[0] + s.grades[1] + s.grades[2]) / 3;

    students[studentCount++] = s;
    printf("Student added successfully.\n");
}

// Function to edit a student's information
void editStudent() {
    int id, found = 0;
    printf("Enter student ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Editing student: %s\n", students[i].name);
            printf("Enter new name: ");
            scanf(" %[^\n]s", students[i].name);
            printf("Enter 3 new grades: ");
            scanf("%f %f %f", &students[i].grades[0], &students[i].grades[1], &students[i].grades[2]);
            students[i].average = (students[i].grades[0] + students[i].grades[1] + students[i].grades[2]) / 3;
            printf("Student updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to delete a student
void deleteStudent() {
    int id, found = 0;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Display all students
void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Grades: %.2f, %.2f, %.2f\n", students[i].grades[0], students[i].grades[1], students[i].grades[2]);
        printf("Average: %.2f\n\n", students[i].average);
    }
}

// Main menu function
void menu() {
    int choice;
    while (1) {
        printf("Student Management System\n");
        printf("1. Add Student\n");
        printf("2. Edit Student\n");
        printf("3. Delete Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                editStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
