#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
	int *key; // 실질적 스택 배열
	int top; // top 위치 저장
	int max_stack_size; // 스택의 max_size 저장 to check full
}Stack;

Stack* CreateStack(int max);

bool IsFull(Stack *S);
bool IsEmpty(Stack *S);

void Push(Stack* S, int X); 
void delete_top(Stack* S); 
int Pop(Stack *S) ;

Stack* CreateStack(int max)
{
    Stack* S = (Stack*)malloc(sizeof(Stack)); // malloc으로 Stack 포인터 S 할당
    
	if(S == NULL) // malloc으로 메모리 할당 실패한 case 처리
		exit(1);
	
	S->key = (int*)malloc(max * sizeof(int)); // S->key 를 max 크기의 int array pointer 할당 (malloc)
    S->max_stack_size = max; // S->max_stack_size 설정
    S->top = -1;// S->top 을 -1로 설정

    return S; // S 반환
}

bool IsFull(Stack* S){
	return (S->top == S->max_stack_size - 1); // index는 '0'부터 시작이기에, 'S->max_stack_size - 1'로 full인 상태 확인 
}

bool IsEmpty(Stack* S){
	return (S->top == -1); // stack이 빈 상태인 'S->top == -1' 조건 확인
}

void Push(Stack *S, int X) 
{
    if(IsFull(S))
        exit(1);

    S->key[++S->top] = X;
}

void delete_top(Stack *S) 
{
    if(IsEmpty(S))
        exit(1);

    S->top--; // 다음 input에 자동으로 값은 덮어쓰임
}

int Pop(Stack *S) 
{
    if(IsEmpty(S))
        return -1;

    return S->key[S->top--];
}

int main()
{
    Stack* stack;
    int K, sum = 0;

    scanf("%d", &K);

	stack = CreateStack(K);

    for (int i = 0; i < K; i++)
    {
        int input;
        scanf("%d", &input);

        if(input == 0)
            delete_top(stack);

        else
            Push(stack, input);
    }
    
    while (stack->top > -1)
    {
        int temp;
        temp = Pop(stack);
        sum += temp;
    }
    
    printf("%d", sum);
    
    free(stack->key);
    free(stack);
    return 0;
}