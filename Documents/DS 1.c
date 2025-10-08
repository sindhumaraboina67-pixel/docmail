#include<stdio.h>
#define SIZE 50
void enqueue();
void dequeue();
void display();
int cqueue[SIZE];
int rear=-1;
int front=-1;
main()
{
    int choice;
    while(1)
    {
        printf("1.insert elements to queue\n");
        printf("2.delete elements from queue\n");
        printf("3.display all elements to queue\n");
        printf("4.quit\n");
        printf("enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("wrong choice\n");
        }
    }
}
void enqueue()
{
    int item;
    if((front==0&&rear==-1)||(front==rear+1))
        printf("queue is full");
    else
    {
        rear=(rear+1)%SIZE;
        printf("enter an item:");
        scanf("%d",&item);
        cqueue[rear]=item;
        if(front==-1)
            front=0;
    }
}
void dequeue()
{
    if(front==-1)
        printf("cqueue is empty");
    else if(front==rear)
    {
        printf("elements deleted is %d",cqueue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("deleted elements is %d",cqueue[front]);
        front=(front+1)%SIZE;
    }
}
void display()
{
    int i;
    if(front==-1)
        printf("c_queue is empty");
    else
    {
        for(i=front;i<=rear;i=(i+1)%SIZE)
            printf("%d",cqueue[i]);
    }
}
