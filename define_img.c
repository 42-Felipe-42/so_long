/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:09:07 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:23:07 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"
#include "so_long.h"

//Affiche des images selon les char rencontre 
void	draw_map(t_data *game, t_map *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			x = j * game->img_size;
			y = i * game->img_size;
			if (game->grid[i][j] == '0' || game->grid[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->floor_img, x, y);
			else if (game->grid[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->wall_img, x, y);
			j++;
		}
		i++;
	}
}

//Affiche des images selon les char rencontre 
void	draw_visu(t_data *game, t_map *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			x = j * game->img_size;
			y = i * game->img_size;
			if (game->grid[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->collect_img, x, y);
			else if (game->grid[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->perso_w_img, x, y);
			j++;
		}
		i++;
	}
}

//En cas d'erreur avec les fichiers xpm
void	error_xpm(t_data *game)
{
	ft_printf(ROUGE "Error with xpm files \n" RESETCOLOR);
	free_img(game);
	close_display(game);
}

//Libere les donnees init avec mlx_init et free le reste 
void	close_display(t_data *game)
{
	mlx_destroy_display(game->map.mlx_ptr);
	free(game->map.mlx_ptr);
	free_grid(game);
	exit(0);
}

//Free toutes ce qui a etait alloue au cours du programme
int	close_game(t_data *game)
{
	free_img(game);
	mlx_destroy_window(game->map.mlx_ptr, game->map.win_ptr);
	close_display(game);
	return (0);
}
