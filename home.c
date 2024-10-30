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
