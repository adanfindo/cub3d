/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:27:49 by afindo          #+#    #+#             */
/*   Updated: 2022/09/11 11:23:43 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_null(t_data *data)
{
	data->map = NULL;
	data->player = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->math = math_init();
	if (!(data->math))
		error_msg_exit(data, "Error mallocing math struct");
}

t_data	*data_init(char *map_path)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	init_null(data);
	parse_map_file(data, map_path);
	check_map_init_player(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	return (data);
}
