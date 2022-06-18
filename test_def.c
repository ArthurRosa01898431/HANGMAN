#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h"


Status test_init_default_returns_nonNULL(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();

 if(hString == NULL)
 {
    strncpy(buffer, "test_init_default_returns_nonNULL\n"
    "my_string_init_default returns NULL", length);
    return FAILURE;
 }
 else
 {	
    my_string_destroy((ITEM*)&hString);
    strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
    return SUCCESS;
 }
}


Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_default();

 if(my_string_get_size(hString) != 0)
 {
    status = FAILURE;
    printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
    strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
    "Did not receive 0 from get_size after init_default\n", length);
 }
 else
 {
    status = SUCCESS;
    strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
    , length);
 }

 my_string_destroy((ITEM*)&hString);
 return status;
}



 Status test_arosa_my_string_destroys_nullfies_valid_object(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();

 my_string_destroy((ITEM*)&hString);

 if(hString !=  NULL)
 {
      strncpy(buffer, "test_arosa_my_string_destroy_nullfies_valid_object\n"" my_string_destorys_doesn't_nullify_valid_object\n" , length); 
      hString = NULL;   
      return FAILURE;


 }

 else
 {
	  strncpy(buffer, "test_arosa_my_string_destroys_nullfies_valid_object\n" , length);
	  return SUCCESS;



 }
}





Status test_arosa_my_string_init_c_string_put_correct_c_string(char* buffer, int length){

 char c_string[] = {"Hello"};
 MY_STRING hString = my_string_init_c_string("Hello");
 Status status;

 for(int i = 0; i < my_string_get_size(hString); i++) {
	if (c_string[i] != *(my_string_at(hString,i))) {
		status = FAILURE;
	}

	status = SUCCESS;

 }

 if(status == FAILURE) {
         
         strncpy(buffer, "test_arosa_my_string_init_c_string_put_correct_c_string\n" "my_string_init_c_string_puts_incorrect_c_string_in_data", length);
        

 }

 else {

        strncpy(buffer, "test_arosa_my_string_init_c_string_put_correct_c_string\n", length);



 }
         my_string_destroy((ITEM*)&hString);
         return status;

}





Status test_arosa_my_string_get_capacity_returns_correct_capacity(char* buffer, int length) {

 MY_STRING hString = NULL; 
 hString = my_string_init_default();
 Status status;

 if(my_string_get_capacity(hString) != 7) {
	 printf("Expect 1 but got %d\n", my_string_get_capacity(hString));
	 strncpy(buffer, "test_arosa_my_string_get_capacity_returns_correct_capacity\n" " _my_string_get_capacity_returns_incorrect_capacity", length);
         status = FAILURE;

 }

 else {

	strncpy(buffer, "test_arosa_my_string_get_capacity_returns_correct_capacity\n", length);

	status =  SUCCESS;


 }
	 my_string_destroy((ITEM*)&hString);
 	 return status;

}


Status test_arosa_my_string_get_size_returns_correct_size(char* buffer, int length) {

 MY_STRING hString = NULL;
 hString = my_string_init_default();

 Status status;


 if(my_string_get_size(hString) != 0) {
	printf("Expect size 0 but got %d\n", my_string_get_size(hString));
         strncpy(buffer, "test_arosa_my_string_get_size_returns_correct_size\n" " _my_string_get_size_returns_incorrect_size", length);
         status = FAILURE;
 
 }


 else {

 
	 strncpy(buffer, "test_arosa_my_string_get_size_returns_correct_capacity\n", length);

 	status = SUCCESS;


 }

	 my_string_destroy((ITEM*)&hString);
	 return status;

}

