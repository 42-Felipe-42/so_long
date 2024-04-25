/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:25:07 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:29:18 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Check si il n'y a pas de mur a gauche quand la touche 'a' est presse
void	npc_move_left(t_data *game, t_npc *npc, int i)
{
	if (game->grid[game->npc_number[i].pos_y][game->npc_number[i].pos_x
		- 1] == '0')
	{
		npc->direction = 'L';
		game->grid[game->npc_number[i].pos_y][game->npc_number[i].pos_x] = '0';
		put_image_window(game, game->map.floor_img, game->npc_number[i].pos_x,
			game->npc_number[i].pos_y);
		game->npc_number[i].pos_x--;
		put_image_window(game, game->img.npc_a, game->npc_number[i].pos_x,
			game->npc_number[i].pos_y);
		game->grid[game->npc_number[i].pos_y][game->npc_number[i].pos_x] = 'M';
	}
}

//Check si il n'y a pas de mur a droite quand la touche 'd' est presse
void	npc_move_right(t_data *game, t_npc *npc, int i)
{
	if (game->grid[game->npc_number[i].pos_y][game->npc_number[i].pos_x
		+ 1] == '0')
	{
		npc->direction = 'R';
		game->grid[game->npc_number[i].pos_y][game->npc_number[i].pos_x] = '0';
		put_image_window(game, game->map.floor_img, game->npc_number[i].pos_x,
			game->npc_number[i].pos_y);
		game->npc_number[i].pos_x++;
		put_image_window(game, game->img.npc_d, game->npc_number[i].pos_x,
			game->npc_number[i].pos_y);
		game->grid[game->npc_number[i].pos_y][game->npc_number[i].pos_x] = 'M';
	}
}

//Check si il n'y a pas de mur en bas quand la touche 's' est presse
void	npc_move_down(t_data *game, t_npc *npc, int i)
{
	if (game->grid[game->npc_number[i].pos_y
			+ 1][game->npc_number[i].pos_x] == '0')
	{
		npc->direction = 'D';
		game->grid[game->npc_number[i].pos_y][game->npc_number[i].pos_x] = '0';
		put_image_window(game, game->map.floor_img, game->npc_number[i].pos_x,
			game->npc_number[i].pos_y);
		game->npc_number[i].pos_y++;
		put_image_window(game, game->img.npc_s, game->npc_number[i].pos_x,
			game->npc_number[i].pos_y);
		game->grid[game->npc_number[i].pos_y][game->npc_number[i].pos_x] = 'M';
	}
}

//Check si il n'y a pas de mur en haut quand la touche 'w' est presse
void	npc_move_up(t_data *game, t_npc *npc, int i)
{
	if (game->grid[game->npc_number[i].pos_y
			- 1][game->npc_number[i].pos_x] == '0')
	{
		npc->direction = 'U';
		game->grid[game->npc_number[i].pos_y][game->npc_number[i].pos_x] = '0';
		put_image_window(game, game->map.floor_img, game->npc_number[i].pos_x,
			game->npc_number[i].pos_y);
		game->npc_number[i].pos_y--;
		put_image_window(game, game->img.npc_w, game->npc_number[i].pos_x,
			game->npc_number[i].pos_y);
		game->grid[game->npc_number[i].pos_y][game->npc_number[i].pos_x] = 'M';
	}
}

//Verifie si au prochain move du npc il y a le joueur sur la case du devant
bool	check_in_front_npc(t_data *game, t_npc *npc, int i)
{
	int	npc_x;
	int	npc_y;

	while (i < game->npc.nb_npc)
	{
		npc_x = game->npc_number[i].pos_x;
		npc_y = game->npc_number[i].pos_y;
		if (npc->direction == 'L')
			npc_x--;
		else if (npc->direction == 'R')
			npc_x++;
		else if (npc->direction == 'D')
			npc_y++;
		else if (npc->direction == 'U')
			npc_y--;
		if (game->start_x == npc_x && game->start_y == npc_y)
		{
			ft_printf(ROUGE "The old Pokémon trainer challenged ");
			ft_printf("you to a duel, but you're not");
			ft_printf(" trained enough to beat him.\n" RESETCOLOR);
			return (true);
		}
		i++;
	}
	return (false);
}
