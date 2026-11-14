#include "../../includes/cub3d.h"

int find_player(t_player *player, t_map *map) {
  int y;
  int x;
  y = 0;
  while (y < map->height) {
    x = 0;
    while (x < map->width) {
      if (map->grid[y][x] == 'N') {
        player->pos_x = x;
        player->pos_y = y;
        return (1);
      }
      x++;
    }
    y++;
  }
  return (0);
}
