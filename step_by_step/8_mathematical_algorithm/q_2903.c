#include <stdio.h>
#include <math.h>

int add_outer_node(int i);
int add_center_node(int i);
int add_shared_node(int outnode);

int add_outer_node(int i)
{
    return 4 * pow(2, i -1); // 각 변{4개 bc 사각형} * 기존 노드 "사이사이" {2^(i-1)}
}

int add_center_node(int i) 
{
    return pow(4, i - 1); // 새로 생기는 "사각형" 수 {4^(i-1)}
}

int add_shared_node(int outnode)
{
    return 2*(outnode - 1)*(outnode - 2); // 가로세로{2} * 내부의 한 변당 겹치는 점 수{n-1} * 내부 변의 수{n-2} 
}


int main()
{
    int N;
    scanf("%d", &N);

    int sum = 4;
    int outside_nodes = 2;

    for(int i = 1; i < N + 1; i++)
    {
        int outer = add_outer_node(i);
        int center = add_center_node(i);
        int shared = add_shared_node(outside_nodes);

        outside_nodes += outer / 4;

        sum += (outer + center + shared);
    }

    printf("%d", sum);

    return 0;    
}