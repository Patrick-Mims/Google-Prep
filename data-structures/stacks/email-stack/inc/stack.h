#ifndef STACK_H
#define STACK_H

#define SIZE 40

struct node
{
  char item[SIZE];
  char address[40];
  struct node *next;
};

void display(struct node *top)
{
  while (top != NULL)
  {
    printf("stack->[%s]\n", top->item);
    top = top->next;
  }
}

void push(struct node **top, char *address)
{
  struct node *newNode = NULL;

  if((newNode = malloc(sizeof(struct node))) == NULL)
    exit(EXIT_FAILURE);

  strcpy(newNode->item, address);
  newNode->next = *top;

  *top = newNode;
}

void pop(struct node **top)
{
  struct node *ptr = *top;

  printf("\tElement Popped Stack-> %s \n", ptr->item);

  ptr = ptr->next;

  *top = ptr;
}

int isEmpty(struct node *top)
{
    return top == NULL;
}

/*
 * isEmpty()
 * topEl()
 * clear()
 * */

#endif
