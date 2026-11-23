#include "../../includes/cub3d.h"

char *skip_wspace(char *str) {
  while (*str == ' ' || *str == '\t')
    str++;
  return (str);
}

int get_conf(char *line, int *found, t_conf type, t_cub *cub) {
  if (found[type])
    return (0);

  if (type <= tWE) {
    if (line[2] != ' ' && line[2] != '\t')
      return (0);
    line += 2;
    line = skip_wspace(line);
    if (*line == '\0' || *line == '\n')
      return (0);
    cub->tex[type].path = ft_strdup(line);
    if (!cub->tex[type].path)
      return (0);
    found[type] = 1;
  }
  return (1);
}

int get_rgb(char *line, int *found, t_conf type, t_cub *cub) {
  int r, g, b;
  char **rgb;
  if (found[type])
    return (0);

  if (type >= cF) {
    // verif conf
    rgb = ft_split(line, ',');
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    /* convert rgb n save */
    found[type] = 1;
  }
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
int prcs_conf(t_cub *cub, char *path) {
  int found[6] = {0};
  char *line, *start;
  int id, fd;
  fd = open(path, O_RDONLY);
  line = get_next_line(fd);
  while (line && !find_map(line)) {
    start = skip_wspace(line);
    if (!ft_strncmp(start, "NO", 2))
      id = tNO;
    else if (!ft_strncmp(start, "SO", 2))
      id = tSO;
    else if (!ft_strncmp(start, "EA", 2))
      id = tEA;
    else if (!ft_strncmp(start, "WE", 2))
      id = tWE;
    else if (!ft_strncmp(start, "C", 1))
      id = cC;
    else if (!ft_strncmp(start, "F", 1))
      id = cF;
    else
      return (1);
    if (!get_conf(start, found, id, cub))
      return (1);
    if (!get_rgb(line, found, id, cub))
      return (1);
    free(line);
    line = get_next_line(fd);
  }
  if (verif_conf(found))
    return (1);
  return (0);
}
