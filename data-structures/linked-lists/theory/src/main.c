#include <stdio.h>
#include <stdlib.h>

/* This is a simple example of a linked list
 * it adds one node to the list and assigns a
 * value to the "item" variable.
 * */

struct node
{
  int item;
  struct node *next;
};

/* add a new node by reference */
static struct node *add_node(struct node **list, int value)
{
    struct node *new_node = NULL;

    if((new_node = malloc(sizeof(struct node))) == NULL)
    {
      exit(EXIT_FAILURE);
    }

    new_node->item = value;
    new_node->next = *list;
    *list = new_node;
}

int main(int argc, char **argv)
{
    struct node *head = NULL;
    if((head = malloc(sizeof(struct node))) == NULL)
      exit(EXIT_FAILURE);

    struct node *new_node = NULL;
    if((new_node = malloc(sizeof(struct node))) == NULL)
      exit(EXIT_FAILURE);

    add_node(&head, 2);

    /*
    (*new_node).item = 30;

    new_node->next = head;
    head = new_node;
    */

    printf("new_node->item: %d\n", head->item);

    add_node(&head, 20);
    printf("new_node->item: %d\n", head->item);

  return 0;
}
