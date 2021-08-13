//CS2211a 2020
//Assignment 4
//Brendan Bain
//251086487
//bbain7
//Nov 16th 2020

#include "headers.h"

int main(void){	//main 

	int numLine = -1;   //numLine: used to count how many lines of input user entered
	char str[1000];    //str: used to get input from user
	SingleLine *pL;   //pL: pointer of SingleLine
	pL = (SingleLine *) calloc(1, sizeof(SingleLine));

	inputParagraph(pL, str, &numLine);   //call on all functions 
	printSingleWords(pL, numLine);
	printSingleLines(pL, numLine);
	searchSingleFunction(pL, str, numLine);

}
