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
    if (!line)
      return (0);
    cub->tex[type].path = ft_strdup(line);
    if (!cub->tex[type].path)
      return (0);
  }
  found[type] = 1;
  return (1);
}

int prcs_conf(int fd, t_cub *cub) {
  int found[6] = {0};
  char *line, *start;
  int id;
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
    free(line);
    line = get_next_line(fd);
  }
  return (0);
}
