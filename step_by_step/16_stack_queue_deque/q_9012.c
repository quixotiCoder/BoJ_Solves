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
int IsVPS(Stack *S);

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

int IsVPS(Stack *S)
{
    return (S->key[S->top] == '(');
}

int main()
{
    int T;
    scanf("%d" ,&T);

    for(int i = 0; i < T; i++)
    {
        char str[51];
        scanf("%s", &str);
        int len = strlen(str);
        int check_VPS = 1;

        Stack* stack = CreateStack(len);

        for(int j = 0; j < len; j++)
        {
            if(str[j] == '(')
                Push(stack, '(');
 
            else if(str[j] == ')')
            {
                if(IsVPS(stack))
                    Pop(stack);

                else
                    check_VPS = 0;    
            }       
        }

        if(check_VPS)
        {
            if(stack->top == -1)
                printf("YES\n"); // ------------- 출력 조건 확인...ㅠ [대/소문자]
        
            else
                printf("NO\n");
        }
        else
            printf("NO\n");

        free(stack->key);
        free(stack);
    }

    return 0;
}
