/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:48:55 by olshklya          #+#    #+#             */
/*   Updated: 2025/10/15 17:50:35 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	r;
	int	nbr;

	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	if (n > INT_MIN && n <= INT_MAX)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		r = n % 10;
		nbr = n / 10;
		r += 48;
		if (nbr > 0)
			ft_putnbr_fd(nbr, fd);
		write(fd, &r, 1);
	}
}
