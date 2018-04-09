/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:59:49 by maduhoux          #+#    #+#             */
/*   Updated: 2018/04/06 16:16:28 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_flags
{
	int		diez;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		prec;
	int		j;
	int		z;
	int		hh;
	int		h;
	int		l;
	int		ll;
}					t_flags;
int					ft_printf(const char *format, ...);
int					ft_printf_if(const char **format, t_flags *lst, \
		int len, va_list args);
void				ft_printf_tab(int (*tab[256])(t_flags *lst, va_list arg));
int					ft_printf_int(t_flags *lst, va_list arg);
int					ft_printf_int_upp(t_flags *lst, va_list arg);
int					ft_printf_uint(t_flags *lst, va_list arg);
int					ft_printf_uint_upp(t_flags *lst, va_list arg);
int					ft_printf_uoctal(t_flags *lst, va_list arg);
int					ft_printf_uoctal_upp(t_flags *lst, va_list arg);
int					ft_printf_uhex_low(t_flags *lst, va_list arg);
int					ft_printf_uhex_upp(t_flags *lst, va_list arg);
int					ft_printf_char(t_flags *lst, va_list arg);
int					ft_printf_str(t_flags *lst, va_list arg);
int					ft_printf_pourcent(t_flags *lst, va_list arg);
int					ft_printf_ulp(t_flags *lst, va_list arg);
int					ft_printf_bin(t_flags *lst, va_list arg);
t_flags				ft_printf_flags_parser(const char **format, t_flags *lst);
int					ft_printf_diez_finder(char c, t_flags *lst);
int					ft_printf_zero_finder(char c, t_flags *lst);
int					ft_printf_plus_finder(char c, t_flags *lst);
int					ft_printf_minus_finder(char c, t_flags *lst);
int					ft_printf_space_finder(char c, t_flags *lst);
int					ft_printf_parse_flag(char c, t_flags *lst);
void				ft_printf_parser_utils(const char **format, t_flags *lst);
int					ft_printf_check_end(char c);
char				*ft_printf_declare_tab_end(void);
char				*ft_printf_declare_tab_conversion(void);
t_flags				ft_printf_lst_filler(void);
int					ft_printf_check_conversion(char c);
int					ft_printf_conversion_filler(char c, int size, t_flags *lst);
char				*ft_printf_itoa_base(uintmax_t nb, int base, char c);
int					ft_printf_i_neg(t_flags *lst, char *nb, int ret);
int					ft_printf_i_pos(t_flags *lst, char *nb, int ret);
int					ft_printf_widthneg(t_flags *lst, int ret, int n, \
		int length);
int					ft_printf_check_precision(t_flags *lst, int ret);
int					ft_printf_check_precision_string(t_flags *lst, int ret);
int					ft_printf_put_width(t_flags *lst, int ret, int n);
int					ft_printf_put_x(t_flags *lst, char nb);
void				ft_printf_plusspace(t_flags *lst);
intmax_t			ft_printf_converter_signed(t_flags *lst, va_list arg);
uintmax_t			ft_printf_converter_unsigned(t_flags *lst, va_list arg);
int					ft_printf_one_o(char *tab, wchar_t c);
int					ft_printf_two_o(char *tab, wchar_t c);
int					ft_printf_three_o(char *tab, wchar_t c);
int					ft_printf_putwchar(wchar_t c);
int					ft_printf_wcharlen(wchar_t c);
int					ft_printf_check_wchar(wchar_t c);
int					ft_printf_char_upp(t_flags *lst, va_list arg);
int					ft_printf_str_upp(t_flags *lst, va_list arg);
int					ft_printf_nothing(t_flags *lst);

#endif
