#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE 80
#define TABLE_SIZE 29
struct node{\
  char name[20];\
  int cnt;\
  struct node* next;\
};
