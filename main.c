#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_string.h"
#include "generic_vector.h"
#include "associative_array.h"
#define MAX_WORD_LEN 29

void clear_keyboard_buffer(void);
int wordLength(void);
int maxGuess(void);
void Hangman (GENERIC_VECTOR* dictionary, int guess_remaining, int wordLength, int showWordAmount );
Boolean alreadyGuessed (MY_STRING guessList, char guess);
void guessMessage(char msg, char guess);

Boolean wonGame(MY_STRING key_intial);
int main(int argc, char* argv[]) {

//	Tree* myTree = tree_init_default();
	
	
		
	
//	MY_STRING Hello = my_string_init_c_string("hello");

//	MY_STRING Yo = my_string_init_c_string("yo");
//	MY_STRING Water = my_string_init_c_string("water");                                                                                                                                                                                
  //     	MY_STRING Yoda = my_string_init_c_string("yoda"); 	
	

//	MY_STRING YoKey = my_string_init_c_string("yo--");

//	MY_STRING Wa = my_string_init_c_string("wa---");

//	MY_STRING llo = my_string_init_c_string("--ll-");


		
//	MY_STRING new_Key = my_string_init_default();

//	get_word_key_value(llo,new_Key, Hello, 'h');
	
//	for(int i= 0; i < my_string_get_size(new_Key); i++) {
//		printf("New key: %c\n",*my_string_at(new_Key, i));
//	}


//	insert(get_tree_root(myTree),YoKey ,Yo);

	

	
//	in_order_tree_print(get_tree_root(myTree));	

//	my_string_destroy(&new_Key);

//	my_string_destroy(&llo);
//	my_string_destroy(&Hello);
//	my_string_destroy(&Yo);
//	my_string_destroy(&Water);
//	my_string_destroy(&Yoda);



	

	FILE* fp;

	GENERIC_VECTOR arr[MAX_WORD_LEN];


	int size;

	int length;

	int numGuess;

	char userInput;

	char showWord;

	MY_STRING hString = my_string_init_default();


//	GENERIC_VECTOR wordListVector = generic_vector_init_default(my_string_assignment, my_string_destroy);




	for(int i = 0; i < MAX_WORD_LEN; i++) {
		arr[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);


	}


        fp = fopen("dictionary.txt", "r");

	while(my_string_extraction(hString,fp)) {
		size = my_string_get_size(hString);

		generic_vector_push_back(arr[--size],hString);


		}

/*
	for(int i = 0; i < MAX_WORD_LEN; i++) {	
		printf("Size %d:\n",i + 1);
		printf("%d\n",generic_vector_get_size(arr[i]));
	
		}
*/
	fclose(fp);

	
	
	do {

		printf("What word length do you like to play with?\n");
		length = wordLength(); 

		numGuess = maxGuess();


		printf("Do you wish to see the total number of words remaining. (y/n)\n");

		scanf(" %c", &showWord);

		clear_keyboard_buffer();
		
		printf("\n");

		Hangman(arr, numGuess, length,showWord);

		printf("Do you wanna play the game again.(y/n)\n");

                scanf(" %c",&userInput);

                clear_keyboard_buffer();





		



		


		
	}
	while (userInput == 'y');

	
	
 	for(int i = 0; i < MAX_WORD_LEN; i++) {
        	generic_vector_destroy(&(arr[i]));

   	}


        my_string_destroy((ITEM*) &(hString));
	
	
	

	

/*
	
	
 MY_STRING hl_string = my_string_init_c_string("apple");
 
 printf("Size: %d\n",my_string_get_size(hl_string));
 printf("Capacity: %d\n",my_string_get_capacity(hl_string));

 MY_STRING hr_string = my_string_init_c_string("orange");


 printf("Size: %d\n",my_string_get_size(hr_string));
 printf("Capacity: %d\n",my_string_get_capacity(hr_string));

 printf("Compare: %d\n",my_string_compare(hl_string,hr_string));

 my_string_destroy(&hl_string);

 my_string_destroy(&hr_string);
 


   MY_STRING hMy_string = NULL;
   FILE* fp;

   hMy_string = my_string_init_default();
   fp = fopen("dictionary.txt", "r");


   while(my_string_extraction(hMy_string, fp))
   {
	  

	   if (my_string_get_size(hMy_string) == 5){	   

		 my_string_insertion(hMy_string, stdout);
		 printf("\n");
		 }


	
   }
  
   my_string_destroy(&hMy_string);
   fclose(fp);
 


  MY_STRING hRstring = my_string_init_c_string("hell");

  MY_STRING hAstring = my_string_init_c_string("o");




  my_string_concat(hRstring, hAstring);

  for(int i = 0; i < my_string_get_size(hRstring); i++){

	printf("%c ",*(my_string_at(hRstring, i)));


  my_string_c_str(hRstring);

 printf("Printing with String: %s\n", (my_string_at(hRstring, 0))); 


  while(!my_string_empty(hRstring)){
             my_string_pop_back(hRstring);
  }
  if (my_string_empty(hRstring)){
        printf("\nString header is empty\n");
  }


  for(char alpha = 'A'; alpha <= 'Z'; alpha++){
 	 my_string_push_back(hRstring, alpha);	

  }

   for(int i = 0; i < my_string_get_size(hRstring); i++){

        printf("%c ",*(my_string_at(hRstring, i)));
  }



   my_string_destroy((Item*)&hRstring);
   my_string_destroy((Item*)&hAstring);


	
MY_STRING arr[100];


for(int i = 0; i < 100; i++) {
	arr[i] = NULL;


}


  arr[0] =  my_string_init_c_string("COPY ME!");
       



   for(int i = 1; i < 100; i = i + 2) {
	my_string_assignment((Item*)&arr[i], (Item)arr[0]);


   }

   for(int i = 0; i < 100; i++) {
	my_string_insertion(arr[i],stdout);
	printf("\n");
	my_string_destroy((Item*)&(arr[i]));

   }
*/
 


return 0;
	
}


	





