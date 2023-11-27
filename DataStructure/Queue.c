#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 큐 초기화
void initialize(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// 큐가 비어 있는지 확인
int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

// 큐가 가득 찼는지 확인
int isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// 큐에 데이터 추가 (Enqueue)
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("큐가 가득 찼습니다. 더 이상 추가할 수 없습니다.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("%d이(가) 큐에 추가되었습니다.\n", value);
    }
}

// 큐에서 데이터 제거 (Dequeue)
int dequeue(Queue* queue) {
    int removed = -1; // 큐가 비어있을 경우의 기본값

    if (!isEmpty(queue)) {
        removed = queue->items[queue->front];

        if (queue->front == queue->rear) {
            // 큐에 마지막 요소를 제거한 경우
            initialize(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }

        printf("%d이(가) 큐에서 제거되었습니다.\n", removed);
    } else {
        printf("큐가 비어 있습니다. 더 이상 제거할 데이터가 없습니다.\n");
    }

    return removed;
}

// 큐의 맨 앞 데이터 확인 (Front)
int front(Queue* queue) {
    if (!isEmpty(queue)) {
        return queue->items[queue->front];
    } else {
        printf("큐가 비어 있습니다.\n");
        return -1; // 더미 값
    }
}

// 큐 출력
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("큐가 비어 있습니다.\n");
    } else {
        printf("현재 큐: ");
        int i = queue->front;
        while (i != queue->rear) {
            printf("%d ", queue->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue->items[i]);
    }
}

int main() {
    Queue myQueue;
    initialize(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    display(&myQueue);

    dequeue(&myQueue);
    display(&myQueue);

    printf("맨 앞의 데이터: %d\n", front(&myQueue));

    return 0;
}