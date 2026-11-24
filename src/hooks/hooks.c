/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:33:02 by olshklya          #+#    #+#             */
/*   Updated: 2026/11/24 15:33:03 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int key, t_cub *cub)
{
	if (key == KEY_ESC)
		clean_exit(cub, 0);
	if (key == KEY_W)
		cub->player.mov_w = 1;
	if (key == KEY_S)
		cub->player.mov_s = 1;
	if (key == KEY_A)
		cub->player.mov_a = 1;
	if (key == KEY_D)
		cub->player.mov_d = 1;
	if (key == KEY_LEFT)
		cub->player.rotate_l = 1;
	if (key == KEY_RIGHT)
		cub->player.rotate_r = 1;
	return (0);
}

int	key_release(int key, t_cub *cub)
{
	if (key == KEY_W)
		cub->player.mov_w = 0;
	if (key == KEY_S)
		cub->player.mov_s = 0;
	if (key == KEY_A)
		cub->player.mov_a = 0;
	if (key == KEY_D)
		cub->player.mov_d = 0;
	if (key == KEY_LEFT)
		cub->player.rotate_l = 0;
	if (key == KEY_RIGHT)
		cub->player.rotate_r = 0;
	return (0);
}

int	close_window(t_cub *cub)
{
	clean_exit(cub, 0);
	return (0);
}