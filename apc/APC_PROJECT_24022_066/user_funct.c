#include "apc.h"

void print_list(apclist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
			if(head->prev==NULL){
			}
			else if(head->data<10)
				printf("000");
			else if(head->data>=10 && head->data<=99)
				printf("00");
			else if(head->data>= 100&& head->data<=999)
				printf("0");
		    /* Printing the list */
		    printf("%d", head -> data);
		    /* Travering in forward direction */
		    head = head -> next;
	    }
    	printf("\n");
    }
}
/*funct to print arg in a line before result*/
void print_list_inline(apclist *head) {
    apclist *current = head;
    while (current) {
        printf("%d", current->data);
        //if (current->next) printf("->");
        current = current->next;
    }
}


/* funct call to validate operands in given arg*/
static const char *operators = "+-/xX";

int validate_operand(const char *operand) {
    int i = 0;
    if (operand[0] == '+' || operand[0] == '-') {
        i++;
    }
    while (operand[i]) {
        if (!isdigit(operand[i])) {
            return FAILURE;
        }
        i++;
    }
    return SUCCESS;
}

int validation(int argc, char **argv) {
    if (argc != 4) {
        return FAILURE;
    }

    // Validate both operands
    if (validate_operand(argv[1]) == FAILURE || validate_operand(argv[3]) == FAILURE) {
        return FAILURE;
    }

    // Validate operator
    if (strlen(argv[2]) != 1 || strchr(operators, argv[2][0]) == NULL) {
        return FAILURE;
    }

    return SUCCESS;
}


/*funct call to insert data into list at first node*/
int insert_first(apclist **head,apclist **tail,data_t data){
    apclist *new=(apclist *)malloc(sizeof(apclist));
    if(new==NULL){
        return FAILURE;
    }
    new->data=data;
    new->prev=new->next=NULL;
    if(*head==NULL){
        *head=*tail=new;
        return SUCCESS;
    }
    new->next=*head;
    (*head)->prev=new;
    *head=new;
    return SUCCESS;
}

