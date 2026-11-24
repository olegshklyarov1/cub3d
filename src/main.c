/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:43:47 by olshklya          #+#    #+#             */
/*   Updated: 2026/11/24 14:35:03 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3D map.cub\n", 2);
		return (1);
	}
	init_data(&cub);
	if (init_mlx(&cub))
		clean_exit(&cub, 1);
	setup_hooks(&cub);
	mlx_loop(cub.mlx);
	return (0);
}