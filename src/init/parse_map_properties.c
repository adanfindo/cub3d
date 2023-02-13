/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_properties.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:52:48 by afindo          #+#    #+#             */
/*   Updated: 2022/09/13 13:12:29 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	decide_refactor(t_data *data, char **arr, int *ret)
{
	if (!(data->map->map_found) && str_arr_len(arr) == 0)
		*ret = 0;
	else if (data->map->map_found && str_arr_len(arr) == 0)
	{
		data->map->height++;
		*ret = 0;
	}
	else if (data->map->map_found && (is_no_ea_so_we_do(arr[0]) || \
			!ft_strncmp(arr[0], "F", 2) || !ft_strncmp(arr[0], "C", 2)))
		*ret = 1;
	else if (is_no_ea_so_we_do(arr[0]) && \
			(str_arr_len(arr) == 2 || str_arr_len(arr) == 3))
		*ret = parse_wall_image(data, arr);
	else if (!ft_strncmp(arr[0], "F", 2) || !ft_strncmp(arr[0], "C", 2))
		*ret = parse_floor_ceiling(data, arr);
	else if (!ft_strncmp(arr[0], "\n", 2) && !(data->map->map_found))
		*ret = 0;
	else
		*ret = 1;
}

static int	parse_str(t_data *data, char *str)
{
	char	**arr;
	int		ret;

	if (is_map_line(str) && !(!(data->map->map_found) && *str == '\n'))
	{
		data->map->map_found = 1;
		data->map->height++;
		if ((int)(ft_strlen(str) - 1) > data->map->width)
			data->map->width = ft_strlen(str) - 1;
		return (0);
	}
	arr = ft_split(str, ' ');
	if (!arr)
		return (1);
	ret = 0;
	decide_refactor(data, arr, &ret);
	free_strarray(arr);
	return (ret);
}

int	parse_map_properties(t_data *data, char *map_path)
{
	int		fd;
	char	*str;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	str = get_next_line(fd);
	while (str)
	{
		if (parse_str(data, str))
		{
			free(str);
			close(fd);
			return (1);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
