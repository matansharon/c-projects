#include "data.h"
/*---------------------------------------------------------------------
  this is the function file, where all the functions are wrriten

----------------------------------------------------------------------*/


/*----------------------------------------------------------------------
print array is just a regular function to print the global array
that contian all 30 names
i created this function mostly to help me during the testing
----------------------------------------------------------------------*/
void print_array(char NAMES[NUM_OF_STRINGS][SIZE_OF_STRING])
{
  int i=0;

  while(i<30)
  {
    if(i<0&&(i%10)==0)printf("\n" );
    printf("%s",NAMES[i] );

    i++;
  }


}
/*----------------------------------------------------------------------
  fill_array function take the text file array example.txt and uses it
  as an input to fil the global array NAMES with 30 names.
----------------------------------------------------------------------*/
void fill_array(char NAMES[NUM_OF_STRINGS][SIZE_OF_STRING])
{
  int i=0;

  FILE *fp;/*a pointer of type file*/
  char str[21];/*a temperory array to save every name for each iteration*/
  char* filename = "array example.txt";
  fp = fopen(filename, "r");
  if (fp == NULL)
    {
        printf("Could not open file %s",filename);

    }
    while (fgets(str, 21, fp) != NULL)
    {

      strcpy(NAMES[i],str);
      i++;

    }
      fclose(fp);
}
/*---------------------------------------------------------------------------
trans_tolower function is a boolean function that get 2 strings as an input
and trasform them into all lower case letters
that it compere the strings useing strcmp from the string.h libary
and return 1 if the 2 strings are identical and 0 if they are diffrent
---------------------------------------------------------------------------*/

int trans_tolower(char str1[],char str2[])
{
  char str3[SIZE_OF_STRING];
  char str4[SIZE_OF_STRING];
  int i=0;
  strcpy(str3,str1);
  strcpy(str4,str2);
  while(i<21)
  {
    if(isupper(str3[i]))str3[i]=tolower(str3[i]);
    if(isupper(str4[i]))str4[i]=tolower(str4[i]);
    i++;
  }
  if(!(strcmp(str3,str4)))return 1;
  else return 0;
}
/*---------------------------------------------------------------------------
  -function get_name is the main function for this maman.
  -it's generate 10 random name using srand() and save them in temp_str array.
  -function get_name also checking if there are 2 identical names from the 10
  random names and update an boolean "bol" to be 0 or 1 in any case.
  -this function also print the chsen names to the stdout.
---------------------------------------------------------------------------*/

void get_name(char temp_str[10][SIZE_OF_STRING])
{

  int bol=0;/*the boolean integer will get 0 or 1*/
  int i=0;
  int j=0;
  int q=0;
  int p;
  int a;/*use to save the random number*/
  srand(time(0));

  while(i<10)
  {
    a=rand()%30;
    strcpy(temp_str[i],NAMES[a]);
    i++;
  }
  while (j<10) {
    printf("the %d name is: %s\n",j,temp_str[j] );
    j++;
  }
  while (q<10)
  {
    p=q+1;
    while(p<10)
    {
      if(trans_tolower(temp_str[q],temp_str[p]))
      {
        printf("there are 2 identical names and they are :\n%sand %s",temp_str[p],temp_str[q]);
        bol=1;
        exit(0);
      }
      p++;
    }
    q++;
  }
  if(bol==0)printf("the random array is o.k and there are no 2 identecal names\n" );
}
/*---------------------------------------------------------------------------*/
