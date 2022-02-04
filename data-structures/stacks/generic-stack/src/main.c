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
    printf("Enter a number: ");
    scanf("%d", &num);
    push(&top, num);
    count = count + 1;
  } while (count <= 3);

  display(top);

  do
  {
    printf("Top of the new stack-> %d\n", top->data);
    pop(&top);
  } while (!isEmpty(top));

  /*
    pop(&top);

    printf("after pop(1) top->data ->%d\n", top->data);

    pop(&top);

    printf("after pop(2) top->data ->%d\n", top->data);

    pop(&top);
    */

  return 0;
}

/* The difference between stacks and linked lists is that insertions
 *  and deletions may occur anywhere in the Linked List, but only at the
 *  top of the Stack.
 * */
