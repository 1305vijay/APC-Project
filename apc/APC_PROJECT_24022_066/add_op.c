#include "apc.h"


/*pfunt to do addition*/
void add(apclist **head1, apclist **tail1, apclist **head2, apclist **tail2, apclist **headR,apclist **tailR)
{
	/* Definition goes here */
	int carry=0,sum=0;
	apclist *temp1=*tail1;
	apclist *temp2=*tail2;
	/*travese list until reaching null*/
	while(temp1||temp2){
		if(temp1)
			sum=temp1->data;//sum offirst list
		else
			sum=0;
		if(temp2)
			sum=sum+ (temp2->data);//sum of second list
		else 
			sum=sum+0;
		sum = carry + sum;/*get sum*/
		carry = sum / 10000;
        sum = sum % 10000;
		
		if((insert_first(headR,tailR,sum))==FAILURE)		//insert sum into result list
			printf("Error: node creation unsuccessful\n");
		
        if (temp1)								//traverse through the nodes
            temp1 = temp1->prev;
        if (temp2)
            temp2 = temp2->prev;
	}
	/*insert carry lastly*/
	if(carry){
		if((insert_first(headR,tailR,carry))==FAILURE)
			printf("Error: node creation unsuccessful\n");
	}

}
