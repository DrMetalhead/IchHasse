/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricschmi <ricschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:04:17 by ricschmi          #+#    #+#             */
/*   Updated: 2023/08/01 10:11:59 by ricschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

long long	getdec(long long nb)
{
	if (nb >= 90)
		return (90);
	else if (nb >= 80)
		return (80);
	else if (nb >= 70)
		return (70);
	else if (nb >= 60)
		return (60);
	else if (nb >= 50)
		return (50);
	else if (nb >= 40)
		return (40);
	else if (nb >= 30)
		return (30);
	else if (nb >= 20)
		return (20);
	else if (nb <= 20)
		return (nb);
	else
		return (0);
}

long long	getmult(long long nb)
{
	if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	else
		return (getdec(nb));
}

void	ft_print_out(long long nbr, t_list *row)
{
	long long	i;
	long long	mult;

	i = 0;
	mult = getmult(nbr);
	if (mult >= 100)
	{
		ft_print_out(nbr / mult, row);
		write(1, " ", 1);
	}
	while (row[i].index != mult)
		i++;
	ft_putstr(row[i].str);
	if (mult != 0 && nbr % mult != 0)
	{
		write(1, " ", 1);
		ft_print_out(nbr % mult, row);
	}
}

int	main(int argc, char **argv)
{
	t_list	*row;

	if (argc == 2)
	{
		if (arg_check(ft_atoi(argv[1])) < 0)
			return (0);
		row = ft_read_dict("numbers.dict");
		ft_print_out(ft_atoi(argv[1]), row);
	}
	else if (argc == 3)
	{
		if (arg_check(ft_atoi(argv[2])) < 0)
			return (0);
		row = ft_read_dict(argv[1]);
		ft_print_out(ft_atoi(argv[2]), row);
	}
	if (argc == 2 || argc == 3)
		ft_free_list(row);
	write(1, "\n", 1);
	return (0);
}
