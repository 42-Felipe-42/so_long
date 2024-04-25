/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:25:16 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:29:36 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Permet de verifier si le npc peux bouger partout depuis 
//sa position de depart 'M'
void	flood_fill_npc(t_data *game, int x, int y)
{
	if (game->grid[y][x] == VISITED_C || game->grid[y][x] == VISITED_E
		|| game->grid[y][x] == VISITED_M || game->grid[y][x] == VISITED_P
		|| game->grid[y][x] == PATH_COVERED || game->grid[y][x] == '1' || x < 0
		|| y < 0 || x >= game->width || y >= game->height)
		return ;
	if (game->grid[y][x] == 'E')
		game->grid[y][x] = VISITED_E;
	if (game->grid[y][x] == 'C')
		game->grid[y][x] = VISITED_C;
	if (game->grid[y][x] == '0')
		game->grid[y][x] = PATH_COVERED;
	if (game->grid[y][x] == 'M')
	{
		game->grid[y][x] = VISITED_M;
		game->npc.nb_npc_see++;
	}
	if (game->grid[y][x] == 'P')
		game->grid[y][x] = VISITED_P;
	flood_fill_npc(game, x + 1, y);
	flood_fill_npc(game, x - 1, y);
	flood_fill_npc(game, x, y + 1);
	flood_fill_npc(game, x, y - 1);
}

//  (x + 1, y) explore la case a droite
//  (x - 1, y) explore la case a gauche
//  (x, y + 1) explore la case en bas
//  (x, y - 1) explore la case en haut
// Permet de verifier si tout les collectibles/sortie sont accesible depuis 'P'
void	ft_flood_fill(t_data *game, int x, int y)
{
	if (game->grid[y][x] == VISITED_C || game->grid[y][x] == VISITED_E
		|| game->grid[y][x] == 'M' || game->grid[y][x] == VISITED_P
		|| game->grid[y][x] == PATH_COVERED || game->grid[y][x] == '1' || x < 0
		|| y < 0 || x >= game->width || y >= game->height)
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
	ft_flood_fill(game, x + 1, y);
	ft_flood_fill(game, x - 1, y);
	ft_flood_fill(game, x, y + 1);
	ft_flood_fill(game, x, y - 1);
}

// Remet la map avec les bons char
void	ft_reload_map(t_data *game)
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
			if (game->grid[y][x] == VISITED_M)
				game->grid[y][x] = 'M';
			x++;
		}
		y++;
	}
}

// Affiche un message selon l'erreur rencontre
void	ft_parse_error(t_data *game)
{
	if (game->start != 1 || game->exit != 1 || game->collectible <= 0)
		ft_printf(ROUGE "Error\n" RESETCOLOR);
	if (game->start != 1)
		ft_printf(ROUGE "Map has no player or more than 1!\n" RESETCOLOR);
	if (game->exit != 1)
		ft_printf(ROUGE "Map has no exit or more than 1!\n" RESETCOLOR);
	if (game->collectible == 0)
		ft_printf(ROUGE "Map has no collectibles!\n" RESETCOLOR);
	if (game->npc.nb_npc < 1)
		ft_printf(ROUGE "U need to have one enemy!\n" RESETCOLOR);
}

// Appel de toute les fonctions necessaire pour le parsing
void	ft_parse_map(t_data *game, char *filename)
{
	check_format(filename);
	ft_init_struct(game);
	get_dimensions(filename, game);
	read_map(filename, game);
	check_is_rectangle(game);
	ft_error_message(game);
	check_nb_enemy(game);
	ft_printf("\033[1;32mTHE MAP IS VALID.\n     ENJOY\033[0m.\n");
}
