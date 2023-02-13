/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_wall1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:21:14 by afindo          #+#    #+#             */
/*   Updated: 2022/09/11 14:18:31 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../utils/hashtable.h"

static t_wall	*wall_init(t_data *data)
{
	t_wall	*wall;

	wall = ft_calloc(sizeof(t_wall), 1);
	if (!wall)
		return (NULL);
	wall->hashtable = NULL;
	wall->pixels = NULL;
	wall->data = data;
	wall->width = 0;
	wall->height = 0;
	return (wall);
}

static void	decide_refactor(int i, int *ret, t_wall *wall, char *line)
{
	if (i == 4)
	{
		if (wall_parse_properties(wall, line))
			*ret = 1;
		wall->hashtable = hashtable_init(100);
		if (!(wall->hashtable))
			*ret = 1;
		if (!(*ret))
			wall->pixels = array_init(wall->height, wall->width);
		if (!wall->pixels)
			*ret = 1;
	}
	else if (i > 4 && i <= wall->n_keys + 4)
	{
		if (wall_parse_keys(wall, line))
			*ret = 1;
	}
	else if (i > wall->n_keys + 5 && i <= wall->n_keys + 5 + wall->height)
	{
		if (wall_parse_pixels(wall, line, i))
			*ret = 1;
	}
}

static t_wall	*parse_file(t_data *data, int fd)
{
	t_wall	*wall;
	char	*line;
	int		i;
	int		ret;

	wall = wall_init(data);
	if (!wall)
		return (NULL);
	ret = 0;
	line = get_next_line(fd);
	i = 1;
	while (line && !ret)
	{
		decide_refactor(i, &ret, wall, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (ret == 1 || i < 4)
	{
		free(line);
		free_wall(wall);
		return (NULL);
	}
	return (wall);
}

static t_wall	*parse_wall(t_data *data, char *str)
{
	t_wall	*wall;
	char	*filename;
	int		fd_wall;

	filename = ft_strtrim(str, "\n");
	if (ft_strncmp(ft_strrchr(filename, '.'), ".xpm", 5))
	{
		free(filename);
		return (NULL);
	}
	fd_wall = open(filename, O_RDONLY);
	free(filename);
	if (fd_wall < 0)
		return (NULL);
	wall = parse_file(data, fd_wall);
	close(fd_wall);
	return (wall);
}

int	parse_wall_image(t_data *data, char **arr)
{
	t_wall	*wall_to_parse;

	if (str_arr_len(arr) == 3 && *(arr[2]) != '\n')
		return (1);
	if ((!ft_strncmp(arr[0], "DO", 3) && data->map->walls->door) || \
		(!ft_strncmp(arr[0], "NO", 3) && data->map->walls->n) || \
		(!ft_strncmp(arr[0], "EA", 3) && data->map->walls->e) || \
		(!ft_strncmp(arr[0], "SO", 3) && data->map->walls->s) || \
		(!ft_strncmp(arr[0], "WE", 3) && data->map->walls->w))
		return (1);
	wall_to_parse = parse_wall(data, arr[1]);
	if (!wall_to_parse)
		return (1);
	if (!ft_strncmp(arr[0], "DO", 3))
		data->map->walls->door = wall_to_parse;
	else if (!ft_strncmp(arr[0], "NO", 3))
		data->map->walls->n = wall_to_parse;
	else if (!ft_strncmp(arr[0], "EA", 3))
		data->map->walls->e = wall_to_parse;
	else if (!ft_strncmp(arr[0], "SO", 3))
		data->map->walls->s = wall_to_parse;
	else
		data->map->walls->w = wall_to_parse;
	return (0);
}
