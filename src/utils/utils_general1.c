/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:49:06 by afindo          #+#    #+#             */
/*   Updated: 2022/09/15 14:47:25 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	**array_init(int height, int width)
{
	int	**int_arr;
	int	i;

	int_arr = ft_calloc(height + 1, sizeof(int *));
	if (!int_arr)
		return (NULL);
	i = 0;
	while (i < height)
	{
		int_arr[i] = ft_calloc(width, sizeof(int));
		if (!int_arr[i])
		{
			free_intarray(int_arr);
			return (NULL);
		}
		i++;
	}
	int_arr[height] = NULL;
	return (int_arr);
}

void	free_intarray(int **int_arr)
{
	int	i;

	i = 0;
	while (int_arr[i])
	{
		free(int_arr[i]);
		i++;
	}
	free(int_arr);
}

int	str_arr_len(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
		i++;
	return (i);
}

void	free_strarray(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

int	str_len_without_spaces_nl(char **arr)
{
	int	n_chars;
	int	i;

	n_chars = 0;
	arr++;
	while (*arr)
	{
		i = 0;
		while ((*arr)[i])
		{
			if ((*arr)[i] != ' ' && (*arr)[i] != '\n')
				n_chars++;
			i++;
		}
		arr++;
	}
	return (n_chars);
}
