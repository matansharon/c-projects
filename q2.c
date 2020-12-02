#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i,cnt=0;/*i is the parameter to run the loop. and cnt is the parameter that count the number of suffix*/
  char str[100];
  char a;
/*
  -print_string is the function to call when we wnat to print a string or the substring.
  -the function parameters is ths array the word is saved in,
  and i that represent the loction in the array to print the string or the substring.
*/
void print_string(char str[],int i)
{
  int j=i;
  while(j<strlen(str))
  {
    printf("%c",str[j]);
    j++;
  }/*end of while*/
}/*end of print_string*/

/*
  -function main is the function to communicate with the client side

*/
 int main()
{
  
  printf("please enter a word: " );
  scanf("%s",str );
  printf("please enter a char: " );
  scanf("%s",&a );
  printf("the string is: %s \n and the char is: %c\n",str,a );

  for(i=0;i<strlen(str);i++)
  {
    if(str[i]==a)
    {
      print_string(str,i);
      printf("\n" );
      cnt++;
    }
  }
  printf("\nand the number of suffix is: %d\n",cnt );
  return 0;
}
