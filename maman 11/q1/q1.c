#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
char String_num[SIZE];/*the array to save the input number*/
int Bin_num[SIZE];/*the array to save the binary number*/
int Int_num;/*the integer to save the sting into*/
/*
  print_array is the function to call when we want to print the binary
  represntion of the number
  the function get's an int array and count(cnt) as paremeters
*/
void print_array(int Bin_num[],int cnt)
{

  int j=cnt;/*the counter to start the revers loop*/
  while (j>=0) {
    printf("%d",Bin_num[j] );
    j--;
  }/*end of while loop*/

  printf("\n" );
}/*end of print_array function*/

/*
  trans_dec_to_bin is the function that responsable to copy the binary
  represntion to the Bin_num array.
  the function gets a number(n) that was cast to an int by the function "atoi"

*/

void trans_dec_to_bin(int n)
{
  if (n==0) {/*special case for 0*/
    printf("0\n" );
  }
  else
  {
  int i=0,cnt=0;/*parameter i is the loction in the array and cnt count the end of the array*/
  int a;
    while (n>0)
    {
      a=n%2;/*parameter a is the remiander of the modulu*/
      Bin_num[i]=(char) a;
      n/=2;
      i++;
      cnt++;

    }
    cnt--;
    printf("\n" );

    print_array(Bin_num,cnt);
  }
}
/*
  function main is the function to communicate with the client side
  the input defulte is the kewboard
  the output defulte is the screen
  function main is uses the print_array,trans_dec_to_bin functions to translate
  a number represnted by a string given from the kewboard.
  and prints it to the screen
*/
int main()
{


printf("please enter a number\n" );
scanf("%s",String_num );
printf("the number is: %s\n",String_num);
printf("and in binary represntion :" );
Int_num=atoi(String_num);/*uses the function atoi to cast the number as a String to an int number*/
trans_dec_to_bin(Int_num);
return 0;
}
