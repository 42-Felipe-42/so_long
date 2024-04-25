/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:05:53 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/13 11:24:51 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"
#include "so_long.h"

//Ouvre le fichier et verifie si il y a une erreur lors de l'ouverture
int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, __O_DIRECTORY);
	if (fd > 0)
	{
		ft_printf(ROUGE "Error\nU can't open .ber directory\n" RESETCOLOR);
		exit(0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(ROUGE "Error\nFailed to open file.\n" RESETCOLOR);
		exit(0);
	}
	return (fd);
}

//Calcul la longueur et largeur de la map
int	get_dimensions(char *filename, t_data *game)
{
	int		fd;
	char	*line;
	int		line_length;

	game->height = 0;
	game->width = 0;
	fd = open_file(filename);
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf(ROUGE "Error\nTry to read empty map.\n" RESETCOLOR),
			close(fd), exit(0), 0);
	while (line)
	{
		game->height++;
		line_length = 0;
		while (line[line_length] != '\0' && line[line_length] != '\n')
			line_length++;
		if (line_length > game->width)
			game->width = line_length;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

//Stock les valeurs lu avec gnl dans game->grid
int	read_map(char *filename, t_data *game)
{
	int		fd;
	char	**line;
	int		i;

	i = 0;
	fd = open_file(filename);
	line = malloc(sizeof(char *) * game->height);
	if (line == NULL)
		return (close(fd), 0);
	game->grid = malloc(sizeof(char *) * game->height);
	if (game->grid == NULL)
		return (free(line), close(fd), 0);
	while (i < game->height)
	{
		line[i] = get_next_line(fd);
		if (line[i] == NULL)
			(free(line), close(fd), exit(0));
		game->grid[i] = ft_strdup(line[i]);
		if (game->grid[i] == NULL)
			return (free(line), close(fd), 0);
		free(line[i]);
		i++;
	}
	return (free(line), close(fd), 1);
}

void	free_grid(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->grid[i]);
		i++;
	}
	free(game->grid);
}

void	print_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			ft_printf("%c", game->grid[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
}
