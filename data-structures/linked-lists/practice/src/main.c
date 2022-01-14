#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

struct node
{
  char email[SIZE];
  struct node *next;
};

struct node *insert(struct node **list, const char *value)
{
  struct node *new_node = NULL;

  if ((new_node = malloc(sizeof(struct node))) == NULL)
    exit(EXIT_FAILURE);

  strcpy(new_node->email, value);
  printf("Email Address: %s\n", new_node->email);
}

int main(int argc, char **argv)
{
  char name[SIZE] = "patrickkevinmims@gmail.com";

  struct node *head = NULL;
  if ((head = malloc(sizeof(struct node))) == NULL)
    exit(EXIT_FAILURE);

  insert(&head, name);

  FILE *fp = NULL;

  if (fp = fopen("email_addresses-10.txt", "r") == NULL)
  {
    fprintf(stderr, "could not open file", error_log.txt);
    exit(EXIT_FAILURE);
  }

  fclose(fp);

  return 0;
}
