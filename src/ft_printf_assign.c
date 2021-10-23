/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_assign.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: smiller <smiller@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/12 09:31:09 by smiller       #+#    #+#                 */
/*   Updated: 2021/10/23 16:36:53 by smiller       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	assign_conv(va_list ap, t_struct *flag)
{
	if (flag->conv == 's')
		handle_s(ap, flag);
	else if (flag->conv == 'c' || flag->conv == '%')
		handle_cpct(ap, flag);
	else if (flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'u')
		handle_diu(ap, flag);
	else if (flag->conv == 'x' || flag->conv == 'X' || flag->conv == 'p')
		handle_px(ap, flag);
	else
		flag->count = -1;
}

void	assign_flags(t_struct *flag, const char **str, va_list ap)
{
	if (**str == '-')
	{
		flag->left = 1;
		(*str)++;
	}
	while (**str == '0')
	{
		flag->zero = 1;
		(*str)++;
		if (**str == '-')
		{
			flag->left = 1;
			(*str)++;
		}
	}
	while (ft_isdigit(**str))
	{
		flag->width = (flag->width * 10) + (**str - '0');
		(*str)++;
	}
	if (**str == '*')
	{
		flag->width = va_arg(ap, int);
		(*str)++;
	}
}

void	assign_prec(t_struct *flag, const char **str, va_list ap)
{
	(*str)++;
	flag->period = 1;
	while (**str == '0')
		(*str)++;
	while (ft_isdigit(**str))
	{
		flag->prec = (flag->prec * 10) + (**str - '0');
		(*str)++;
	}
	if (**str == '*')
	{
		flag->prec = va_arg(ap, int);
		if (flag->prec < 0)
			flag->period = 0;
		(*str)++;
	}
}

void	assign_fill(t_struct *flag, int d)
{
	if (d == 0 && flag->period == 1)
	{
		flag->printzeros = flag->prec;
		flag->len = 0;
	}
	else if (flag->prec > flag->len - flag->neg)
		flag->printzeros = flag->prec - flag->len + flag->neg;
	else if (flag->zero == 1 && flag->width > flag->len
		&& flag->period == 0 && flag->left == 0 && flag->conv == 'p')
		flag->printzeros = flag->width - flag->len - 2;
	else if (flag->zero == 1 && flag->width > flag->len
		&& flag->period == 0 && flag->left == 0)
		flag->printzeros = flag->width - flag->len;
	if ((flag->width > flag->printzeros + flag->len + 2) && flag->conv == 'p')
		flag->printspaces = flag->width - (flag->printzeros + flag->len + 2);
	else if (flag->width > flag->printzeros + flag->len && flag->conv != 'p')
		flag->printspaces = flag->width - (flag->printzeros + flag->len);
	else
		flag->printspaces = 0;
	flag->count = flag->len + flag->count;
}
