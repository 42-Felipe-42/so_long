/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:36:34 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:29:48 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Free toutes ce qui a etait alloue au cours du programme
int	ft_close_game(t_data *game)
{
	free_img(game);
	free_assets_player(game);
	free_npc(game);
	free_assets_npc(game);
	mlx_destroy_window(game->map.mlx_ptr, game->map.win_ptr);
	close_display(game);
	return (0);
}

//En cas d'erreur avec les fichiers xpm
void	ft_error_xpm(t_data *game)
{
	ft_printf(ROUGE "Error with xpm files \n" RESETCOLOR);
	free_assets_player(game);
	free_npc(game);
	free_assets_npc(game);
	free_img(game);
	close_display(game);
}

//Pour eviter les appele repetitif a mlx_image
void	put_image_window(t_data *game, void *images, int x, int y)
{
	mlx_put_image_to_window(game->map.mlx_ptr, game->map.win_ptr, images, x
		* game->img_size, y * game->img_size);
}

//Affichage d'un carre noir 
void	put_black_case(t_data *game)
{
	mlx_put_image_to_window(game->map.mlx_ptr, game->map.win_ptr,
		game->img.black_case, (game->width - 1) * (game->img_size),
		(game->height) * (game->img_size));
}
