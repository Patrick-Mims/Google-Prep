#ifndef MS_H
#define MS_H

struct node
{
  char email[25];
  int data;
  struct node *next;
};

struct node *delete_data(struct node *, int);
struct node *delete_email(struct node *, char *);
void dequeue(struct node *);
void display_data(struct node *);
void display_email(struct node *);
void enqueue_data(struct node **, int);
void enqueue_email(struct node **, FILE *);

#endif
