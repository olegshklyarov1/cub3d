/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:43:47 by olshklya          #+#    #+#             */
/*   Updated: 2026/11/02 15:43:59 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

/*void init(t_cub *cub) {
  t_player player;
  cub->player = player;
}*/

int main() {
  t_cub cub;
  init_data(&cub);
  pars_cub(&cub, "map.cub");
  return 1;
}
