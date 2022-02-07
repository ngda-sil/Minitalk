/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:49:23 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 15:42:18 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *input, ...);
int		ft_printchar(char c);
int		ft_print_hex(unsigned int n, const char c);
int		ft_printnbr(int n);
int		ft_printstr(char *s);
int		ft_print_ptr(void *ptr);
int		ft_print_unsigned(unsigned int n);

#endif
