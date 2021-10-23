/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_scpct.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: smiller <smiller@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/24 11:10:14 by smiller       #+#    #+#                 */
/*   Updated: 2021/10/23 16:36:14 by smiller       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_fill(t_struct *flag)
{
	while (flag->width > flag->len)
	{
		if (flag->zero == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		flag->width--;
		flag->count++;
	}
}

static void	write_s(t_struct *flag, char *s, int len)
{
	int		i;

	i = 0;
	while (len > i && s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
		flag->count++;
	}
	if (flag->width > len && flag->left == 1)
		write_fill(flag);
}

void	handle_s(va_list ap, t_struct *flag)
{
	char		*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	flag->len = ft_strlen(s);
	if (flag->period == 1 && flag->prec < flag->len)
		flag->len = flag->prec;
	if (flag->width != 0 && flag->width < flag->len)
	{
		flag->left = 0;
		flag->width = flag->len;
	}
	if (flag->left == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->left == 0 || flag->len == 0 || flag->zero == 1)
		write_fill(flag);
	write_s(flag, s, flag->len);
}

void	handle_cpct(va_list ap, t_struct *flag)
{
	char	c;

	c = '%';
	flag->len = 1;
	if (flag->zero == 1 && flag->left == 1)
		flag->zero = 0;
	if (flag->conv == 'c')
		c = va_arg(ap, int);
	if (flag->left == 0 && flag->width > flag->len)
	{
		write_fill(flag);
		ft_putchar_fd(c, 1);
		flag->count++;
	}
	else
	{
		ft_putchar_fd(c, 1);
		flag->count++;
		if (flag->width > flag->len && flag->left == 1)
			write_fill(flag);
	}
}
