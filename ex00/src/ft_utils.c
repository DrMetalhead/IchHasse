/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricschmi <ricschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:58:44 by ricschmi          #+#    #+#             */
/*   Updated: 2023/07/30 22:45:56 by ricschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	long long	letter;

	letter = 0;
	while (str[letter] != '\0')
	{
		ft_putchar(str[letter]);
		letter++;
	}
}

long long	ft_atoi(char *str)
{
	long long	i;
	long long	minus;
	long long	num;

	num = 0;
	minus = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * minus);
}

int	ft_strlen(char *src, int i)
{
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int 	t;
	char	*dest;

	i = 0;
	t = 0;
	dest = malloc(ft_strlen(src, 0) + 1);
	if (!dest)
		return (0);
	while (src[i] != '\0')
	{
			if (src[i] == ' ')
		{
			while (src[i + 1] == ' ')
				i++;
		}
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

long long	ft_atoi_free(char *str)
{
	long long	i;
	long long	minus;
	long long	num;

	num = 0;
	minus = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	free(str);
	return (num * minus);
}