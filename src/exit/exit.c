/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:39:32 by afindo          #+#    #+#             */
/*   Updated: 2022/09/11 09:33:56 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_msg_exit(t_data *data, char *str)
{
	ft_putendl_fd(str, 2);
	free_all(data);
	exit(1);
}

// Reads an fd to the end, closes it, then calls error_msg_exit
void	error_fd_msg_exit(t_data *data, char *str, int fd)
{
	char	*helper;

	helper = get_next_line(fd);
	while (helper)
	{
		free(helper);
		helper = get_next_line(fd);
	}
	free(helper);
	close(fd);
	error_msg_exit(data, str);
}

//frees string and calls error_fd_msg_exit
void	error_str_fd_msg_exit(t_data *data, char *msg, char *free_str, int fd)
{
	if (free_str)
		free(free_str);
	error_fd_msg_exit(data, msg, fd);
}

void	error_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	cub_exit(t_data *data, int exit_code)
{
	free_all(data);
	exit(exit_code);
}
