/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:47:21 by dsiroten          #+#    #+#             */
/*   Updated: 2024/01/22 14:17:32 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*#include <stdio.h>*/

void	printer(int *arr)
{
	char	c;
	int		j;

	j = 0;
	while (j < 10)
	{
		c = arr[j] + '0';
		write(1, &c, 1);
		j++;
	}
	write(1, "\n", 1);
}

int	is_valid(int *arr, int i, int j)
{
	int	shift;

	shift = 1;
	while ((j - shift) >= 0)
	{
		if (arr[j - shift] == i + shift || arr[j - shift] == i - shift)
			return (0);
		shift++;
	}
	shift = j - 1;
	while (j != 0 && shift >= 0)
	{
		if (arr[shift] == i)
			return (0);
		shift--;
	}
	return (1);
}

int	recursive_queens(int *arr, int j)
{
	int	col;
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 10)
	{
		arr[j] = i;
		if (is_valid(arr, i, j))
		{
			if (j == 9)
			{
				printer(arr);
				count++;
				break ;
			}
			col = j + 1;
			count = count + recursive_queens(arr, col);
		}
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	j;
	int	count;

	j = 0;
	count = recursive_queens(arr, 0);
	return (count);
}

/*int	main(void)
{
	int count;

	count = ft_ten_queens_puzzle();
	printf("%d", count);
	return (0);
}*/
