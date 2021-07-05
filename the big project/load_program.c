#include "data.h"
/*
  the lod_program.c file is the file that contain all the void function
  that handel,fix and mnipulate the program
*/


/*
  add_to_program_list is the first function use in my program.
  it is simply read the input file word by word and add each word to an intial linked list.

*/
void add_to_program_list(char str[])
{
  line_ptr p=(line_ptr)malloc(sizeof(line));/*a new node*/
  if(!p){printf("error at add_to_program_list func\n" );exit(0);}/*if the malloc fail*/
  else{
    strcpy(p->str,str);
    if(!line_head)line_head=p;/*if the head of the linked list is null its mean that this node is the first*/
    else{
      line_ptr temp=line_head;/*temp pointer to look for the last node*/
      while(temp->next)temp=temp->next;
      temp->next=p;
    }
  }

}
/*
  print_program_list its a simple function the print the program node by node
  mostly use for debug
*/
void print_program_list(line_ptr p)
{
  line_ptr temp=p;
  while(temp)
  {
    printf("%d %s\n",temp->label_counter,temp->str );
    temp=temp->next;
  }
}
/*free_all_lists its a function that free all the node that was malloc*/
void free_all_lists()
{
  free_list(line_head);
  free_entry_list(entry_label_head);
  free_extern_list(extern_head);
  free_label_list(label_head);
}
/*free_list free the main list*/
void free_list(line_ptr p)
{
  line_ptr curr=p;
  line_ptr prev;
  while(curr)
  {
    prev=curr;
    curr=curr->next;
    free(prev);
    prev=curr;
  }
}
/*free the entry list*/
void free_entry_list(entry_label_ptr p)
{
  entry_label_ptr curr=p;
  entry_label_ptr prev;
  while(curr)
  {
    prev=curr;
    curr=curr->next;
    free(prev);
    prev=curr;
  }
}
/*free the extern list*/
void free_extern_list(extern_ptr p)
{
  extern_ptr curr=p;
  extern_ptr prev;
  while(curr)
  {
    prev=curr;
    curr=curr->next;
    free(prev);
    prev=curr;
  }
}
/*free the label list*/
void free_label_list(label_ptr p)
{
  label_ptr curr=p;
  label_ptr prev;
  while(curr)
  {
    prev=curr;
    curr=curr->next;
    free(prev);
    prev=curr;
  }
}
/*
  clear_comma function clear the comma from all the node's in the program.
  with my implention i dont need the comma beaccuse i'm checking if it is a destntion register,
  or source register by a prev pointer.
*/
void clear_comma(char str[])
{
  int i;
  for(i=0;str[i]!='\0';i++)
  {
    if(str[i]==',')str[i]='\0';
  }
}
/*
  build_entry_list go over the main linked list and search for an entry labels.
  then the function build a linked list from thos label. creation a final linkend list of entr label list

*/
void build_entry_list(line_ptr h)
{
  line_ptr line=h;

  while(line)
  {
    if(is_entry(line->str))/*if it is true this mean the the node is like ".entry" and the next one is the label to add*/
    {
      entry_label_ptr label=(entry_label_ptr)malloc(sizeof(entry_label_node));
      line=line->next;/*the node to add to the list*/
      strcpy(label->str,line->str);
      label->label_counter=line->label_counter;
      if(!entry_label_head)entry_label_head=label;/*if the list is empty*/
      else{
        entry_label_ptr temp_label=entry_label_head;/*pointr*/
        while(temp_label->next)/*loop to search the last node*/
        {
          temp_label=temp_label->next;
        }
        temp_label->next=label;
      }
    }

      line=line->next;
  }
}
/*simple function to print the entry list. mostly use for debug*/
void print_entry_list(entry_label_ptr h)
{
  entry_label_ptr temp=h;
  while(temp)
  {
    printf("%s\n",temp->str );
    temp=temp->next;
  }
}
/*
  build_extern_list function go over the main list/program.
  the is search a node like this ".extern".
  and add the next one to the extern list as a label.
*/
void build_extern_list(line_ptr h)
{
  line_ptr line=line_head;/*the head of the main program*/
  while(line)/*loop to search all the extern labels*/
  {
    if(is_extern(line->str))/*if the node is like ".extern" the the next one is the label to add to the list*/
    {
      line=line->next;/*the label to add*/
      extern_ptr p=(extern_ptr)malloc(sizeof(extern_node));/*a new node creat*/
      strcpy(p->str,line->str);
      p->label_counter=line->label_counter;
      if(!extern_head)extern_head=p;/*if the list is empty*/
      else {
      extern_ptr temp_extern=extern_head;/*pointer*/

      while(temp_extern->next)
      {
        temp_extern=temp_extern->next;
      }
      temp_extern->next=p;
      }
    }
    line=line->next;
    }
  }
  /*simple program to print the extern list. mostly use for my debugging*/
  void print_extern_list(extern_ptr h)
  {
    extern_ptr temp_extern=h;
    while(temp_extern)
    {
      printf("%s\n",temp_extern->str );
      temp_extern=temp_extern->next;
    }
  }
