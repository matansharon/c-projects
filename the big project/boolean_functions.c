#include "data.h"
/*
  All the function in this files are returnig some value.
  rather if is 1 or 0 for the boolean function or some number to represnt somthing.
  I'v grouped them toghther in this file for my convinence.
  I thoght this is a correct sepertion.

*/
/*this enum is use only for the function "what_is_it"*/
typedef enum{op,reg,pointer,Label,Extern,entry,label_adress,extern_adress,immediate,string,data}type;
/*
  what_is_it function is 1 of the top 3 important function in my project.
  Baiscly this function uses most of the other function in thist file,
  and determain what is it the nature of a specific node from the big linked list.

*/
int what_is_it(char str[])
{
  int num=0;
  if(is_op(str))num=1;/*1*/
  else if(is_reg(str))num=2;/*2*/
  else if(is_pointer(str))num=3;/*3*/
  else if(is_label(str))num=4;/*4*/
  else if(is_extern(str))num=5;/*5*/
  else if(is_entry(str))num=6;/*6*/
  else if(is_adress(str))num=7;/*7*/
  else if(is_extern_label(str))num=8;/*8*/
  else if(is_immediate(str))num=9;/*9*/
  else if(is_string(str))num=10;/*10*/
  else if(is_data(str))num=11;/*11*/
  return num;
}


/*
  is_op determain if a specific node is op or not.
  is_op have an instance variabel of op_array that contain all of the known op names.
  is_op compare the specific node by the name with all the other op names.
*/