Status test_arosa_my_string_compare_identical_strings_return_0(char* buffer, int length) {
	 MY_STRING hlString = my_string_init_c_string("HELLO");
	 MY_STRING hrString = my_string_init_c_string("HELLO");
	 Status status;


	 if(my_string_compare(hlString, hrString) !=  0){
		         strncpy(buffer, "test_arosa_my_string_compare_identical_strings_return_0\n" " _my_string_compare_returns_incorrect_integer", length);
        	status = FAILURE;



	 }

	 else {

		  strncpy(buffer, "test_arosa_my_string_compare_identical_strings_return_0\n", length);
		status = SUCCESS;
		

	 } 

	 my_string_destroy((ITEM*)&hrString);
       	my_string_destroy((ITEM*)&hlString);

	return status;



}

Status test_arosa_my_string_extraction_returns_failure_when_object_is_null(char* buffer, int length) {
	 MY_STRING hString = NULL;
        Status status;


        FILE* fp;

        fp = fopen("dictionary.txt", "r");
        my_string_extraction(hString,fp);

        if((my_string_extraction(hString,fp)!= FAILURE)){
           
                 strncpy(buffer, "test_arosa_my_string_extraction_returns_failure_when_object_is_null" "my_sting_extraction_does_not_return_NULL",length);
                 status = FAILURE;


        }

        else {


                strncpy(buffer, "test_arosa_my_string_extraction_returns_failure_when_object_is_null",length);
                status = SUCCESS;


        }


       
        fclose(fp);

        return status;






}

Status test_arosa_get_size_on_my_string_insertion_with_valid_object_returns_0(char* buffer, int length) {

        MY_STRING hString = my_string_init_c_string("HELLO!!");
        Status status;


        FILE* fp;

        fp = fopen("dictionary.txt", "r");
	my_string_insertion(hString,fp);

        if((my_string_get_size(hString) != 0)){
		printf("Expected 0 but got %d", my_string_get_size(hString));
                 strncpy(buffer, "test_arosa_get_size_on_my_string_insertion_with_valid_object_returns_0" "my_sting_get_size__does_return_0",length);
                 status = FAILURE;


        }

        else {


                strncpy(buffer, "test_arosa_get_size_on_my_string_insertion_with_valid_object_returns_0",length);
                status = SUCCESS;


        }


        my_string_destroy((ITEM*)&hString);
        fclose(fp);

        return status;





}



Status test_arosa_get_size_on_my_string_push_back_returns_size_plus_1(char* buffer, int length){
	MY_STRING hString = my_string_init_default();
	Status status;

	int org_size = my_string_get_size(hString);

	my_string_push_back(hString,'c');
	

	if((my_string_get_size(hString) != org_size + 1)){
		printf("Expect %d but got %d\n", org_size + 1, my_string_get_size(hString));
		strncpy(buffer, "test_arosa_get_size_on_my_string_push_back_returns_size_plus_1\n" " get_size_does_not_return_size_plus_one", length);
		status = FAILURE;



	}

	else {
		 strncpy(buffer, "test_arosa_get_size_on_my_string_push_back_returns_size_plus_1\n",length);
		  status = SUCCESS;

	}
	
	my_string_destroy((ITEM*)&hString);
	return status;
}

Status test_arosa_my_string_insertion_returns_0_when_size_equal_0(char* buffer, int length) {
	MY_STRING hString = my_string_init_default();
        Status status;


	FILE* fp;

	fp = fopen("dictionary.txt", "r");


	if((my_string_insertion(hString,fp) != FAILURE)){ 
		 strncpy(buffer, "test_arosa_my_string_insertion_returns_0_when_size_equal_0" "my_sting_insertion_does_return_NULL",length);
		 status = FAILURE;


	}

	else {


		strncpy(buffer, "test_arosa_my_string_insertion_returns_0_when_size_equal_0",length);
		status = SUCCESS;


	}
	

	my_string_destroy((ITEM*)&hString);
	fclose(fp);

	return status;



}




