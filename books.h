/* 
 * File:   books.h
 * Author: nezu
 * books header file
 * Created on February 23, 2013, 5:09 PM
 */

#ifndef BOOKS_H
#define	BOOKS_H



typedef char* string;

typedef enum
{
BK_ID,BK_Name
}
B_STATUS;

typedef struct 
{
unsigned long bID;
char bName[30];
char author[20];
short int quantity;	
} Book;

//Book Prototype

void fnAddBookInfo(Book*, int);
void fnPrintBookInfo(Book []);
int fnSearchBook(Book*);//funct that searches via book id and prints that struct
void fnReturnTitle(Book []);//funct that searches via title and print that struct

#endif	/* BOOKS_H */
