#pragma once

typedef struct student {
    char name[200];
    char number[12];
    int grade;
} Student;

typedef struct student* PtStudent;

//or
//typedef Student* PtStudent;

/**
 * @brief Creates and initializes a student
 * 
 * @param name [in] student name
 * @param number [in] student number
 * @param grade  [in] student grade
 * @return Student struct
 */

Student studentCreate(char *name, char *number, int grade);

/**
 * @brief Populates array with students.
 * 
 * The function returns how many students were actually populated.
 * This is important if 'howMany' is greater than available students.
 * 
 * Should use the return value to iterate the array afterwards.
 * 
 * @param arr [out] array of students to populate. Must have necessary space.
 * @param howMany [in] number of students to load
 * @return int actually number of populated students.
 */

int loadStudents(Student arr[], int howMany);

//Definição de tipos de dados - 1

/**
* @brief Searches for the name of a student in an array of students
* @param arr [in] The student's array.
* @param arrLength [in] The size of the array.
* @param name [in] The student's name.
* @return true if the student exists
* @return false otherwise.
*/

bool studentExistsByName(char name[], Student arr[], int arrLength);

// Definição de tipos de dados - 2

/**
* @brief Selects the youngest student in an array of students
*
* @param studentArr [in] The student's array.
* @param size [in] The size of the array.
*
* @return index of student with minimum grade.
* @return -1 if array is empty
*/

int studentMinimumGradeIndex(Student arr[], int arrLength);

// Definição de tipos de dados - 3

/**
* @brief Selects the youngest student in an array of students
*
* @param studentArr [in] The student's array.
* @param size [in] The size of the array.
*
* @return copy of student with minimum grade;
* @return 'empty' student
*/

Student studentMaximumGrade(Student arr[], int arrLength);

// Definição de dados - 4

void studentArrSortByGrade(Student arr[], int arrLength);

// Definição de dados - 5

void studentArrSortByName(Student arr[], int arrLength);

