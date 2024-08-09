// BoJ 28279
// theme : stack_queue_deque

#include <stdio.h>
#include <stdlib.h>

typedef struct _DequeNode DequeNode;

struct _DequeNode{ // linked-list 형태 for node
    DequeNode* next;
	DequeNode* prev; 
    int data; // 값 저장
};

typedef struct { // 위의 node들을 묶은 Queue == FIFO 
	DequeNode* front; // 가장 먼저 dequeue할 node 가리킴
	DequeNode* rear; // 가장 최근 enqueue된 node 가리킴
	int size; // en/dequeue마다 갱신 -> 나중에 graph의 총 개수와 비굣
} Deque;

Deque* CreateDeque() {
	Deque* deque = (Deque*)malloc(sizeof(Deque));
	if(deque == NULL)
		return NULL;

	deque->front = NULL;	
	deque->rear = NULL;
	deque->size = 0;

	return deque;	
}

//	--- --- functions --- ---
void InsertFront(Deque* d, int X);
void InsertRear(Deque* d, int X);
int PopFront(Deque* d);
int PopRear(Deque* d);
int SizeOfDeque(Deque* d);
int IsEmpty(Deque* d);
int PeekFront(Deque* d);
int PeekRear(Deque* d);

// # funct 1
void InsertFront(Deque* d, int X) {
	DequeNode* NewFrontNode = (DequeNode*)malloc(sizeof(DequeNode));
	if(NewFrontNode == NULL)
		return;

	if(IsEmpty(d)) {
		NewFrontNode->data = X;
		NewFrontNode->next = NULL;
		NewFrontNode->prev = NULL;
		d->front = NewFrontNode;
		d->rear = NewFrontNode;
	}
	else {
		NewFrontNode->data = X;
		NewFrontNode->next = d->front;
		NewFrontNode->prev = d->front->prev;
		d->front->prev = NewFrontNode;
		d->front = NewFrontNode;
	}	
	d->size++;
}
// # funct 2
void InsertRear(Deque* d, int X) {
	DequeNode* NewRearNode = (DequeNode*)malloc(sizeof(DequeNode));
	if(NewRearNode == NULL)
		return;

	if(IsEmpty(d)) {
		NewRearNode->data = X;
		NewRearNode->next = NULL;
		NewRearNode->prev = NULL;
		d->front = NewRearNode;
		d->rear = NewRearNode;
	}
	else {
		NewRearNode->data = X;
		NewRearNode->next = d->rear->next;
		NewRearNode->prev = d->rear;
		d->rear->next = NewRearNode;
		d->rear = NewRearNode;
	}
	d->size++;
}
// # funct 3
int PopFront(Deque* d) {
    if (IsEmpty(d))
        return -1;

    int temp = d->front->data;
    DequeNode* oldFront = d->front;

    if (d->front == d->rear) { // only 1 node
        d->front = NULL;
        d->rear = NULL;
    } else {
        d->front = d->front->next;
        d->front->prev = NULL;
    }

    free(oldFront);
    d->size--;
    return temp;
}

// # funct 4
int PopRear(Deque* d) {
    if (IsEmpty(d))
        return -1;

    int temp = d->rear->data;
    DequeNode* oldRear = d->rear;

    if (d->front == d->rear) { // only 1 node
        d->front = NULL;
        d->rear = NULL;
    } else {
        d->rear = d->rear->prev;
        d->rear->next = NULL;
    }

    free(oldRear);
    d->size--;
    return temp;
}
// # funct 5
int SizeOfDeque(Deque* d) {
	return d->size;
}
// # funct 6
int IsEmpty(Deque* d) {
	return (d->size == 0);
}
// # funct 7
int PeekFront(Deque* d) {
	if(IsEmpty(d))
		return -1;
	else {
		int temp = d->front->data;
		return temp;
	}
}
// # funct 8
int PeekRear(Deque* d) {
	if(IsEmpty(d))
		return -1;
	else {
		int temp = d->rear->data;
		return temp;
	}
}

int main(){
	Deque* deque = CreateDeque();

	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		int instruction, X;
        scanf("%d", &instruction);

        switch(instruction)
        {
            case 1:
                scanf("%d", &X);
                InsertFront(deque, X);
                break;
            case 2:
                scanf("%d", &X);
                InsertRear(deque, X);
                break;
            case 3:
                printf("%d\n", PopFront(deque));
                break;
            case 4:
                printf("%d\n", PopRear(deque));
                break;
            case 5:
                printf("%d\n", SizeOfDeque(deque));
                break;
			case 6:
                printf("%d\n", IsEmpty(deque));
                break;
			case 7:
                printf("%d\n", PeekFront(deque));
                break;
			case 8:
                printf("%d\n", PeekRear(deque));
                break;		
        }
	}

	free(deque);
	return 0;
}