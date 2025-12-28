/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:31:45 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/28 19:49:07 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUF_SIZE 2048

typedef struct s_node
{
	int				i;
	int				j;
	int				size;
	struct s_node	*next;
}	t_list;

int		ft_atoi(char *nbr);
void	ft_putstr(char *str);
char	**read_map(char *pathname, int x, int y);
void	free_total(char **map);
char	**mem_map(int x, int y);
int		map_validator(char **map, char *emp, char *obs, char *sq);
int		is_emp(char emp, char c);
int		is_obs(char **map, char c);
int		save_sq(char size, int i, int j, t_list **list);
char    **map_mgmt(char *map_path, t_list **list);
void	free_list(t_list *list);
int		sq_finder(char **map, char emp, t_list **list, int max_size);
void    print_map(char **map);
char    **map_from_stdin(t_list **list);
void    colour_bs(char **map, char sq, t_list **list);

#endif