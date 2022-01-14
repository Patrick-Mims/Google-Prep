#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

struct node
{
  char email[SIZE];
  struct node *next;
};
static struct node *display(struct node *list)
{
  struct node *p = NULL;

  for (p = list; p != NULL; p = p->next)
  {
    printf("%s\n", p->email);
  }
}
static struct node *insert(struct node **list, const char *value)
{
  struct node *new_node = NULL;

  if ((new_node = malloc(sizeof(struct node))) == NULL)
    exit(EXIT_FAILURE);

  strcpy(new_node->email, value);

  new_node->next = *list;

  *list = new_node;
}

int main(int argc, char **argv)
{
  char address[SIZE] = {0};
  char name[SIZE] = "patrickkevinmims@gmail.com";

  struct node *head = NULL;
  if ((head = malloc(sizeof(struct node))) == NULL)
    exit(EXIT_FAILURE);

  FILE *fp;

  if ((fp = fopen("email_addresses-10.txt", "r")) == NULL)
  {
    fprintf(stderr, "Could not open file");
    exit(EXIT_FAILURE);
  }

  while (fscanf(fp, "%s", address) != EOF)
  {
    insert(&head, address);
  }

  fclose(fp);

  display(head);

  return 0;
}