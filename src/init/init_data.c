/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:10:29 by olshklya          #+#    #+#             */
/*   Updated: 2026/11/24 14:30:24 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	init_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->mov_w = 0;
	player->mov_s = 0;
	player->mov_a = 0;
	player->mov_d = 0;
	player->rotate_l = 0;
	player->rotate_r = 0;
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0.0;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0.0;
	ray->side_dist_y = 0.0;
	ray->delta_dist_x = 0.0;
	ray->delta_dist_y = 0.0;
	ray->perp_dist = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->line_h = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->tex_x = 0;
	ray->wall_x = 0.0;
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->floor_color = 0;
	map->ceil_color = 0;
}

void	init_img(t_img *img)
{
	img->img_ptr = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

void	init_tex(t_tex *tex)
{
	init_img(&tex->img);
	tex->path = NULL;
	tex->width = 0;
	tex->height = 0;

}

void	init_data(t_cub *cub)
{
	int	i;

	cub->mlx = NULL;
	cub->win = NULL;
	init_img(&cub->img);
	init_map(&cub->map);
	init_player(&cub->player);
	init_ray(&cub->ray);
	i = 0;
	while (i < 4)
	{
		init_tex(&cub->tex[i]);
		i++;
	}
}