#include "../../includes/cub3d.h"
#include <stdio.h>

int free_tgrid(char **tgrid, int height) {
  int y;

  y = 0;
  while (y < height)
    free(tgrid[y++]);
  free(tgrid);
  return (0);
}

char **dup_grid(t_map *map) {
  char **copy;
  int y;

  y = 0;
  copy = malloc(sizeof(char *) * map->height);
  if (!copy)
    return (NULL);
  while (y < map->height) {
    copy[y] = ft_strdup(map->grid[y]);
    if (!copy[y]) {
      while (y > 0)
        free(copy[--y]);
      free(copy);
      return (NULL);
    }
    y++;
  }
  return (copy);
}

int floodfill(t_map *map, char **tgrid, int x, int y) {
  if (x < 0 || y < 0 || x >= map->width || y >= map->height ||
      tgrid[y][x] == ' ')
    return (0);
  if (tgrid[y][x] == '1' || tgrid[y][x] == 'V')
    return (1);
  tgrid[y][x] = 'V';
  if (!floodfill(map, tgrid, x + 1, y))
    return (0);
  if (!floodfill(map, tgrid, x - 1, y))
    return (0);
  if (!floodfill(map, tgrid, x, y + 1))
    return (0);
  if (!floodfill(map, tgrid, x, y - 1))
    return (0);
  return (1);
}

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
    while (x < map->width) {
      /*if (!verif_w(y, x, map))
        return (0);*/
      if (map->grid[y][x] != '0' && map->grid[y][x] != '1' &&
          map->grid[y][x] != 'N' && map->grid[y][x] != 'S' &&
          map->grid[y][x] != 'E' && map->grid[y][x] != 'W' &&
          map->grid[y][x] != ' ')
        return (0);
      x++;
    }
    y++;
  }
  return (1);
}
