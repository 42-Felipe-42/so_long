/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:54:40 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:24:05 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"
#include "so_long.h"

//  (x + 1, y) explore la case a droite
//  (x - 1, y) explore la case a gauche
//  (x, y + 1) explore la case en bas
//  (x, y - 1) explore la case en haut
// Permet de verifier si tout les collectibles/sortie sont accesible depuis 'P'
void	flood_fill(t_data *game, int x, int y)
{
	if (game->grid[y][x] == VISITED_C || game->grid[y][x] == VISITED_E
		|| game->grid[y][x] == VISITED_P || game->grid[y][x] == PATH_COVERED
		|| game->grid[y][x] == '1' || x < 0 || y < 0 || x >= game->width
		|| y >= game->height)
		return ;
	if (game->grid[y][x] == 'E')
	{
		game->grid[y][x] = VISITED_E;
		game->found_exit++;
		game->exit_x = x;
		game->exit_y = y;
	}
	if (game->grid[y][x] == 'C')
	{
		game->grid[y][x] = VISITED_C;
		game->collected_collectible++;
	}
	if (game->grid[y][x] == '0')
		game->grid[y][x] = PATH_COVERED;
	if (game->grid[y][x] == 'P')
		game->grid[y][x] = VISITED_P;
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

// Remet la map avec les bons char
void	reload_map(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == VISITED_E)
				game->grid[y][x] = 'E';
			if (game->grid[y][x] == VISITED_C)
				game->grid[y][x] = 'C';
			if (game->grid[y][x] == PATH_COVERED)
				game->grid[y][x] = '0';
			if (game->grid[y][x] == VISITED_P)
				game->grid[y][x] = 'P';
			x++;
		}
		y++;
	}
}

// Affiche un message selon l'erreur rencontre
int	error_message(t_data *game)
{
	if (check_is_close(game) == 0)
		return (ft_printf(ROUGE "Error\nMap not closed\n" RESETCOLOR),
			free_grid(game), exit(0), 0);
	if (check_is_close(game) == -1)
		return (ft_printf(ROUGE "Error\nPut only '1,0,E,P,C'\n" RESETCOLOR),
			free_grid(game), exit(0), 0);
	if (check_collectible(game) != 1)
		return (parse_error(game), free_grid(game), exit(0), 0);
	flood_fill(game, game->start_x, game->start_y);
	reload_map(game);
	if (game->collected_collectible != game->collectible)
		return (ft_printf(ROUGE "Error\nAll the collectible"),
			ft_printf("can't be recolted.\n" RESETCOLOR), free_grid(game),
			exit(0), 0);
	else if (game->found_exit != game->exit)
		return (ft_printf(ROUGE "Error\nExit not found on the map.\n" RESETCOLOR),
			free_grid(game), exit(0), 0);
	return (1);
}

// Affiche un message selon l'erreur rencontre
void	parse_error(t_data *game)
{
	if (game->start != 1 || game->exit != 1 || game->collectible <= 0)
		ft_printf(ROUGE "Error\n" RESETCOLOR);
	if (game->start != 1)
		ft_printf(ROUGE "Map has no player or more than 1!\n" RESETCOLOR);
	if (game->exit != 1)
		ft_printf(ROUGE "Map has no exit or more than 1!\n" RESETCOLOR);
	if (game->collectible == 0)
		ft_printf(ROUGE "Map has no collectibles!\n" RESETCOLOR);
}

// Appel de toute les fonctions necessaire pour le parsing
void	parse_map(t_data *game, char *filename)
{
	check_format(filename);
	init_struct(game);
	get_dimensions(filename, game);
	read_map(filename, game);
	check_is_rectangle(game);
	error_message(game);
	ft_printf("                       \033[1;32mTHE MAP IS VALID\033[0m.\n");
}
