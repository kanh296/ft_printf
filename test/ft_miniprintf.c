/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghoang <nghoang@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:08:34 by nghoang           #+#    #+#             */
/*   Updated: 2023/02/20 15:36:13 by nghoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <stdio.h> //delete later

/* Code the mini_printf*/

void	mini_printf(char *fmt, ...)
{
	va_list	ap;
	char	*p;
	char	*sval;
	int	ival;
	double	dval;
	int	i;

	va_start(ap, fmt);
	p = fmt;
	i = 0;
	while (p[i] != '\0')
	{
		while (p[i] != '%')
		{
			ft_putchar(p[i]);
			i++;
			//continue;
		}
		i++;
		switch (p[i])
		{
			case 'd':
				ival = va_arg(ap, int);
				ft_putnbr(ival);
				//printf("a");
				//printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				sval = va_arg(ap, char *);
				ft_putstr(sval);
				break;
			default:
				ft_putchar(*p);
				break;
		}
		i++;
	}
	va_end(ap);
}
