/* 
 * File:   students.h
 * Author: nezu
 * source file for students
 * Revises on 3/4/13 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"
#include "main.h"

void fnAddStudInfo(Student *studentInfo, int studindex)
{           
     FILE *sf;
     sf = fopen("Student.dat", "a+");
     
       if (sf != NULL) {
          
               printf("Enter Student ID:");
	       scanf("%lu",&studentInfo[studindex].sID);
               fprintf(sf,"%s","Student ID: ");
               fprintf(sf,"%lu\n",studentInfo[studindex].sID);
               
               printf("Enter Student name:");
	       scanf(" %19[^\n]", studentInfo[studindex].sName);
	       while(getchar() != '\n') continue; //ignores the /n 
               fprintf(sf,"%s","Student Name: ");
               fprintf(sf,"%s\n",studentInfo[studindex].sName);
               
               printf("Enter Student email:");
	       scanf(" %29[^\n]", studentInfo[studindex].sEmail);
	       while(getchar() != '\n') continue;
               fprintf(sf,"%s","Email: ");
               fprintf(sf,"%s\n",studentInfo[studindex].sEmail);
               fprintf(sf,"\n");
           
               printf("Information has been saved to Student.dat\n");
           
   }
       
       else {
           fprintf(stderr, "Problems writing to file Student.dat");
       }
   fclose(sf);		
	
}

void fnPrintStudInfo(Student *studentInfo)
{
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		printf("Student ID: %lu\n Name: %s\n Email: %s\n", studentInfo[i].sID, studentInfo[i].sName, studentInfo[i].sEmail);
	} //prints all the students in the array structure
	

}

int fnSearchStud(Student* ps) //search via student id
{
	int j;
	unsigned long SID;
	for(j = 0; j < 10; j++){
		printf("Enter student ID:");
		scanf("%lu", &SID);
			if(SID == ps[j].sID) {
		return j;
		}
		else {
			printf("No such ID exists\n");
			return -1;
			}	
	}
	return STUD_ID;
}

void fnReturnSName(Student* studentInfo){ //prints selected student info via name comparison
	int l;
	string Name;
	int i;
	
		printf("Please enter full Student name:");
		scanf(" %[^\n]", Name);
			for(l = 0; l < 10; l++) {
				if(strcmp (Name, studentInfo[l].sName) == 0) {
					printf("Selected Student detail via student name\n");
					printf("Student Id: %lu\n",studentInfo[l].sID);
					printf("Student Name: %s\n",studentInfo[l].sName);
					printf("Student Email: %s\n",studentInfo[l].sEmail);
					}
				else {
					i = 1;
					}
			}
	if(i == 1) {
		 printf("No such Name exists");
		 }
}


