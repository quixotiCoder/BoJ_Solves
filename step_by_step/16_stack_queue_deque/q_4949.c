// BoJ q_4949
// theme : stack_queue_deque

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
	int *key; // 실질적 스택 배열
	int top; // top 위치 저장
	int max_stack_size; // 스택의 max_size 저장 to check full
}Stack;

Stack* CreateStack(int max);

void Push(Stack* S, int X); 
void Pop(Stack *S);

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

void Push(Stack *S, int X) 
{
    S->key[++S->top] = X;
}

void Pop(Stack *S) 
{
    S->top--;
}

int main()
{
    while(1)
    {
        char str[102];
        fgets(str, 102, stdin);
        if(str[0] == '.')
            break;

        int len = strlen(str);
        Stack* stack = CreateStack(len);

        int check_VPS = 1;
        
        for(int i = 0; i < len; i++)
        {
            if(str[i] == '(' || str[i] == '[')
                Push(stack, str[i]);

            else if(str[i] == ')')
            {
                if(stack->top == -1 || stack->key[stack->top] != '(')
                {
                    check_VPS = 0;
                    break;
                }
                else
                    Pop(stack);
            }
            else if(str[i] == ']')
            {
                if(stack->top == -1 || stack->key[stack->top] != '[')
                {
                    check_VPS = 0;
                    break;
                }
                else
                    Pop(stack);
            }
        }
        if(check_VPS == 1 && stack->top == -1)
            printf("yes\n");
        else
            printf("no\n");
        
        free(stack->key);
        free(stack);    
    }
    
    return 0;
}
