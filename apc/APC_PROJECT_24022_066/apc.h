#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE 1


#define MAX_SIZE 200

typedef int data_t;

typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}apclist;


/*_________function prototypes of mathematical operations_____________*/
/*to do addition*/
void add(apclist **head1, apclist **tail1, apclist **head2, apclist **tail2, apclist **headR,apclist **tailR);
/*funct to do subraction*/
void subtraction(apclist **head1, apclist **tail1, apclist **head2, apclist **tail2, apclist **headR,apclist **tailR);
/*funct to do multiplication*/
data_t multiplication(apclist **head1, apclist **tail1, apclist **head2, apclist **tail2, apclist **headR, apclist **tailR);
/*funct to do division*/
data_t division(apclist **head1, apclist **tail1, apclist **head2, apclist **tail2, apclist **headR,apclist **tailR);


/*______funct to operate with sign and arg of user___________*/

/*read and validations*/
data_t validation(data_t argc,char **argv);
/*reverse*/
void strrev(char *str);
/*finding length of the string*/
data_t str_length(char *str);
/*compare two strings*/
data_t str_cmp(char *str1,char *str2);
/*length*/
data_t list_length(apclist *head);
/*funct to find greater num*/
data_t if_larger(apclist *head1, apclist *head2);


/*________user defined functiions_______________*/

/*to print list*/
void print_list(apclist *head);
/*insert at first*/
data_t insert_first(apclist **head,apclist **tail,data_t data);

void insert_numbers_to_list(char *str, apclist **head, apclist **tail);

/*delete list*/
data_t delete_all(apclist **head, apclist **tail);
/*insert data*/
data_t insert(apclist **head1,apclist **tail1,apclist **head2,apclist **tail2);

/*division checking*/
data_t checking(apclist **head,apclist **tail,apclist **head2,apclist **tail2);

/*repeate the stament getting zeros*/
data_t repeat(apclist **temp_head1, apclist **temp_tail1, apclist **temp_head2, apclist **temp_tail2, apclist **temp_res_head, apclist **temp_res_tail);
/*remove leading zeros from division*/
void remove_leading_zeros(apclist **head, apclist **tail);

void print_list_inline(apclist *head);


#endif
