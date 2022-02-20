#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

void msg_debug(int *msg)
{
    printf("value-> [%d]\n", *msg);
    *msg = 33;
}

void msg_debug_cstring(char *msg)
{
    printf("value-> [%s]\n", msg);
    strcpy(msg, "whitewoman");
}

int main(int main, char **argv)
{
  FILE *fp, *w_t_f = NULL;
  int value = 0;
  struct node *head = NULL;

  if((head = malloc(sizeof(struct node))) == NULL)
    exit(EXIT_FAILURE);

  printf("mailslurp\n");

  enqueue_data(&head, 300);
  enqueue_data(&head, 400);
  enqueue_data(&head, 500);
  enqueue_data(&head, 600);
  enqueue_data(&head, 700);
  enqueue_data(&head, 800);
  enqueue_data(&head, 900);
  enqueue_data(&head, 1000);
  display_data(head);

  /* showing the use of delete_node */
  delete_node(head, 400);
  display_data(head);

  printf("Value: ");
  scanf("%d", &value);

  msg_debug(&value);

  printf("New Value Son-> ");
  msg_debug(&value);

  //printf("value->[ %d ]", value);

  /* showing the use of delete_node */
  delete_node(head, 500);
  display_data(head);

  enqueue_email(&head, fp);
  display_email(head);

  delete_email(head, "lulu28@hotmail.com");
  display_email(head);

  delete_email(head, "pmurray@cassin.com");
  display_email(head);

  char emailaddress[30];
  char *ea = NULL;
  ea = emailaddress;
  printf("Search for an email address: ");
  scanf("%s", ea);

  printf("%s\n", emailaddress);

  msg_debug_cstring(emailaddress);
  printf("After-> ");
  msg_debug_cstring(emailaddress);

  printf("Done!\n");

  write_to_file(&w_t_f);

  //display_email(head);

  return 0;
}
