// BoJ q_18258
// theme : stack_queue_deque

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int *key; // 실질적 큐 배열
    int front; // front 위치 저장
    int rear; // rear 위치 저장
    int max_queue_size; // 큐의 max_size 저장 to check full
}Queue;

Queue* CreateQueue(int max);
