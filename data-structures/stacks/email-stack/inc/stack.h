#ifndef STACK_H
#define STACK_H

#define SIZE 40

struct node
{
  char item[SIZE];
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

void push(struct node **top, char *value)
{
  struct node *newNode = NULL;

  if((newNode = malloc(sizeof(struct node))) == NULL)
    exit(EXIT_FAILURE);

  strcpy(newNode->item, value);
  newNode->next = *top;

  *top = newNode;
}

#endif