void clear_keyboard_buffer(void) {
    char c;
    int noc;
    noc = scanf("%c", &c);

    while (noc == 1 && c != '\n') {
        noc = scanf("%c", &c);
    }
}

int maxGuess(void)
{
    int number_of_guesses;
    int noc;

    printf("How many guesses would you like: ");
    noc = scanf("%d", &number_of_guesses);
    clear_keyboard_buffer();

    while (number_of_guesses <= 0)
    {
        if (noc < 1){
	       	printf("Invalid input.\n");
	}

        printf("How many guesses would you like: ");
        scanf("%d", &number_of_guesses);
        clear_keyboard_buffer();
    }

    return number_of_guesses;
}


int wordLength(void) {	
    int word_length;

    scanf("%d", &word_length);
    clear_keyboard_buffer();

   
    while (word_length < 2 || word_length >29 || word_length == 23 || word_length == 25 || word_length == 26 || word_length == 27)
    {
        printf("Invalid word length. Choose again: ");
        scanf("%d", &word_length);
        clear_keyboard_buffer();
    }

    return word_length;

}

void Hangman (GENERIC_VECTOR* dictionary, int guess_remaining, int wordLength, int showWordAmount ) {
	
	int i;
	
	int wordListSize;

	Tree* wordTree;

	MY_STRING new_key;

	
	MY_STRING usedLetters = my_string_init_default();

	MY_STRING currentWord;
	
	MY_STRING key_intial = my_string_init_default();

	MY_STRING current_key;

	
	GENERIC_VECTOR currentWordlist = generic_vector_init_default(my_string_assignment, my_string_destroy);

	int correctGuessCount = 0;	
//	printf("CHECK\n");

	for(i = 0; i < wordLength; i++) {
		my_string_push_back(key_intial,'-');

	
	}
	
	for(i = 0; i < generic_vector_get_size(dictionary[wordLength - 1]); i++) {

		generic_vector_push_back(currentWordlist,generic_vector_at(dictionary[wordLength - 1],i ));

	}
	
//	printf("CHECK\n");
//	char guessedLetters[26] = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'};
	
	char guess = ' ';

	char msg = 'B';

	int noc;

	while (guess_remaining > 0) {

		

		wordListSize = generic_vector_get_size(currentWordlist);
		if(showWordAmount == 'y') {
			printf("There are %d possibilties remaining\n", wordListSize);

		}
		printf("You have %d guesses remaining\n", guess_remaining);	
		printf("Used letters: %s\n", my_string_c_str(usedLetters));
	
		/*printf("Used letters:");
		 for (i = 0; i < 26; i++ ) {

                                if((guessedLetters[i] > 96) && (guessedLetters[i] < 123) ) {
                                        printf(" %c", guessedLetters[i]);

                                }


                        }
*/
		printf("\nWord: %s\n",my_string_c_str(key_intial));
		
		guessMessage(msg,guess);

		printf("Enter your guess:\n");
		noc = scanf(" %c",&guess);
		

		msg = 'B';
		
		 clear_keyboard_buffer();

		while (noc < 1 || !isalpha(guess))
       		 {
        		printf("Invalid input\n");
                	printf("Enter your guess:\n ");
                	noc = scanf(" %c", &guess);
                	clear_keyboard_buffer();
                   }
	


		guess = tolower(guess);


			if (!(alreadyGuessed(usedLetters, guess ))) {
				my_string_push_back(usedLetters, guess);
				my_string_push_back(usedLetters, ' ');
				}

			else {

				correctGuessCount = -1;
				}
	

		/*
		while (guess == guessedLetters[guess - 'a']) {
			printf("You have already guessed that letter. Try again!\n");
			scanf(" %c",&guess);
			clear_keyboard_buffer();
			msg = 'A';
		}	

		guessedLetters[guess - 'a'] = guess;
		
		*/


		guessMessage(msg,guess);
		wordTree = tree_init_default();
		
	//	new_key = my_string_init_default();
		for(i = 0; i < wordListSize;  i++) {
			new_key = my_string_init_default();


			currentWord = generic_vector_at(currentWordlist,i);
		//	my_string_c_str(currentWord);
		//	printf("Current Word: %s\n",my_string_at(currentWord,0));
			get_word_key_value(key_intial, new_key, currentWord , guess);
		
		//	my_string_c_str(new_key);
		//	printf("New key: %s\n",my_string_at(new_key,0));


//			printf("After get word key value function call CHECK\n");
			tree_insert(wordTree,new_key, currentWord);
			
	//		in_order_tree_print(wordTree->root);

			my_string_destroy(&new_key);
		}
//			my_string_destroy(&new_key);	

			current_key = my_string_init_default();    //Create a key for list of words that has the max size using guess	

		        

		
	//		my_string_destroy(&new_key);


			in_order_tree_print(wordTree->root);

	       // current_key = my_string_init_default();
	//	printf("CHECK\n");

	//	maxVector = *find_max_list_in_tree(&wordTree);
		
		//	generic_vector_destroy(&currentWordlist);	
			generic_vector_destroy(&currentWordlist);	

			swapVector(&currentWordlist,find_max_list_in_tree(&wordTree));  //Put function straight in the swapVector and not through a variable
				
		//	Tree_destroy(&wordTree);

			currentWord = generic_vector_at(currentWordlist,0);   //Start a new key with the first word in the new generic vector
			
	//		printf("Key intial Before using it for Current Key: %s \n", my_string_c_str(key_intial));

			get_word_key_value(key_intial, current_key, currentWord , guess);  //Make a new key for the new generic vector based on the max size
		
		//	in_order_tree_print(wordTree->root);
			
	//		 printf("Key Current: %s \n", my_string_c_str(current_key));


			my_string_destroy(&key_intial);

			key_intial = my_string_init_default();
				
						//I changed things around and messed things up and I know that my keys are being overwritten and not added on too
						//
						//

			my_string_assignment(&key_intial,current_key);
			
	//		printf("Key intial After: %s \n", my_string_c_str(key_intial));

	//		
	//		printf("Current Key before its destoryed: %s and intial key %s\n", my_string_c_str(current_key), my_string_c_str(key_intial));
		

			Tree_destroy(&wordTree);

			my_string_destroy(&current_key);

			for(i = 0; i < wordLength; i++) {
	//			printf("Guess compared to letter of key: %c and %c\n",guess,*my_string_at(key_intial,i)); 
				if(*my_string_at(key_intial,i) == guess) {
					correctGuessCount++;
				}
			}	


			if(correctGuessCount > 0) {
		            	msg = 'F';
              
			}

			else if (correctGuessCount < 0) {
				msg = 'P';
			}

			else {
				msg = 'W';
				guess_remaining--;

			}

			correctGuessCount = 0;
/*

		for(i = 0; i <  wordLength; i++ ) {
				while(*my_string_at(key_intial,i) == '-') {
					break;
				}
				else {

				foundWord = 1;
				break;
				}

			}
*/

/*
			printf("Used Letters:  ");
			for (i = 0; i < 26; i++ ) {

				if((guessedLetters[i] > 96) && (guessedLetters[i] < 123) ) {
					printf(" %c", guessedLetters[i]);

				}

		
			}	
			printf("\nWord: %s\n", my_string_c_str(key_intial));
*/			
	if(wonGame(key_intial)) {
		printf("Congrats!!! The word was %s\n",my_string_c_str(currentWord));
		break;
	}	
	
	
	else if (guess_remaining <= 0) {

                printf("Didn't find the word. The word was %s \n",my_string_c_str(generic_vector_at(currentWordlist,0)));
        }
	

}



	my_string_destroy(&key_intial);
	
//	printf("Below key intial dest\n");	 
	generic_vector_destroy(&currentWordlist);	
	
//	printf("below currWrdlist\n");
	my_string_destroy(&usedLetters);		
//	 printf("Below used letter dest\n");
//	my_string_destroy(&new_key);

//	my_string_destroy(&currentWord);	

//	printf("Below used currentWord\n");

}

Boolean alreadyGuessed (MY_STRING guessList, char guess) {
	printf("Size of Gueesslist %d\n",my_string_get_size(guessList));
	for (int i = 0; i < my_string_get_size(guessList); i++) {
		if(guess == *my_string_at(guessList,i)) {
			return TRUE;

		}
	
	}
	return FALSE;
}

Boolean wonGame(MY_STRING key_intial) {
	for(int i = 0; i < my_string_get_size(key_intial); i++) {
		if (*my_string_at(key_intial, i) == '-') {
			return FALSE;
		}

	}

	return TRUE;



}

void guessMessage(char msg, char guess) {

	switch (msg) {

		case 'F': //Found letter
			printf("The letter %c was in the word\n", guess);
			break;
		case 'P': //Already played letter
			printf("You have already guessed the letter %c\n",guess);
			break;
		case 'W':	//Wrong letter
			printf("The letter %c was not in the word\n",guess);
			break;
		case 'B':
			break;
	}
		 

}
