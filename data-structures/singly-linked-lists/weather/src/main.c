#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "weather.h"

static struct node *display(struct node *list)
{
  printf("Display Function\n");
  struct node *d = NULL;

  int i = 0;

  for (d = list; d != NULL; d = d->next)
  {
    printf("%d.-> %s\n", i, d->date);
    i = i + 1;
  }
}

static struct node *insert(struct node **list, const char *value)
{
  printf("Insert\n");
  struct node *new_node = NULL;

  if((new_node = malloc(sizeof(struct node))) == NULL)
  {
    exit(EXIT_FAILURE);
  }

  strcpy(new_node->date, value);

  new_node->next = *list;

  *list = new_node;
}

static struct node *search(struct node *list, char *item)
{
  printf("Search Function\n");
  struct node *s = NULL;

  for(; list != NULL; list = list->next)
  {
    int ret;
    if (ret = strcmp(list->date, item) == 0)
    {
      return list;
    }
    return NULL;
  }
}

int main(int argc, char **argv)
{
  struct node *head = NULL;
  struct node *searched_object = NULL;
  char str[20];

  if((head = malloc(sizeof(struct node))) == NULL)
  {
    printf("No memory available\n");
    exit(EXIT_FAILURE);
  }

  printf("Enter a month: ");

  scanf("%s", str);

  printf("Month entered: %s\n", str);

  insert(&head, str);
  display(head);

  searched_object = search(head, str);

  printf("searched_object->date: %s\n", searched_object->date);

  printf("Item Found: %s\n", searched_object->date);

  return 0;
}
