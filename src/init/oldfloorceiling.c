/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_floor_ceiling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:32:46 by afindo          #+#    #+#             */
/*   Updated: 2022/09/13 13:26:28 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**prepare_string_array(char *str)
{
	char	*helper;
	char	**str_arr;

	helper = ft_strtrim(str, "\n");
	if (!helper)
		return (NULL);
	str_arr = ft_split(helper, ',');
	free(helper);
	return (str_arr);
}

t_rgb_triple	*parse_rgb_triple(char *str)
{
	t_rgb_triple	*rgb_triple;
	char			**str_arr;

	str_arr = prepare_string_array(str);
	if (!str_arr || str_arr_len(str_arr) != 3)
	{
		if (str_arr)
			free_strarray(str_arr);
		return (NULL);
	}
	rgb_triple = malloc(sizeof(t_rgb_triple));
	if (!rgb_triple)
		return (NULL);
	rgb_triple->r = ft_atoi(str_arr[0]) % 255;
	rgb_triple->g = ft_atoi(str_arr[1]) % 255;
	rgb_triple->b = ft_atoi(str_arr[2]) % 255;
	free_strarray(str_arr);
	return (rgb_triple);
}

int	parse_floor_ceiling(t_data *data, char **arr)
{
	t_rgb_triple	*rgb;

	if (str_arr_len(arr) != 2)
		return (1);
	rgb = parse_rgb_triple(arr[1]);
	if (!rgb)
		return (1);
	if ((!ft_strncmp(arr[0], "F", 1) && data->map->c_floor) || \
		(!ft_strncmp(arr[0], "C", 1) && data->map->c_ceiling))
	{
		free(rgb);
		return (1);
	}
	if (!ft_strncmp(arr[0], "F", 1))
		data->map->c_floor = encode_rgb(rgb->r, rgb->g, rgb->b);
	else
		data->map->c_ceiling = encode_rgb(rgb->r, rgb->g, rgb->b);
	free(rgb);
	return (0);
}
