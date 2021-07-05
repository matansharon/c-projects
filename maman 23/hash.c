 #include "general.h"

FILE *fp;/*fp is pointer to rea from the input files*/
struct node hashtable[TABLE_SIZE];/*the hashtable to store our data*/
char temp_array[MAX_LINE];/*the array to store our line by line text files*/
struct node *pt,*p1,*p2;/*pointers to build the linked lists*/
struct node *pr;/*pointer to print the  list*/
char num[5];/*a little array to store the numbers.
i'v let my self asume there will not be a numbers bigger the 99999*/

void clear_nums();
void get_line(char str[],char str2[]);
void print_table();


int main(int argc, char  *argv[])
{

  int i;/*i is the var inside the line*/
  int pos;/*pos is the loction to store the next digit*/
  if(argc==1)printf("you didnt put any arguments at the command line please try again\n" );
  for(i=1;i<argc;i++)/*loop that read the text lines*/
  {
    fp=fopen(argv[i],"r");
    if(fp==NULL){printf("the is a problem with %s please check it again\n",argv[i] );exit(0);}
    while(fgets(temp_array,MAX_LINE,(FILE*)fp)!=NULL)/*the loop that goes over the line*/
    {

      get_line(temp_array,argv[i]);/*function get line is explained later.*/
      for(pos=0;pos<MAX_LINE;pos++)temp_array[pos]='\0';/*loop to clear the array that store the line*/
    }
    free(pt);
    fclose(fp);
  }
print_table();

  return 0;
}
/*
  clear nums is set the number array to 0;
*/
 void clear_nums()
 {
   int i=0;
   for(;i<6;i++)num[i]='\0';

 }
 /*
    get line function is the big and main funtion in my maman;
    the get line functio get 2 arguments.
    @str is the line from the extrnal file.
    @str2 is the name of the file from argv.
    the get line function scan the line and add to the hashtable the number that it read

 */
 void get_line(char str[],char str2[])
 {
   int i;
   int pos=0;
   int temp;/*is the var to hold each number*/
   for(i=0;i<MAX_LINE;i++)/*this for loop goes over the line*/
   {
      if(isdigit(str[i]))
      {
        num[pos]=str[i];
        pos++;
      }
      else if(isspace(str[i]))
      {
        temp=atoi(num);
        clear_nums();
        pos=0;
        pt=(struct node*)malloc(sizeof(struct node));/*pt is the new node to add*/
        strcpy(pt->name,str2);
        p1=&hashtable[temp];/*p1 is the pointer to look for the correct node*/
        p2=p1;/*p2 is the pointer to save the previos node*/
        if(strcmp(hashtable[temp].name,"")==0)
        {
          strcpy(hashtable[temp].name,str2);
          hashtable[temp].cnt++;
        }
        else
        {
          while(p1)/*while loop to go over the linked list in the hashtable*/
          {
            if(strcmp(p1->name,pt->name)==0){p1->cnt++;break;}
            p2=p1;/*p2 is the predecceor*/
            p1=p1->next;

          }/*end of while*/
          if(!p1){p2->next=pt;pt->cnt++;}
        }/*end of else*/


        }
        }
      }

void print_table()
{
  int i;
  for(i=0;i<TABLE_SIZE;i++)
  {
    p1=&hashtable[i];
    while(p1)
    {

      if(strcmp(p1->name,"")!=0)printf("number %d is in %s %d times\n",i,p1->name,p1->cnt );
      p1=p1->next;



    }
  }
}
