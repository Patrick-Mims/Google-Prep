#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDEX_SIZE 30

struct node
{
  char email[INDEX_SIZE];
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

static struct node *delete_node(struct node *list, char *email)
{
  /*
   1. Locate the node to be deleted.
   2. Alter the previous node so that it "bypasses" the deleted node.
   3. Call free to reclaim the space occupied by the deleted node.
  */

  struct node *current = NULL,
              *previous = NULL;

  for(current = list; previous = NULL; current != NULL, current = current->next)
  {
    /* the problem is here...*/
    if(strcmp(current->email, email) != 0)
    {
       previous = current;
       current = current->next;
    }
    /*
       && strcmp(current->email, email) != 0;
       previous = current, current = current->next)
       ;
       */
  }

  if(current == NULL)
  {
    return list;
  }

  if(previous == NULL)
  {
    list = list->next;
  } else {
    previous->next = current->next;
  }

//  free(current);

  return list;
}

static struct node *search_list(struct node *list, char *address)
{
  int ret;
  struct node *p = NULL;
  for (p = list; p != NULL; p = p->next)
  {
    if (ret = strcmp(p->email, address) == 0)
      return p;
  }
}

static struct node *insert_node(struct node **list, const char *value)
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
  char address[INDEX_SIZE] = "";
  char str[INDEX_SIZE];

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
    insert_node(&head, address);
  }

  fclose(fp);

  display(head);

  struct node *searched_object = NULL;

  searched_object = search_list(head, "qkuhn@hotmail.com");

  printf("NEW Returned object -> %s\n", searched_object->email);

  printf("Delete an Address: ");

  scanf("%s", str);

  printf("This is the value you're going to delete: %s\n", str);

  display(head);

  delete_node(head, str);

  display(head);

  free(head);

  return 0;
}

/*
lulu28@hotmail.com
qkuhn@hotmail.com
prosacco.mollie@towne.com
stehr.annie@gmail.com
roman.ferry@bechtelar.com
jimmy72@gmail.com
pmurray@cassin.com
auer.fern@willms.com
pdubuque@ebert.com
oklein@vonrueden.info
*/
