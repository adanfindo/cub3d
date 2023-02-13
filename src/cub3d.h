/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:03:23 by afindo          #+#    #+#             */
/*   Updated: 2022/09/15 14:34:37 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "utils/hashtable.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

# define MOV_STEP 0.0666f
# define ROT_STEP 0.0785f

# define SCREEN_HEIGHT 768
# define SCREEN_WIDTH 1024
# define FOV_DEG 90.0f

# ifdef __linux__
// Linux
enum e_keys
{
	KEY_W = 119,
	KEY_E = 101,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ARROW_LEFT = 65361,
	KEY_ARROW_RIGHT = 65363,
	KEY_ESCAPE = 65307
};
# else
// Mac
enum e_keys
{
	KEY_W = 13,
	KEY_E = 14,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ESCAPE = 53,
	KEY_ARROW_LEFT = 123,
	KEY_ARROW_RIGHT = 124,
};
# endif

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_rgb_triple
{
	__uint8_t	r;
	__uint8_t	g;
	__uint8_t	b;
}	t_rgb_triple;

typedef struct s_wall
{
	struct s_hashlist	***hashtable;
	struct s_data		*data;
	int					**pixels;
	int					width;
	int					height;
	int					n_keys;
	int					key_len;
}	t_wall;

typedef struct s_walls
{
	t_wall	*n;
	t_wall	*e;
	t_wall	*s;
	t_wall	*w;
	t_wall	*door;
}	t_walls;

enum e_tile
{
	tile_empty,
	tile_floor,
	tile_wall,
	tile_door,
	tile_door_open,
	tile_p_n,
	tile_p_e,
	tile_p_s,
	tile_p_w
};

typedef struct s_map
{
	int				**tiles;
	t_walls			*walls;
	int				*c_floor;
	int				*c_ceiling;
	int				map_found;
	int				height;
	int				width;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	bool	mov_forward;
	bool	mov_backward;
	bool	rot_left;
	bool	rot_right;
	bool	strafe_left;
	bool	strafe_right;
}	t_player;

typedef struct s_math
{
	double		*sin;
	double		*cos;
	double		*tan;
}	t_math;

typedef struct s_data
{
	t_map		*map;
	t_player	*player;
	t_math		*math;
	void		*mlx;
	void		*win;
}	t_data;

typedef struct s_raycast_h
{
	int		map_x;
	int		map_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		image_x;
	t_wall	*wall;
}	t_raycast_h;

//* INIT AND PARSING *//

t_data		*data_init(char *map_path);
void		parse_map_file(t_data *data, char *map_path);

int			parse_map_properties(t_data *data, char *map_path);
int			parse_floor_ceiling(t_data *data, char **arr);
void		parse_map_tiles(t_data *data, char *map_path);

int			parse_wall_image(t_data *data, char **arr);
int			wall_parse_properties(t_wall *wall, char *line);
int			wall_parse_keys(t_wall *wall, char *line);
int			wall_parse_pixels(t_wall *wall, char *line, int i);

void		check_map_init_player(t_data *data);
t_player	*player_init(t_data *data, int i, int j);

//* KEY AND MOUSE EVENTS *//

int			hook_key_press(int keycode, t_data *data);
int			hook_key_release(int keycode, t_data *data);
int			hook_mouse(int x, int y, t_data *data);
int			hook_exit(t_data *data);
void		open_door(t_data *data);

//* NAVIGATION *//

void		move(t_data *data);
void		translate_forward(t_data *data, t_player *p);
void		translate_backward(t_data *data, t_player *p);
void		translate_left(t_data *data, t_player *p);
void		translate_right(t_data *data, t_player *p);

//* RENDERING *//

void		render_scene(t_data *data);
void		render_minimap(t_data *data, t_image *image);
void		render_pov(t_data *data, t_image *image);
void		ray_cast(t_data *data, t_image *image, int ray_n);
void		draw(t_data *data, t_image *image, t_raycast_h *helper, int ray_n);

//* UTILS PARSING *//

int			is_no_ea_so_we_do(char *str);
int			is_map_line(char *str);
int			*encode_rgb(__uint8_t red, __uint8_t green, __uint8_t blue);

//* UTILS RENDERING *//

t_image		*image_init(void *mlx, int height, int width);
void		image_pix_put(t_image *image, int x, int y, int color);

//* UTILS EXIT *//

void		error_msg_exit(t_data *data, char *str);
void		error_fd_msg_exit(t_data *data, char *str, int fd);
void		error_str_fd_msg_exit(t_data *data, char *msg, \
									char *free_str, int fd);
void		error_exit(char *str);
void		cub_exit(t_data *data, int exit_code);
void		free_all(t_data *data);
void		mlx_destroy(t_data *data);
void		free_wall(t_wall *image);

//* UTILS MATH *//

t_math		*math_init(void);
void		math_free(t_math *math);
float		get_dir_x(float dir);
float		get_dir_y(float dir);

//* UTILS GENERAL *//

int			is_hex(char *str);
int			is_number(char *str);
int			str_arr_len(char **str_arr);
int			str_len_without_spaces_nl(char **arr);
int			**array_init(int height, int width);
char		*get_first_n_chars(char *str, int n_chars);
int			is_wall_door_closed(int tile);
void		free_strarray(char **arr);
int			free_str_return(char *str, int return_value);
void		free_intarray(int **int_arr);
void		image_free(t_image *image, t_data *data);

#endif