Status test_arosa_get_capacity_on_my_string_push_back_when_size_greater_than_or_equal_to_capacity_returns_capacity_times_2(char* buffer, int length) {
	 MY_STRING hString = my_string_init_c_string("HELLO!");
	 Status status;
 	 int org_cap = my_string_get_capacity(hString);	
	 my_string_push_back(hString,'c');
	 my_string_push_back(hString,'c');

       
	

	 if(my_string_get_capacity(hString) != org_cap * 2){
		 printf("Expect %d but got %d\n", org_cap * 2 , my_string_get_capacity(hString));
		 strncpy(buffer, "test_arosa_get_capacity_on_my_string_push_back_when_size_greater_than_or_equal_to_capacity_returns_capacity_times_2\n" "get_capacity_return_wrong_value",length);
		 status = FAILURE;
	 }

	 else {
		 strncpy(buffer, "test_arosa_get_capacity_on_my_string_push_back_when_size_greater_than_or_equal_to_capacity_returns_capacity_times_2", length);
		 status = SUCCESS;
	 }

	 my_string_destroy((ITEM*)&hString);


	 return status;



}


Status test_arosa_my_string_push_back_returns_0_when_object_is_NULL(char* buffer, int length) {
	MY_STRING hString = NULL;
	 Status status;


	if(my_string_push_back(hString, 'c') != 0) {
		strncpy(buffer,"test_arosa_my_string_push_back_returns_0_when_object_is_NULL\n""my_string_push_back_returns_non_0 ",length);

		status = FAILURE;


	}


	else {

		 strncpy(buffer,"test_arosa_my_string_push_back_returns_0_when_object_is_NULL",length);
		status = SUCCESS;
	}


	return status;




}


Status test_arosa_my_string_at_on_init_default_returns_NULL(char* buffer, int length) {

 MY_STRING hString = my_string_init_default();
         Status status;


        if(my_string_at(hString,0) != NULL) {
                strncpy(buffer,"test_arosa_my_string_at_on_init_default_returns_NULL\n""my_string_at_returns_non_NULL",length);

                status = FAILURE;


        }


        else {

                 strncpy(buffer,"test_arosa_my_string_at_on_init_default_returns_NULL",length);
                status = SUCCESS;
        }

	my_string_destroy((ITEM*)&hString);
        return status;




}


Status test_arosa_get_size_on_my_string_pop_back_returns_size_minus_one(char* buffer, int length) {

 MY_STRING hString = my_string_init_c_string("Hello");
         Status status;
	 int org_size = my_string_get_size(hString);

	 my_string_pop_back(hString);

        if(my_string_get_size(hString) != org_size - 1 ) {
		printf("Expected size %d but got %d\n", org_size - 1, my_string_get_size(hString));
                strncpy(buffer,"test_arosa_get_size_on_my_string_pop_back_returns_size_minus_one\n""my_string_get_size_does_not_return_size_minus_one",length);

                status = FAILURE;


        }


        else {

                 strncpy(buffer,"test_arosa_get_size_on_my_string_pop_back_returns_size_minus_one",length);
                status = SUCCESS;
        }

        my_string_destroy((ITEM*)&hString);
        return status;




}

Status test_arosa_my_string_at_on_my_string_c_str_when_idex_is_size_returns_NULL(char* buffer, int length) {
 MY_STRING hString = my_string_init_c_string("Hello");
	
         Status status;

	 my_string_c_str(hString);


       

        if(my_string_at(hString, my_string_get_size(hString)) != NULL ) {
                printf("Expected NULL  but got %s\n", my_string_at(hString, my_string_get_size(hString)));
                strncpy(buffer,"test_arosa_my_string_at_on_my_string_c_str_when_idex_is_size_returns_NULL\n""my_string_at__does_not_return_NULL\n",length);

                status = FAILURE;


        }


        else {

                 strncpy(buffer,"test_arosa_my_string_at_on_my_string_c_str_when_idex_is_size_returns_NULL\n",length);
                status = SUCCESS;
        }

        my_string_destroy((ITEM*)&hString);
        return status;





}


