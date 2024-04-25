/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:13:26 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/11 12:10:45 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include ".libft/ft_printf/ft_printf.h"
# include ".libft/getnextline/get_next_line.h"
# include ".libft/libft.h"
# include ".minilibx-linux/mlx.h"
# include "bonus/so_long_bonus.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <time.h>

# define NOIR "\033[0;30m"
# define ROUGE "\033[0;31m"
# define VERT "\033[0;32m"
# define JAUNE "\033[0;33m"
# define BLEU "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define BLANC "\033[0;37m"
# define RESETCOLOR "\033[0m"
# define VISITED_C '8'
# define VISITED_E 'A'
# define VISITED_P 'D'
# define VISITED_M 'L'
# define PATH_COVERED 'x'
# define PIXEL_SIZE 32

typedef struct s_npc
{
	int		pos_x;
	int		pos_y;
	int		nb_npc;
	int		nb_npc_see;
	char	direction;
}			t_npc;

typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*collect_img;
	void	*perso_w_img;
	void	*perso_s_img;
	void	*perso_a_img;
	void	*perso_d_img;
	void	*exit_img;
	void	*wall_img;
	void	*floor_img;

}			t_map;

typedef struct s_imgs
{
	void	*player_s1;
	void	*player_s;
	void	*player_w;
	void	*player_d;
	void	*player_a;
	void	*npc_s;
	void	*npc_d;
	void	*npc_a;
	void	*npc_w;
	void	*die_img;
	void	*dance_f1;
	void	*dance_f2;
	void	*dance_f3;
	void	*dance_b1;
	void	*dance_b2;
	void	*dance_b3;
	void	*black_case;
}			t_imgs;

typedef struct s_data
{
	char	**grid;
	int		width;
	int		height;
	int		walls;
	int		collectible;
	int		exit;
	int		found_exit;
	int		collected_collectible;
	int		steps;
	int		start;
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;
	int		img_size;
	int		dead;
	int		loop_npc;
	int		dead_player;
	int		started;
	int		sizex;
	int		sizey;
	t_npc	*npc_number;
	t_map	map;
	t_npc	npc;
	t_imgs	img;
}			t_data;

void		init_img_map(t_map *mlx, t_data *game);
void		init_img_player(t_map *mlx, t_data *game);
void		error_xpm(t_data *game);
void		close_display(t_data *game);
void		draw_visu(t_data *game, t_map *mlx);
int			close_game(t_data *game);
int			user_keypress(int keycode, t_data *game);
void		put_img(char *name_assets, t_data *game);
void		move_left(int keycode, t_data *game);
void		move_right(int keycode, t_data *game);
void		move_up(int keycode, t_data *game);
void		move_down(int keycode, t_data *game);
void		free_img(t_data *game);
void		draw_map(t_data *game, t_map *mlx);
void		parse_map(t_data *game, char *filename);
void		parse_error(t_data *game);
int			check_is_rectangle(t_data *game);
void		print_map(t_data *game);
int			error_message(t_data *game);
int			check_is_close(t_data *game);
int			read_map(char *filename, t_data *game);
int			get_dimensions(char *filename, t_data *game);
void		flood_fill(t_data *game, int x, int y);
void		reload_map(t_data *game);
// utils
void		free_grid(t_data *game);
int			open_file(char *filename);
int			check_format(char *map);
int			check_collectible(t_data *game);
void		init_struct(t_data *game);
#endif