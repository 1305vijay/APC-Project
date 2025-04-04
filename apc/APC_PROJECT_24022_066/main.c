/*_________________
NAME: M Vijay
DATE: 23/12/24
ID: 24022_066
DESCRP: APC project to calculate larger numbers 
__________________*/


#include "apc.h"

/*main funct*/
int main(int argc, char *argv[]) {
    // Validate operands, print error message on failure
    if (validation(argc, argv) == FAILURE) {
        printf("Error: Invalid arguments\n");
        printf("..............................................\n");
        printf("Usage: ./a.out <NUMBER1> <Operator> <NUMBER2>\n");
        printf("..............................................\n");
        return FAILURE;
    }

    // Initialize linked lists
    apclist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
    char str1[MAX_SIZE], str2[MAX_SIZE], opr[2];
    int isOperand1Larger = 0, isBothOperandsEqual = 0;

    // Determine the larger operand
    char *operand1 = argv[1], *operand2 = argv[3];
    if (str_length(operand2) > str_length(operand1) ||
        (str_length(operand2) == str_length(operand1) && str_cmp(operand2, operand1) > 0)) {
        strcpy(str1, operand2);
        strcpy(str2, operand1);
        isOperand1Larger = 1;
    } else {
        strcpy(str1, operand1);
        strcpy(str2, operand2);
        if (str_length(operand2) == str_length(operand1) && str_cmp(operand1, operand2) == 0) {
            isBothOperandsEqual = 1;
        }
    }

    strcpy(opr, argv[2]);

    // Handle operator logic
    int isNegativeResult = 0;
    if ((str1[0] == '-' && str2[0] != '-' && opr[0] == '+') ||
        (str1[0] != '-' && str2[0] == '-' && opr[0] == '+')) {
        opr[0] = '-';
        isNegativeResult = 1;
    } else if (str1[0] == '-' && str2[0] == '-' && opr[0] == '+') {
        opr[0] = '+';
        isNegativeResult = 1;
    } else if ((str1[0] == '-' || str2[0] == '-') && (opr[0] == 'X' || opr[0] == 'x' || opr[0] == '/')) {
        isNegativeResult = 1;
    }

    strrev(str1);
    strrev(str2);

    // Insert operand into linked lists
    insert_numbers_to_list(str1, &head1, &tail1);
    insert_numbers_to_list(str2, &head2, &tail2);

    /*print_list(head1);
    printf("%s\n", opr);
    print_list(head2);*/
    print_list_inline(head1);  // Print operand1
printf(" %s ", opr);       // Print the operator
print_list_inline(head2);  // Print operand2
printf("\n");



    // Perform operations based on operator
    switch (opr[0]) {
        case '+':
            add(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Operation Addition Successfully\nThe Result is: ");
            break;
        case '-':
            subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Operation Subtraction Successfully\nThe Result is: ");
            break;
        case 'X':
        case 'x':
            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Operation Multiplication Successfully\nThe Result is: ");
            break;
        case '/':
            if (isOperand1Larger == 1) {
                printf("Operation Division\nThe Result is: 0\n");
                return 0;
            }
            division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Operation Division Successfully\nThe Result is: ");
            break;
    }

    if (isNegativeResult) {
        printf("-");
    }
    print_list(headR);
}

void insert_numbers_to_list(char *str, apclist **head, apclist **tail) {
    int i = 0, len = strlen(str);
    while (i < len) {
        char buffer[5] = {0};
        strncpy(buffer, str + i, (len - i >= 4) ? 4 : len - i);
        strrev(buffer);
        int num = abs(atoi(buffer));
        if (insert_first(head, tail, num) == FAILURE) {
            printf("Error: node creation unsuccessful\n");
        }
        i += 4;
    }
}

void strrev(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int str_length(char *str) {
    while (*str == '+' || *str == '-') str++;
    while (*str == '0') str++;
    return strlen(str);
}

int str_cmp(char *str1, char *str2) {
    while (*str1 == '+' || *str1 == '-') str1++;
    while (*str1 == '0') str1++;
    while (*str2 == '+' || *str2 == '-') str2++;
    while (*str2 == '0') str2++;
    return strcmp(str1, str2);
}
