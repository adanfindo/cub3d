/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:50:09 by afindo          #+#    #+#             */
/*   Updated: 2022/09/11 21:49:07 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	translate(t_data *data)
{
	if (data->player->mov_forward && !(data->player->mov_backward))
		translate_forward(data, data->player);
	if (data->player->mov_backward && !(data->player->mov_forward))
		translate_backward(data, data->player);
	if (data->player->strafe_left && !(data->player->strafe_right))
		translate_left(data, data->player);
	if (data->player->strafe_right && !(data->player->strafe_left))
		translate_right(data, data->player);
}

static void	rotate(t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	if (p->rot_right)
	{
		p->dir_x = p->dir_x * cos(ROT_STEP) - p->dir_y * sin(ROT_STEP);
		p->dir_y = old_dir_x * sin(ROT_STEP) + p->dir_y * cos(ROT_STEP);
		p->plane_x = p->plane_x * cos(ROT_STEP) - p->plane_y * sin(ROT_STEP);
		p->plane_y = old_plane_x * sin(ROT_STEP) + p->plane_y * cos(ROT_STEP);
	}
	if (p->rot_left)
	{
		p->dir_x = p->dir_x * cos(-ROT_STEP) - p->dir_y * sin(-ROT_STEP);
		p->dir_y = old_dir_x * sin(-ROT_STEP) + p->dir_y * cos(-ROT_STEP);
		p->plane_x = p->plane_x * cos(-ROT_STEP) - p->plane_y * sin(-ROT_STEP);
		p->plane_y = old_plane_x * sin(-ROT_STEP) + \
						p->plane_y * cos(-ROT_STEP);
	}
}

void	move(t_data *data)
{
	rotate(data->player);
	translate(data);
}
