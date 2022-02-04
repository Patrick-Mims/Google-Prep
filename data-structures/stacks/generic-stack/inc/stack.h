#ifndef STACK_H
#define STACK_H

struct stackNode
{
    int data;
    struct stackNode *nextPtr;
};

void display(struct stackNode *top)
{
    if (top != NULL)
    {
        while (top != NULL)
        {
            printf("-> %d\n", top->data);
            top = top->nextPtr;
        }
    }
    else
    {
        printf("Empty Stack");
    }
}

void push(struct stackNode **stackTop, int value)
{
    struct stackNode *newNode = NULL;

    if ((newNode = malloc(sizeof(struct stackNode))) == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->nextPtr = *stackTop;
    *stackTop = newNode;
}

/* passing a double pointer allows the list to be returned after the pop */
void pop(struct stackNode **top)
{
    struct stackNode *ptr = *top;
    printf("Element Removed From the Stack->[%d]\n", ptr->data);
    ptr = ptr->nextPtr;
    *top = ptr;
}

int isEmpty(struct stackNode *top)
{
    return top == NULL;
}

/*
 * isEmpty()
 * */

#endif

/* VSC Theme: Fodder Contrast (rainbow) */