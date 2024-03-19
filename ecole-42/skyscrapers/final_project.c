#include <unistd.h>
#include "myheader.h"
#include "myotherheader.h"

int	g_inp[4][4];
int	g_res[4][4] = {0};

int	valid_input(char *s)
{
	if (*s < 49 || *s > 52)
		return (0);
	if (*(s + 1) != ' ' && *(s + 1) != '\0')
		return (0);
	if (*(s + 1) == ' ' && *(s + 2) == '\0')
		return (0);
	return (1);
}

int	read_input(char	*s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (!valid_input(s))
			return (0);
		g_inp[i][j] = *s - '0';
		s++;
		if (*s != '\0')
			s++;
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
		if ((i == 4 && *s != '\0') || (*s == '\0' && i != 4))
			return (0);
	}
	return (1);
}

int	vch_clup(int i, int j)
{
	int	count;
	int	max;
	int	row;

	max = 0;
	row = 0;
	count = 0;
	while (row <= i)
	{
		if (g_res[row][j] > max)
		{
			max = g_res[row][j];
			count++;
		}
		row++;
	}
	if (g_inp[0][j] < count)
		return (0);
	return (1);
}

int	vch_cld(int i, int j)
{
	int	count;
	int	max;
	int	row;

	max = 0;
	row = i;
	count = 0;
	while (row >= 0)
	{
		if (g_res[row][j] > max)
		{
			max = g_res[row][j];
			count++;
		}
		row--;
	}
	if (g_inp[1][j] != count)
		return (0);
	return (1);
}

int	vch_rowl(int i, int j)
{
	int	count;
	int	max;
	int	col;

	max = 0;
	col = 0;
	count = 0;
	while (col <= j)
	{
		if (g_res[i][col] > max)
		{
			max = g_res[i][col];
			count++;
		}
		col++;
	}
	if (g_inp[2][i] < count)
		return (0);
	return (1);
}

int	vch_rowr(int i, int j)
{
	int	count;
	int	max;
	int	col;

	max = 0;
	col = j;
	count = 0;
	while (col >= 0)
	{
		if (g_res[i][col] > max)
		{
			max = g_res[i][col];
			count++;
		}
		col--;
	}
	if (g_inp[3][i] != count)
		return (0);
	return (1);
}

int	view_check(int guess, int i, int j)
{
	g_res[i][j] = guess;
	if (i == 3 && j == 3)
	{
		if (vch_rowl(i, j) && vch_rowr(i, j) && vch_clup(i, j) && vch_cld(i, j))
			return (1);
	}
	else if (j == 3)
	{
		if (vch_rowl(i, j) && vch_rowr(i, j) && vch_clup(i, j))
			return (1);
	}
	else if (i == 3)
	{
		if (vch_rowl(i, j) && vch_clup(i, j) && vch_cld(i, j))
			return (1);
	}
	else
	{
		if (vch_rowl(i, j) && vch_clup(i, j))
			return (1);
	}
	g_res[i][j] = 0;
	return (0);
}

int	rep_check(int guess, int i, int j)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (col < j)
	{
		if (g_res[i][col] == guess)
			return (0);
		col++;
	}
	while (row < i)
	{
		if (g_res[row][j] == guess)
			return (0);
		row++;
	}
	return (1);
}

int	make_guess(int i, int j)
{
	int	guess;
	int	row;
	int	col;

	if (i == 4)
		return (1);
	guess = 1;
	while (guess <= 4)
	{
		if (rep_check(guess, i, j) && view_check(guess, i, j))
		{
			col = j + 1;
			row = i;
			if (col == 4)
			{
				col = 0;
				row++;
			}
			if (make_guess(row, col))
				return (1);
			g_res[i][j] = 0;
		}
		guess++;
	}
	return (0);
}

void	printer(void)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			c = g_res[i][j] + '0';
			write(1, &c, 1);
			j++;
			if (j != 4)
				write(1, " ", 1);
		}
		j = 0;
		i++;
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !(read_input(argv[1])))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (make_guess(0, 0))
		printer();
	else
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (0);
}
