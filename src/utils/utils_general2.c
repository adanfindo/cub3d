/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:49:06 by afindo          #+#    #+#             */
/*   Updated: 2022/09/11 14:13:41 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_hex(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9') && (*str < 'A' || *str > 'F'))
			return (0);
		str++;
	}
	return (1);
}

int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_wall_door_closed(int tile)
{
	return (tile == tile_wall || tile == tile_door);
}

char	*get_first_n_chars(char *str, int n_chars)
{
	char	*ret;

	ret = ft_calloc(n_chars + 1, 1);
	if (!ret)
		return (NULL);
	ft_strlcat(ret, str, n_chars + 1);
	return (ret);
}

int	free_str_return(char *str, int return_value)
{
	if (str)
		free(str);
	return (return_value);
}
