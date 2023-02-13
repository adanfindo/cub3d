/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:03:30 by afindo          #+#    #+#             */
/*   Updated: 2022/09/11 21:32:50 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_data *data)
{
	move(data);
	render_scene(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || ft_strrchr(argv[1], '.') == NULL || \
			ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5) != 0)
		error_exit("Usage: [./cub3d <map.cub>]");
	data = data_init(argv[1]);
	mlx_hook(data->win, 2, 1L << 0, hook_key_press, data);
	mlx_hook(data->win, 3, 1L << 1, hook_key_release, data);
	mlx_hook(data->win, 6, 1L << 6, hook_mouse, data);
	mlx_hook(data->win, 17, 0, hook_exit, data);
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_loop(data->mlx);
}
