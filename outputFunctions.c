//CS2211a 2020
//Assignment 4
//Brendan Bain
//251086487
//bbain7
//Nov 16th 2020

void printSingleWords(SingleLine *p, int numLines){//prints words entered by the user one line at a time
	printf("\nThis is all the words printed out one line at a time: \n");
	for (int i = 0; i < numLines-1; i++){			
		int words = (p[i].wordCount);    //words: number of words in line

		for(int j = 0; j < words; j++){
			int chars = p[i].wordSentence[j].charCount; //chars: number of chars in word
			char str[1000] = "";
			for(int k = 0; k < chars; k++){
				char letter = p[i].wordSentence[j].pChar[k];
				strncat(str, &letter, 1);		//build the word one char at a time
			}
			printf("%s\n", &str);				//print out the word one at a time
		}	
	}
	printf("\n\n");	
}

void printSingleLines(SingleLine *p, int numLines){//prints lines entered by the user without extra whitespace 
	printf("This is all the words printed out on the same line as entered: \n");
	for (int i = 0; i < numLines-1; i++){
		int words = (p[i].wordCount);			//words: number of words in line
		char line[1000] = "";

		for (int j = 0; j < words; j++){
			int chars = (p[i].wordSentence[j].charCount); //build words, add a space to the end, and add it to line cumulative string
			char str[1000] = ""; 	//str: string that accumulates the words
			char space[2] = " ";	//space: the space string added after characters

			for (int k = 0; k < chars; k++){
				char letter = p[i].wordSentence[j].pChar[k]; //build words character at a time
				strncat(str, &letter,1);
			}
			strcat(str, space);  			//adds space to end of word
		        strcat(line, str);			//add word to sentence
		}
		printf("%s\n", &line);
	}
	printf("\n\n");
}

void searchSingleFunction(SingleLine *p, char str[], int numLines){//searches for every instance of a word specified by user and prints its location 
	
	while (0==0){
		printf("\nEnter a word to search: ");
		fgets(str, 1000, stdin);
		int found = 0;						//found: 0 if no instances of word, 1 if at least one was found

		if(str[0] == '\n')   						//exit if new line
			break;

		for(int i = 0; i < numLines-1; i++){
			int words = (p[i].wordCount);

			for(int j = 0; j < words; j++){
				int chars = (p[i].wordSentence[j].charCount);
				char word[1000] = "";

				for(int k = 0; k < chars; k++){
					char letter = p[i].wordSentence[j].pChar[k];	//build word one character at a time
					strncat(word, &letter, 1);
				}
				if(strcmp(str, word) == 0){			//if target word matches word print location of where it was found
					printf("%s found in line %i position %i\n", &str, &i, &j);	
					found = 1;
				}
			}
		}
		if (found == 0)						//if there were no matches, print appropriate messate
			printf("%s was not found in this file\n", &str);
	}

	for(int i = numLines - 1; i >= 0; i--){				//free allocated space
		int words = (p[i].wordCount);
		
		for (int j = words - 1; j>= 0; j--){
			free(p[i].wordSentence[j].pChar);
			free(p[i].wordSentence);
		}
	}
	free(p);
}
