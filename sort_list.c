// Assignment name  : sort_list
// Expected files   : sort_list.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following functions:

// t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

// This function must sort the list given as a parameter, using the function
// pointer cmp to select the order to apply, and returns a pointer to the
// first element of the sorted list.

// Duplications must remain.

// Inputs will always be consistent.

// You must use the type t_list described in the file list.h
// that is provided to you. You must include that file
// (#include "list.h"), but you must not turn it in. We will use our own
// to compile your assignment.

// Functions passed as cmp will always return a value different from
// 0 if a and b are in the right order, 0 otherwise.

// For example, the following function used as cmp will sort the list
// in ascending order:

// int ascending(int a, int b)
// {
// 	return (a <= b);
// }

#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------
// Define the structure
typedef struct s_list t_list;
struct s_list {
    int data;
    t_list *next;
};

// Function to create a new node
t_list *create_node(int data) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

// Function to insert a node at the end of the list
void insert_end(t_list **head, int data) {
    t_list *new_node = create_node(data);
    if (new_node == NULL) {
        fprintf(stderr, "Failed to create a new node\n");
        exit(EXIT_FAILURE);
    }

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = new_node;
    } else {
        // Traverse the list to find the last node
        t_list *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Insert the new node at the end
        current->next = new_node;
    }
}

// Function to iterate through the list and print each element
void print_list(t_list *head) {
    t_list *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the list
void free_list(t_list *head) {
    t_list *current = head;
    t_list *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
// ----------------------------------------------------------------------------
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *tmp;
	int aux;
	

	tmp = lst;
	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			aux = lst->next->data;
			lst->next->data = lst->data;
			lst->data = aux;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);

}

int cmp(int a, int b)
{
	return (a <= b);
}

// ----------------------------------------------------------------------------
int main() {
    t_list *list = NULL; // Initialize an empty list

    // Insert some elements into the list
    insert_end(&list, 5);
    insert_end(&list, 4);
    insert_end(&list, 3);
	insert_end(&list, 2);
	insert_end(&list, 1);

    // Print the elements of the list
    printf("Linked List: ");
    print_list(list);
	list = sort_list(list, cmp);
	printf("Sorted List: ");
    print_list(list);

    // Free the memory allocated for the list
    free_list(list);

    return 0;
}