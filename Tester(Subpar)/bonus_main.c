#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

// -L. -lft

void *fun(void *node_content)
{
	if (!(ft_strncmp(node_content, "Two", ft_strlen("Two"))))
		return (ft_strdup("2"));
	return (ft_strdup(node_content));
}

// void *fun(void *content)
// {
//     char *str = "mmm";
//     content = str;
//     char *new_content = malloc(5); // Allocate enough space for "9wed\0"
//     if (!new_content)
//         return (NULL);
//     strcpy(new_content, (char *)content); // Copy "9wed" into the newly allocated memory
//     return (new_content);        // Return the allocated string
// }

void f(void *node_content)
{
	if (!(ft_strncmp(node_content, "Two", ft_strlen("Two"))))
		printf("I found \"Two\" in => ");
}

void del(void *node_content)
{
	free(node_content);
}

void print_list(t_list *head)
{
	t_list *current = head;
	while (current)
	{
		printf("%s -> ", (char *)(current->content));
		current = current->next;
	}
	printf("NULL\n");
}

int main(void)
{
	t_list	*head;
	t_list	*new_head;
	t_list	*head_NULL;
	
	head = NULL;
	head_NULL = NULL; 
	new_head = NULL; 

	t_list	*node1 = ft_lstnew(ft_strdup("One"));
	t_list	*node2 = ft_lstnew(ft_strdup("Two"));
	t_list	*node3 = ft_lstnew(ft_strdup("Three"));

	// ===> ft_lstadd_front
	printf("print the linked nodes :");
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	print_list(head);

	// head = node1;
	// node1->next = node2;
	// node2->next = node3;

	// ===> ft_lstsize
	printf("size of list : %d\n", ft_lstsize(head));
	printf("\n");

	// ===> ft_lstlast
	// printf("print the last node:");
	// print_list(ft_lstlast(head));
	// printf("\n");

	// ===> ft_lstnew
	t_list	*node4 = ft_lstnew(ft_strdup("Four"));
	printf("print the list aftr add node :");
	ft_lstadd_back(&head, node4);
	print_list(head);
	printf("size of list : %d\n", ft_lstsize(head));
	printf("\n");

	// ===> ft_lstdelone
	// ft_lstdelone(node4, fun);
	// printf("print the linked nodes after del node4 :");
	// print_list(head);
	// printf("size of list : %d\n", ft_lstsize(head));
	// printf("\n");

	// ===> ft_lstiter
	// ft_lstiter(node2, f);
	// printf("print the list after iter:");
	// print_list(head);

	// === ft_lstmap
	new_head = ft_lstmap(head, fun, del);
	printf("print the new list :");
	print_list(new_head);
	printf("size of list : %d\n", ft_lstsize(new_head));
	printf("\n");

	// ===> ft_lstclear
	printf("print the list after del head list:");
	ft_lstclear(&head, del);
	print_list(head);
	printf("size of list : %d\n", ft_lstsize(head));
	printf("\n");

	printf("print the list after del new_head list:");
	ft_lstclear(&new_head, del);
	print_list(new_head);
	printf("size of list : %d\n", ft_lstsize(new_head));
	printf("\n");

	// free(node1);
	// free(node2);
	// free(node3);
	// free(node4);
	// free(head);
}

