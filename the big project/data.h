#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define line_size 81
#define reg_name 15

typedef struct line_node *line_ptr;
typedef struct line_node{
  char str[reg_name];
  int label_counter;
  line_ptr next;
}line;
line_ptr line_head;

typedef struct entry_label_node *entry_label_ptr;
typedef struct entry_label_node{
  char str[reg_name];
  int label_counter;
  entry_label_ptr next;
}entry_label_node;
entry_label_ptr entry_label_head;

typedef struct extern_node *extern_ptr;
typedef struct extern_node{
  char str[reg_name];
  int label_counter;
  extern_ptr next;
}extern_node;
extern_ptr extern_head;

typedef struct label_node *label_ptr;
typedef struct label_node{
  char str[reg_name];
  int label_counter;
  label_ptr next;
}label_node;
label_ptr label_head;

typedef struct op_reg *op_ptr;
typedef struct op_reg{
  unsigned char op_code:4;
  unsigned char d_reg:4;
  unsigned char s_reg:4;
  unsigned char ARE:3;

}op_reg;

typedef struct dir_reg *dir_ptr;
typedef struct dir_reg{
  unsigned char op_code:6;
  unsigned char d_reg:3;
  unsigned char s_reg:3;
  unsigned char ARE:3;
}dir_reg;

typedef struct data_reg *data_ptr;
typedef struct data_reg{
  unsigned short int num:15;
}data_reg;

typedef struct immi_reg *immi_ptr;
typedef struct immi_reg{
  unsigned int num:12;
  unsigned char ARE:3;
}immi_reg;


FILE *fp,*ob_ptr,*ent_ptr,*ext_ptr;
char temp_line[line_size];
char node[reg_name];
char bin_num[reg_name];
char main_name[reg_name];
char entry_name[reg_name];
char extern_name[reg_name];

void create_files_name(char str[]);
void add_to_program_list(char str[]);
void print_program_list(line_ptr h);
void free_list(line_ptr p);
void load_program(char str[]);
void clear_comma(char str[]);
void build_entry_list(line_ptr h);
void print_entry_list(entry_label_ptr h);
void build_extern_list(line_ptr h);
void print_extern_list(extern_ptr h);
void build_label_list(line_ptr h);
void print_label_list(label_ptr h);
void delete_entry();
void delete_extern();
void delete_label();
void fix_string();
void label_counter_update();
void print_op(line_ptr line);
void print_s_reg(line_ptr line);
void print_d_reg(line_ptr line);
void print_immi(line_ptr line);
void print_data(line_ptr line);
void print_string(line_ptr line);
void print_by_value(line_ptr line,int value);
void print_list(line_ptr h);
void print_extern_adress(line_ptr line);
void delete_last_node();
void add_data_label();
void bin_to_oct(char str[],line_ptr node);
void print_two_regs_toghther(line_ptr line);
void write_entry_list();
void write_extern_list();
void print_error(line_ptr line);
void free_label_list(label_ptr head);
void free_extern_list(extern_ptr head);
void free_entry_list(entry_label_ptr head);
void free_all_lists();

int is_op(char str[]);
int is_label(char str[]);
int is_pointer(char str[]);
int is_reg(char str[]);
int is_extern(char str[]);
int is_entry(char str[]);
int is_entry_label(char str[]);
int is_immediate(char str[]);
int get_immediate(char str[]);
int what_is_it(char str[]);
int is_string(char str[]);
int is_data(char str[]);
int is_op_from_group1(char str[]);
int what_op(char str[]);
int is_adress(char str[]);
int get_adress(char str[]);
int is_op_from_group2(char str[]);
int is_op_from_group3(char str[]);
int is_extern_label(char str[]);
int is_number(char str[]);
