#include <stdio.h>
#include <stdlib.h>

#define SIZE 1001

typedef struct {
	int queue[SIZE];
	int front, rear;
}Queue;

void init_queue(Queue* q);
int is_full(Queue* q);
int is_empty(Queue* q);

void push(Queue* q, int e);
int pop(Queue* q);
int size(Queue* q);


void init_queue(Queue* q)
{
	q->front = q->rear = 0;
}

int is_full(Queue* q)
{
	return ((q->rear + 1) % SIZE == q->front);
}

int is_empty(Queue* q)
{
	return (q->front == q->rear);
}

void push(Queue* q, int e)
{
	if (is_full(q))
		return;

	q->rear = (q->rear + 1) % SIZE;
	q->queue[q->rear] = e;
}

int pop(Queue* q)
{
	if (is_empty(q))
		return -1;

	q->front = (q->front + 1) % SIZE;
	return q->queue[q->front];
}

int size(Queue* q)
{
	if (q->front < q->rear)
		return q->rear - q->front;
	else
		return SIZE - q->front + q->rear;
}

int main()
{
    Queue queue;
    init_queue(&queue);

    int N, K;
    scanf("%d %d", &N, &K);

    for(int i = 1; i < 7; i++)
        push(&queue, i);
    
    for (int j = 0; j < N; j++)
    {
        
    }
    
}