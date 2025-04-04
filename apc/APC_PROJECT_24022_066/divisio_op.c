#include "apc.h"

//*funt to do division operation
int division(apclist **head1, apclist **tail1, apclist **head2, apclist **tail2, apclist **res_head, apclist **res_tail)
{
    int count = 0;
    //declaring temporary nodes from tails and head
    apclist *temp_head1 = *head1;
    apclist *temp_tail1 = *tail1;

    apclist *temp_head2 = *head2;
    apclist *temp_tail2 = *tail2;

    apclist *temp_res_head = NULL;
    apclist *temp_res_tail = NULL;
    //check which is greater 
    if(if_larger(temp_head1,temp_head2) == 2)
    {
        //insert data into first
        insert_first(res_head,res_tail,0);
        return 0;
    }
    int decide = 0;
    //repeating the nodes from the data
    while (decide =repeat(&temp_head1, &temp_tail1, &temp_head2, &temp_tail2, &temp_res_head, &temp_res_tail))
    {
        count++;
        //print_list(temp_head1);
    }
    if(decide == 0)
    count++;
    printf("%d\n", count);  // Print final quotient
    insert_first(res_head, res_tail, count);
}

int repeat(apclist **temp_head1, apclist **temp_tail1, apclist **temp_head2, apclist **temp_tail2, apclist **temp_res_head, apclist **temp_res_tail)
{
    //subract data from the tail1 to tail2
    subtraction(temp_head1, temp_tail1, temp_head2, temp_tail2, temp_res_head, temp_res_tail);

    //print_list(*temp_res_head);
    remove_leading_zeros(temp_res_head,temp_res_tail);
    // Check if the result is zero or if the dividend is smaller than the divisor
    if (*temp_res_head == NULL || (*temp_res_head)->data == 0)
    {
        return 0;
    }

    // Update temporary dividend with the result of subtraction
    *temp_head1 = *temp_res_head;
    *temp_tail1 = *temp_res_tail;

    // Reset result pointers for the next iteration
    *temp_res_head = NULL;
    *temp_res_tail = NULL;

    // Check if the current dividend is less than the divisor
    if (if_larger(*temp_head1, *temp_head2) == 2)
    {
        return 0;
    }

    return 1;
}

//remove the zeros from the head                          
void remove_leading_zeros(apclist **head, apclist **tail)
{
    //traverse the data until the data
    while (*head && (*head)->data == 0)
    {
        apclist *temp = *head;
        *head = (*head)->next;
        if (*head)
            (*head)->prev = NULL;
        free(temp);//free the data
    }
    if (*head == NULL)
        *tail = NULL; 
}

//check greater list
int if_larger(apclist *head1, apclist *head2)
{
    apclist *temp1 = head1;
    apclist *temp2 = head2;
    // Check number of nodes
    int count1 = 0, count2 =0;
    // Traverse through the null and get count
    while(temp1 != NULL)
    {
        count1 ++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }
    if(count1 > count2)
    {
        return 1;
    }
    if(count1 < count2)
    {
        return 2;
    }
    if(count1 == count2)
    {
        temp1 = head1;
        temp2 = head2;
        while (temp1 && temp2)
    {
        if (temp1->data > temp2->data)
            return 1;
        if (temp1->data < temp2->data)
            return 2;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
        return 0;
    }
}