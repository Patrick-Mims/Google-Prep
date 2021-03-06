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

/* pushing onto the stack, again using double pointer */
void push(struct stackNode **top, int value)
{
  // create a new node to insert
  struct stackNode *newNode = NULL;

  /* malloc memory for the new node*/
  if ((newNode = malloc(sizeof(struct stackNode))) == NULL)
  {
    exit(EXIT_FAILURE);
  }

  /* assign value to data */
  newNode->data = value;
  newNode->nextPtr = *top;

  /* return the pointer or address of the newNode */
  *top = newNode;
}

/* passing a double pointer allows the list to be returned after the pop */
void pop(struct stackNode **top)
{
  struct stackNode *ptr = *top;
  printf("\tElement Popped Stack->[%d]\n\n", ptr->data);
  ptr = ptr->nextPtr;
  *top = ptr;
}

int isEmpty(struct stackNode *top)
{
  return top == NULL;
}

#endif

/* VSC Theme: Fodder Contrast (rainbow) */
