#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int main(int argc, char **argv)
{
  char address[40];

  struct node *top = NULL;

  FILE *fp = NULL;

  if((fp = fopen("emails.txt","r")) == NULL)
  {
    printf("Error File Not Found\n");
    exit(EXIT_FAILURE);
  }

  while (fscanf(fp, "%s", address) != EOF)
  {
    push(&top, address);
  }

  while(!isEmpty(top))
  {
    pop(&top);
    display(top);
  }

  return 0;
}
