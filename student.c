#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"
#include "input.h"

Student studentCreate(char *name, char *number, int grade) {
    Student student;

    strcpy(student.name, name);
    strcpy(student.number, number);
    student.grade = grade;

    return student;
}

int loadStudents(Student arr[], int howMany) {

    FILE* stream = fopen("students.csv", "r");

    int count = 0;
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        if(count == howMany) break;

        char* tmp = strdup(line);
        
        char** tokens = splitString(tmp, 3, ";");
        
        int grade = atoi(tokens[2]);
        arr[count++] = studentCreate(tokens[0], tokens[1], grade);

	    free(tokens);
        free(tmp);
    }

    fclose(stream);

    return count;
}

// Definição de tipos de dados - 1

bool studentExistsByName(char name[], Student arr[], int arrLength){

    for (int i = 0; i < arrLength; i++)
    {
        if(strcmp(arr[i].name, name) == 0){
         return 0;
        }
    }

    return 1;

}

// Definição de tipos de dados - 2

int studentMinimumGradeIndex(Student arr[], int arrLength){
    int minGrade = arr[0].grade;
    int minGradeIndex = 0;

    if(arr == 0) return -1;

    for (int i = 1; i < arrLength; i++)
    {
        if(minGrade > arr[i].grade){
            minGrade = arr[i].grade;
            minGradeIndex = i;
        }
    }

    return minGradeIndex;
    
}

// Definição de tipos de dados - 3

Student studentMaximumGrade(Student arr[], int arrLength){

    int maxGrade = arr[0].grade;
    int maxIndex = 0;

    if (arr <= 0){
	    return studentCreate("","",-1);
    }

    for (int i = 1; i < arrLength; i++)
    {
        if(maxGrade < arr[i].grade){

			maxGrade = arr[i].grade;
            maxIndex = i;
        }
    }

    return arr[maxIndex];  

}

// Definição de dados - 4

void studentArrSortByGrade(Student arr[], int arrLength){

    Student tempStd;

    for (int i = 0; i < arrLength; i++)
    {
        for (int j = 0; j < arrLength-i-1; j++)
        {
            if(arr[j].grade < arr[j+1].grade){
                tempStd = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tempStd;
            }
        }       
    }
}

// Definição de dados - 5

void studentArrSortByName(Student arr[], int arrLength){

    Student tempStd;

    for (int i = 0; i < arrLength-1; i++)
    {
        int indexMin = i;
         
        for (int j = i; j < arrLength; j++)
        {
            if(strcmp(arr[j].name, arr[indexMin].name)< 0){
                indexMin = j;
            }
        }

        tempStd = arr[i];
        arr[i] = arr[indexMin];
        arr[indexMin] = tempStd;
        
    }   
}
