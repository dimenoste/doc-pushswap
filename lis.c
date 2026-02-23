
// https://www.youtube.com/watch?v=cjWnW0hdF1Y
// https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html
#include <stdio.h> // A SUPPRIMER !!!!!!!!!!!!!!!!!!!
#include <stdlib.h>
#include <unistd.h>

void	print_array(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("number at index %d is %d\n", i, arr[i]);
		i++;
	}
}

int	*init_array(int *arr, int len, int val)
{
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = val;
		i++;
	}
	return (arr);
}

int	*lis(int *arr, int len_arr)
{
	int	*d;
	int	*p;
	int	*subseq;
	int	i;
	int	j;
	int	ans;
	int	pos;
	int	k;
	int	end;

	ans = 0;
	pos = 0;
	i = 0;
	d = init_array(d, len_arr, 1);
	print_array(d, len_arr);
	p = init_array(d, len_arr, -1);
	print_array(p, len_arr);
	while (i < len_arr)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1;
				p[i] = j;
			}
			j++;
		}
		i++;
	}
	i = 1;
	ans = d[0];
	while (i < len_arr)
	{
		if (d[i] > ans)
		{
			ans = d[i];
			pos = i;
		}
		i++;
	}
	printf("lis length is %d\n", ans);
	subseq = malloc(sizeof(int) * ans);
	if (!subseq)
		return (NULL);
	end = ans - 1;
	while (pos != -1)
	{
		subseq[end] = arr[pos];
		pos = p[pos];
		end--;
	}
	free(d);
	free(p);
	print_array(subseq, ans);
	return (subseq);
}

int	main(void)
{
	int arr[] = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};

	// print_array(arr, 10);
	lis(arr, 10);
	return (0);
}