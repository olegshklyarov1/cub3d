/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:43:00 by olshklya          #+#    #+#             */
/*   Updated: 2026/11/11 17:27:24 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
// debug
#include <stdio.h>

#define WIN_W 1280
#define WIN_H 720

typedef enum e_dir { NO, SO, EA, WE } t_dir;

typedef struct s_player {
  double pos_x; // player position on 2d grid
  double pos_y;
  double dir_x; // player direction vector component
  double dir_y;
  double plane_x; // camera plain component
  double plane_y;
  int mov_w; // event hooks
  int mov_s;
  int mov_a;
  int mov_d;
  int rotate_l; // rotation flags
  int rotate_r;
} t_player;

typedef struct s_ray {

} t_ray;

typedef struct s_img {
  void *img_ptr; // mlx_new_image pointer
  char *addr;    // image data memory
  int bpp;       // bits per pixel (usually 32)
  int line_len;  // size of data line
  int endian;    // byte architecture
} t_img;

typedef struct s_tex {
  t_img img;
  char *path;
  int width;
  int height;
} t_tex;

typedef struct s_map {
  char **grid;
  int width;
  int height;
  int floor_color;
  int ceil_color;
} t_map;

// Main structure to be passed to all functions
typedef struct s_cub {
  void *mlx;       // mlx instance pointer
  void *win;       // mlx window pointer
  t_img img;       // main screen frame buffer
  t_map map;       // parsing and map data
  t_player player; // player
  t_ray ray;       // raycasting map
  t_tex tex[4];    // north, south, east, west texture assets
} t_cub;

// init

void init_data(t_cub *cub);
void init_img(t_img *img);

// gnl
char *get_next_line(int fd);
// parsing
int pars_cub(t_cub *cub, char *path);

#endif
