/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:37:11 by akarahan          #+#    #+#             */
/*   Updated: 2022/09/29 14:48:18 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>
# include "./libft/includes/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define WIDTH 1024
# define HEIGHT 780

# ifdef __APPLE__
enum e_keys {
	ON_DESTROY = 17,
	ESC = 53,
	UP = 126,
	DOWN = 125,
	LEFT = 123,
	RIGHT = 124,
	PLUS = 27,
	MINUS = 24,
	ZERO = 29,
	Z_KEY = 6,
	X_KEY = 7,
	Q_KEY = 12,
	W_KEY = 13,
	E_KEY = 14,
	I_KEY = 34,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 22,
	KEY_6 = 23,
	AYU_B = 0x39bae6,
	AYU_Y = 0xffb454
};
#elif __linux__
enum e_keys{
	ON_DESTROY = 17,
	ESC = 65307,
	UP = 126,
	DOWN = 125,
	LEFT = 65361,
	RIGHT = 65363,
	PLUS = 27,
	MINUS = 24,
	ZERO = 29,
	Z_KEY = 6,
	X_KEY = 7,
	Q_KEY = 12,
	W_KEY = 119,
	E_KEY = 14,
	I_KEY = 34,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 22,
	KEY_6 = 23,
	AYU_B = 0x39bae6,
	AYU_Y = 0xffb454
};
#endif

typedef struct s_line
{
	float	x_s;
	float	y_s;
	int		clr_s;
	int		clr_e;
	float	dx;
	float	dy;
	float	x;
	float	y;
	int		z;
	float	x1;
	float	y1;
	int		z1;
}				t_line;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		width;
	int		height;
	int		**tab;
	int		zoom;
	int		default_zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		z_max;
	int		z_min;
	float	angle;
	float	alpha;
	float	beta;
	float	gamma;
	int		ch_height;
	int		proj;
	int		is_clear;
}				t_fdf;

/* parse_map.c */
void	parse_map(t_fdf *fdf, char *fname);

/* error.c */
void	handle_error(void);

/* handle_window.c */
void	handle_window(t_fdf *fdf);
void	my_pixel_put(t_fdf *fdf, int x, int y, int color);

/* handle_key.c */
int		handle_key(int key, t_fdf *fdf);

/* checks.c */
void	rot_check(t_fdf *fdf, int key);
void	move_zoom_check(t_fdf *fdf, int key);
void	proj_check(t_fdf *fdf, int key);
void	iso_check(t_fdf *fdf, int key);

/* draw.c */
void	dda(t_fdf *fdf, t_line line);
void	draw_map(t_fdf *fdf);

/* draw_utils.c */
void	isometric(float *x, float *y, int z, t_fdf *fdf);
void	zoom_xyz(t_fdf *fdf, t_line *line);
void	rotate_xyz(t_fdf *fdf, float *x, float *y, int *z);
void	move_xyz(t_fdf *fdf, t_line *line);

/* colors.c */
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/* color_utils.c */
float	percent(int start, int end, int curr);
int		get_light(int clr1, int clr2, float perc);
int		lerp(t_line *line, float x, float y);
int		get_z_clr(t_fdf *fdf, int z);

/* utils.c */
void	print_arr(t_fdf *fdf);
void	change_height(t_fdf *fdf, int factor);
void	find_min_max(t_fdf *fdf);

/* fdf_utils.c */
void	default_pos(t_fdf *fdf);
void	default_zoom(t_fdf *fdf);
void	init_fdf(t_fdf *fdf);
int		close_app(t_fdf *fdf);

#endif
