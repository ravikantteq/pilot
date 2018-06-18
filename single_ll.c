#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct list_node
{
	int value;
	struct list_node* next;
} list_node;

int traverse_list(list_node *head)
{
	list_node *current = NULL;
	if (NULL == head)
	{
		printf("[%s]: list is empty\n", __func__);
		return FAILURE;
	}

	current = head;
	printf("List: ");
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
	return SUCCESS;
}

void insert_into_list(list_node **head, int value)
{
	list_node *new = malloc(sizeof(list_node) * 1);
	new->value = value;
	new->next = NULL;

	if (head == NULL)
	{
		*head = new;
		return;
	}

	new->next = *head;
	*head = new;

	return;
}

void delete_from_list(list_node **head, int value)
{
	list_node *current = NULL;
	list_node *prev = NULL;

	if (NULL == *head)
	{
		printf("[%s]: list is empty\n", __func__);
		return;
	}

	current = *head;
	while(current != NULL)
	{
		if (current->value == value)
		{
			break;
		}
		prev = current;
		current = current->next;
	}

	/* considering three possible cases 
	 * - element is not present
	 * - element is at first location
	 * - element is at any other location
	 */
	if (NULL == current)
	{
		printf("[%s]: value[%d] doesn't exist in list\n", __func__, value);
	}
	else if (current == *head)
	{
		*head = current->next;
		free(current);
	}
	else
	{
		prev->next = current->next;
		free(current);
	}
}

int main()
{
	list_node *head = NULL;

	// insert into list
	insert_into_list(&head, 5);
	insert_into_list(&head, 6);
	insert_into_list(&head, 7);
	insert_into_list(&head, 8);
	insert_into_list(&head, 9);
	insert_into_list(&head, 1);

	// traverse list
	traverse_list(head);

	// delete first element
	delete_from_list(&head, 5);
	traverse_list(head);

	// delete last element
	delete_from_list(&head, 1);
	traverse_list(head);

	// delete non existent element
	delete_from_list(&head, 11);
	// delete any element in-between
	delete_from_list(&head, 7);
	traverse_list(head);
}
