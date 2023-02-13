/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_tiles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:53:52 by afindo          #+#    #+#             */
/*   Updated: 2022/09/06 09:24:57 by afindo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	decide_tile(t_data *data, char *str, int fd, char c)
{
	if (c == ' ')
		return (tile_empty);
	if (c == '0')
		return (tile_floor);
	if (c == '1')
		return (tile_wall);
	if (c == 'D')
		return (tile_door);
	if (c == 'N')
		return (tile_p_n);
	if (c == 'E')
		return (tile_p_e);
	if (c == 'S')
		return (tile_p_s);
	if (c == 'W')
		return (tile_p_w);
	close(fd);
	free(str);
	error_msg_exit(data, "Invalid character in map");
	return (-1);
}

static void	parse_str(t_data *data, char *str, int fd, int i)
{
	int	j;

	j = 0;
	while (str[j] && str[j] != '\n')
	{
		data->map->tiles[i][j] = decide_tile(data, str, fd, str[j]);
		j++;
	}
}

void	parse_map_tiles(t_data *data, char *map_path)
{
	char	*str;
	int		fd;
	int		i;

	data->map->tiles = array_init(data->map->height, data->map->width);
	if (!(data->map->tiles))
		error_msg_exit(data, "Error mallocing tiles struct!");
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_msg_exit(data, "Error opening map file!");
	data->map->map_found = 0;
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (is_map_line(str) && !(data->map->map_found == 0 && *str == '\n'))
		{
			data->map->map_found = 1;
			parse_str(data, str, fd, i);
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
