#include <stdio.h>
#include <stdlib.h>
typedef int elem;

int stack_top = -1;
int stack_size = 0;
elem *stack;

int size(void)
{
    //스택의 현재 사이즈를 반환
    return stack_top+1;
}

int empty(void)
{
    if (size() == 0)
        return 1; //empty
    else
        return 0; //not empty
}

int full(void)
{
    if (stack_top >= stack_size-1)
        return 1;
    return 0;
}

void push(elem item)
{
    //스택에 데이터 추가
    if (full()==1)
        printf("Stack is full!\n");
    else
    {
        stack[++stack_top] = item;
    }
}

elem pop(void)
{
    //스택의 top에 위치한 데이터 삭제 및 반환
    int top = stack[stack_top];
    if (empty()==1)
    {
        printf("Stack is empty!\n");
        stack_top = -1 ;
        
    }
    else
        stack_top--;
    return top;
}

elem top(void)
{
    //스택의 top에 위치한 데이터 반환
    if (empty()==1){
        printf("Stack is empty!\n");
        stack_top = -1;
    }
    return stack[stack_top];
        
}

void print(void)
{
    //스택 원소 모두 출력
    int i;
    for (i=0; i<=stack_top; i++)
        printf("%d ",stack[i]);
    printf(" \n");
}

int main(void)
{
    int action = 0;
    elem newElem = 0;
    printf("Size of stack: ");
    scanf("%d", &stack_size);
    rewind(stdin);
    // dynamic allocation
    stack = (elem*)malloc(sizeof(elem)*stack_size);
    
    while(1)
    {
        printf("Choose action: \n");
        printf("1: push(), 2: pop(), 3: top(), 4: size(), 5: empty(), 6: end\n");
        scanf("%d", &action);
        rewind(stdin);
        
        switch(action)
        {
        case 1:
            printf("Element to push: ");
            scanf("%d", &newElem);
            rewind(stdin);
            push(newElem);
            print();
            break;
        case 2:
            printf("pop(): %d\n", pop());
            print();
            break;
        case 3:
            printf("top(): %d\n", top());
            print();
            break;
        case 4:
            printf("size(): %d\n", size());
            print();
            break;
        case 5:
            printf("empty(): %d\n", empty());
            print();
            break;
        case 6:
            printf("End the program\n");
            exit(0);
        default:
            printf("Wrong option: %d\n", action);
        }
    }
    return 0;
}
