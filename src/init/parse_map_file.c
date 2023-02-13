/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:25:26 by afindo          #+#    #+#             */
/*   Updated: 2022/09/13 13:23:23 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_map_completeness(t_map *map)
{
	if (!map->c_ceiling || !map->c_floor || !map->walls->n || !map->walls->e \
		|| !map->walls->s || !map->walls->w || !map->walls->door \
		|| !map->map_found)
		return (1);
	return (0);
}

static t_map	*map_init(t_data *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		error_msg_exit(data, "Error malloc'ing map struct!\n");
	map->walls = malloc(sizeof(t_walls));
	if (!(map->walls))
		error_msg_exit(data, "Error malloc'ing wall struct!\n");
	map->walls->n = NULL;
	map->walls->e = NULL;
	map->walls->s = NULL;
	map->walls->w = NULL;
	map->walls->door = NULL;
	map->tiles = NULL;
	map->c_ceiling = NULL;
	map->c_floor = NULL;
	map->map_found = 0;
	map->height = 0;
	map->width = 0;
	return (map);
}

void	parse_map_file(t_data *data, char *map_path)
{
	data->map = map_init(data);
	if (parse_map_properties(data, map_path))
		error_msg_exit(data, "Error\nError parsing map");
	if (check_map_completeness(data->map))
		error_msg_exit(data, "Error\nMap not complete");
	parse_map_tiles(data, map_path);
}
