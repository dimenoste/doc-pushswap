#include "push_swap.h"

swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = *a;
}
void	bubble(int *arr, int len)
{
	int	end_index;
	int	i;

	end_index = len - 1;
	if (!arr || len < 2)
		return (NULL);
	while (end_index)
	{
		while (i < end_index)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
			}
			i++;
		}
		end_index--;
	}
}

int	main(void)
{
	return (0);
}