Status test_arosa_my_string_concat_returns_FAILURE_when_Append_String_is_NULL(char* buffer, int length) {

 MY_STRING RString = my_string_init_c_string("Hello");
 MY_STRING AString = NULL;
         Status status;




        if(my_string_concat(RString,AString) != FAILURE ) {
              
                strncpy(buffer,"test_arosa_my_string_concat_returns_FAILURE_when_Append_String_is_NULL\n""my_string_concat__does_not_return_FAILURE\n",length);

                status = FAILURE;


        }


        else {

                 strncpy(buffer,"test_arosa_my_string_concat_returns_FAILURE_when_Append_String_is_NULL\n",length);
                status = SUCCESS;
        }

        my_string_destroy((ITEM*)&RString);
        return status;

}



Status test_arosa_my_string_empty_on_init_default_returns_TRUE(char* buffer, int length){


 MY_STRING hString = my_string_init_default();
         Status status;


        if(my_string_empty(hString) != TRUE ) {
	
                strncpy(buffer,"test_arosa_my_string_empty_on_init_default_returns_TRUE\n""my_string_empty_does_not_return_TRUE\n",length);

                status = FAILURE;


        }


        else {

                 strncpy(buffer,"test_arosa_my_string_empty_on_init_default_returns_TRUE(\n",length);
                status = SUCCESS;
        }

        my_string_destroy((ITEM*)&hString);
        return status;


}

Status test_arosa_my_string_empty_on_init_c_string_returns_FALSE(char* buffer, int length){

 MY_STRING hString = my_string_init_c_string("Hello");
         Status status;


        if(my_string_empty(hString) != FALSE ) {

                strncpy(buffer,"test_arosa_my_string_empty_on_init_c_string_returns_FALSE\n""my_string_empty_does_not_return_FALSE\n",length);

                status = FAILURE;


        }


        else {

                 strncpy(buffer,"test_arosa_my_string_empty_on_init_c_string_returns_FALSE(\n",length);
                status = SUCCESS;
        }

        my_string_destroy((ITEM*)&hString);
        return status;



}


Status test_arosa_my_string_concat_worked_succefully_with_two_valid_strings(char* buffer, int length){




  MY_STRING RString = my_string_init_c_string("Hello");
  MY_STRING AString = my_string_init_c_string("!!");
	char result[] = {"Hello!!"};

         Status status;
	 
	my_string_concat(RString,AString); 


	for(int i = 0; i < my_string_get_size(RString); i++){
		if(result[i] != *(my_string_at(RString, i))) {
			status = FAILURE;
			break;
		}

		status = TRUE;
	}
        if(status == FAILURE ) {

                strncpy(buffer,"test_arosa_my_string_concat_worked_succefully_with_two_valid_strings\n""my_string_concat_did_not_concat_successfully\n",length);

           


        }


        else {

                 strncpy(buffer,"test_arosa_my_string_concat_worked_succefully_with_two_valid_strings\n",length);
              
        }

        my_string_destroy((ITEM*)&RString);
	my_string_destroy((ITEM*)&AString);

        return status;



}


Status test_arosa_my_string_pop_back_on_init_default_returns_0(char* buffer, int length) {
	 MY_STRING hString = my_string_init_default();

	Status status;

      

        if(my_string_pop_back(hString) != 0) {
		printf("Expected 0 but returned %d", my_string_pop_back(hString));
		status = FAILURE;
                strncpy(buffer,"test_arosa_my_string_pop_back_on_init_default_returns_0\n""my_string_pop_back_did_not_return_0\n",length);




        }


        else {
		 status = TRUE;
                 strncpy(buffer,"test_arosa_my_string_pop_back_on_init_default_returns_0\n",length);

        }

        my_string_destroy((ITEM*)&hString);

        return status;



}


