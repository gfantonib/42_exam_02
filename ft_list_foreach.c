// Assignment name  : ft_list_foreach
// Expected files   : ft_list_foreach.c, ft_list.h
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that takes a list and a function pointer, and applies this
// function to each element of the list.

// It must be declared as follows:

// void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

// The function pointed to by f will be used as follows:

// (*f)(list_ptr->data);

// You must use the following structure, and turn it in as a file called
// ft_list.h:

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;

#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------

// Define the structure
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;


// Function to create a new node
t_list *create_node(void *data) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

// Function to insert a node at the end of the list
void insert_end(t_list **head, void *data) {
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
        printf("%s ", (char *)current->data);
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

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *list_ptr = begin_list;

	while (list_ptr)
	{
		f(list_ptr->data);
		list_ptr = list_ptr->next;
	}

}

void	cmp(void *arg1)
{
	char *str = arg1;
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%c", str[i]+1);
		//str[i] = 'z';
		i++;
	}
	printf(" ");
	
}

// ----------------------------------------------------------------------------
int main() 
{
    t_list *list = NULL; // Initialize an empty list

    // Insert some elements into the list
    insert_end(&list, "aaa");
    insert_end(&list, "bbb");
    insert_end(&list, "ccc");
	insert_end(&list, "ddd");
	insert_end(&list, "eee");

    // Print the elements of the list
    printf("Linked List: ");
    print_list(list);
	ft_list_foreach(list, cmp);
	printf("\n");
	printf("For Each List: ");
    print_list(list);

    // Free the memory allocated for the list
    free_list(list);

    return 0;
}