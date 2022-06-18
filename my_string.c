

#include <stdio.h>
#include "my_string.h"
#include <stdlib.h>
/*
struct my_string {

    int size;
    int capacity;
    char* data;

};

typedef struct my_string My_string;
*/
MY_STRING my_string_init_default(void) {
    My_string* pString;

    pString = (My_string*)malloc(sizeof(My_string));

    if (pString != NULL) {
        pString->size = 0;
        pString->capacity = 7;
        pString->data = (char*)malloc(sizeof(char) * pString->capacity);
    }
    if (pString->data == NULL)
    {
        free(pString);
	pString = NULL;

    }


    return (MY_STRING)pString;

}

Status my_string_assignment(ITEM* pLeft, ITEM Right){

	My_string* pRight = (My_string*) Right;
	My_string* ppLeft = (My_string*) *pLeft;

	if(ppLeft == NULL) {
		ppLeft = (My_string*)my_string_init_default();

		if (ppLeft == NULL) {

                return FAILURE;

       		 }

	}

	if(pRight == NULL) {

		return FAILURE;
	}



	ppLeft->size = 0;

		for (int i = 0; i < pRight->size; i++) {
		

	
			my_string_push_back((MY_STRING) ppLeft, pRight->data[i]);

		
		}
		

	*pLeft =  ppLeft; 
	return SUCCESS;	
}

void my_string_destroy(ITEM* phItem)
{
    //cast to the known type
    My_string* pItem = (My_string*)*phItem;


    if(pItem != NULL) {

		   
    free(pItem->data);
    free(pItem);
     	
    }
	  *phItem = NULL;

    
    
}


MY_STRING my_string_init_c_string(const char* c_string) {
    My_string* pString;
    int length = 0;
   
    
    pString = (My_string*)malloc(sizeof(My_string));

    if (pString != NULL) {
	  while (c_string[length] != '\0')
	  {
      		  length++;
          }

	pString->size = length;
        pString->capacity = length + 1;
        pString->data = (char*)malloc(sizeof(char) * pString->capacity );
	if(pString->data == NULL ){
		free(pString);

		return NULL;
	}
        for (int j = 0; j < length; j++) {
            pString->data[j] = c_string[j];
          
	}
    }
        return (MY_STRING) pString;
    
    
}

int my_string_get_capacity(MY_STRING hMy_string) {
    My_string* pString = (My_string*)hMy_string;
	if(pString == NULL){
		printf("my get capacity error, string is null");
		exit(1);
	}
    return (int)pString->capacity;
}

int my_string_get_size(MY_STRING hMy_string) {
    My_string* pString = (My_string*)hMy_string;
      if(pString == NULL){
                printf("my get size error, string is null");
                exit(1);
        }


    return (int)pString->size;
}


int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {

    My_string* phLeft_string = (My_string*)hLeft_string;
    My_string* phRight_string = (My_string*)hRight_string;
	if(phLeft_string == NULL || phRight_string == NULL ){
		printf("String is Null:Error");
		exit(1);

	}
	int i = 0;
	int size = my_string_get_size(phLeft_string);
	if (my_string_get_size(phLeft_string)  >  my_string_get_size(phRight_string)  ){

		size = my_string_get_size(phRight_string);


	}

    while (i < size) {
	

	 if (phLeft_string->data[i] > phRight_string->data[i])
   		 {

       		 return 1;

   	 }
	 
	  else if (phLeft_string->data[i] < phRight_string->data[i]){
		 
		 return -1;
	 }

        i++;
    }

    if (my_string_get_size(phLeft_string) > my_string_get_size(phRight_string)){

		return 1;

		    }

    else if(my_string_get_size(phLeft_string) <  my_string_get_size(phRight_string)) {

		return -1;

    }


    else {

		return 0;

    }
    

/*
	int i = 0;

        My_string* pLeftString = (My_string*)(hLeft_string);
        My_string* pRightString = (My_string*)(hRight_string);

        while(pLeftString->data[i] != '\0' && pRightString->data[i] != '\0'){
                if(pLeftString->data[i] < pRightString->data[i]){
                        return -1;
                }
                if(pLeftString->data[i] > pRightString->data[i]){
                        return 1;
                }
                else {
                        ++i;
                }
        }
        return 0;
*/
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp){
   My_string* pMy_string = (My_string*) hMy_string;
    if(pMy_string == NULL || fp == NULL){
	    return FAILURE;
    }

    char c = '\0';
    int status = fscanf(fp,"%c", &c);

    if(status){
        pMy_string->size = 0;
        while(status){
            //Resize if capacity = size to 2*size
            if(pMy_string->capacity == pMy_string->size){
                char* newData = (char*) malloc(sizeof(char) * pMy_string->capacity * 2);
                if(newData == NULL) {
			return FAILURE;
		}
                for(int i = 0; i<pMy_string->size; i++)
                    newData[i] = pMy_string->data[i];
                
                free(pMy_string->data);
                pMy_string->data = newData;
                pMy_string->capacity *= 2;
            }
            if(c == '\n' || c == EOF || c == '\0')
                break;
            if(c == ' '){
                ungetc(c, fp);
                c = '\0';
                break;
            }
            pMy_string->data[pMy_string->size++] = c;
            status = fscanf(fp,"%c", &c);
        }
    }
    if(status != 1 && c == '\0'){
	    return FAILURE;
    }
    
    return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp){
	
 My_string* pMy_string = (My_string*)hMy_string;
	if(pMy_string == NULL || pMy_string->size == 0) {
		return FAILURE;

	}



	for(int i = 0; i < pMy_string->size; i++){
		fprintf(fp,"%c", pMy_string->data[i]);


	}

 pMy_string->size = 0;


 return SUCCESS;
}


