#include "../../includes/cub3d.h"
#include <unistd.h>

char *skip_wspace(char *str) {
  while (*str == ' ' || *str == '\t')
    str++;
  return (str);
}

int get_conf(char *line, int *found, t_conf type, t_cub *cub) {
  if (type <= tWE) {
    if (found[type] == 0) {
      if (line[2] != ' ' && line[2] != '\t')
        return (0);
      line += 2;
      line = skip_wspace(line);
      if (*line == '\0' || *line == '\n')
        return (0);
      cub->tex[type].path = ft_strdup(line);
      if (!cub->tex[type].path)
        return (0);
      cleanN(cub->tex[type].path);
    }
    found[type]++;
  }
  return (1);
}
int verif_form(char *line) {
  int nb;
  int verif;

  nb = 0;
  verif = 0;
  while (*line && *line != '\n') {
    if (*line >= '0' && *line <= '9')
      nb++;
    else if (*line == ',' && nb > 0 && verif < 2) {
      nb = 0;
      verif++;
    } else
      return (1);
    line++;
  }
  if (verif != 2 || nb == 0)
    return (1);
  return (0);
}

int conv_color(char **rgb) {
  int r, g, b, color;
  r = ft_atoi(rgb[0]);
  g = ft_atoi(rgb[1]);
  b = ft_atoi(rgb[2]);
  if (r > 255 || g > 255 || b > 255)
    return (-1);
  if (r < 0 || g < 0 || b < 0)
    return (-1);
  color = (r << 16) | (g << 8) | b;
  return (color);
}
int get_rgb(char *line, int *found, t_conf type, t_cub *cub) {
  int color;
  char **rgb;
  if (type >= cF) {
    if (found[type] == 0) {
      if (line[1] != ' ' && line[1] != '\t')
        return (0);
      line += 1;
      line = skip_wspace(line);
      if (verif_form(line))
        return (0);
      rgb = ft_split(line, ',');
      if (!rgb)
        return (0);
      color = conv_color(rgb);
      free_split(rgb);
      if (color == -1)
        return (0);
      if (type == cF)
        cub->map->floor_color = color;
      else if (type == cC)
        cub->map->ceil_color = color;
    }
  }
  if (type >= cF)
    found[type]++;
  return (1);
}

int verif_conf(int *found) {
  int i;
  i = 0;

  while (i < 6) {
    if (found[i] != 1)
      return (1);
    i++;
  }
  return (0);
}

int find_id(char *start) {
  if (!ft_strncmp(start, "NO", 2) && (start[2] == ' ' || start[2] == '\t'))
    return tNO;
  else if (!ft_strncmp(start, "SO", 2) && (start[2] == ' ' || start[2] == '\t'))
    return tSO;
  else if (!ft_strncmp(start, "EA", 2) && (start[2] == ' ' || start[2] == '\t'))
    return tEA;
  else if (!ft_strncmp(start, "WE", 2) && (start[2] == ' ' || start[2] == '\t'))
    return tWE;
  else if (!ft_strncmp(start, "C", 1) && (start[1] == ' ' || start[1] == '\t'))
    return cC;
  else if (!ft_strncmp(start, "F", 1) && (start[1] == ' ' || start[1] == '\t'))
    return cF;
  else
    return (-1);
}

int prcs_conf(t_cub *cub, char *path) {
  int found[6] = {0};
  char *line, *start;
  int id, fd;

  id = -1;
  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (0);
  line = get_next_line(fd);
  while (line && !find_map(line)) {
    start = skip_wspace(line);
    if (*start != '\0' && *start != '\n') {
      id = find_id(start);
      if (id == -1)
        break;
      if (!get_conf(start, found, id, cub)) {
        id = -1;
        break;
      }
      if (!get_rgb(start, found, id, cub)) {
        id = -1;
        break;
      }
    }
    free(line);
    line = get_next_line(fd);
  }
  free(line);
  close(fd);
  if (verif_conf(found) || id == -1)
    return (0);
  return (1);
}
