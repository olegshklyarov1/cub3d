#include "../../includes/cub3d.h"

int check_map(t_cub *cub) {
  char **tgrid;

  tgrid = dup_grid(cub->map);
  if (!tgrid)
    return (0);
  if (!floodfill(cub->map, tgrid, cub->player->pos_x, cub->player->pos_y)) {
    free_tgrid(tgrid, cub->map->height);
    return (0);
  }
  free_tgrid(tgrid, cub->map->height);
  return (1);
}

int find_player(t_player *player, t_map *map) {
  int y;
  int x;
  int verif;

  verif = 0;
  y = 0;
  while (y < map->height) {
    x = 0;
    while (x < map->width) {
      if (map->grid[y][x] == 'N' || map->grid[y][x] == 'W' ||
          map->grid[y][x] == 'E' || map->grid[y][x] == 'S') {
        player->pos_x = x;
        player->pos_y = y;
        verif++;
      }
      x++;
    }
    y++;
  }
  if (verif != 1)
    return (0);
  return (1);
}