Status test_arosa_my_string_at_out_of_bounds_on_init_default_c_string_returns_NULL(char* buffer, int length) {
         MY_STRING hString = my_string_init_c_string("HELLO!");

        Status status;



        if(my_string_at(hString,10) != NULL) {
                printf("Expected NULL but returned %s", my_string_at(hString, 10));
                status = FAILURE;
                strncpy(buffer,"test_arosa_my_string_at_out_of_bounds_on_init_default_c_string_returns_NULL\n""my_string_at_did_not_return_NULL\n",length);




        }


        else {
                 status = TRUE;
                 strncpy(buffer,"test_arosa_my_string_at_out_of_bounds_on_init_default_c_string_returns_NULL\n",length);

        }

        my_string_destroy((ITEM*)&hString);

        return status;


}


Status test_arosa_get_capacity_on_init_default_returns_7(char* buffer, int length) {
         MY_STRING hString = my_string_init_default();

        Status status;



        if(my_string_get_capacity(hString) != 7) {
                printf("Expected 1 but returned %d", my_string_get_capacity(hString));
                status = FAILURE;
                strncpy(buffer,"test_arosa_get_capacity_on_init_default_returns_1\n""my_string_get_capacity_did_not_return_one\n",length);

        }


        else {
                 status = TRUE;
                 strncpy(buffer,"test_arosa_get_capacity_on_init_default_returns_1\n",length);

        }

        my_string_destroy((ITEM*)&hString);

        return status;

}


Status test_arosa_get_size_on_my_string_init_c_string_returns_c_string_length(char* buffer, int length){

//	char c_string[] = {"HELLO"};

//	int string_length = strlen(c_string);
    MY_STRING hString = my_string_init_c_string("HELLO");

        Status status;



        if(my_string_get_size(hString) != 5) {
                printf("Expected 5 but returned %d", my_string_get_size(hString));
                status = FAILURE;
                strncpy(buffer,"test_arosa_get_size_on_my_string_init_c_string_returns_c_string_length\n""my_string_get_size_did_not_return_5\n",length);




        }


        else {
                 status = TRUE;
                 strncpy(buffer,"test_arosa_get_size_on_my_string_init_c_string_returns_c_string_length\n",length);

        }

        my_string_destroy((ITEM*)&hString);

        return status;






}



Status test_arosa_get_capacitiy_on_my_string_init_c_string_returns_c_string_length_plus_one(char* buffer, int length){

    MY_STRING hString = my_string_init_c_string("HELLO");

        Status status;



        if(my_string_get_capacity(hString) != 6) {
                printf("Expected 6 but returned %d", my_string_get_capacity(hString));
                status = FAILURE;
                strncpy(buffer,"test_arosa_get_capacity_on_my_string_init_c_string_returns_c_string_length_plus_one\n""my_string_get_capacity_does_not_return_5\n",length);




        }


        else {
                 status = TRUE;
                 strncpy(buffer,"test_arosa_get_capacity_on_my_string_init_c_string_returns_c_string_length_plus_one\n",length);

        }

        my_string_destroy((ITEM*)&hString);

        return status;






}

