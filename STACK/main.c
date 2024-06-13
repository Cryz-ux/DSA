#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

#define MAX 100 // Maximum size of the stack


// Test the stack implementation
int main() {
    StackArrayList s = createStack();

    // Push items onto the stack
    int items_to_push[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < sizeof(items_to_push) / sizeof(items_to_push[0]); i++) {
        if (stack_push(&s, items_to_push[i])) {
            printf("Pushed %d onto the stack\n", items_to_push[i]);
        } else {
            printf("Failed to push %d onto the stack\n", items_to_push[i]);
        }
    }

    // Display the stack
    printf("Displaying stack:\n");
    display(s);

    // Visualize the stack
    printf("Visualizing stack:\n");
    visualize(s);

    return 0;
}

