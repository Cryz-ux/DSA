#include <stdio.h>
#include "StackArray.h"

int main() {
    StackArrayList stack = createStack();

    stack_push(&stack, 10);
    stack_push(&stack, 20);
    stack_push(&stack, 30);

    display(stack);
    visualize(stack);

    printf("Top element is %d\n", stack_peek(stack));

    stack_pop(&stack);

    display(stack);
    visualize(stack);

    return 0;
}

