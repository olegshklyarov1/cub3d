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
    }
    found[type]++;
  }
  return (1);
}

int get_rgb(char *line, int *found, t_conf type, t_cub *cub) {
  /*int r, g, b;
  char **rgb;
  if (type >= cF) {
    // verif conf
    rgb = ft_split(line, ',');
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
     convert rgb n save
  found[type]++;
}
return (1);
*/

  (void)line;
  (void)cub;
  if (type >= cF)
    found[type]++;
  return (1);
}

int verif_conf(t_cub *cub, int *found) {
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
      if (!get_rgb(line, found, id, cub)) {
        id = -1;
        break;
      }
    }
    free(line);
    line = get_next_line(fd);
  }
  free(line);
  close(fd);
  if (verif_conf(cub, found) || id == -1)
    return (0);
  return (1);
}
