#include <stdio.h>
#include <stdlib.h>

struct node
{
  int item;
  struct node *next;
};

int main(int argc, char **argv)
{
    struct node *head = NULL;
    if((head = malloc(sizeof(struct node))) == NULL)
      exit(EXIT_FAILURE);

    struct node *new_node = NULL;
    if((new_node = malloc(sizeof(struct node))) == NULL)
      exit(EXIT_FAILURE);

    (*new_node).item = 30;

    new_node->next = head;
    head = new_node;

    printf("new_node->item: %d\n", new_node->item);

  return 0;
}
