// BoJ 12789
// theme : stack_queue_deque

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *key;
    int top;
    int max_stack_size;
} Stack;

Stack* CreateStack(int max) {
    Stack* S = (Stack*)malloc(sizeof(Stack)); // malloc으로 Stack 포인터 S 할당
    if (S == NULL) // malloc으로 메모리 할당 실패한 case 처리
        return NULL;

    S->key = (int*)malloc(max * sizeof(int)); // S->key 를 max 크기의 int array pointer 할당 (malloc)
    S->max_stack_size = max; // S->max_stack_size 설정
    S->top = -1; // S->top 을 -1로 설정

    return S; // S 반환
}

void DeleteStack(Stack* S) {
    free(S->key); // key를 free
    free(S); // S를 free
    return;
}

void Push(Stack* S, int X) {
    if (IsFull(S)) // 'Stack이 꽉 차있는 상태에서 Push 하는 경우'
        return;

    S->top += 1; // S->top += 1
    S->key[S->top] = X; // S->key의 top 에 X 대입
    return;
}

int Pop(Stack* S) {
    if (IsEmpty(S)) // 'Stack이 비어있는 상태에서 Pop 하는 경우'
        return -1;

    return S->key[S->top--]; // S->key의 top 반환 후, top을 하나 낮춤
}

int Top(Stack* S) {
    return S->key[S->top]; // S->key의 top 반환
}

int StackSize(Stack* S){
    return S->top + 1;
}

int IsFull(Stack* S) {
    return (S->top == S->max_stack_size - 1); // index는 '0'부터 시작이기에, 'S->max_stack_size - 1'로 full인 상태 확인
}

int IsEmpty(Stack* S) {
    return (S->top == -1); // stack이 빈 상태인 'S->top == -1' 조건 확인
}

int main() {
    int N;
    scanf("%d", &N);

    Stack* stack = CreateStack(N);
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    int* studentNums = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++)
        scanf("%d", &studentNums[i]);

    int rightOrder = 1;

    for(int i = 0; i < N; i++) {
        while (!IsEmpty(stack) && Top(stack) == rightOrder) {
            Pop(stack);
            rightOrder++;
        }

        if (studentNums[i] == rightOrder) {
            rightOrder++;
        } else {
            Push(stack, studentNums[i]);
        }
    }

    while (!IsEmpty(stack) && Top(stack) == rightOrder) {
        Pop(stack);
        rightOrder++;
    }

    if (IsEmpty(stack))
        printf("Nice");
    else
        printf("Sad");

    DeleteStack(stack);
    free(studentNums);

    return 0;
}
