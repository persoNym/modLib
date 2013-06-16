/* 
 * File:   students.h
 * Author: nezu
 * source file for books
 * Created on February 23, 2013, 5:08 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"
#include "main.h"


void fnAddBookInfo(Book *bookInfo, int bookindex)
{
	
		
    FILE *bf; 
    bf = fopen("Book.dat", "a+");
     
       if (bf != NULL) {
           
               printf("Enter Book ID:");
	       scanf("%lu",&bookInfo[bookindex].bID); 
               fprintf(bf,"%s","Book ID: ");
               fprintf(bf,"%lu\n",bookInfo[bookindex].bID);
               
               printf("Enter Title:");
	       scanf(" %29[^\n]",bookInfo[bookindex].bName);
               while(getchar() != '\n') continue; //discards new line
               fprintf(bf,"%s","Title: ");
               fprintf(bf,"%s\n",bookInfo[bookindex].bName);
               
               printf("Enter Author:");
	       scanf(" %19[^\n]", bookInfo[bookindex].author);
	       while(getchar() != '\n') continue;
               fprintf(bf,"%s","Author: ");
               fprintf(bf,"%s\n", bookInfo[bookindex].author);
               
               printf("Enter Quantity:");
	       scanf("%hi", &bookInfo[bookindex].quantity);
               fprintf(bf,"%s","Quantity: ");
               fprintf(bf,"%hi\n", bookInfo[bookindex].quantity);
               fprintf(bf,"\n");
          
           
           printf("Information has been saved to Book.dat\n");
           
       }
       else {
           fprintf(stderr, "Problems writing to file Book.dat");
       }
   fclose(bf);	
}

void fnPrintBookInfo(Book *bookInfo)
{
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		printf("Book ID: %lu\n Title: %s\n Author: %s\n Quantity: %hi\n", bookInfo[i].bID, bookInfo[i].bName, bookInfo[i].author, bookInfo[i].quantity);
	} 
}

int fnSearchBook(Book* pb)
{
	int k;
	unsigned long BID;
	for(k = 0; k < 1; k++){
		printf("Enter book ID:");
		scanf("%lu", &BID);
			if(BID == pb[k].bID) {
				return k;	
			}
			else {
				printf("No such ID exists\n");
				return -1;	
			}	
	}
	return BK_ID;
}	

void fnReturnTitle(Book* bookInfo) { 

	int m;
	string title;
	int i;
	
	printf("Please enter Title:");
	scanf("%19s[^\n]", title);
	for(m = 0; m < 10; m++) {
		if(strcmp (title, bookInfo[m].bName) == 0) {
			printf("Selected Book detail via book title\n");
			printf("Book Id: %lu\n", bookInfo[m].bID);
			printf("Title: %s\n",bookInfo[m].bName);
			printf("Author: %s\n",bookInfo[m].author);
			printf("Quantity: %i\n",bookInfo[m].quantity);
		}
		else {
			i = 1;	
		}
	}
	if (i == 1) {
		printf("No such title exists \n");
		}
}
