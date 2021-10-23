/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_write.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: smiller <smiller@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/24 10:43:43 by smiller       #+#    #+#                 */
/*   Updated: 2021/10/23 16:36:21 by smiller       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	putnbr_pux(unsigned long n, t_struct *flag)
{
	if (n <= 9)
		ft_putchar_fd(n + '0', 1);
	else if ((n >= 10 && n <= 15) && (flag->conv == 'x' || flag->conv == 'p'))
		ft_putchar_fd((5 - (15 - n)) + 97, 1);
	else if ((n >= 10 && n <= 15) && flag->conv == 'X')
		ft_putchar_fd((5 - (15 - n)) + 65, 1);
	else if (flag->conv == 'p' || flag->conv == 'x' || flag->conv == 'X')
	{
		putnbr_pux(n / 16, flag);
		putnbr_pux(n % 16, flag);
	}
	else
	{
		putnbr_pux(n / 10, flag);
		ft_putchar_fd(n % 10 + '0', 1);
	}
}

static void	write_spaces(t_struct *flag)
{
	while (flag->printspaces > 0)
	{
		ft_putchar_fd(' ', 1);
		flag->printspaces--;
		flag->count++;
	}
}

void	write_d(t_struct *flag, int n)
{
	if (flag->left == 0)
		write_spaces(flag);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		if (n != -2147483648)
			n = n * -1;
	}
	while (flag->printzeros > 0)
	{
		ft_putchar_fd('0', 1);
		flag->printzeros--;
		flag->count++;
	}
	if (flag->len > 0)
	{
		if (n == -2147483648)
			ft_putstr_fd("2147483648", 1);
		else
			ft_putnbr_fd(n, 1);
	}
	if (flag->left == 1)
		write_spaces(flag);
}

void	write_u(t_struct *flag, unsigned int n)
{
	if (flag->left == 0)
		write_spaces(flag);
	while (flag->printzeros > 0)
	{
		ft_putchar_fd('0', 1);
		flag->printzeros--;
		flag->count++;
	}
	if (flag->len > 0)
		putnbr_pux(n, flag);
	if (flag->left == 1)
		write_spaces(flag);
}

void	write_px(t_struct *flag, unsigned long n)
{
	if (flag->left == 0)
	{
		write_spaces(flag);
		if (flag->conv == 'p')
		{
			ft_putstr_fd("0x", 1);
			flag->count = flag->count + 2;
		}
	}
	if (flag->left == 1 && flag->conv == 'p')
	{
		ft_putstr_fd("0x", 1);
		flag->count = flag->count + 2;
	}
	while (flag->printzeros > 0)
	{
		ft_putchar_fd('0', 1);
		flag->printzeros--;
		flag->count++;
	}
	if (flag->len > 0)
		putnbr_pux(n, flag);
	if (flag->left == 1)
		write_spaces(flag);
}
