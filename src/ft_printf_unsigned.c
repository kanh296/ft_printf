/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghoang <nghoang@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:02:26 by nghoang           #+#    #+#             */
/*   Updated: 2023/02/20 22:43:56 by nghoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //delete later
#include "ft_printf.h"
#include <stdlib.h>

int	ft_nlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_nlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_len;
	char	*num;

	print_len = 0;
	if (n == 0)
		print_len = print_len + write (1, "0", 1);
	else
	{
		num = ft_unsigned_itoa(n);
		print_len = print_len + ft_printstr(num);
		free(num);
	}
	return (print_len);
}
