/* 
 * File:   students.h
 * Author: nezu
 * header file for students
 * Created on February 23, 2013, 5:08 PM
 */

#ifndef STUDENTS_H
#define	STUDENTS_H

typedef char* string;

typedef enum
{
STUD_ID,STUD_NAME
}
S_STATUS;

typedef struct
{	
unsigned long sID;
char sName[20];
char sEmail[30];	
} Student;

//Student Prototypes
void fnAddStudInfo(Student*, int);
void fnPrintStudInfo( Student []);
int fnSearchStud(Student*);//function that searches via id and prints that detail
void fnReturnSName(Student []);//function that searches via student name and print that struct

#endif	/* STUDENTS_H */
