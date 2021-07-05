#include "data.h"
/*
the main method is seperate to 4 stages:
stage 1: is to build the variebels and then read the input file.
stage 2: build a linked list from the input.
each node of the list is a struct with a field to save th word  a field to save the label counter.
stage 3: is a couple of functions that goes over the linked list and analyzed and fix the linked list.
stage 4: call print_list function to print the list in octal represntion in the correct file.

*/
int main(int argc, char const *argv[])
{
  /*-------------stage1---------------------------------------------------------*/
  int i;/*use as an position in the argv array*/
  for(i=1;i<argc;i++)/*the loop that will continue as many files input there is*/
  {

  char node[reg_name];/*an array to save the name of the input file*/
  strcpy(node,argv[i]);
  create_files_name(node);/*this function get a string as an input and creat 3names for the 3 output files*/
  fp=fopen(node,"r");/*the pointer to open the input file*/
  ob_ptr=fopen(main_name,"w");/*the pointer to open th .ob file*//*the pointer to open th input file*/
  ent_ptr=fopen(entry_name,"w");/*the pointer to open the .ent file*/
  ext_ptr=fopen(extern_name,"w");/*the pointer to open the .ext file*/
  /*-------------stage2---------------------------------------------------------*/

  while(!feof(fp))/*as long as there is an input to read*/
  {
    fscanf(fp,"%s",node);
    clear_comma(node);/*function to clear the comma*/
    add_to_program_list(node);/*function to add a new node to the list*/
  }/*end of while*/

  /*-------------stage3---------------------------------------------------------*/

  build_entry_list(line_head);/*create the entry sybols list*/
  build_extern_list(line_head);/*create the extern sybols list*/
  fix_string();/*seperate the string. explantion at the method api*/
  delete_last_node();/*last node is adding twice. this function delete the lase one*/

  delete_entry();/*delete all ".entry" nodes from the list*/
  delete_extern();/*delete all ".extern" nodes from the list*/

  label_counter_update();/*after fixing the list. thist function update the label counter for each node*/

  build_label_list(line_head);/*build the label list after the label counter is update*/
  delete_label();/*after bulding the label list we no longer need the on the list we want to print*/
  add_data_label();/*fix aliitle thing when we would like to print data number*/
  
  /*-------------stage4---------------------------------------------------------*/

  print_list(line_head);/*the biggest function that is printing the clean list to the files*/
  write_entry_list();/*print the entry list to .ent file*/
  write_extern_list();/*print the extern list to .ext file*/
  entry_label_head=NULL;
  line_head=NULL;
  extern_head=NULL;
  label_head=NULL;

  }
  return 0;
}
