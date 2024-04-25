/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:41:21 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:22:21 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"
#include "so_long.h"

// Verifie le format du fichier qui essaye d'etre ouvert
int	check_format(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len > 4 && (!ft_strcmp(map + len - 4, ".ber")) == 0)
	{
		ft_printf(ROUGE "Error\nThis is not the good format.\n" RESETCOLOR);
		exit(0);
	}
	return (1);
}
// Check si chaque ligne (x) et la compare avec game->width
// pour verifier si c'est bien un rectangle

int	check_is_rectangle(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] != '\0' && game->grid[y][x] != '\n')
				x++;
			else
				break ;
		}
		if (game->grid[y][0] == '\n')
			return (ft_printf(ROUGE "Error\nEmpty ligne.\n" RESETCOLOR),
				free_grid(game), exit(0), 0);
		if (x != game->width)
			return (ft_printf(ROUGE "Error\nNot a rectangle.\n" RESETCOLOR),
				free_grid(game), exit(0), 0);
		y++;
	}
	return (1);
}

// Compte de le nombre de collectible dispo sur la map
// et donne la position de depart du joueur
int	check_collectible(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->grid[y][x] == 'P')
			{
				game->start_y = y;
				game->start_x = x;
				game->start++;
			}
			if (game->grid[y][x] == 'E')
				game->exit++;
			if (game->grid[y][x] == 'C')
				game->collectible++;
		}
	}
	if (game->start != 1 || game->exit != 1 || game->collectible < 1)
		return (0);
	return (1);
}

// Check si chaque ligne ce fini par un '1' ou si la 1ere ou la derniere
// ligne a que des 1, verifie aussi si les char sont valides
int	check_is_close(t_data *game)
{
	int		x;
	int		y;
	char	*valid_char;

	valid_char = "01PEC";
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if ((ft_strchr(valid_char, game->grid[y][x]) == 0))
				return (-1);
			if ((y == game->height - 1 && game->grid[y][x] != '1') || (y == 0
					&& game->grid[y][x] != '1'))
				return (0);
			else if ((x == game->width - 1 && game->grid[y][x] != '1')
				|| (x == 0 && game->grid[y][x] != '1'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
