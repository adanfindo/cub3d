/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:45:15 by afindo          #+#    #+#             */
/*   Updated: 2022/09/11 13:44:38 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	image_free(t_image *image, t_data *data)
{
	if (image->image)
		mlx_destroy_image(data->mlx, image->image);
	if (image->addr)
		free(image->addr);
	free(image);
	image = NULL;
}

void	free_wall(t_wall *image)
{
	if (image->hashtable)
		hashtable_delete(image->hashtable);
	if (image->pixels)
		free_intarray(image->pixels);
	free(image);
	image = NULL;
}

static void	free_walls(t_walls *walls)
{
	if (walls->n)
		free_wall(walls->n);
	if (walls->e)
		free_wall(walls->e);
	if (walls->s)
		free_wall(walls->s);
	if (walls->w)
		free_wall(walls->w);
	if (walls->door)
		free_wall(walls->door);
	free(walls);
	walls = NULL;
}

static void	free_map(t_map *map)
{
	if (map->c_ceiling)
		free(map->c_ceiling);
	if (map->c_floor)
		free(map->c_floor);
	if (map->tiles)
		free_intarray(map->tiles);
	if (map->walls)
		free_walls(map->walls);
	free(map);
	map = NULL;
}

void	free_all(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->player)
		free(data->player);
	if (data->math)
		math_free(data->math);
	mlx_destroy(data);
	free(data);
	data = NULL;
}
