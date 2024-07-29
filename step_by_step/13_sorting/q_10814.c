// BoJ 10814
// theme : sorting

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[101];
} client;

// stable sort : 버블 / 삽입 / 병렬 / 기수 / 카운팅

//      ###     Trial 1) Bubble sort 너무 느림
//      ###     Trial 2) Merge sort


void merge(client *Clients, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    client *L = (client*)malloc(sizeof(client) * n1);
    client *R = (client*)malloc(sizeof(client) * n2);

    for (int i = 0; i < n1; i++)
        L[i] = Clients[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = Clients[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].age <= R[j].age) {
            Clients[k] = L[i];
            i++;
        } else {
            Clients[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        Clients[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        Clients[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(client *Clients, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(Clients, left, mid);
        mergeSort(Clients, mid + 1, right);

        merge(Clients, left, mid, right);
    }
}

int main(){
    int N;
    scanf("%d", &N);

    client* Clients = (client*)malloc(sizeof(client) * N);

    for(int i = 0; i < N; i++)
        scanf("%d %s", &Clients[i].age, &Clients[i].name);

//  BubbleSort(Clients, N);
    mergeSort(Clients, 0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d %s\n", Clients[i].age, Clients[i].name);

    free(Clients);
    return 0;
}