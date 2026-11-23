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
  printf("%s", cub.tex[0].path);
  return 1;
}
/*void print_map(t_map *map) {
  int i;

  i = 0;
  while (i < map->height) {
    printf("%s\n", map->grid[i]);
    i++;
  }
}
int main(void) {
  t_map *map;

  map = load_map("map.cub");
  if (!map) {
    printf("Erreur chargement map\n");
    return (1);
  }
  print_map(map);
  free_map(map);
  return (0);
}

int main(void) {
  int height;
  int width;

  if (!count_map("map.cub", &height, &width)) {
    printf("Erreur chargement map\n");
    return (1);
  }

  printf("Map height : %d\n", height);
  printf("Map width  : %d\n", width);

  return (0);
}*/
