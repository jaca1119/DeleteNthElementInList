#include <stdio.h>
#include <stdlib.h>
#include <time.h>



struct list{
	int key;
	struct list *next;
};


struct list* add_to_list(struct list *list, int x)
{
	struct list *tmp;
	
	tmp = (struct list*) malloc(sizeof(struct list));
	
	tmp->key = x;
	tmp->next = list;
	list = tmp;
	
	return list;
	
}

void print_list(struct list *list)
{
//	struct list *tmp;
	
	int i = 0;
	
//	tmp = list;
	
	while(list != NULL)
	{
		printf("\nElement nr: %d, key = %d\n", i++, list->key);
		
		list = list->next;
	}
}

struct list* del_from_list(struct list *list, int x)
{
	struct list *tmp, *pom;
	int i = 0;
	
	
	pom = list;
	
	while (pom != NULL && pom->key != x)
	{
		tmp = pom;
		pom = pom->next;
		i++;
	}
	
	if(i == 0)
	{
		tmp = list->next;
		//free(list);
		list = tmp;
		return list;
	}
	
	if (pom != NULL)
	{
		if(pom == list)
		{
			list = pom->next;
		}
		else
		{
			tmp->next = pom->next;
		}
		
		free(pom);
	}
	else
	{
		printf("\nElement not found\n");
	}
	
	return list;
}

struct list* delete_nth_element(struct list* list, int nth)
{
	struct list *tmp, *pom;
	
	int i = 0;
	
	pom = list;
	
	while (pom != NULL && i != nth)
	{
		tmp = pom;
		pom = pom->next;
		i++;
	}
	

	
	if (pom != NULL)
	{
		if(pom == list)
		{
			list = pom->next;
		}
		else
		{
			tmp->next = pom->next;
		}
		
		free(pom);
	}
	else
	{
		printf("\Wrong number\n");
	}
	
	return list;
	
}



int main(int argc, char *argv[]) {
	int i;
	struct list *head = NULL;
	
	for (i = 0; i < 5; i++)
	{
		head = add_to_list(head, i);
	}
	head = add_to_list(head, 3);
	
	if(head != NULL)
	{
		print_list(head);
	}
	
	head = delete_nth_element(head, 3);
	
	print_list(head);
	
	
	return 0;
}
