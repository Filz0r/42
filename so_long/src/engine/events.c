/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:08:37 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/20 19:06:51 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	on_keypress(int keysym, t_data *game)
{
	printf("pressed: %d\n", keysym);
	if (keysym == XK_a || keysym == XK_Left)
		move_player(game, LEFT);
	else if (keysym == XK_s || keysym == XK_Down)
		move_player(game, DOWN);
	else if (keysym == XK_d || keysym == XK_Right)
		move_player(game, RIGHT);
	else if (keysym == XK_w || keysym == XK_Up)
		move_player(game, UP);
	if (keysym == XK_Escape)
		quit_game(game);
	return (0);
}

void	move_player(t_data *game, int action)
{
	//moving up
	if (action == UP)
		handle_movement(game, game->map->player->x, game->map->player->y - 1, UP);
	else if (action == DOWN)
		handle_movement(game, game->map->player->x, game->map->player->y + 1, DOWN);
	else if (action == LEFT)
		handle_movement(game, game->map->player->x - 1, game->map->player->y, LEFT);
	else if (action == RIGHT)
		handle_movement(game, game->map->player->x + 1, game->map->player->y, RIGHT);
}

void	handle_movement(t_data *g, int x, int y, int action)
{
	int	signal;

	signal = 0;
	move_on_map(g, &signal, x, y);
	if (signal == 1)
		return ;
	if (action == UP)
		g->map->player->y--;
	else if (action == DOWN)
		g->map->player->y++;
	else if (action == LEFT)
		g->map->player->x--;
	else if (action == RIGHT)
		g->map->player->x++;
	g->steps++;
	ft_printf("Player has moved %d times.\n", g->steps);
}

void	move_on_map(t_data *g, int *signal, int x, int y)
{
	if (x < 0 || y < 0)
	{
		*signal = 1;
		return ;
	}
	if (g->map->map[y][x] == '0')
	{
		g->map->map[y][x] = 'P';
		g->map->map[g->map->player->y][g->map->player->x] = '0';
	}
	else if (g->map->map[y][x] == '1')
	{
		*signal = 1;
		return ;
	}
	else if (g->map->map[y][x] == 'C')
	{
		g->map->map[y][x] = 'P';
		g->map->map[g->map->player->y][g->map->player->x] = '0';
		remove_collectible(g, x, y);
	}
	else
		handle_end(g, x, y);
}

//todo: fix all memory leaks
void	handle_end(t_data *g, int x, int y)
{
	if (g->collectibles != NULL)
		return ;
	g->map->map[y][x] = 'P';
	g->map->map[g->map->player->y][g->map->player->x] = '0';
	ft_printf("Congratulations!\nYou have completed the map in %d moves\n", \
		g->steps);
	free_map(g);
	quit_game(g);
}

void	remove_collectible(t_data *g, int x, int y)
{
	t_list	*curr;
	t_list	*prev;
	t_point	*temp;

	prev = NULL;
	curr = g->collectibles;
	while (curr)
	{
		temp = (t_point *)curr->content;
		if (temp && temp->x == x && temp->y == y)
		{
			if (prev)
				prev->next = curr->next;
			else
				g->collectibles = curr->next;
			free(temp);
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

int	quit_game(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map(game);
	exit(1);
}
