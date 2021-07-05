#include "data.h"
/*
  This file contain all the function realted to print the data to the external files.
  The other 2 files handel the input and manipulate it.
  Then this file and all of its functions interptate and print the output to the correct external file.
*/

/*
  what_op function getting a node input and return a number represnting an op.
  the function return -1 if the op is not extist
*/
int what_op(char str[])
{
  if(!strcmp(str,"mov"))return 0;
  else if(!strcmp(str,"cmp"))return 1;
  else if(!strcmp(str,"add"))return 2;
  else if(!strcmp(str,"sub"))return 3;
  else if(!strcmp(str,"lea"))return 4;
  else if(!strcmp(str,"clr"))return 5;
  else if(!strcmp(str,"not"))return 6;
  else if(!strcmp(str,"inc"))return 7;
  else if(!strcmp(str,"dec"))return 8;
  else if(!strcmp(str,"jmp"))return 9;
  else if(!strcmp(str,"bne"))return 10;
  else if(!strcmp(str,"red"))return 11;
  else if(!strcmp(str,"prn"))return 12;
  else if(!strcmp(str,"jsr"))return 13;
  else if(!strcmp(str,"rts"))return 14;
  else if(!strcmp(str,"stop"))return 15;
  else return -1;

}
/*
  print_op function get a node as a parameter.
  The function and then create a new struct with 4 fileds and send the struct to another function to print
*/
void print_op(line_ptr line)
{

  op_ptr p=(op_ptr)malloc(sizeof(op_reg));/*the new struct*/
  p->op_code=0;p->s_reg=0;p->d_reg=0;/*first initial*/
  p->op_code=what_op(line->str);/*what_op return a number between 0-15*/
  p->ARE=4;
  /*
  this is_op_from_group1,2,3 function determain if the op gets 2,1,0 oprands and then tsosses accordingly
  8-represnt 1000 method
  4-represnt 0100 method
  2-represnt 0010 method
  1-represnt 0001 method
  */
  if(is_op_from_group1(line->str))
  {
    line_ptr next=line->next;
    line_ptr nextnext=next->next;

    if(is_reg(next->str))p->s_reg=8;
    if(is_reg(nextnext->str))p->d_reg=8;

    if(is_pointer(next->str))p->s_reg=4;
    if(is_pointer(nextnext->str))p->d_reg=4;

    if(is_adress(next->str))p->s_reg=2;
    if(is_adress(nextnext->str))p->d_reg=2;

    if(is_immediate(next->str))p->s_reg=1;
    if(is_immediate(next->str))p->d_reg=1;


  }
  else if(is_op_from_group2(line->str))
  {
    p->s_reg=0;
    line_ptr next=line->next;
    if(is_reg(next->str))p->d_reg=8;
    if(is_pointer(next->str))p->d_reg=4;
    if(is_adress(next->str))p->d_reg=2;
    if(is_immediate(next->str))p->d_reg=1;

  }
  else if(is_op_from_group3(line->str))
  {
    p->s_reg=0;
    p->d_reg=0;
  }
  /*
    from here forward the function save the bits into an array of char represntiong the binary represntion
  */
  int i,j=1;
  char str[15];
    for(i=11;i<15;i++,j*=2)
    {
      if(p->op_code&j)str[i]='1';
      else str[i]='0';
    }
    for(i=7,j=1;i<11;i++,j*=2)
    {
      if(p->s_reg&j)str[i]='1';
      else str[i]='0';
    }
    for(i=3,j=1;i<7;i++,j*=2)
    {
      if(p->d_reg&j)str[i]='1';
      else str[i]='0';
    }
    for(i=0,j=1;i<3;i++,j*=2)
    {
      if(p->ARE&j)str[i]='1';
      else str[i]='0';
    }
    char temp[15];
    for(i=0,j=14;i<15;i++,j--)
    {
      temp[j]=str[i];
    }
    bin_to_oct(temp,line);/*function to print in octal. explain ahead*/

}
/*
  print_s_reg function is printing a register or a pointer.
*/
void print_s_reg(line_ptr line)
{
  dir_ptr p=(dir_ptr)malloc(sizeof(dir_reg));
  p->op_code=0;
  char c;/*the number to be save*/
  int num;
  if(is_pointer(line->str))c=line->str[2];
  else if(is_reg(line->str))c=line->str[1];
  num=c-'0';/*the number as a char represntion -'0' will give the correct number*/
  p->d_reg=0;
  p->s_reg=num;
  p->ARE=4;
  /*
    from here forward the function save the bits into an array of char represntiong the binary represntion
  */
  int i,j=1;
  char str[15];
    for(i=9;i<15;i++)
    {
      str[i]='0';
    }
    for(i=6,j=1;i<9;i++,j*=2)
    {
      if(p->s_reg&j)str[i]='1';
      else str[i]='0';
    }
    for(i=3,j=1;i<6;i++,j*=2)
    {
      if(p->d_reg&j)str[i]='1';
      else str[i]='0';
    }
    for(i=0,j=1;i<3;i++,j*=2)
    {
      if(p->ARE&j)str[i]='1';
      else str[i]='0';
    }
    char temp[15];
    for(i=0,j=14;i<15;i++,j--)
    {
      temp[j]=str[i];
    }
    bin_to_oct(temp,line);/*function to print in octal. explain ahead*/

}
/*
  print_d_reg function is printing a register or a pointer.
*/
void print_d_reg(line_ptr line)
{
  dir_ptr p=(dir_ptr)malloc(sizeof(dir_reg));
  p->op_code=0;
  char c;/*the number to be save*/
  int num;
  if(is_pointer(line->str))c=line->str[2];
  else if(is_reg(line->str))c=line->str[1];
  num=c-'0';/*the number as a char represntion -'0' will give the correct number*/
  p->s_reg=0;
  p->d_reg=num;
  p->ARE=4;

  /*
    from here forward the function save the bits into an array of char represntiong the binary represntion
  */
  int i,j=1;
  char str[15];
    for(i=9;i<15;i++)
    {
      str[i]='0';
    }
    for(i=6,j=1;i<9;i++,j*=2)
    {
      if(p->s_reg&j)str[i]='1';
      else str[i]='0';
    }
    for(i=3,j=1;i<6;i++,j*=2)
    {
      if(p->d_reg&j)str[i]='1';
      else str[i]='0';
    }
    for(i=0,j=1;i<3;i++,j*=2)
    {
      if(p->ARE&j)str[i]='1';
      else str[i]='0';
    }
    char temp[15];
    for(i=0,j=14;i<15;i++,j--)
    {
      temp[j]=str[i];
    }
    bin_to_oct(temp,line);/*function to print in octal. explain ahead*/

}
/*
  print_immi function is printing nodes like #6 or the adress of a label like MAIN or LIST
*/
void print_immi(line_ptr line)
{
  immi_ptr p=(immi_ptr)malloc(sizeof(immi_reg));
  p->ARE=2;
  if(is_immediate(line->str))/*if is  an number like #6*/
  {
    p->num=get_immediate(line->str);
  }
  if(is_adress(line->str))/*if is an adress like MAIN*/
  {
    p->num=get_adress(line->str);
  }
  /*
    from here forward the function save the bits into an array of char represntiong the binary represntion
  */
  int i,j;
  char str[15];
  for(i=3,j=1;i<15;i++,j*=2)
  {
    if(p->num&j)str[i]='1';
    else str[i]='0';
  }
  str[0]='0';
  str[1]='1';
  str[2]='0';
  char temp[15];
  for(i=0,j=14;i<15;i++,j--)
  {
    temp[j]=str[i];
  }
  bin_to_oct(temp,line);/*function to print in octal. explain ahead*/
}
/*
  print_data function is printing the .data numbers aline like: .data 9
  so 9 will be printed
*/
void print_data(line_ptr line)
{
  int num;
  data_ptr p=(data_ptr)malloc(sizeof(data_reg));
  line_ptr temp=line;
  num=atoi(temp->str);/*the number after the atoi convertion*/
  p->num=num;
  /*
    from here forward the function save the bits into an array of char represntiong the binary represntion
  */
  int i,j;
  char str[15];
  for(i=0,j=1;i<15;i++,j*=2)
  {
    if(p->num&j)str[i]='1';
    else str[i]='0';
  }
  char str2[15];
  for(i=0,j=14;i<15;i++,j--)
  {
    str2[j]=str[i];
  }
  bin_to_oct(str2,line);/*function to print in octal. explain ahead*/

}
/*
  print_string function print the numeric represntion of a char.
  so 'a' will be 97, and 'A' is 65
  according to the ascii table
*/
void print_string(line_ptr line)
{
  data_ptr p=(data_ptr)malloc(sizeof(data_reg));
  int num=0;
  char c;
  int i,j;
  char str[15];
  char str2[15];
    c=line->str[0];
    num=c;
    p->num=num;
    /*
      from here forward the function save the bits into an array of char represntiong the binary represntion
    */
    for(i=0,j=1;i<15;i++,j*=2)
    {
      if(p->num&j)str[i]='1';
      else str[i]='0';
    }

    for(i=0,j=14;i<15;i++,j--)
    {
      str2[j]=str[i];
    }



  for(i=0,j=1;i<15;i++,j*=2)
  {
    if(p->num&j)str[i]='1';
    else str[i]='0';
  }

  for(i=0,j=14;i<15;i++,j--)
  {
    str2[j]=str[i];
  }
  bin_to_oct(str2,line);/*function to print in octal. explain ahead*/


}
/*
  print_extern_adress is printing the extern label adress as default it 1
  and in binary is 000...(15 times)1


*/
void print_extern_adress(line_ptr line)
{
  data_ptr p=(data_ptr)malloc(sizeof(data_reg));
  if(is_extern_label(line->str))
  {
    p->num=1;
  }

  char str[15];
  str[14]='1';/*the most right bit*/
  int i;
  for(i=0;i<14;i++)str[i]='0';/*zeroiez all the other bits*/
  bin_to_oct(str,line);/*function to print in octal. explain ahead*/
}
/*
  print_two_regs_toghther function is the special case that there is two regs/pointer after an op from group1
  the function is pulling out from the nodes, the number it need to print.
*/
void print_two_regs_toghther(line_ptr line)
{

  dir_ptr p=(dir_ptr)malloc(sizeof(dir_reg));
  p->op_code=0;
  line_ptr next=line->next;/*the first node after the op*/
  line_ptr nextnext=line->next->next;/*the second node after the op*/
  int num1,num2;/*the two numbers to save*/
  if(is_reg(next->str))num1=next->str[1]-'0';/*if the first one is a reg*/
  else num1=next->str[2]-'0';/*else if it is pointer */
  if(is_reg(nextnext->str))num2=nextnext->str[1]-'0';/*if the second one is a reg*/
  else num2=nextnext->str[2]-'0';/*else if it is pointer */
  p->s_reg=num1;
  p->d_reg=num2;
  p->ARE=4;
  /*
    from here forward the function save the bits into an array of char represntiong the binary represntion
  */
  int i,j=1;
  char str[15];
    for(i=9;i<15;i++)
    {
      str[i]='0';
    }
    for(i=6,j=1;i<9;i++,j*=2)
    {
      if(p->s_reg&j)str[i]='1';
      else str[i]='0';
    }
    for(i=3,j=1;i<6;i++,j*=2)
    {
      if(p->d_reg&j)str[i]='1';
      else str[i]='0';
    }
    for(i=0,j=1;i<3;i++,j*=2)
    {
      if(p->ARE&j)str[i]='1';
      else str[i]='0';
    }
    char temp[15];
    for(i=0,j=14;i<15;i++,j--)
    {
      temp[j]=str[i];
    }
    bin_to_oct(temp,line);/*function to print in octal. explain ahead*/


}
/*
  simple function to print an error to the ob file
*/
void print_error(line_ptr line)
{
  fprintf(ob_ptr, "you have an error at %d\n",line->label_counter );
  fprintf(ob_ptr, "\n" );
}
/*
  print_by_value is very very very important function.
  the function gets 2 parameters.
  the node from the main list. and an int from what_is_it function. that is determine what kind of function to trigger/

*/
void print_by_value(line_ptr line,int value)
{
  line_ptr next;
  switch (value) {
    case 1:
      print_op(line);
      break;
    case 2: case 3:
      next=line->next;
      if(is_op(next->str)||is_string(next->str)||is_data(next->str)||next==NULL)print_d_reg(line);
      else print_s_reg(line);
      break;
    case 7: case 9:
      print_immi(line);
      break;
    case 8:
      print_extern_adress(line);
      break;
    case 10:
      print_string(line);
      break;
    case 11:
      print_data(line);
      break;
    default :
      printf("error at print by value func\n" );
      break;
  }
}
/*
  print_list function is the main main main list the all the other fucntions in this files made for her.
  this function goes over the list.
  and with the help of 2 othe important function
  hat_is_it and print_by_value it is printng the list to the .ob files.
*/
void print_list(line_ptr h)
{
  line_ptr node=h;/*the head of the list*/
  int num=0;/*the returning value of what_is_it*/
  int prev_op=0;/*a flag buffer*/
  while(node)
  {
    /*here i have a veryyyyyyyyyyyyyyyyyyyyyyyyyyyy big problem i didnt manage to solve.
    when im deleting the printf line down here. im getting an error of stack smashing detected
    I couldn't solve it.
    my guess it is somthing with the pipeline.fetch and read.

    */
    printf("an error i couldn't solve at print_func.c line 457\n" );
    num=what_is_it(node->str);

     if(num==1)
    {
      if(is_op_from_group1(node->str))
      {
      int num1=what_is_it(node->next->str);
      int num2=what_is_it(node->next->next->str);
      if((num1==2||num1==3)&&(num2==2||num2==3))
      {
        print_op(node);
        print_two_regs_toghther(node);
        node=node->next->next;
      }
      else print_op(node);
      }
    }
    else/*the else this is a string or data*/
    {
      /*
      if num is 1 this mean this is an op
      */
        if(num==1)prev_op=0;
        else if(num==10)prev_op=10;/*10 is a string label*/
        else if(num==11)prev_op=11;/*11 is a data label*/
        if(num!=0&&num!=11&&num!=10)print_by_value(node,num);/*all the other options*/
        else if(num==0&&prev_op==10)print_string(node);/*if it is a string*/
        else if(num==0&&prev_op==11)print_data(node);/*if it is a data*/


      }
      node=node->next;
      }


}
/*
  bin_to_oct function simply get a string of the node represnting its binary value
  and a node for the label_counter.
  the function save 3 char's and interptate the to an octal represntion.
  then finnaly the function print to the external .ob file
*/
void bin_to_oct(char str[],line_ptr node)
{
  int octal[5];/*the final octal number to print*/
  char temp[3];/*the temp 3 char's array*/
  int i,j;
  for(i=0,j=0;j<5;i+=3,j++)
  {
  temp[0]=str[i];temp[1]=str[i+1];temp[2]=str[i+2];
  if(!strcmp(temp,"000"))octal[j]=0;
  else if(!strcmp(temp,"001"))octal[j]=1;
  else if(!strcmp(temp,"010"))octal[j]=2;
  else if(!strcmp(temp,"011"))octal[j]=3;
  else if(!strcmp(temp,"100"))octal[j]=4;
  else if(!strcmp(temp,"101"))octal[j]=5;
  else if(!strcmp(temp,"110"))octal[j]=6;
  else if(!strcmp(temp,"111"))octal[j]=7;

  }
  /*these lines printing the octal represntion and the line number*/
  fprintf(ob_ptr, "%d ",node->label_counter );
  for(i=0;i<5;i++)/*the loop prints number by number of the octal represntion*/
  {
    fprintf(ob_ptr,"%d",octal[i] );
  }
  fprintf(ob_ptr,"\n" );/*printing a new line*/



}
