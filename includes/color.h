/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:00:00 by olshklya          #+#    #+#             */
/*   Updated: 2026/11/24 15:44:27 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/* Format 0xRRGGBB (mlx sur Linux, pas de canal alpha utilise) */

/* Basiques */
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define YELLOW			0xFFFF00
# define CYAN			0x00FFFF
# define MAGENTA		0xFF00FF

/* Gris */
# define GREY_LIGHT		0xC8C8C8
# define GREY			0x808080
# define GREY_DARK		0x323232

/* Sol et plafond par defaut (si besoin d'un fallback) */
# define DEFAULT_FLOOR	0x505050
# define DEFAULT_CEIL	0x87CEEB

/* Murs sans texture (debug du raycasting, un par face) */
# define WALL_NO		0xE74C3C
# define WALL_SO		0x3498DB
# define WALL_EA		0x2ECC71
# define WALL_WE		0xF1C40F

/* Minimap (bonus) */
# define MM_WALL		0xFFFFFF
# define MM_FLOOR		0x202020
# define MM_PLAYER		0xFF0000
# define MM_RAY			0xFFFF00
# define MM_BORDER		0x808080

#endif

