
#include "apc.h"

/* funct to do multiplication*/
int multiplication(apclist **head1, apclist **tail1, apclist **head2, apclist **tail2, apclist **headR, apclist **tailR)
{
	/* Definition goes here */
	apclist *temp1=*tail1;
	apclist *temp2=*tail2;
	unsigned long long int carry=0,rem,res,count=0,mul=1;
	int num=temp2->data;
	apclist *result=NULL;
	apclist *rres=NULL;
	apclist *list=NULL;
	apclist *rlist=NULL;
	//insert result at first
	if((insert_first(&result,&rres,0))==FAILURE)
			printf("Error: node creation unsuccessful\n");
	//traverse through the node
	while(temp2){
		
		rem=num%10;
		res=temp1->data * rem * mul+carry;//get result
		if(temp1->next==NULL){
			//if count is not zero multilty result with 10 
			for(int i=0;i<count;i++){
				res=res*10;
				mul=mul*10;
				
			}
		}
		carry=res/10000;
		res=res%10000; 
		//insert the result
		if((insert_first(&list,&rlist,res))==FAILURE)
			printf("Error: node creation unsuccessful\n");
		 //print_list(list);
		temp1=temp1->prev;
		//if temp1 became null
		if(temp1==NULL){
			if(carry!=0){
			if((insert_first(&list,&rlist,carry))==FAILURE)
			printf("Error: node creation unsuccessful\n");
			}
			//print_list(list);
			//perform addition on result
			add(&list, &rlist, &result, &rres, headR, tailR);
			//delete list
			delete_all(&result,&rres);
			delete_all(&list,&rlist);
			insert(&result,&rres,headR,tailR);//insert result list into rresult
			delete_all(headR,tailR);
			num/=10;
			temp1=*tail1;
			count++;
			// printf("%ld\n",count);
			carry=0;
			mul=1;
		}
		if(num==0){
			
			temp2=temp2->prev;
			if(temp2!=NULL)
			num=temp2->data;
			carry=0;
			mul=1;
		}

	}
	insert(headR,tailR,&result,&rres);
	delete_all(&result,&rres);
}

//deleting list
int delete_all(apclist **head, apclist **tail)
{
    if(*head==NULL){
        return FAILURE;
    }
    apclist *temp=*head;
    while(temp!=NULL){
        *head=(*head)->next;
        free(temp);
        temp=*head;
    }
    *tail=NULL;
    return SUCCESS;
}
//insert one list into another
int insert(apclist **head1,apclist **tail1,apclist **head2,apclist **tail2){
	apclist *temp=*tail2;
	while(temp!=NULL){
		int n=temp->data;
		if((insert_first(head1,tail1,n))==FAILURE)
			printf("Error: node creation unsuccessful\n");
		temp=temp->prev;
	}
	return SUCCESS;
}