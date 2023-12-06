// Assignment name  : ft_list_remove_if
// Expected files   : ft_list_remove_if.c
// Allowed functions: free
// --------------------------------------------------------------------------------

// Write a function called ft_list_remove_if that removes from the
// passed list any element the data of which is "equal" to the reference data.

// It will be declared as follows :

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// cmp takes two void* and returns 0 when both parameters are equal.

// You have to use the ft_list.h file, which will contain:

// $>cat ft_list.h
// typedef struct      s_list
// {
//     struct s_list   *next;
//     void            *data;
// }                   t_list;
// $>

#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------
// Define the structure
// typedef struct s_list t_list;
// struct s_list 
// {
//     int data;
//     t_list *next;
// };

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
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (*begin_list == NULL || begin_list == NULL)
		return ;

	t_list	*cur = *begin_list;	

	if ((*cmp)(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		cur = *begin_list;
		ft_list_remove_if(&cur->next, data_ref, cmp);
	}

}

int	cmp(void *arg1, void *arg2)
{
	char *str1 = arg1;
	char *str2 = arg2;
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

// ----------------------------------------------------------------------------
int main() {
    t_list *list = NULL; // Initialize an empty list

	char *ref = "ccc";

    // Insert some elements into the list
    insert_end(&list, "aaa");
    insert_end(&list, "bbb");
    insert_end(&list, "ccc");
	insert_end(&list, "ddd");
	insert_end(&list, "eee");

    // Print the elements of the list
    printf("Linked List: ");
    print_list(list);
	ft_list_remove_if(&list, ref, cmp);
	printf("Remove If List: ");
    print_list(list);

    // Free the memory allocated for the list
    free_list(list);

    return 0;
}