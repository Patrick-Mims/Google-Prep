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

/* delete()
 * display()
 * insert()
 * search()
 * update()
 * */

static struct node *display(struct node *list)
{
  struct node *d = NULL;
  d = list;

  printf("-> %d\n", d->item);
}

static struct node *insert(struct node **list, int value)
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
  int value = 0;
  struct node *head = NULL;

  if((head = malloc(sizeof(struct node))) == NULL)
    exit(EXIT_FAILURE);

  insert(&head, 2);
  display(head);

  insert(&head, 20);
  display(head);

  printf("Insert: ");
  scanf("%d", &value);

  printf("You entered: %d\n", value);

  return 0;
}
