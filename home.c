#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
struct Student {
    int id;
    char name[50];
    int age;
    float grade;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;
void addStudent();
void viewAllStudents();
void editStudent(int id);
void deleteStudent(int id);
void searchStudent(int id);
void classSummary();
void displayMenu();
int main() {
    int choice, id;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewAllStudents();
                break;
            case 3:
                printf("Enter student ID to edit: ");
                scanf("%d", &id);
                editStudent(id);
                break;
            case 4:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;
            case 5:
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                searchStudent(id);
                break;
            case 6:
                classSummary();
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
void displayMenu() {
    printf("\n---- Student Management System ----\n");
    printf("1. Add Student\n");
    printf("2. View All Students\n");
    printf("3. Edit Student\n");
    printf("4. Delete Student\n");
    printf("5. Search Student\n");
    printf("6. Class Summary\n");
    printf("7. Exit\n");
}
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter name: ");
    scanf(" %[^\n]%*c", newStudent.name);  // to capture name with spaces
    printf("Enter age: ");
    scanf("%d", &newStudent.age);
    printf("Enter grade: ");
    scanf("%f", &newStudent.grade);

    students[studentCount++] = newStudent;
    printf("Student added successfully!\n");
}
void viewAllStudents() {
    if (studentCount == 0) {
        printf("No students available to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d | Name: %s | Age: %d | Grade: %.2f\n", 
               students[i].id, students[i].name, students[i].age, students[i].grade);
    }
}

void editStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Editing student ID %d:\n", id);
            printf("Enter new name: ");
            scanf(" %[^\n]%*c", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new grade: ");
            scanf("%f", &students[i].grade);
            printf("Student details updated successfully!\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void deleteStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}
void searchStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Student found:\n");
            printf("ID: %d | Name: %s | Age: %d | Grade: %.2f\n", 
                   students[i].id, students[i].name, students[i].age, students[i].grade);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}
void classSummary() {
    if (studentCount == 0) {
        printf("No students available for summary.\n");
        return;
    }

    float totalGrade = 0, highestGrade = students[0].grade, lowestGrade = students[0].grade;

    for (int i = 0; i < studentCount; i++) {
        totalGrade += students[i].grade;
        if (students[i].grade > highestGrade) {
            highestGrade = students[i].grade;
        }
        if (students[i].grade < lowestGrade) {
            lowestGrade = students[i].grade;
        }
    }

    printf("\n--- Class Summary ---\n");
    printf("Average Grade: %.2f\n", totalGrade / studentCount);
    printf("Highest Grade: %.2f\n", highestGrade);
    printf("Lowest Grade: %.2f\n", lowestGrade);
}
