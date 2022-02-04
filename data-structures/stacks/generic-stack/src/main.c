#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int main(int argc, char **argv)
{
  struct stackNode *top = NULL;

  int count = 0, num = 0;

  do
  {
    printf("Enter an integer: ");
    scanf("%d", &num);
    push(&top, num);
    count = count + 1;
  } while (count <= 3);

  display(top);

  /* pop off the stack */
  do
  {
    printf("Top of the new stack-> %d\n", top->data);
    pop(&top);
  } while (!isEmpty(top));

  return 0;
}

/* The difference between stacks and linked lists is that insertions
 *  and deletions may occur anywhere in the Linked List, but only at the
 *  top of the Stack.
 * */