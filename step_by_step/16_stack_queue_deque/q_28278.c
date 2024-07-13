#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
	int *key; // 실질적 스택 배열
	int top; // top 위치 저장
	int max_stack_size; // 스택의 max_size 저장 to check full
}Stack;

Stack* CreateStack(int max);

void Push(Stack* S, int X); // '1'
void Pop(Stack* S); // '2'
void Stack_Size(Stack* S); // '3'
int Is_Full_Or_Empty(Stack* S); // '4'
void Top(Stack* S); // '5'

Stack* CreateStack(int max)
{
    Stack* S = (Stack*)malloc(sizeof(Stack)); // malloc으로 Stack 포인터 S 할당
    
	if(S == NULL) // malloc으로 메모리 할당 실패한 case 처리
		return -1;
	
	S->key = (int*)malloc(max * sizeof(int)); // S->key 를 max 크기의 int array pointer 할당 (malloc)
    S->max_stack_size = max; // S->max_stack_size 설정
    S->top = -1;// S->top 을 -1로 설정

    return S; // S 반환
}

void Push(Stack *S, int X) // '1'
{
    S->key[++S->top] = X;
}

void Pop(Stack *S) // '2'
{
    if(Is_Full_Or_Empty(S))
        printf("-1\n");

    else 
        printf("%d\n", S->key[S->top--]);
}

void Stack_Size(Stack* S) // '3'
{
    printf("%d\n", S->top + 1);
}

int Is_Full_Or_Empty(Stack* S) // '4'
{
    if(S->top == -1) // empty
        return 1; // '4'에서 변수로 받아 출력 || return 값으로 다른 함수에서 사용
    else
        return 0;
}

void Top(Stack* S) // '5'
{
    if(Is_Full_Or_Empty(S))
        printf("-1\n");

    else 
        printf("%d\n", S->key[S->top]);
}

int main()
{
    Stack* stack;
	int N;
	int max = 1000001;

	stack = CreateStack(max);

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int instruction, X;
        scanf("%d", &instruction);

        switch(instruction)
        {
            case 1:
                scanf("%d", &X);
                Push(stack, X);
                break;
            case 2:
                Pop(stack);
                break;
            case 3:
                Stack_Size(stack);
                break;
            case 4:
                printf("%d\n", Is_Full_Or_Empty(stack));
                break;
            case 5:
                Top(stack);
                break;
        }
    }

    free(stack->key);
    free(stack);
    return 0;
}