#include <stdio.h>

int main()
{
    int fir, sec;
    scanf("%d", &fir);
    scanf("%d", &sec);

    int thi, fou, fif, six;

    thi = fir * (sec%10);
    fou = fir * ((sec%100)/10);
    fif = fir * (sec/100);

    six = fir * sec;

    printf("%d\n", thi);
    printf("%d\n", fou);
    printf("%d\n", fif);
    printf("%d", six);
}