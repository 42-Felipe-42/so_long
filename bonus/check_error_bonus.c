/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:27:29 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:25:11 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Check si chaque ligne ce fini par un '1' ou si la 1ere ou la derniere 
//ligne a que des 1, verifie aussi si les char sont valides
int	ft_check_is_close(t_data *game)
{
	int		x;
	int		y;
	char	*valid_char;

	valid_char = "01PECM";
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

//Recupere la position du npc et verifie qu'il y en a plus d'un
int	check_npc_pos(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'M')
				game->npc.nb_npc++;
			x++;
		}
		y++;
	}
	if (game->npc.nb_npc < 1)
		return (0);
	return (1);
}

//Verifie que chaque enemy peut bouger et que leur nombre 
//correspond bien a ceux compte plus tot
void	check_nb_enemy(t_data *game)
{
	int	i;

	i = 0;
	init_nb_npc(game);
	while (i < game->npc.nb_npc)
	{
		game->npc.nb_npc_see = 0;
		flood_fill_npc(game, game->npc_number[i].pos_x,
			game->npc_number[i].pos_y);
		ft_reload_map(game);
		if (game->npc.nb_npc_see != game->npc.nb_npc)
		{
			ft_printf(ROUGE "Error\nAll the villain can't move.\n" RESETCOLOR);
			free_grid(game);
			exit(0);
		}
		i++;
	}
}
