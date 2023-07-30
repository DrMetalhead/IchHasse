/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichali <mmichali@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:00:49 by ricschmi          #+#    #+#             */
/*   Updated: 2023/07/30 12:15:52 by mmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

long long	arg_check(long long nbr)
{
	if (nbr < 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (1);
}
