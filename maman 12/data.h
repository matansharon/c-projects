#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define NUM_OF_STRINGS 30
#define SIZE_OF_STRING 21


void print_array(char NAMES[NUM_OF_STRINGS][SIZE_OF_STRING]);
void fill_array(char NAMES[NUM_OF_STRINGS][SIZE_OF_STRING]);
int trans_tolower(char str1[],char str2[]);
void get_name(char temp_str[10][SIZE_OF_STRING]);

char NAMES[NUM_OF_STRINGS][SIZE_OF_STRING];/*the big array to save all 30 names*/
char temp_str[10][SIZE_OF_STRING];/*the little array to save 10 names for each call*/
