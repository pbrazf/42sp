int	count_visible_from_top(int matrix[6][6], int col)
{
	int	max_height;
	int	count;
	int	row;

	max_height = 0;
	count = 0;
	row = 1;
	while (row <= 4)
	{
		if (matrix[row][col] > max_height)
		{
			max_height = matrix[row][col];
			count++;
		}
		row++;
	}
	return (count);
}

int	count_visible_from_bottom(int matrix[6][6], int col)
{
	int	max_height;
	int	count;
	int	row;

	max_height = 0;
	count = 0;
	row = 4;
	while (row >= 1)
	{
		if (matrix[row][col] > max_height)
		{
			max_height = matrix[row][col];
			count++;
		}
		row--;
	}
	return (count);
}

int	count_visible_from_left(int matrix[6][6], int row)
{
	int	max_height;
	int	count;
	int	col;

	max_height = 0;
	count = 0;
	col = 1;
	while (col <= 4)
	{
		if (matrix[row][col] > max_height)
		{
			max_height = matrix[row][col];
			count++;
		}
		col++;
	}
	return (count);
}

int	count_visible_from_right(int matrix[6][6], int row)
{
	int	max_height;
	int	count;
	int	col;

	max_height = 0;
	count = 0;
	col = 4;
	while (col >= 1)
	{
		if (matrix[row][col] > max_height)
		{
			max_height = matrix[row][col];
			count++;
		}
		col--;
	}
	return (count);
}

int	check_clues(int matrix[6][6])
{
	int	i;
	i = 1;
	while (i <= 4)
	{
		if (count_visible_from_top(matrix, i) != matrix[0][i])
			return (0);
		if (count_visible_from_bottom(matrix, i) != matrix[5][i])
			return (0);
		if (count_visible_from_left(matrix, i) != matrix[i][0])
			return (0);
		if (count_visible_from_right(matrix, i) != matrix[i][5])
			return (0);
		i++;
	}
	return (1);
}
