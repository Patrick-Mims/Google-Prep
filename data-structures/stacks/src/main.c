#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 25

/*
 * void stack_init(Stack *stack, void(*destroy)(void *data));
 * void stack_destroy(Stack *stack);
 * int stack_push(Stack *stack, const void *data);
 * int stack_pop(Stack *stack, void **data);
 * void stack_peek(const Stack *stack);
 * int stack_size(const Stack *stack);
 * */

/* Structures are not permitted to contain instances of themselves,
 * but they can contain POINTERS of instances of themselves */
struct node
{
  void *data;
  char item[SIZE];
  int part_number;
  struct node *next;
};

int swap2(void *x, void *y, int size)
{
    void *tmp;

    if((tmp = malloc(size)) == NULL)
      return -1;
}

struct node *search_list(struct node *list, char *item)
{
  struct node *s = NULL;

  int ret;

  for(s = list; s != NULL; s = s->next)
  {
    ret = strcmp(s->item, item);
    if(ret == 0)
    {
      return s;
    }
  }
  return NULL;
}

void display(struct node *list)
{
  struct node *p = NULL;

  for(p = list; p != NULL; p = p->next)
  {
    printf("%s\n", p->item);
  }
}

struct node *head_insert(struct node **list, const char *desc)
{
  struct node *new_node = NULL;
  if((new_node = malloc(sizeof(struct node))) == NULL)
  {
    exit(EXIT_FAILURE);
  }

  strcpy(new_node->item, desc);
  new_node->next = *list;

  *list = new_node;
}

int main(int argc, char **argv)
{
  char address[SIZE];
  FILE *fp = NULL;
  struct node *head = NULL;

  if((head = malloc(sizeof(struct node))) == NULL)
  {
    printf("Could not allocate space for *head");
    exit(EXIT_FAILURE);
  }

  if((fp = fopen("email_addresses-1000.txt", "r")) == NULL)
  {
    printf("File not avail.");
    exit(EXIT_FAILURE);
  }

  while (fscanf(fp, "%s", address) != EOF)
  {
    head_insert(&head, address);
  }

  fclose(fp);

//display(head);

  struct node *r = search_list(head, "murazik.brendon@gmail.com");

  printf("Item found-> %s\n", r->item);

  return 0;
}
