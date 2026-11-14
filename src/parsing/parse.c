#include "../../includes/cub3d.h"

int check_extension(const char *path) {
  int len;

  len = ft_strlen(path);
  if (len < 4)
    return (0);
  return (ft_strncmp(path + len - 4, ".cub", 4) == 0);
}

int count_map(const char *path, int *height, int *width) {
  char *line;
  int fd;

  *height = 0;
  *width = 0;
  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (0);
  line = get_next_line(fd);
  if (!line)
    return (close(fd), 0);
  *width = ft_strlen(line);
  while (line) {
    (*height)++;
    free(line);
    line = get_next_line(fd);
  }
  close(fd);
  return (1);
}

void free_map(t_map *map) {
  int y;

  y = 0;
  if (!map)
    return;
  while (y < map->height) {
    if (map->grid[y])
      free(map->grid[y]);
    y++;
  }
  free(map->grid);
  free(map);
}

int fill_grid(t_map *map, int fd) {
  char *line;
  int i;

  i = 0;
  while (i < map->height)
    map->grid[i++] = NULL;
  i = 0;
  line = get_next_line(fd);
  while (line && i < map->height) {
    map->grid[i] = line;
    i++;
    line = get_next_line(fd);
  }
  return (1);
}

t_map *load_map(const char *path) {
  int height;
  int width;
  int fd;
  t_map *map;

  if (!count_map(path, &height, &width))
    return (NULL);
  map = malloc(sizeof(t_map));
  if (!map)
    return (NULL);
  if (width * 64 > 1980 || height * 64 > 1080)
    return (free(map), NULL);
  map->height = height;
  map->width = width;
  map->grid = malloc(sizeof(char *) * map->height);
  if (!map->grid)
    return (free(map), NULL);
  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (free(map->grid), free(map), NULL);
  fill_grid(map, fd);
  close(fd);
  return (map);
}
int pars_cub(t_cub *cub, char *path) {
  (void)cub;
  if (!check_extension(path))
    return (write(2, "Error\nMap must have .cub extension\n", 35), 0);
  cub->map = load_map(path);
  if (!cub->map)
    return (write(2, "Error\nCannot load map\n", 22), 0);
  if (!check_chars(cub->map)) {
    free_map(cub->map);
    return (write(2, "Error\nInvalid map characters or borders\n", 40), 0);
  }
  if (!find_player(cub->player, cub->map)) {
    free_map(cub->map);
    return (write(2, "Error\nNo Player Found\n", 22), 1);
  }
  printf("%f %f", cub->player->pos_x, cub->player->pos_y);
  printf("passed");
  return 0;
}
