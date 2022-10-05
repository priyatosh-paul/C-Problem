#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
		struct node *next;
		int data;
}NODE;

NODE *top=NULL;

void push_stack(int data)
{
		NODE *temp=(NODE*)malloc(sizeof(struct node)*1);

		if(top==NULL)//if stack is empty
		{
				top=temp;
				top->data=data;
				top->next=NULL;
		}
		else//if stack is not empty
		{
				temp->next=top;
				temp->data=data;
				top=temp;
		}
} // Push of Stack

void pop_stack(void)
{
		NODE *temp;
		if(top==NULL)
		{
				printf("\n No Node Exit in the Node \n");
		}
		else if(top->next==NULL)
		{
				free(top);
				top=NULL;
		}
		else
		{
				temp=top;
				top=top->next;
				free(temp);
		}

}

void display_stack(void)
{
		NODE *trav;
		printf("\n Entered Stack Is:::::");

		if(top==NULL)
		{
				printf("\n Entered List Is Empty \n");
		}
		else
		{
				trav=top;
				while(trav !=NULL)
				{
						printf("%d\t",trav->data);
						trav=trav->next;
				}

		}
}// display of stack
int main(void)
{
		push_stack(400);
		push_stack(300);
		push_stack(200);
		push_stack(100);

		display_stack();

		pop_stack();

		display_stack();

		return 0;
}

