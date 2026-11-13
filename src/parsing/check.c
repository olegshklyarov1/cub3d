#include "../../includes/cub3d.h"

int verif_w(int y, int x, t_map *map) {
  int verif;

  verif = 1;
  if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 2) {
    if (map->grid[y][x] != '1')
      return (0);
    else if (map->grid[y][x] != '0' && map->grid[y][x] != '1')
      return (0);
  }
  return (verif);
}

int check_chars(t_map *map) {
  int y;
  int x;

  y = 0;
  while (y < map->height) {
    x = 0;
    while (x < map->width - 1) {
      if (!verif_w(y, x, map))
        return (0);
      if (map->grid[y][x + 1] == '\n')
        map->grid[y][x + 1] = '\0';
      x++;
    }
    y++;
  }
  return (1);
}
