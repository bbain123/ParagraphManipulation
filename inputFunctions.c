//CS2211a 2020
//Assignment 4
//Brendan Bain
//251086487
//bbain7
//Nov 16th 2020

void inputParagraph(SingleLine *p, char str[], int* numLines){ //collects user input, print individual words, prints each lines
	*numLines = 1; //the number of paragraphs


	p[0].wordCount = 0;

	while(0==0){
		printf("\nEnter a string: ");
		fgets(str, 1000, stdin);

		int wordLength = 0, numWords = 0, i = 0;//wordLength: length of individual word | numWords: number of words | i: used to go through string input
		char check = str[i], prev = ' ';	//check: the current character from input | prev: the previous character
		if (str[i] == '\n')						//if user enters empty line, exit while loop
			break;
		
		p = (SingleLine *)realloc(p, ((*numLines)*sizeof(SingleLine)));		 //reallocate space for single lines
		p[(*numLines-1)].wordSentence = (Word *) calloc (1, sizeof(Word));		//allocate space for words
		p[(*numLines-1)].wordSentence[0].pChar = (char *) calloc (1, sizeof(char));    //allocate space for characters


		while (check != '\0'){				
			if (check != ' ' && prev == ' '){						//beginning of word
				numWords++;								//increase number of words
				p[(*numLines)-1].wordSentence[(numWords-1)].pChar =			//expand space by one character 
				(char *)realloc(p[(*numLines)-1].wordSentence[(numWords-1)].pChar, (wordLength+1) * sizeof(char));
				wordLength++;
				p[(*numLines)-1].wordSentence[(numWords-1)].pChar[(wordLength-1)] = check; //add character  
			
			}
			else if (check != ' ' && prev != ' '){						//middle of word
				p[(*numLines)-1].wordSentence[(numWords-1)].pChar = 
				(char *) realloc(p[(*numLines)-1].wordSentence[(numWords-1)].pChar, (wordLength+1)*sizeof(char));
				wordLength++;								//increase word length 	
				p[(*numLines)-1].wordSentence[(numWords-1)].pChar[(wordLength-1)] = check; //add character
			}
			else if (check == ' ' && prev != ' '){						//end of word 
				p[(*numLines)-1].wordSentence = (Word *) realloc(p[(*numLines)-1].wordSentence, numWords*sizeof(Word));
				p[(*numLines)-1].wordSentence[(numWords-1)].charCount = wordLength; //set char count 
				p[(*numLines)-1].wordSentence[(numWords-1)].wordPos = numWords;  //set word position
				wordLength = 0;
			}
			prev = str[i];		//set prev to current character
			i++;
			check = str[i];		//set check as next character
		}
		
		if (prev != ' ' && check == '\0'){	//end of word due to end of string
			p[(*numLines)-1].wordSentence = (Word *) realloc(p[(*numLines)-1].wordSentence, numWords*sizeof(Word)); 
			p[(*numLines)-1].wordSentence[(numWords-1)].charCount = wordLength - 1;
			p[(*numLines)-1].wordSentence[(numWords-1)].wordPos = numWords;
		}
	
		p[(*numLines)-1].wordCount = numWords;
		p[(*numLines)-1].linePos = *numLines;
		*numLines = *numLines + 1;  		//increase number of single lines 		
	
	}
}
