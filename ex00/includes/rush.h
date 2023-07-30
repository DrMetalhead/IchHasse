/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricschmi <ricschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:44:29 by ricschmi          #+#    #+#             */
/*   Updated: 2023/07/30 23:25:10 by ricschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# define INITIAL_BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	long long	index;
	char		*str;
}	t_list;

long long	arg_check(long long i);
void		ft_putstr(char *str);
long long	ft_atoi(char *str);
long long	ft_atoi_free(char *str);
char		*ft_strdup(char *src);
void		ft_print_out(long long n, t_list *row);
void		ft_free_list(t_list *row);
void		ft_free_str(char *str);
void		*ft_realloc(void *ptr, size_t new_size);
t_list		*ft_read_dict(char *file);

#endif