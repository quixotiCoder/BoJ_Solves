// BoJ q_2839
// theme : brute force

#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int cnt_case1 = 9999, cnt_case2 = 9999, cnt_case3 = 9999;

    // only divide by five
    if (N % 5 == 0)
        cnt_case1 = N / 5;

    // only divide by three
    if (N % 3 == 0)
        cnt_case2 = N / 3;

    // divide by both five & three
    for (int i = 0; i <= N / 5; i++) {
        int remainder = N - i * 5;
        if (remainder % 3 == 0) {
            int total_bags = i + remainder / 3;
            if (total_bags < cnt_case3) {
                cnt_case3 = total_bags;
            }
        }
    }

    int min_bags = (cnt_case1 < cnt_case2) ? cnt_case1 : cnt_case2;
    min_bags = min_bags < cnt_case3 ? min_bags : cnt_case3;

    if (min_bags == 9999) {
        min_bags = -1;
    }

    printf("%d", min_bags);

    return 0;
}
