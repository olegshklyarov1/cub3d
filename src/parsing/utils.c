#include "../../includes/cub3d.h"

char *cleanN(char *line) {
  char *start;

  start = line;
  while (*line != '\n' && *line)
    line++;
  if (*line == '\n')
    *line = '\0';
  return (start);
}
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
void free_split(char **split) {
  int i;

  i = 0;
  while (split[i]) {
    free(split[i]);
    i++;
  }
  free(split);
}

void save_player(t_map *map, t_player *player, int x, int y) {
  player->pos_x = x;
  player->pos_y = y;
  if (map->grid[y][x] == 'N') {
    player->dir_x = 0;
    player->dir_y = 1;
  } else if (map->grid[y][x] == 'S') {
    player->dir_x = 0;
    player->dir_y = -1;
  } else if (map->grid[y][x] == 'E') {
    player->dir_x = 1;
    player->dir_y = 0;
  } else if (map->grid[y][x] == 'W') {
    player->dir_x = -1;
    player->dir_y = 0;
  }
  map->grid[y][x] = '0';
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
        save_player(map, player, x, y);
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
