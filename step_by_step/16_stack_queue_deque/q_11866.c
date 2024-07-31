// BoJ 11866   
// theme : stack_queue_deque

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _QueueNode QueueNode;

struct _QueueNode{ // linked-list 형태 for node
    QueueNode* next; // for linked-list
    int data; // 값 저장
};

typedef struct _Queue { // 위의 node들을 묶은 Queue == FIFO 
	QueueNode* front; // 가장 먼저 dequeue할 node 가리킴
	QueueNode* rear; // 가장 최근 enqueue된 node 가리킴
	int size; // en/dequeue마다 갱신 -> 나중에 graph의 총 개수와 비굣
} Queue;

Queue* CreateQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue)); // queue를 malloc으로 할당
    if (queue == NULL) // 메모리 할당 실패 시 
        return NULL;

    queue->front = NULL; // 구조체 변수 초기화
    queue->rear = NULL;  // ''
    queue->size = 0;     // ''
    return queue;        // 생성한 queue 반환
}

bool IsEmpty(Queue* Q){
    if(Q->size == 0) // 빈 상태
        return true;
    else // 아닌 상태
        return false;
}

bool IsSizeOne(Queue* Q){
    if(Q->size == 1)
        return true;
    else
        return false;
}


int Dequeue(Queue* Q){
    QueueNode* temp = Q->front; //queue 맨 앞쪽의 노드를 꺼내기
    Q->size--; //size --
    int value = temp->data;

    if(temp->next == NULL) // 빼면 empty인 경우 front, rear 둘 다 NULL로
    {
        Q->front = NULL;
        Q->rear = NULL;
    }
    else
        Q->front = temp->next; // linked list때와 동일하게 Q->front 포인터를 갱신
    
    free(temp); // temp node 메모리 free
    
    return value; // 가장 앞 노드'였던' data 반환
}

void Enqueue(Queue* Q, int X){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)); // 노드 구조체 할당
    if (newNode == NULL) // 메모리 할당 실패 시
        return;

    newNode->data = X; // data 삽입
    newNode->next = NULL; // Queue == FIFO 구조체이기에
    if (IsEmpty(Q)) // 빈 queue ->front, rear 둘 다 새로 만든 node로
    {
        Q->front = newNode; // front와
        Q->rear = newNode;  // rear 모두 생성된 newNode
    }
    else // 뭐라도 든 경우 -> linked list때와 동일하게 Q->rear->next와 Q->rear 포인터를 갱신
    {
        Q->rear->next = newNode; // 기존 노드 중 마지막 노드의 다음 위치로 할당
        Q->rear = newNode; // Q 전체의 rear를 newNode로
    }
    Q->size++;  // size 한 칸 증가
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Queue* queue = CreateQueue();
    for (int i = 1; i <= N; i++)
        Enqueue(queue, i);
    

    printf("<");
    while (!IsSizeOne(queue)) 
    {
        for (int i = 0; i < K - 1; i++)
            Enqueue(queue, Dequeue(queue));
            
        printf("%d, ", Dequeue(queue));
    }
   
    printf("%d>", Dequeue(queue));

    free(queue);
    return 0;
}