/*build_label_list function search in the main list for all the labels form like: MAIN LIST, LOOP,K
  then the function build and label linked list
*/
void build_label_list(line_ptr h)
  {
    line_ptr temp_line=h;/*the head of the main list*/
    while(temp_line)/*loop to search all the labels*/
    {
    if(is_label(temp_line->str))/*if the node is like "MAIN:"*/
    {

      label_ptr p=(label_ptr)malloc(sizeof(label_node));/*a new node to add*/
      strcpy(p->str,temp_line->str);
      p->label_counter=temp_line->label_counter;
      int i;
      for(i=0;p->str[i]!=':';i++);
      p->str[i]='\0';/*clear the last char ':' to save in the label list. example: MAIN: will beacome MAIN*/
      label_ptr temp_label=label_head;
      if(!label_head)label_head=p;
      else{
        while(temp_label->next)temp_label=temp_label->next;
        temp_label->next=p;
      }

    }

    temp_line=temp_line->next;
    }
}
/*simple program to print the label list. mostly use for my debugging*/
void print_label_list(label_ptr h)
{
  label_ptr temp_label=h;
  while(temp_label)
  {
    printf("%d %s\n",temp_label->label_counter,temp_label->str );
    temp_label=temp_label->next;
  }
}
/*
  delete_entry function is delete all the node like ".entry" and the next one.
  witch is ovaisly an entry label.
*/
void delete_entry()
{

  if(is_entry(line_head->str))/*if the head is an entry*/
  {
    line_head=line_head->next->next;/*the head pointer will jump 2 node next*/
  }
  line_ptr curr=line_head->next;
  line_ptr prev=line_head;
  while(curr)
  {
    if(is_entry(curr->str))
    {
      curr=curr->next->next;
      if(!curr)prev->next=NULL;
      else
      {
        prev->next=curr;
        prev=curr;
        curr=curr->next;
      }

    }

  else {prev=curr;curr=curr->next;}
  }
}
/*
  delete_entry function is delete all the node like ".extern" and the next one.
  witch is ovaisly an extern label.
*/
void delete_extern()
{
  if(is_extern(line_head->str))/*if the head is an extern*/
  {
    line_head=line_head->next->next;/*the head pointer will jump 2 node next*/
  }
  line_ptr curr=line_head->next;
  line_ptr prev=line_head;
  while(curr)
  {
    if(is_extern(curr->str))
    {
      curr=curr->next->next;
      if(!curr){prev->next=NULL;}
      else
      {
        prev->next=curr;
        prev=curr;
        curr=curr->next;
      }
    }
  else {prev=curr;curr=curr->next;}
  }

}
/*
  delete_label function deleteing all the label from the main list. label like MAIN: LIST: K:
*/
void delete_label()
{
  if(is_label(line_head->str))line_head=line_head->next;
  line_ptr curr=line_head->next;
  line_ptr prev=line_head;
  while(curr)
  {
    if(is_label(curr->str))
    {
      curr=curr->next;
      prev->next=curr;
      prev=curr;
      curr=curr->next;
    }
    else{prev=curr;curr=curr->next;}
  }

}
/*
  fix_string function seperate a string like "abcd" to seperate nodes that every node will contain a singal char
  so the fix string go over the main list and search for node that indicate for a string.
  then create a new node for each char and update the main list
*/
void fix_string()
{
  line_ptr curr=line_head;/*the head of the main list*/
  line_ptr prev,next;
  while(curr)
  {
    if(is_string(curr->str))/*if we fund a ".string" node*/
    {
      prev=curr;
      curr=curr->next;
      next=curr->next;
      int i;
      for(i=0;curr->str[i]!='\0';i++)/*the loop that go over the original string*/
      {
        if(curr->str[i]>41&&curr->str[i]<126)/*condition for lowercase letter or uppercase letter*/
        {
          line_ptr temp=(line_ptr)malloc(sizeof(line));
          temp->str[0]=curr->str[i];
          prev->next=temp;
          prev=prev->next;
        }

      }
      /*the bunch of lines adding an '\0' at the and of the string*/
      line_ptr temp2=(line_ptr)malloc(sizeof(line));
      temp2->str[0]='\0';
      prev->next=temp2;
      prev=prev->next;
      prev->next=next;
      curr=prev->next;
    }
    prev=curr;
    curr=curr->next;

  }
}
/*
  label_counter_update is one of the most important function in my project
  the function os analyze the program and update the label_counter field for all the node of the main list
*/
void label_counter_update()
{
  line_ptr curr;

  curr=line_head;
  int l_c=100;/*the intial value*/

  while(curr)
  {
    if(!is_string(curr->str)&&!is_data(curr->str)&&!is_label(curr->str))/*the function ignor all the node like: ".entry",".extern",of labels like "MAIN:"*/
    {
      if(is_op_from_group1(curr->str))/*only in case the op is from group 1 we need to increse extra time the label counter*/
      {
        line_ptr next1,next2;
        next1=curr->next;/*the first node afetr the op*/
        next2=curr->next->next;/*the second node after the op*/
            if((is_reg(next1->str)||is_pointer(next1->str))&&(is_reg(next2->str)||is_pointer(next2->str)))
            {
              curr->label_counter=l_c;
              l_c++;
              next1->label_counter=l_c;
              next2->label_counter=l_c;
              curr=next2;
            }
            else/*it is op but not from group 1*/
            {
              curr->label_counter=l_c;
              l_c++;
              curr=curr->next;
            }
          }
        else
        {
          curr->label_counter=l_c;
          l_c++;
          curr=curr->next;
        }
      }
      else{
        curr->label_counter=l_c;

        curr=curr->next;
      }
    }
}
/*delete_last_node deleting the last node of the main program.
  i dont know why but when im reading the input file the last node is read twice.
  so i have created this function to fix this problem
*/
void delete_last_node()
{
  line_ptr temp=line_head;
  while(temp->next->next)temp=temp->next;
  temp->next=NULL;
}
/*
  add_data_label function will add node like ".data".
  so after the function is trigger a line like this: .data -6,9; will be
  .data -6
  .data 9
*/
void add_data_label()
{
  line_ptr curr,prev;
  prev=line_head;
  curr=prev->next;
  while(curr)
  {
    if(is_number(curr->str)&&!is_data(prev->str))
    {
      line_ptr p=(line_ptr)malloc(sizeof(line));
      strcpy(p->str,".data");
      p->label_counter=curr->label_counter;
      prev->next=p;
      p->next=curr;
    }
    prev=curr;
    curr=curr->next;
  }
}
/*
  create_files_name will create the name to the all 3 extranl files we need.
  the function will get from the command line the name of the input file.
  so if the input is ps.as
  3 strings will be created
  ps.ent
  ps.ob
  ps.ext
*/
void create_files_name(char str[])
{
  int i;
  for(i=0;i<strlen(str)&&str[i]!='.';i++)/*the loop to srearch the end of the name of the file*/
  {
    main_name[i]=str[i];
    entry_name[i]=str[i];
    extern_name[i]=str[i];
  }
  main_name[i]='.';
  main_name[i+1]='o';
  main_name[i+2]='b';
  entry_name[i]='.';
  entry_name[i+1]='e';
  entry_name[i+2]='n';
  entry_name[i+3]='t';
  extern_name[i]='.';
  extern_name[i+1]='e';
  extern_name[i+2]='x';
  extern_name[i+3]='t';

}
/*
  write_entry_list function is writing to the .ent extranl file.
  useing a FILE pointer ent_ptr
*/
void write_entry_list()
{
  label_ptr temp=label_head;

  while(temp)
  {
    if(is_entry_label(temp->str))fprintf(ent_ptr,"%d %s\n",temp->label_counter,temp->str );

    temp=temp->next;
  }
}
/*
  write_extern_list function is writing to the .ext extranl file.
  useing a FILE pointer ext_ptr
*/
void write_extern_list()
{
  line_ptr temp=line_head;

  while(temp)
  {
    if(is_extern_label(temp->str))
      fprintf(ext_ptr,"%d %s\n",temp->label_counter,temp->str );

    temp=temp->next;
  }
}
