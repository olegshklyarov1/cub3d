/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:43:00 by olshklya          #+#    #+#             */
/*   Updated: 2026/11/24 15:45:34 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define WIN_W 1280
# define WIN_H 720
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_LEFT	65361
# define KEY_RIGHT	65363

typedef enum e_dir
{
	NO,
	SO,
	EA,
	WE
}	t_dir;

typedef struct	s_player
{
	double	pos_x; //player position on 2d grid
	double	pos_y;
	double	dir_x; //player direction vector component
	double	dir_y;
	double	plane_x; //camera plain component
	double	plane_y;
	int		mov_w;	// event hooks
	int		mov_s;
	int		mov_a;
	int		mov_d;
	int		rotate_l; //rotation flags
	int		rotate_r;
}	t_player;


typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int	map_x;
	int	map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_dist;
	int	step_x;
	int	step_y;
	int	side;
	int	line_h;
	int	draw_start;
	int	draw_end;
	int tex_x;
	double	wall_x;
}	t_ray;

typedef struct	s_img
{
	void	*img_ptr; //mlx_new_image pointer
	char	*addr;	//image data memory
	int		bpp; //bits per pixel (usually 32)
	int		line_len; //size of data line
	int		endian; //byte architecture
}	t_img;

typedef struct	s_tex
{
	t_img	img;
	char	*path;
	int		width;
	int		height;
}	t_tex;

typedef struct	s_map
{
	char	**grid;
	int		width;
	int		height;
	int		floor_color;
	int		ceil_color;
}	t_map;

//Main structure to be passed to all functions
typedef struct s_cub
{
	void		*mlx; //mlx instance pointer
	void		*win; //mlx window pointer
	t_img		img;  //main screen frame buffer
	t_map		map;  //parsing and map data
	t_player	player;//player
	t_ray		ray;   //raycasting map
	t_tex		tex[4]; //north, south, east, west texture assets
}	t_cub;


//init

void	init_data(t_cub *cub);
void	init_img(t_img *img);
void	init_ray(t_ray *ray);
int		init_mlx(t_cub *cub);
void	setup_hooks(t_cub *cub);
int		init_textures(t_cub *cub);
void	free_textures(t_cub *cub);

int		key_press(int key, t_cub *cub);
int		key_release(int key, t_cub *cub);
int		close_window(t_cub *cub);
int		render(t_cub *cub);
void	put_pixel(t_img *img, int x, int y, int color);
void	clean_exit(t_cub *cub, int code);

#endif