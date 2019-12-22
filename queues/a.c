#include"stdio.h"
#include"malloc.h"

typedef struct node
{
	int data;
	struct node*Next;
}node;

typedef struct queue
{
	struct node *Front;
	struct node *Rear;
}queue;

void init_queue(queue *q)
{
	
	q->Front = NULL;
	q->Rear = NULL;
}

int is_empty(queue *q)
{
	if (q->Front == NULL)
		return 1;
	else
		return 0;
}

int dequeue(queue *q)
{
	if (is_empty(q) == 1)
		printf("the queue is empty");
	else
	{
		int data;
		node *temp;
		temp = q->Front;
		data = temp->data;
		q->Front = temp->Next;
		free(temp);
		return data;
	}
	return -1;
}

void enqueue(queue *q, int val)
{
	node *temp;
	temp = (node*)malloc(sizeof(node));
	
	if (is_empty(q) == 1)
	{
		q->Front = q->Rear = temp;
		temp->data = val;
	}
		
	else
	{
		q->Rear->Next = temp;
		q->Rear = temp;
		temp->data = val;
		q->Rear->Next = NULL;
	}
		
}

void display_queue(queue *q)
{
	node *temp;
	temp = q->Front;
	while (temp)
	{
		printf("%d", temp->data);
		temp=temp->Next;
	}
}

int main()
{
	queue *q;
	q = (queue*)malloc(sizeof(queue));
	init_queue(q);
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	display_queue(q);
	dequeue(q);
	display_queue(q);
	return 0;
}
