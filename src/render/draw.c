/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:04:41 by afindo          #+#    #+#             */
/*   Updated: 2022/09/15 22:30:14 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_wall(t_data *data, t_image *image, t_raycast_h *h, int ray_n)
{
	double	step;
	double	image_pos;
	int		i;
	int		image_y;

	step = (double)(h->wall->height) / (double)(h->line_height);
	image_pos = (h->draw_start - SCREEN_HEIGHT / 2 + h->line_height / 2) * step;
	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		if (i < h->draw_start)
			image_pix_put(image, ray_n, i, *(data->map->c_ceiling));
		else if (i < h->draw_end)
		{
			image_y = (int)image_pos;
			image_pos += step;
			image_pix_put(image, ray_n, i, \
							h->wall->pixels[image_y][h->image_x]);
		}
		else
			image_pix_put(image, ray_n, i, *(data->map->c_floor));
		i++;
	}
}

static void	calculate_image_parameters(t_raycast_h *h)
{
	h->image_x = (int)(h->wall_x * (double)(h->wall->width));
	if ((h->side == 0 && h->ray_dir_x > 0) || (h->side && h->ray_dir_y < 0))
		h->image_x = h->wall->width - h->image_x - 1;
}

static t_wall	*decide_wall(t_data *data, t_raycast_h *h)
{
	if (data->map->tiles[h->map_y][h->map_x] == tile_door)
		return (data->map->walls->door);
	if (h->ray_dir_y > 0 && h->side)
		return (data->map->walls->s);
	if (h->ray_dir_y < 0 && h->side)
		return (data->map->walls->n);
	if (h->ray_dir_x > 0 && h->side == 0)
		return (data->map->walls->e);
	if (h->ray_dir_x < 0 && h->side == 0)
		return (data->map->walls->w);
	return (NULL);
}

static void	calculate_draw_parameters(t_data *data, t_raycast_h *h)
{
	if (!h->side)
		h->perp_wall_dist = h->side_dist_x - h->delta_dist_x;
	else
		h->perp_wall_dist = h->side_dist_y - h->delta_dist_y;
	h->line_height = (int)(SCREEN_HEIGHT / h->perp_wall_dist);
	h->draw_start = -(h->line_height) / 2 + SCREEN_HEIGHT / 2;
	if (h->draw_start < 0)
		h->draw_start = 0;
	h->draw_end = h->line_height / 2 + SCREEN_HEIGHT / 2;
	if (h->draw_end >= SCREEN_HEIGHT)
		h->draw_end = SCREEN_HEIGHT - 1;
	if (h->side)
		h->wall_x = data->player->x + h->perp_wall_dist * h->ray_dir_x;
	else
		h->wall_x = data->player->y + h->perp_wall_dist * h->ray_dir_y;
	h->wall_x -= floor(h->wall_x);
}

void	draw(t_data *data, t_image *image, t_raycast_h *helper, int ray_n)
{
	calculate_draw_parameters(data, helper);
	helper->wall = decide_wall(data, helper);
	calculate_image_parameters(helper);
	draw_wall(data, image, helper, ray_n);
}
