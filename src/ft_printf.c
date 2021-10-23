/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smiller <smiller@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/10 13:08:45 by smiller       #+#    #+#                 */
/*   Updated: 2021/10/23 16:36:27 by smiller       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	initialize(t_struct *flag)
{
	flag->left = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->prec = 0;
	flag->period = 0;
	flag->len = 0;
	flag->neg = 0;
	flag->printzeros = 0;
	flag->printspaces = 0;
}

static void	parse(va_list ap, t_struct *flag, const char **str)
{
	initialize(flag);
	while (**str)
	{
		(*str)++;
		if (**str == '-' || ft_isdigit(**str) || (**str) == '*')
			assign_flags(flag, str, ap);
		if (**str == '.')
			assign_prec(flag, str, ap);
		if (ft_strchr("cspdiuxX%%", **str))
		{
			if (flag->width < 0)
			{
				flag->width = flag->width * -1;
				flag->left = 1;
			}
			flag->conv = **str;
			(*str)++;
			assign_conv(ap, flag);
			return ;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	t_struct	flag;
	va_list		ap;

	flag.count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && ft_strchr("-.*0123456789cpsdiuxX%%", *(str + 1)))
			parse(ap, &flag, &str);
		else
		{
			ft_putchar_fd(*str, 1);
			flag.count++;
			str++;
		}
		if (flag.count == -1)
		{
			va_end(ap);
			return (-1);
		}
	}
	va_end(ap);
	return (flag.count);
}