Status my_string_push_back(MY_STRING hMy_string, char item){
	 My_string* pMy_string = (My_string*)hMy_string;

	  if(pMy_string == NULL ) {
                return FAILURE;

        }
	   if(pMy_string->capacity <=  pMy_string->size){
                char* newData = (char*) malloc(sizeof(char) * pMy_string->capacity * 2);  //Maybe another size
                if(newData == NULL) {
                        return FAILURE;
                }
                for(int i = 0; i< pMy_string->size; i++){

                    newData[i] = pMy_string->data[i];
		}
                free(pMy_string->data);
                pMy_string->data = newData;
                pMy_string->capacity *= 2;
            }

	   pMy_string->data[pMy_string->size] = item;
	   pMy_string->size++;






 return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index) {

 	My_string* pMy_string = (My_string*)hMy_string;

	if(my_string_empty(pMy_string)){


                return NULL;

	}

        if (index >= pMy_string->size || index < 0){
		return NULL;
	}


	  return &(pMy_string->data[index]);





}
Status my_string_pop_back(MY_STRING hMy_string){

	 My_string* pMy_string = (My_string*)hMy_string;

	 if( my_string_empty(pMy_string)){
		return FALSE;
	 }

	 pMy_string->size--;
	 return SUCCESS;						


}

char* my_string_c_str(MY_STRING hMy_string) {																	
	My_string* pString = (My_string*)hMy_string;

	/*

	 if(pMy_string == NULL ) {
                return NULL;

        }

	      if(pMy_string->capacity == pMy_string->size){
                char* newData = (char*) malloc(sizeof(char) * pMy_string->capacity + 1);  //Maybe another size
                if(newData == NULL) {
                        return FAILURE;
                }
                for(int i = 0; i<pMy_string->size; i++)
                    newData[i] = pMy_string->data[i];

                free(pMy_string->data);
                pMy_string->data = newData;
                pMy_string->capacity *= 2;
            }







	pMy_string->data[pMy_string->size] = '\0';
	return (char*) pMy_string->data;

	*/

	char* temp;
    int i;

    if (pString->capacity <= pString->size) // Not even big enough for NULL terminator so resize
    {
        pString->capacity *= 2;
        temp = (char*)malloc(sizeof(char) * pString->capacity);

        if (temp == NULL)
        {
            pString->capacity /= 2;
            return NULL;
        }

        for (i = 0; i < pString->size; i++)
        {
            temp[i] = pString->data[i];
        }

        free(pString->data);
        pString->data = temp;
    }

    //Simply make sure the string has a NULL terminator before showing it as a c-string.
    pString->data[pString->size] = '\0';

    return pString->data;
}


Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){
	 My_string* pRstring = (My_string*)hResult;
	 My_string* pAstring = (My_string*)hAppend;

	 if (pRstring == NULL || pAstring == NULL){
		return FAILURE;
	 }

	 if(pRstring->capacity - pRstring->size <= pAstring->size ){
		            
                char* newData = (char*) malloc(sizeof(char) * pRstring->capacity * 2);  //Maybe another size
                if(newData == NULL) {
                        return FAILURE;
                }
                for(int i = 0; i< pRstring->size; i++)
                    newData[i] = pRstring->data[i];

                free(pRstring->data);
                pRstring->data = newData;
                pRstring->capacity *= 2;
            }


	 for(int j = 0; j < pAstring->size; j++){
		pRstring->data[pRstring->size++] =   pAstring->data[j];

	 }


	return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string){
	My_string* pMy_string = (My_string*)hMy_string;

	return (Boolean)(pMy_string->size <= 0);
}
