/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:10:29 by olshklya          #+#    #+#             */
/*   Updated: 2026/11/11 17:29:48 by olshklya         ###   ########.fr       */
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

void	init_img(t_img *img)
{
	img->img_ptr = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

void	init_data(t_cub *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	init_player(&cub->player);
}