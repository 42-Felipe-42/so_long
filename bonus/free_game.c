/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:06:25 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:25:33 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Libere l'espace allouer pour chaque image
void	free_assets_player(t_data *game)
{
	if (game->img.player_s)
		mlx_destroy_image(game->map.mlx_ptr, game->img.player_s);
	if (game->img.player_d)
		mlx_destroy_image(game->map.mlx_ptr, game->img.player_d);
	if (game->img.player_a)
		mlx_destroy_image(game->map.mlx_ptr, game->img.player_a);
	if (game->img.player_w)
		mlx_destroy_image(game->map.mlx_ptr, game->img.player_w);
	if (game->img.dance_f1)
		mlx_destroy_image(game->map.mlx_ptr, game->img.dance_f1);
	if (game->img.dance_f2)
		mlx_destroy_image(game->map.mlx_ptr, game->img.dance_f2);
	if (game->img.dance_f3)
		mlx_destroy_image(game->map.mlx_ptr, game->img.dance_f3);
	if (game->img.dance_b1)
		mlx_destroy_image(game->map.mlx_ptr, game->img.dance_b1);
	if (game->img.dance_b2)
		mlx_destroy_image(game->map.mlx_ptr, game->img.dance_b2);
	if (game->img.dance_b3)
		mlx_destroy_image(game->map.mlx_ptr, game->img.dance_b3);
}

//Libere l'espace allouer pour chaque image
void	free_assets_npc(t_data *game)
{
	if (game->img.npc_s)
		mlx_destroy_image(game->map.mlx_ptr, game->img.npc_s);
	if (game->img.npc_d)
		mlx_destroy_image(game->map.mlx_ptr, game->img.npc_d);
	if (game->img.npc_a)
		mlx_destroy_image(game->map.mlx_ptr, game->img.npc_a);
	if (game->img.npc_w)
		mlx_destroy_image(game->map.mlx_ptr, game->img.npc_w);
	if (game->img.die_img)
		mlx_destroy_image(game->map.mlx_ptr, game->img.die_img);
	if (game->img.player_s1)
		mlx_destroy_image(game->map.mlx_ptr, game->img.player_s1);
	if (game->img.black_case)
		mlx_destroy_image(game->map.mlx_ptr, game->img.black_case);
}

//Free l'espace alloue pour chaque npc
void	free_npc(t_data *game)
{
	while (game->npc_number)
	{
		free(game->npc_number);
		game->npc_number = NULL;
	}
}

// Affiche un message selon l'erreur rencontre
int	ft_error_message(t_data *game)
{
	if (ft_check_is_close(game) == 0)
		return (ft_printf(ROUGE "Error\nMap not closed\n" RESETCOLOR),
			free_grid(game), exit(0), 0);
	if (ft_check_is_close(game) == -1)
		return (ft_printf(ROUGE "Error\nPut only '1,0,E,P,C,M'\n" RESETCOLOR),
			free_grid(game), exit(0), 0);
	if (check_collectible(game) != 1 || check_npc_pos(game) == 0)
		return (ft_parse_error(game), free_grid(game), exit(0), 0);
	ft_flood_fill(game, game->start_x, game->start_y);
	reload_map(game);
	if (game->collected_collectible != game->collectible)
		return (ft_printf(ROUGE "Error\nAll the collectible"),
			ft_printf(" can't be recolted.\n" RESETCOLOR), free_grid(game),
			exit(0), 0);
	else if (game->found_exit != game->exit)
		return (ft_printf(ROUGE "Error\nExit not found on the map.\n" RESETCOLOR),
			free_grid(game), exit(0), 0);
	return (1);
}
