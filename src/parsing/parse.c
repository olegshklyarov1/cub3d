#include "../../includes/cub3d.h"

int check_extension(const char *path) {
  int len;

  len = ft_strlen(path);
  if (len < 4)
    return (0);
  return (ft_strncmp(path + len - 4, ".cub", 4) == 0);
}

int find_map(char *line) {
  int i;
  int valid;

  i = 0;
  valid = 0;
  while (line[i]) {
    if (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S' ||
        line[i] == 'E' || line[i] == 'W')
      valid = 1;
    else if (line[i] != ' ' && line[i] != '\n')
      return (0);
    i++;
  }
  return (valid);
}

/* potentielment ajouter un strlen qui verifie le dernier caracter ou ligne*/
int count_map(const char *path, int *height, int *width) {
  char *line;
  int fd, len;

  len = 0;
  *height = 0;
  *width = 0;
  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (0);
  line = get_next_line(fd);
  while (line && !find_map(line)) {
    free(line);
    line = get_next_line(fd);
  }
  while (line) {
    len = ft_strlen(line);
    if (len > 0)
      if (line[len - 1] == '\n')
        len = len - 1;
    if (len > *width)
      *width = len;
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

int cpy_map(t_map *map, char *line, int i) {
  int n;
  int len;
  n = 0;
  len = ft_strlen(line);
  if (len > 0 && line[len - 1] == '\n')
    len = len - 1;
  map->grid[i] = malloc(sizeof(char) * map->width + 1);
  if (!map->grid[i])
    return (0);
  ft_memcpy(map->grid[i], line, len);
  while (n + len < map->width) {
    map->grid[i][len + n] = ' ';
    n++;
  }
  map->grid[i][len + n] = '\0';
  return (1);
}

int fill_grid(t_map *map, int fd) {
  char *line;
  int i;
  i = 0;
  init_map(map);
  line = get_next_line(fd);
  while (line && !find_map(line)) {
    free(line);
    line = get_next_line(fd);
  }
  while (line && i < map->height) {
    if (!cpy_map(map, line, i)) {
      free(line);
      return (0);
    }
    free(line);
    line = get_next_line(fd);
    i++;
  }
  if (i != map->height)
    return (0);
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
  map->height = height;
  map->width = width;
  map->grid = malloc(sizeof(char *) * map->height);
  if (!map->grid)
    return (free(map), NULL);
  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (free(map->grid), free(map), NULL);
  if (!fill_grid(map, fd)) {
    free_map(map);
    return (NULL);
  }
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
    return (write(2, "Error\nNo Player Found\n", 22), 0);
  }
  if (!check_map(cub)) {
    free_map(cub->map);
    return (write(2, "Error\nNeed closed map\n", 22), 0);
  }
  printf("%f %f", cub->player->pos_x, cub->player->pos_y);
  printf("passed");
  return 0;
}
