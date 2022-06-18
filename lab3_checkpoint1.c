#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
int main(int argc, char* argv[])
{
/*
 MY_STRING hl_string = my_string_init_c_string("hi");
 
 printf("Size: %d\n",my_string_get_size(hl_string));
 printf("Capacity: %d\n",my_string_get_capacity(hl_string));

 MY_STRING hr_string = my_string_init_c_string("hi");

 printf("Size: %d\n",my_string_get_size(hr_string));
 printf("Capacity: %d\n",my_string_get_capacity(hr_string));

 printf("Compare: %d\n",my_string_compare(hl_string,hr_string));

 my_string_destroy(&hl_string);

 my_string_destroy(&hr_string);
 */




   MY_STRING hMy_string = NULL;
   FILE* fp;

   hMy_string = my_string_init_default();
   fp = fopen("simple.txt", "r");

   while(my_string_extraction(hMy_string, fp))
   {
	 my_string_insertion(hMy_string, stdout);
	 printf("\n");
	 if(fgetc(fp)== ' ')
    {
		 printf("Found a space after the string\n");
	 }
 	}
	

  
   my_string_destroy(&hMy_string);
   fclose(fp);

   return 0;
}

