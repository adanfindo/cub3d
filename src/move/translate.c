/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:41:44 by afindo          #+#    #+#             */
/*   Updated: 2022/09/09 17:47:43 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	translate_forward(t_data *data, t_player *p)
{
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y)][(int)(p->x + p->dir_x * MOV_STEP)]))
		p->x += p->dir_x * MOV_STEP;
	else
		p->x = (int)(p->x + p->dir_x * MOV_STEP) + \
				(p->dir_x > 0) * (-0.01) + (p->dir_x < 0) * (1.01);
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y + p->dir_y * MOV_STEP)][(int)(p->x)]))
		p->y += p->dir_y * MOV_STEP;
	else
		p->y = (int)(p->y + p->dir_y * MOV_STEP) + \
				(p->dir_y > 0) * (-0.01) + (p->dir_y < 0) * (1.01);
}

void	translate_backward(t_data *data, t_player *p)
{
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y)][(int)(p->x - p->dir_x * MOV_STEP)]))
		p->x -= p->dir_x * MOV_STEP;
	else
		p->x = (int)(p->x - p->dir_x * MOV_STEP) + \
				(p->dir_x > 0) * (1.01) + (p->dir_x < 0) * (-0.01);
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y - p->dir_y * MOV_STEP)][(int)(p->x)]))
		p->y -= p->dir_y * MOV_STEP;
	else
		p->y = (int)(p->y - p->dir_y * MOV_STEP) + \
				(p->dir_y > 0) * (1.01) + (p->dir_y < 0) * (-0.01);
}

void	translate_right(t_data *data, t_player *p)
{
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y)][(int)(p->x + p->plane_x * MOV_STEP)]))
		p->x += p->plane_x * MOV_STEP;
	else
		p->x = (int)(p->x + p->plane_x * MOV_STEP) + \
				(p->plane_x > 0) * (-0.01) + (p->plane_x < 0) * (1.01);
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y + p->plane_y * MOV_STEP)][(int)(p->x)]))
		p->y += p->plane_y * MOV_STEP;
	else
		p->y = (int)(p->y + p->plane_y * MOV_STEP) + \
				(p->plane_y > 0) * (-0.01) + (p->plane_y < 0) * (1.01);
}

void	translate_left(t_data *data, t_player *p)
{
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y)][(int)(p->x - p->plane_x * MOV_STEP)]))
		p->x -= p->plane_x * MOV_STEP;
	else
		p->x = (int)(p->x - p->plane_x * MOV_STEP) + \
				(p->plane_x > 0) * (1.01) + (p->plane_x < 0) * (-0.01);
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y - p->plane_y * MOV_STEP)][(int)(p->x)]))
		p->y -= p->plane_y * MOV_STEP;
	else
		p->y = (int)(p->y - p->plane_y * MOV_STEP) + \
				(p->plane_y > 0) * (1.01) + (p->plane_y < 0) * (-0.01);
}
