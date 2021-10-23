/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_diupx.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: smiller <smiller@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/24 11:14:02 by smiller       #+#    #+#                 */
/*   Updated: 2021/10/23 16:36:45 by smiller       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_diu(va_list ap, t_struct *flag)
{
	int				d;

	if (flag->conv == 'd' || flag->conv == 'i')
	{
		d = va_arg(ap, int);
		flag->len = nbrlen_d(d);
		if (d < 0)
			flag->neg = 1;
		assign_fill(flag, d);
		write_d(flag, d);
	}
	else if (flag->conv == 'u')
	{
		d = va_arg(ap, unsigned int);
		flag->len = nbrlen_u(d);
		assign_fill(flag, d);
		write_u(flag, d);
	}
}

void	handle_px(va_list ap, t_struct *flag)
{
	unsigned long	d;

	if (flag->conv == 'p')
		d = va_arg(ap, unsigned long);
	else
		d = va_arg(ap, unsigned int);
	flag->len = nbrlen_px(d);
	assign_fill(flag, d);
	write_px(flag, d);
}
