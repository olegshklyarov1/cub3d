/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:42:31 by olshklya          #+#    #+#             */
/*   Updated: 2026/11/24 15:19:21 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	load_tex(t_cub *cub, t_tex *tex)
{
	tex->img.img_ptr = mlx_xpm_file_to_image(cub->mlx, tex->path,
			&tex->width, &tex->height);
	if (!tex->img.img_ptr)
		return (1);
	tex->img.addr = mlx_get_data_addr(tex->img.img_ptr, &tex->img.bpp,
			&tex->img.line_len, &tex->img.endian);
	if (!tex->img.addr)
		return (1);
	return (0);
}

int	init_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!cub->tex[i].path || load_tex(cub, &cub->tex[i]))
		{
			ft_putstr_fd("Error\nCannot load texture\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

void	free_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->tex[i].img.img_ptr)
			mlx_destroy_image(cub->mlx, cub->tex[i].img.img_ptr);
		free(cub->tex[i].path);
		i++;
	}
}