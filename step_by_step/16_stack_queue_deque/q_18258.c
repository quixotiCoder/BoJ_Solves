// BoJ q_18258
// theme : stack_queue_deque

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int* key;
	int front, rear;
    int max_queue_size;
}Queue;

Queue* CreateQueue(int max);
void Push(Queue* Q, int n);
int Pop(Queue* Q);
int Size(Queue* Q);
int Is_Empty(Queue* Q);
int Front(Queue* Q);
int Back(Queue* Q);

Queue* CreateQueue(int max){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if(Q == NULL) 
		exit(1);

    Q->key = (int*)malloc(max * sizeof(int));
    Q->max_queue_size = max;
    Q->front = -1;
    Q->rear = -1;

    return Q;
}

void Push(Queue* Q, int n){
    Q->key[++Q->rear] = n;
}

int Pop(Queue* Q){
    if(Is_Empty(Q))
        return -1;

    int temp = Q->key[++Q->front];
    return temp;
}

int Size(Queue* Q){
    return (Q->rear - Q->front);
}

int Is_Empty(Queue* Q){
    if(Q->front == Q->rear)
        return 1;
    else
        return 0;
}

int Front(Queue* Q){
    if(Is_Empty(Q))
        return -1;
    
    int temp = Q->key[Q->front + 1];
    return temp;
}

int Back(Queue* Q){
    if(Is_Empty(Q))
        return -1;
    
    int temp = Q->key[Q->rear];
    return temp;
}

int main(){
    int N;
    scanf("%d", &N);

    Queue* main_queue = CreateQueue(N);

    for(int i = 0; i < N; i++)
    {
        char str[15];
        scanf("%s", str);
        if(strcmp(str, "push") == 0) 
        {
            int num;
            scanf("%d", &num);
            Push(main_queue, num);
        } 
        else if(strcmp(str, "pop") == 0) 
            printf("%d\n", Pop(main_queue));

        else if(strcmp(str, "size") == 0) 
            printf("%d\n", Size(main_queue));

        else if(strcmp(str, "empty") == 0)
            printf("%d\n", Is_Empty(main_queue));

        else if(strcmp(str, "front") == 0)
            printf("%d\n", Front(main_queue));
        
        else if(strcmp(str, "back") == 0)
            printf("%d\n", Back(main_queue));

    }
    free(main_queue->key);
    free(main_queue);

    return 0;
}
