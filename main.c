#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"
#include "input.h"

int main() {
   
    Student students[200];

    int n = loadStudents(students, 60);

    for(int i=0; i < n; i++) {
        printf("Student[%2d]: %s \n", i, students[i].name);
    }

    // Definição de tipos de dados - 1

    char studentName[] = "Nathaniel Cook";
    int checkStdName = studentExistsByName(studentName, students, n);
    printf("Check if students name is in array: %d\n", checkStdName);

    // Definição de tipos de dados - 2

    int checkMinGradeIndex = studentMinimumGradeIndex(students, n);
    printf("Check index of lowest grade: %d\n", checkMinGradeIndex);

    // Definição de tipos de dados - 3

    Student stdMaximumGrade = studentMaximumGrade(students, n);
    printf("Student with highest grade: %s | %s | %d\n",stdMaximumGrade.name, stdMaximumGrade.number, stdMaximumGrade.grade);
    
    // Definição de tipos de dados - 4
    studentArrSortByGrade(students, n);

    for(int i=0; i < n; i++) {
        printf("Student: %s | %s | %d \n", students[i].name, students[i].number, students[i].grade);
    }

    // Definição de dados - 5
    printf("--------------------------------------------------\n");
    studentArrSortByName(students, n);

    for(int i=0; i < n; i++) {
        printf("Student: %s | %s | %d \n", students[i].name, students[i].number, students[i].grade);
    }

    return EXIT_SUCCESS;
}
