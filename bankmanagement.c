#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int acc_num;
	char name[50];
	float balance;
	struct node *link;
};
typedef struct node *NODE;
NODE first = NULL;

NODE createAcc(NODE first){
	NODE newAcc=(NODE)malloc(sizeof(NODE));
	if(newAcc==NULL){
		printf("Out of memory\n");
		exit(0);
	}
	int prevAccnum=18759000;
	printf("Enter name : ");
    scanf("%s",newAcc->name);
	printf("Enter initial balance :");
	scanf("%f",newAcc->balance);
	newAcc->link=NULL;
	newAcc->acc_num=++prevAccnum;
	prevAccnum=newAcc->acc_num;
	printf("Account number : %d",newAcc->acc_num);
	if(first==NULL){
		first=newAcc;
		printf("Account created successfully!\n");
		return first;
	}
	newAcc->link=first;
	first=newAcc;
	printf("Account created successfully!");
	return first;
}

NODE updateAcc(NODE first){
	int account_num;
	float deposit;
	printf("Enter account number :");
	scanf("%d",&account_num);
	NODE cur=first;
	while(cur!=NULL){
		if(cur->acc_num==account_num){
			printf("Enter new name :");
			scanf("%s",cur->name);
			printf("Amount to be deposited :");
			scanf("%f",&deposit);
			cur->balance=cur->balance+deposit;
			printf("Account updated successfull!\n");
			return first;
		}
		cur-cur->link;
	}
	printf("Account not found.Please try again\n");
	return first;
}

NODE viewAcc(NODE first){
	int account_num;
	printf("Enter account number :");
	scanf("%d",account_num);
	NODE cur=first;
	while(cur!=NULL){
		if(cur->acc_num==account_num){
			printf("Account number : %d\n",cur->acc_num);
			printf("Account holder name : %s\n",cur->name);
			printf("Balance : %2f Rupees\n",cur->balance);
			return first;
		}
		cur=cur->link;
	}
	printf("Account not found.Please try again\n");
	return first;
}

NODE removeAcc(NODE first){
	NODE cur = first;
	int account_num;
	printf("Enter account number :");
	scanf("%d",&account_num);
	NODE prev =NULL;
	if(account_num==first->acc_num){
		first=first->link;
		printf("Account deleted successfully!\n");
		free(cur);
		return first;
	}
	while(cur!=NULL&&cur->acc_num!=account_num){
		prev=cur;
		cur=cur->link;
	}
	if(cur==NULL){
		printf("Account not found.Please try again\n");
    	return first;
	}
	prev->link=cur->link;
	printf("Account deleted successfully!\n");
	free(cur);
	return first;
}

NODE viewAllAcc(NODE first){
	NODE cur=first;
	printf("--------------------Customers List---------------------\n");
	printf("Account number\tName\tBalance\n");
	while(cur!=NULL){
		printf("%d\t%s\t%2f\n",cur->acc_num,cur->name,cur->balance);
		cur=cur->link;
	}
}

int main(){
	int option;
	do{
		printf("********Bank Management System********\n\n");
		printf("1.Create new account\n2.Update information of an existing account\n");
		printf("3.View and manage transactions\n4.Check the details of an existing account\n");
		printf("5.Remove an existing account\n6.View customers list\n");
		printf("7.Exit\n\nEnter your option : ");
		scanf("%d",&option);
		switch(option){
			case 1 : first=createAcc(first);
			         break;
			case 2 : first=updateAcc(first);
			         break;
			case 3 : printf("Will be updated soon\n");
			         break;
			case 4 : first=viewAcc(first);
			         break;
			case 5 : first=removeAcc(first);
			         break;
			case 6 : first=viewAllAcc(first);
			         break;
			case 7 : exit(0);
			default : printf("Invalid option.Please try again\n");   
		}
	}while(option!=7);
}
