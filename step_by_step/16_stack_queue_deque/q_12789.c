#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
	int *stack_space;
	int top;
	int max_stack_size;
}Stack;

Stack* Initstack(int max);
void Push(Stack* S, int X);
int Pop(Stack* S);

void DeleteStack(Stack* S);
bool IsEmpty(Stack* S);
bool IsFull(Stack* S);

Stack* Initstack(int max){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->stack_space = (int*)malloc(sizeof(int) * max);
    S->max_stack_size = max;
    S->top = -1;
    return S;
}

void Push(Stack* S, int X){
    if(IsFull(S)){
        return;
    }
    S->stack_space[++S->top] = X;
}

int Pop(Stack* S){
    if(IsEmpty(S)){
        return -1;
    }
    return S->stack_space[S->top--];
}

void DeleteStack(Stack* S){
    free(S->stack_space);
    free(S);
}

bool IsEmpty(Stack* S){
    return S->top == -1;
}
bool IsFull(Stack* S){
    return S->top == S->max_stack_size - 1;
}

int is_ascending(int *arr, int size) {
    int i, val;
    val = arr[0];
    for(i = 1; i < size; ++i) {
        if(val > arr[i]) return 0;
        val = arr[i];
    }
    return 1;
}

int main()
{
    int N; // [1, 1000]
    scanf("%d", &N);

    Stack* S = Initstack(N);
    for(int i = 0; i < N; i++)
    {
        int X;
        scanf("%d", &X);
        Push(S, X);
    }

    Stack* temp = Initstack(N);
    int val = 1;    //  1 ~ N 순서대로
    while(!IsEmpty(S))
    {
        if(S->stack_space[S->top] == val)
        {
            Pop(S);
            val++;
        }
        else
            Push(temp, Pop(S));
    }

    while(!IsEmpty(temp))
    {
        if(temp->stack_space[temp->top] == val)
        {
            Pop(temp);
            val++;
        }
        else
            break;
    }
    return 0;
}