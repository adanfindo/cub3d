/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:20:30 by afindo          #+#    #+#             */
/*   Updated: 2022/09/11 11:18:35 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	perform_dda(t_data *data, t_raycast_h *h)
{
	while (h->hit == 0)
	{
		if (h->side_dist_x < h->side_dist_y)
		{
			h->side_dist_x += h->delta_dist_x;
			h->map_x += h->step_x;
			h->side = 0;
		}
		else
		{
			h->side_dist_y += h->delta_dist_y;
			h->map_y += h->step_y;
			h->side = 1;
		}
		if (is_wall_door_closed(data->map->tiles[h->map_y][h->map_x]))
		{
			h->hit = 1;
		}
	}
}

static void	get_step_and_initial_dist(t_data *data, t_raycast_h *h)
{
	if (h->ray_dir_x < 0)
	{
		h->step_x = -1;
		h->side_dist_x = (data->player->x - h->map_x) * h->delta_dist_x;
	}
	else
	{
		h->step_x = 1;
		h->side_dist_x = (h->map_x + 1 - data->player->x) * h->delta_dist_x;
	}
	if (h->ray_dir_y < 0)
	{
		h->step_y = -1;
		h->side_dist_y = (data->player->y - h->map_y) * h->delta_dist_y;
	}
	else
	{
		h->step_y = 1;
		h->side_dist_y = (h->map_y + 1 - data->player->y) * h->delta_dist_y;
	}
}

static void	ray_init(t_data *data, t_raycast_h *h, int ray_n)
{
	h->camera_x = 2 * ray_n / (double)SCREEN_WIDTH - 1;
	h->ray_dir_x = data->player->dir_x + data->player->plane_x * h->camera_x;
	h->ray_dir_y = data->player->dir_y + data->player->plane_y * h->camera_x;
	h->map_x = data->player->x;
	h->map_y = data->player->y;
	if (h->ray_dir_x == 0)
		h->delta_dist_x = 10000;
	else
		h->delta_dist_x = fabs(1 / h->ray_dir_x);
	if (h->ray_dir_y == 0)
		h->delta_dist_y = 10000;
	else
		h->delta_dist_y = fabs(1 / h->ray_dir_y);
	h->hit = 0;
	h->side = 0;
}

void	ray_cast(t_data *data, t_image *image, int ray_n)
{
	t_raycast_h	*h;

	h = malloc(sizeof(t_raycast_h));
	if (!h)
	{
		image_free(image, data);
		error_msg_exit(data, "Error mallocing raycast helper");
	}
	ray_init(data, h, ray_n);
	get_step_and_initial_dist(data, h);
	perform_dda(data, h);
	draw(data, image, h, ray_n);
	free(h);
}
