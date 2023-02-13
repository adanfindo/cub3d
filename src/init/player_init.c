/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:24:29 by afindo          #+#    #+#             */
/*   Updated: 2022/09/13 13:22:36 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_player	*player_init(t_data *data, int i, int j)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!(player))
		error_msg_exit(data, "Error mallocing player");
	player->x = j + 0.5;
	player->y = i + 0.5;
	player->dir_x = ((data->map->tiles[i][j] == tile_p_e) * 1 + \
						(data->map->tiles[i][j] == tile_p_w) * -1);
	player->dir_y = ((data->map->tiles[i][j] == tile_p_s) * 1 + \
						(data->map->tiles[i][j] == tile_p_n) * -1);
	player->plane_x = -player->dir_y * 0.66;
	player->plane_y = player->dir_x * 0.66;
	player->mov_forward = false;
	player->mov_backward = false;
	player->rot_left = false;
	player->rot_right = false;
	player->strafe_left = false;
	player->strafe_right = false;
	return (player);
}
