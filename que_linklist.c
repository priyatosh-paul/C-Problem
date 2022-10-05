#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
struct node *next;
int data;
}NODE;
NODE *rear=NULL,*front=NULL;
void insert_into_queaue(int data)
{
NODE *temp=(NODE*)malloc(sizeof(struct node)*1);
NODE *trav;
if(rear==NULL)
{
rear=front=temp;
rear->data=data;
rear->next=NULL;
}
else
{
trav=rear;
while(trav->next !=NULL)
{
trav=trav->next;
}
temp->next=NULL;
temp->data=data;trav->next=temp;
rear=temp;
}
} // insert into queue
void delete_from_queue(void)
{
NODE *temp;
if(front==NULL)
{
printf("\n Queue Is Empty \n");
}
else if(front->next==NULL)
{
free(front);
front=rear=NULL;
}
else
{
temp=front;
front=front->next;
free(temp);
}
} // delete from queue
void display_of_queue(void)
{
NODE *trav;
printf("\n Entered queue Is:::::");
if(front==NULL)
{
printf("\n Queue is Empty \n");
}
else
{
trav=front;
while(trav !=NULL)
{
printf("%d\t",trav->data);
trav=trav->next;
}
}
}// display of queue
int main(void)
{
insert_into_queaue(100);
insert_into_queaue(200);
insert_into_queaue(300);
insert_into_queaue(400);
display_of_queue();delete_from_queue();
display_of_queue();
return 0;
}


