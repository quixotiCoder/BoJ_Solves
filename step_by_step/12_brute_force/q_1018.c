// BoJ q_1018
// theme : brute force

#include <stdio.h>

int min_repaints(int x, int y, char board[50][50], char first_color) {
    int repaints = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char expected_color = ((i + j) % 2 == 0) ? first_color : (first_color == 'W' ? 'B' : 'W');
            if (board[x + i][y + j] != expected_color) {
                repaints++;
            }
        }
    }
    return repaints;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M); // [N : row, M : column] 의 수

    char board[50][50] = {0, };

    for(int i = 0; i < N; i++)
        scanf("%s", board[i]);
    
    int max_count = 64; // 8 * 8 체스판의 최대 칠해야 하는 칸의 수

    for(int i = 0; i <= N - 8; i++)
    {
        for(int j = 0; j <= M - 8; j++)
        {
            int repaints_w = min_repaints(i, j, board, 'W');
            int repaints_b = min_repaints(i, j, board, 'B');
            int min_repaints_for_8x8 = (repaints_w < repaints_b) ? repaints_w : repaints_b;
            if (min_repaints_for_8x8 < max_count)
                max_count = min_repaints_for_8x8;
        }
    }

    printf("%d", max_count);

    return 0;
    
}