/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:30:52 by afindo          #+#    #+#             */
/*   Updated: 2022/09/06 15:31:19 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	image_pix_put(t_image *image, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	i = image->bpp - 8;
	pixel = image->addr + (y * image->line_len + x * (image->bpp / 8));
	while (i >= 0)
	{
		if (image->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (image->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

t_image	*image_init(void *mlx, int height, int width)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->bpp = 0;
	image->endian = 0;
	image->line_len = 0;
	image->addr = 0;
	image->image = mlx_new_image(mlx, width, height);
	image->addr = mlx_get_data_addr(image->image, &image->bpp, \
									&image->line_len, &image->endian);
	image->height = SCREEN_HEIGHT;
	image->width = SCREEN_WIDTH;
	return (image);
}
