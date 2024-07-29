// BoJ 1181
// theme : sorting

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *str1 = *(char **)a;
    char *str2 = *(char **)b;
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        return len1 - len2;    // 크면 swap 후, 뒤로
    }
    return strcmp(str1, str2); // 같으면 '0'으로 생략
}

int main() {
    int N;
    scanf("%d", &N);

    char **str = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) 
    {
        str[i] = (char *)malloc(51 * sizeof(char));
        scanf("%s", str[i]);
    }

    qsort(str, N, sizeof(char *), compare);

    // 중복 제거
    for (int i = 0; i < N; i++) {
        if (i == 0 || strcmp(str[i], str[i - 1]) != 0) {
            printf("%s\n", str[i]);
        }
    }

    // 메모리 해제
    for (int i = 0; i < N; i++) {
        free(str[i]);
    }
    free(str);

    return 0;
}
