#ifndef STACK_H
#define STACK_H

struct stackNode
{
    int data;
    struct stackNode *nextPtr;
};

void display(struct stackNode *stackTop)
{
    if (stackTop != NULL)
    {
        while (stackTop != NULL)
        {
            printf("-> %d\n", stackTop->data);
            stackTop = stackTop->nextPtr;
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

/*
 * isEmpty()
 * pop()
 * */

#endif