int is_op(char str[])
{
  char op_arr[16][4]={"mov","cmp","add","sub","lea","clr","not","inc","dec","jmp","bne","red","prn","jsr","rts","stop"};
  int length=16;
  int i;
  char temp[5];
  if(!strcmp(str,"stop"))return 1;
  for(i=0;i<length;i++)
  {
    strcpy(temp,op_arr[i]);
    if(!strcmp(temp,str))return 1;

  }
  return 0;
}
/*
  is_op_from_group1 check if a specific op if from this group of op:
  mov,cmp,add,sub,lea beacuse all of these op gets 2 operands.
*/
int is_op_from_group1(char str[])
{
  if(!strcmp("mov",str)||!strcmp("cmp",str)||!strcmp("add",str)||!strcmp("sub",str)||!strcmp("lea",str))return 1;
  else return 0;
}
/*
  is_op_from_group2 check if a specific op if from this group of op:
  clr,not,inc,dec,jmp,bne,red,prn,jsr beacuse all of these op gets 1 operand.
*/
int is_op_from_group2(char str[])
{
  if(!strcmp("clr",str)||!strcmp("not",str)||!strcmp("inc",str)||!strcmp("dec",str)||!strcmp("jmp",str)||!strcmp("bne",str)||!strcmp("red",str)||!strcmp("prn",str)||!strcmp("jsr",str))return 1;
  else return 0;
}
/*
  is_op_from_group3 check if a specific op if from this group of op:
  rts,stop beacuse all of these op dosen't get operands at all.
*/
int is_op_from_group3(char str[])
{
  if(!strcmp("rts",str)||!strcmp("stop",str))return 1;
  else return 0;
}
/*
  is_reg function is getting a node as an input and checks if is a register
  return true if it is and false othewise.
*/
int is_reg(char str[])
{
  if(str[0]=='r'&&str[1]<='7'&&str[1]>='0')return 1;
  else return 0;
}
/*
  is_pointer function check if a given node is a pointer register
*/
int is_pointer(char str[])
{
  if(str[0]=='*'&&str[1]=='r'&&str[2]<='7'&&str[2]>=0)return 1;
  else return 0;
}
/*
  is_label check if a given node is label like "MAIN:"
*/
int is_label(char str[])
{
  int i;
  for(i=0;i<strlen(str);i++)
  {
    if(str[i]==':')return 1;
  }
  return 0;
}
/*
  is_extern check if a given node is label like ".extern"
*/
int is_extern(char str[])
{
  if(!strcmp(str,".extern"))return 1;
  else return 0;
}
/*
  is_extern check if a given node is label like ".entry"
*/
int is_entry(char str[])
{
  if(!strcmp(str,".entry"))return 1;
  else return 0;
}
/*
  is_entry_label check if a given node is an entry label
  the function get a given node by his str value.
  and search liniar at the entry label linked list.
  the function return true once the strcmp return 1.
  if the while loop end without stopping this meanning the node is not an entry label.

*/
int is_entry_label(char str[])
{
  entry_label_ptr temp=entry_label_head;/*the head of the entry list */
  while(temp)
  {
    if(!strcmp(temp->str,str))return 1;
    temp=temp->next;
  }
  return 0;
}
/*
  is_immediate check if a given node is an immediate number like "#3" or "#-6"
*/
int is_immediate(char str[])
{
  if(str[0]=='#')/*an immediate number must start with '#' signed. if not the function will return false*/
  {
    if(str[1]=='-'||str[1]=='+')/*the function can get a number start with + sign*/
    {
      int i;
      for(i=2;str[i]!='\0';i++)
      {
        if(!isdigit(str[i]))return 0;
      }
      if(i>=2)return 1;

    }
    else/*case 2 if the number not strting with '-' of '+' signes*/
    {
      int j;
      for(j=1;str[j]!='\0';j++)
      {
        if(!isdigit(str[j]))return 0;
      }
      if(j>=1)return 1;
    }
  }
  return 0;
}
/*
  is_string check for a ".string" label
*/
int is_string(char str[])
{
  if(!strcmp(str,".string"))return 1;
  else return 0;
}
/*
  is_string check for a ".data" label
*/
int is_data(char str[])
{
  if(!strcmp(str,".data"))return 1;
  else return 0;
}
/*
  is_adress check if a given node is a label without the ':'.
  the function is in use at the what_is_it function.
  the function goes all over the label list. with a while loop.
*/
int is_adress(char str[])
{
  label_ptr temp=label_head;/*the head of the linked list*/
  while(temp)
  {
    if(!strcmp(temp->str,str))return 1;

    temp=temp->next;
  }
 return 0;
}
/*
  get_adress return the label counter of a specific node.
  for example:
  in line 103 there is an adress LIST. so the get_adress return 130 as it is where the LIST label is in the program.

*/
int get_adress(char str[])
{
  label_ptr temp=label_head;/*a pointer to go over the label list.*/
  int num=0;
  while(temp)
  {
    if(!strcmp(temp->str,str))num=temp->label_counter;
    temp=temp->next;
  }
  return num;
}
/*
  get_immediate convert an immediate number like "#-9" to -9 useing atoi function
*/
int get_immediate(char str[])
{
  int num=0,i;
  char temp_num[reg_name];


    for(i=1;i<reg_name;i++)
    {
      temp_num[i-1]=str[i];
    }
    num=atoi(temp_num);


  return num;
}
/*
  is_extern_label check if a given node is an extern label.
  meaning the function go over the extern label list with a while loop useing an pointer.
  if strcmp return true the loop stops. else the function return false.
*/
int is_extern_label(char str[])
{
  extern_ptr temp=extern_head;
  while(temp)
  {
    if(!strcmp(temp->str,str))return 1;

    temp=temp->next;
  }
  return 0;
}
/*
  is_number check if a given node is a .data number. meanning is in line like: .data 6,-9
  the function return true if it is a number and false if its not.
  the for loop in the function will stop at the first time if one of the charchters is not a digit.
*/
int is_number(char str[])
{
  int i;
  if(str[0]=='\0')return 0;/*if anumber start with the char '\0' its mean its the 0 number.*/
  if(str[0]=='-'||str[0]=='+')/*anumber can start with both '-' or '+' sign*/
  {
    for(i=1;i<strlen(str);i++)/*case 1 if the number start with '-' or '+' sign*/
    {
      if(!isdigit(str[i]))return 0;
    }
  }
  else/*the else if a number is compuse only from digits.*/
  {
    for(i=0;i<strlen(str);i++)
    {
      if(!isdigit(str[i]))return 0;
    }
  }
  return 1;
}
