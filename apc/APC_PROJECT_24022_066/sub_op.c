#include "apc.h"

/*funt to do subtraction*/
void subtraction(apclist **head1, apclist **tail1, apclist **head2, apclist **tail2, apclist **headR,apclist **tailR)
{
	int barrow=0,differ=0;
	apclist *temp1=*tail1;
	apclist *temp2=*tail2;
	/*travese list until reaching null*/
	while(temp1||temp2){	
		if(((temp1?temp1->data:0)) < (temp2?temp2->data:0))
		{
			differ=(temp1?temp1->data:0) +10000-barrow - (temp2?temp2->data:0) ;//get differ
			barrow=1;			
		}
		else if((temp1?temp1->data:0) > (temp2?temp2->data:0))
		{	
			differ=(temp1?temp1->data:0)-barrow-(temp2?temp2->data:0) ;//get differ
			barrow=0;
		}
		else if(temp1->data==0&&barrow==1){
			differ=10000-barrow ;//get differ
		}
		else{
			differ=(temp1?temp1->data:0)-barrow-(temp2?temp2->data:0) ;//get differ
			barrow=0;
		}
		if(temp1->prev!=NULL || differ!=0)
		if((insert_first(headR,tailR,differ))==FAILURE)//insert differ into nodes
			printf("Error: node creation unsuccessful\n");
		//travese nodes
		if(temp1)
			temp1=temp1->prev;
		if(temp2)
			temp2=temp2->prev;
	}
}




 