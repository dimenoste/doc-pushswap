#include "push_swap.h"

void	swap_array(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble(int *arr, int len)
{
	int	i;

	printf("len of ll %d\n", len);
	i = 0;
	if (!arr || len < 2)
		return ;
	while (len > 0)
	{
		i = 0;
		while (i < (len - 1))
		{
			if (arr[i] > arr[i + 1])
			{
				swap_array(&arr[i], &arr[i + 1]);
			}
			i++;
		}
		len--;
	}
}

int	*from_ll_to_array(t_stack *stk)
{
	t_node	*ptr_node;
	int		*arr;
	size_t	i;

	if (!stk)
		return (NULL);
	i = 0;
	ptr_node = stk->head;
	arr = malloc(sizeof(int) * (stk->length));
	if (!arr || !ptr_node)
		return (NULL);
	while (i < stk->length)
	{
		arr[i] = ptr_node->value;
		ptr_node = ptr_node->next;
		i++;
	}
	return (arr);
}

size_t	find_index(int val, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (val == arr[i])
			return (i);
		i++;
	}
	return (-1);
}
void	add_rank_node(t_stack *stk, int *arr_sorted)
{
	t_node	*ptr_node;
	size_t	i;
	int		index;

	i = 0;
	if (!stk)
		return ;
	ptr_node = stk->head;
	if (!ptr_node)
		return ;
	while (i < stk->length)
	{
		index = find_index(ptr_node->value, arr_sorted, stk->length);
		if (index >= 0)
			ptr_node->rank = (size_t)index;
		else
			return ;
		ptr_node = ptr_node->next;
		i++;
	}
}
