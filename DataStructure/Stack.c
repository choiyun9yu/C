#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100    // C언어에서 사용되는 전처리 지시문 중 특정 토큰 또는 코드 조각에 대해 매크로를 정의하는데 사용된다. (상수 만들었다고 생각하면 편함)

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// 스택 초기화
void initialize(Stack* stack) {    // 포인터(*): Stack이라는 구조체의 인스턴스를 가리키는 stack이라는 포인터
    stack->top = -1;        // 멤버 접근 연산자(->): stack이 가리키는 구조체의 top멤버에 접근 
}

// 스택이 비어있는지 확인
int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// 스택이 가득 찾는지 확인
int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE -1);
}

// 스택에 데이터 추가 (push)
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("스택이 가득 찼습니다.\n");
    } else {
        stack->items[++stack->top] = value;
        printf("%d이(가) 스택에 추가되었습니다.\n", value);
    }
}

// 스택에서 데이터 제거 (pop)
int pop(Stack* stack) {
    if(isEmpty(stack)) {
        printf("스택이 비어 있습니다.\n");
        return -1;    // 임의의 값 반환
    } else {
        int popped = stack->items[stack->top--];
        printf("%d이(가) 스택에서 제거되었습니다.\n", popped);
        return popped;
    }
}

// 스택의 맨 위 데이터 반환 (peek)
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어 있습니다.\n");
        return -1;    // 임의의 값 반환
    } else {
        return stack->items[stack->top];
    }
 }


// 스택 출력
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어 있습니다.\n");
    } else {
        printf("현재 스택: " );
        for (int i=0; i <= stack->top; i++) {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
     }
}

int main() {
    Stack myStack;
    initialize(&myStack);    // &myStack은 구조체 변수 myStack의 주소를 의미

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    display(&myStack);

    pop(&myStack);
    display(&myStack);

    printf("맨 위의 데이터: %d\n", peek(&myStack));   

    return 0;
}

