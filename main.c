/* 
@title					main
@description			Database emulation with files
@author					Victoria C
@version 				2.0
@ last revised 			03/4/13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "books.h"
#include "students.h"



int main(void)
{

int bookindex = 0;
int studindex = 0;
B_STATUS bookstatus;
S_STATUS studstatus;
Book book; //struct type Book named book
Student student; //struct type Student named student
Student studentInfo[10] = {}; //stores 10 student structures all initialized to NULL
Book bookInfo[10] = {}; //store 10 book structures all initialized to NULL
Student* ps = studentInfo;	//pointer to traverse the student array
Book* pb = bookInfo; //pointer to traverse the book array
int i,choice; //for menu loop and swtich statement
string menu[9] = {"1. Add new book\n","2. Add new student\n","3. Print book list\n",
"4. Print student list\n","5. Find student by ID\n","6. Find student by name\n",
"7. Find book by ID\n","8. Find book by name\n","9. Quit\n"};



	for(;;){ //menu loop 
            puts(" ");
			puts("LIBRARY SYSTEM MAIN MENU"); 
            puts("-------------------------------------");
                 for(i = 0; i < 9; i++) {
                    printf("%-10s", menu[i]);
                 }
            printf("SELECT:");
            scanf("%i", &choice);
                if(choice < 1 || choice > 9) {
                     printf("Invalid Option: %i\n", choice);
                     printf("SELECT:");
					 scanf("%i", &choice);
            }
               switch(choice) {
        
    case 1: //add new book function called
        fnAddBookInfo(bookInfo, bookindex); //function saves each new book to file
	bookindex++;
	break;
            
    case 2: //add new student function called
        fnAddStudInfo(studentInfo, studindex); //function saves each new student to file
        studindex++;
	break;
            
    case 3: //print book list function called
        fnPrintBookInfo(bookInfo); //prints all the book structures in the array
	break;
              
    case 4: //print student list function called
	fnPrintStudInfo(studentInfo); //prints all the students structures in the array
	break;
            
    case 5: //find student by student ID function called
        {int j = fnSearchStud(studentInfo);
            if(j != -1) {
		printf("Selected Student detail via student ID\n");
		printf("Student Id: %lu\n",studentInfo[j].sID);
		printf("Student Name: %s\n",studentInfo[j].sName);
		printf("Student Email: %s\n",studentInfo[j].sEmail);
    } 
           else { break;}
           break;} //only prints specified student structure from array via the student ID
            
    case 6: //find student by student name function called
        fnReturnSName(studentInfo);
        break;//only prints specified student structure from array via student name
    
    case 7: //find book by book ID function called
        {int k = fnSearchBook(bookInfo);
             if(k != -1) {
		 printf("Selected Book detail via book ID\n");
		 printf("Book Id: %lu\n", bookInfo[k].bID);
		 printf("Title: %s\n",bookInfo[k].bName);
		 printf("Author: %s\n",bookInfo[k].author);
		 printf("Quantity: %i\n",bookInfo[k].quantity);
	}
	    else { break;   }
            break;} //only prints specified book structure from array via book ID
    
    case 8: //find book by book name function called
        fnReturnTitle(bookInfo);
        break; 
    
    case 9: //quit the menu. Will cause it to break out of switch and then after break loop
        break;
            
    }
    if(choice == 9) { //quits the loop
        printf("Exiting Program\n");
        break;
    }
			}
			
return 0;	
}

