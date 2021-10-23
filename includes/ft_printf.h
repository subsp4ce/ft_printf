/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smiller <smiller@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/10 11:49:33 by smiller       #+#    #+#                 */
/*   Updated: 2021/04/01 16:30:55 by smiller       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	char			conv;
	int				left;
	int				zero;
	int				width;
	int				prec;
	int				period;
	int				len;
	int				count;
	int				neg;
	int				printzeros;
	int				printspaces;
}					t_struct;

int					ft_printf(const char *str, ...);
int					nbrlen_d(int n);
int					nbrlen_px(unsigned long n);
int					nbrlen_u(unsigned int n);
void				assign_conv(va_list ap, t_struct *flag);
void				assign_flags(t_struct *flag, const char **str, va_list ap);
void				assign_prec(t_struct *flag, const char **str, va_list ap);
void				assign_fill(t_struct *flag, int d);
void				handle_s(va_list ap, t_struct *flag);
void				handle_cpct(va_list ap, t_struct *flag);
void				handle_diu(va_list ap, t_struct *flag);
void				handle_px(va_list ap, t_struct *flag);
void				write_d(t_struct *flag, int n);
void				write_px(t_struct *flag, unsigned long n);
void				write_u(t_struct *flag, unsigned int n);

#endif
