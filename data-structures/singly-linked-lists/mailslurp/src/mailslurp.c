#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

int main(int main, char **argv)
{
  FILE *fp;
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

  /* showing the use of delete_data */
  delete_data(head, 400);
  display_data(head);

  /* showing the use of delete_data */
  delete_data(head, 500);
  display_data(head);

  enqueue_email(&head, fp);
  display_email(head);

  delete_email(head, "lulu28@hotmail.com");
  display_email(head);

  delete_email(head, "pmurray@cassin.com");
  display_email(head);

  printf("Enter a new email address: ");


  //display_email(head);

  return 0;
}
