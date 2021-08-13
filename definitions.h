//CS2211a 2020
//assignment 4
//Brendan Bain
//251086487
//bbain7
//Nov 16th 2020


#ifndef DEFINITIONS
	#define DEFINITIONS
	
	typedef struct word{
		char *pChar;
		int charCount;
		int wordPos;
	}Word;

	typedef struct sentence{
		Word *wordSentence;
		int wordCount;
		int linePos;
	}SingleLine;

#endif
