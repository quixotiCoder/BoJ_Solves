// BoJ q_1018
// theme : brute force

#include <stdio.h>

int main(){
    int N, M;   //  8 ~ 50
    scanf("%d %d", &M, &N); // M : 행의 수, N : 열의 수

    char board[50][51] = {0, }; // default: '0' == 공백
    for(int i = 0; i < M; i++)  // 행 단위
        scanf("%s", board[i]);  // 'W' | 'B' 입력받기
    
    char standard_color = board[0][0]; // 첫 번째 칸의 색

    int total_count = 65;

    for(int i = 0; i < M - 7; i++) {
        for(int j = 0; j < N - 7; j++) {
            int temp_count = 0;

            // 내부 8*8이기에 짝/홀에 색 결정
            for(int k = i; k < i + 8; k++) {
                for(int l = j; l < j + 8; l++) {
                    if((k + l) % 2 == 0)    // 짝수
                    {  
                        if(board[k][l] != standard_color)
                            temp_count++;
                    } 
                    else                    // 홀수
                    {    
                        if(board[k][l] == standard_color)
                            temp_count++;
                    }
                }
            }

            if(total_count > temp_count)
                total_count = temp_count;
        }
    }
    printf("%d", total_count);

    return 0;
}