#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

FILE *write_to_file(FILE **file)
{
  static int count = 0;

  char buffer[23];
  char *message = NULL;

  strcpy(buffer,"write-to-file-> ");

  message = buffer;

  if((*file = fopen("data.txt", "w+")) == NULL)
  {
    exit(EXIT_FAILURE);
  }

  fprintf(*file, "%s", message);
}

void enqueue_data(struct node **queue, int value)
{
  struct node *new_node = NULL;

  if((new_node = malloc(sizeof(struct node))) == NULL)
    exit(EXIT_FAILURE);

  /* An alternate way of accessing struct values */
  (*new_node).data = value;
  (*new_node).next = *queue;

  *queue = new_node;
}

void enqueue_email(struct node **queue, FILE *file)
{
  char item[30];
  struct node *new_node = NULL;

  if((file = fopen("email", "r")) == NULL)
    printf("Error Opening File");

  printf("FILE is OPEN and WORKING\n");

  while (fscanf(file, "%s", item) != EOF)
  {
    if((new_node = malloc(sizeof(struct node))) == NULL)
    {
      exit(EXIT_FAILURE);
    }

    strcpy(new_node->email, item);

    new_node->next = *queue;

    *queue = new_node;
  }

  fclose(file);
}

struct node *delete_node(struct node *queue, int n)
{
  struct node *current = NULL, *previous = NULL;

  for(current = queue, previous; current != NULL && current->data != n; previous = current, current = current->next)
    ;

  if(current == NULL)
    return queue;

  if(previous == NULL)
    queue = queue->next;
  else
    previous->next = current->next;

  free(current);
}

struct node *delete_email(struct node *queue, char *email)
{
  struct node *current = NULL, *previous = NULL;

  for(current = queue, previous; current != NULL && strcmp(current->email, email); previous = current, current = current->next)
    ;

  if(current == NULL)
    return queue;

  if(previous == NULL)
    queue = queue->next;
  else
    previous->next = current->next;

  free(current);
}

void dequeue(struct node *queue)
{}

void display_email(struct node *queue)
{
  struct node *p = NULL;
  for (p = queue; p != NULL; p = p->next)
  {
    printf("-> %s\n", p->email);
  }
}

void display_data(struct node *queue)
{
  struct node *p = NULL;

  for(p = queue; p != NULL; p = p->next)
  {
    printf("-> %d\n", p->data);
  }
}
