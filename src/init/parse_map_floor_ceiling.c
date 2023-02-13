/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_floor_ceiling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:32:46 by afindo          #+#    #+#             */
/*   Updated: 2022/09/15 14:54:43 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_rgb_triple	*get_rgb_triple(char **str_arr)
{
	t_rgb_triple	*rgb_triple;
	int				overflow;
	int				r;
	int				g;
	int				b;

	rgb_triple = malloc(sizeof(t_rgb_triple));
	if (!rgb_triple)
		return (NULL);
	overflow = 0;
	r = ft_atoi_e(str_arr[0], &overflow);
	g = ft_atoi_e(str_arr[1], &overflow);
	b = ft_atoi_e(str_arr[2], &overflow);
	free_strarray(str_arr);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0 || overflow)
	{
		free(rgb_triple);
		return (NULL);
	}
	rgb_triple->r = r;
	rgb_triple->g = g;
	rgb_triple->b = b;
	return (rgb_triple);
}

static char	*build_new_str_without_spaces(char **arr)
{
	char	*helper;
	char	*ret;
	int		i;
	int		j;

	helper = ft_calloc(str_len_without_spaces_nl(arr) + 1, 1);
	if (!helper)
		return (NULL);
	j = 0;
	arr++;
	while (*arr)
	{
		i = 0;
		while ((*arr)[i])
		{
			if ((*arr)[i] != ' ' && (*arr)[i] != '\n')
				helper[j++] = (*arr)[i];
			i++;
		}
		arr++;
	}
	ret = helper;
	return (ret);
}

static char	**prepare_string_array(char **arr)
{
	char	*without_spaces;
	char	**str_arr;

	without_spaces = build_new_str_without_spaces(arr);
	if (!without_spaces)
		return (NULL);
	str_arr = ft_split(without_spaces, ',');
	free(without_spaces);
	return (str_arr);
}

t_rgb_triple	*parse_rgb_triple(char **arr)
{
	t_rgb_triple	*rgb_triple;
	char			**str_arr;

	str_arr = prepare_string_array(arr);
	if (!str_arr || str_arr_len(str_arr) != 3 || !is_number(str_arr[0]) || \
		!is_number(str_arr[1]) || !is_number(str_arr[2]))
	{
		if (str_arr)
			free_strarray(str_arr);
		return (NULL);
	}
	rgb_triple = get_rgb_triple(str_arr);
	return (rgb_triple);
}

int	parse_floor_ceiling(t_data *data, char **arr)
{
	t_rgb_triple	*rgb;

	rgb = parse_rgb_triple(arr);
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