// Here uis the new
//
//
//
//
//
// 
//
Status test_nwright_get_capacity_on_init_default_returns_7(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();

    if(my_string_get_capacity(hString) != 7){
        status = FAILURE;
        printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
        strncpy(buffer, "test_nwright_get_size_on_init_default_returns_7\n \tDid not receive 7 from get_capacity after init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_get_size_on_init_default_returns_7\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_compare_on_init_default_returns_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();

    if(my_string_compare(hString, hString) != 0){
        status = FAILURE;
        printf("Expected a result or 0 but got %d\n", my_string_compare(hString, hString));
        strncpy(buffer, "test_nwright_compare_on_init_default_returns_0\n \tDid not receive 0 from compare after init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_compare_on_init_default_returns_0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_my_string_init_c_string_with_string_Hello(char* buffer, int length){
    MY_STRING hString = NULL;

    hString = my_string_init_c_string("Hello");

    if(hString == NULL){
        strncpy(buffer, "test_nwright_my_string_init_c_string_with_string_Hello\n \ttest_nwright_my_string_init_c_string_with_string_Hello returns NULL", length);
        return FAILURE;
    }
    else{
        my_string_destroy(&hString);
        strncpy(buffer, "\test_nwright_my_string_init_c_string_with_string_Hello\n", length);
        return SUCCESS;
    }
}
Status test_nwright_size_with_string_Hello_returns_5(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("Hello");

    if(my_string_get_size(hString) != 5){
        status = FAILURE;
        printf("Expected a size of 5 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_size_with_string_Hello_returns_5\n \tDid not receive 5 from get_size with string Hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_size_with_string_Hello_returns_5\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_capacity_with_string_Hello_returns_6(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("Hello");

    if(my_string_get_capacity(hString) != 6){
        status = FAILURE;
        printf("Expected a capacity of 6 but got %d\n", my_string_get_capacity(hString));
        strncpy(buffer, "test_nwright_capacity_with_string_Hello_returns_6\n \tDid not receive 6 from get_capacity with string Hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_capacity_with_string_Hello_returns_6\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_compare_with_string_Hello_returns_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("Hello");
	printf("Expected a result of 0 but got %d\n", my_string_compare(hString, hString));
	
    if(my_string_compare(hString, hString) != 0){
        status = FAILURE;
        printf("Expected a result of 0 but got %d\n", my_string_compare(hString, hString));
        strncpy(buffer, "test_nwright_compare_with_string_Hello_returns_0\n \tDid not receive 0 from compare with string Hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_compare_with_string_Hello_returns_0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_extraction_and_insertion_using_simple(char* buffer, int length){
    MY_STRING hMy_string = NULL;
    FILE* fp;

    hMy_string = my_string_init_default();
    fp = fopen("simple.txt", "r");

    while(my_string_extraction(hMy_string, fp)){
        if(my_string_insertion(hMy_string, stdout) == FAILURE){
            return FAILURE;
        }
        printf(" ");
    }
    printf("\n");
    my_string_destroy(&hMy_string);
    fclose(fp);

    return SUCCESS;
}
Status test_nwright_push_back_with_init_default_returns_SUCCESS(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();

    if(my_string_push_back(hString, 'a') == FAILURE){
        status = FAILURE;
        printf("Expected SUCCESS but got FAILURE");
        strncpy(buffer, "test_nwright_push_back_with_init_default_returns_SUCCESS\n \tDid not receive SUCCESS with init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_push_back_with_init_default_returns_SUCCESS\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_push_back_with_init_default_updates_size(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    my_string_push_back(hString, 'a');

    if(my_string_get_size(hString) != 1){
        status = FAILURE;
        printf("Expected a result of 1 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_push_back_with_init_default_updates_size\n \tDid not receive 1 from size with letter a and init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_push_back_with_init_default_updates_size\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_pop_back_with_init_default_and_push_back_char_a_returns_success(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    my_string_push_back(hString, 'a');

    if(my_string_pop_back(hString) != 1){
        status = FAILURE;
        printf("Expected a result of SUCCESS but got FAILURE\n");
        strncpy(buffer, "test_nwright_pop_back_with_init_default_and_push_back_char_a_returns_success\n \tDid not receive SUCCESS from pop back with push back a and init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_pop_back_with_init_default_and_push_back_char_a_returns_success\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_pop_back_with_init_default_and_push_back_char_a_updates_size(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    my_string_push_back(hString, 'a');
    my_string_pop_back(hString);

    if(my_string_get_size(hString) != 0){
        status = FAILURE;
        printf("Expected a result of 0 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_pop_back_with_init_default_and_push_back_char_a_updates_size\n \tDid not receive 0 from get size after pop back with push back a and init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_pop_back_with_init_default_and_push_back_char_a_updates_size\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_success(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    my_string_push_back(hString, 'a');

    if(my_string_pop_back(hString) != 1){
        status = FAILURE;
        printf("Expected a result of SUCCESS but got FAILURE\n");
        strncpy(buffer, "test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_success\n \tDid not receive SUCCESS from pop back with push back a and string of hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_success\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_5(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    my_string_push_back(hString, 'a');
    my_string_pop_back(hString);

    if(my_string_get_size(hString) != 5){
        status = FAILURE;
        printf("Expected a result of 5 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_5\n \tDid not receive 5 from pop back with push back a and string of hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_5\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_my_string_at_0_with_init_default_returns_NULL(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    char* c = my_string_at(hString, 0);


    if(c != NULL){
        status = FAILURE;
        printf("Expected a result of Null\n");
        strncpy(buffer, "test_nwright_my_string_at_0_with_init_default_returns_NULL\n \tDid not receive Null from my string at with init default and 0\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_0_with_init_default_returns_NULL\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_my_string_at_negative_1_with_init_default_returns_NULL(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    char* c = my_string_at(hString, -1);


    if(c != NULL){
        status = FAILURE;
        printf("Expected a result of Null\n");
        strncpy(buffer, "test_nwright_my_string_at_negative_1_with_init_default_returns_NULL\n \tDid not receive Null from my string at with init default and -1\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_negative_1_with_init_default_returns_NULL\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_my_string_at_10_with_init_default_returns_NULL(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    char* c = my_string_at(hString, -1);


    if(c != NULL){
        status = FAILURE;
        printf("Expected a result of Null\n");
        strncpy(buffer, "test_nwright_my_string_at_10_with_init_default_returns_NULL\n \tDid not receive Null from my string at with init default and 10\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_10_with_init_default_returns_NULL\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_my_string_at_0_with_string_hello(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    char* c = my_string_at(hString, 0);



    if(*c != 'h'){
        status = FAILURE;
        printf("Expected a result of h\n");
        strncpy(buffer, "test_nwright_my_string_at_0_with_string_hello\n \tDid not receive h from my string at with string hello and 0\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_0_with_string_hello\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_my_string_at_negative_1_with_string_hello(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    char* c = my_string_at(hString, -1);


    if(c != NULL){
        status = FAILURE;
        printf("Expected a result of Null\n");
        strncpy(buffer, "test_nwright_my_string_at_negative_1_with_string_hello\n \tDid not receive Null from my string at with string hello and -1\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_negative_1_with_string_hello\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_my_string_at_10_with_string_hello(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    char* c = my_string_at(hString, 10);


    if(c != NULL){
        status = FAILURE;
        printf("Expected a result of Null\n");
        strncpy(buffer, "test_nwright_my_string_at_10_with_string_hello\n \tDid not receive Null from my_string_at with string hello and 10\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_10_with_string_hello\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_c_str_with_init_defaults_returns_string(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    char* c = my_string_c_str(hString);

    if(c == NULL){
        status = FAILURE;
        printf("Expected a string but got NULL\n");
        strncpy(buffer, "test_nwright_c_str_with_init_defaults_returns_string\n \tDid not receive a string from my_string_c_str with init defaults\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_c_str_with_init_defaults_returns_string\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_c_str_with_init_defaults_has_size_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    char* c = my_string_c_str(hString);

    if(my_string_get_size(hString) != 0){
        status = FAILURE;
        printf("Expected size to be zero but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_c_str_with_init_defaults_has_size_0\n \tDid not receive a size of 0 from my_string_get_size after my_string_c_str with init defaults\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_c_str_with_init_defaults_has_size_0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_c_str_with_string_hello_returns_string(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    char* c = my_string_c_str(hString);

    if(c == NULL){
        status = FAILURE;
        printf("Expected a string but got NULL\n");
        strncpy(buffer, "test_nwright_c_str_with_string_hello_returns_string\n \tDid not receive a string from my_string_c_str with string hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_c_str_with_string_hello_returns_string\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_c_str_with_string_hello_has_size_5(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    char* c = my_string_c_str(hString);
    c = NULL;

    if(my_string_get_size(hString) != 5){
        status = FAILURE;
        printf("Expected size to be 5 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_c_str_with_string_hello_has_size_5\n \tDid not receive a size of 5 from my_string_get_size after my_string_c_str with string hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_c_str_with_string_hello_has_size_5\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
