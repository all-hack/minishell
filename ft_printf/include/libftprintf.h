/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 00:08:01 by obelange          #+#    #+#             */
/*   Updated: 2016/11/12 00:08:02 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define FT_PRINTF_NULLGUARD(INPUT) if ((INPUT) == NULL) return (NULL)

typedef struct		s_conversion
{
	char		*flag;
	char		*prepend;
	char		*mfieldwidth;
	char		*precision;
	char		*length;
	char		*conversion;
	char		*substring;
	char		cmfw;
	char		cprec;
	intmax_t	mfw;
	intmax_t	prec;
	size_t		skips;
	size_t		srt_seq;
	size_t		end_seq;
	intmax_t	num;
	va_list		arg_list;
}					t_mod;
extern const char	*g_sequence_symbols;
extern const char	*g_flag_symbols;
extern const char	*g_mfieldwidth_symbols;
extern const char	*g_precision_symbols;
extern const char	*g_length_symbols[7];
extern const char	*g_conversion_symbols;
extern void			(*g_printf_get[90]) (t_mod *conv, va_list args);
extern void			(*g_printf_parse[6]) (char **seq, t_mod *conv);
extern void			(*g_printf_process[4]) (t_mod *conv);
extern void			(*g_printf_flags[6]) (t_mod *conv);
extern void			(*g_printf_apply[5]) (t_mod *conv);
void				ft_printf_symdet_flags(char **seq, t_mod *conv);
void				ft_printf_symdet_mfw(char **seq, t_mod *conv);
void				ft_printf_symdet_prec(char **seq, t_mod *conv);
void				ft_printf_symdet_length(char **seq, t_mod *conv);
void				ft_printf_symdet_conv(char **seq, t_mod *conv);
void				ft_printf_dfree_hack(char **str);
void				ft_printf_free_struct(t_mod **this);
t_mod				*ft_printf_init_struct();
void				ft_printf_reset_struct(t_mod **this);
void				ft_printf_proc_setchar_prec(t_mod *conv, char chr);
void				ft_printf_proc_precision(t_mod *conv);
void				ft_printf_proc_mfieldwidth(t_mod *conv);
void				ft_printf_app_conv(t_mod *conv);
void				ft_printf_app_precision(t_mod *conv);
void				ft_printf_app_mfieldwidth(t_mod *conv);
void				ft_printf_app_flags(t_mod *conv);
void				ft_printf_flag_plus(t_mod *conv);
void				ft_printf_flag_space(t_mod *conv);
void				ft_printf_flag_minus(t_mod *conv);
void				ft_printf_flag_0(t_mod *conv);
void				ft_printf_flag_hash(t_mod *conv);
void				ft_printf_fstrinsert(char **printit,
								char *substr, size_t strt, size_t end);
char				*ft_printf_frmvdup(char	**str, size_t size);
char				*ft_printf_strinsert(char *printit,
							char *substr, size_t strt, size_t end);
int					ft_printf(const char *format, ...);
void				ft_printf_flow(char **seq, t_mod *conv, va_list args);
void				ft_printf_format_parsing(char const *format,
										t_mod *conv, va_list args);
void				ft_printf_chng_char(t_mod *conv, signed char num);
void				ft_printf_chng_uchar(t_mod *conv, unsigned char num);
void				ft_printf_chng_short(t_mod *conv, short num);
void				ft_printf_chng_ushort(t_mod *conv, unsigned short num);
void				ft_printf_chng_int(t_mod *conv, int num);
void				ft_printf_chng_uint(t_mod *conv, unsigned int num);
void				ft_printf_chng_long(t_mod *conv, long num);
void				ft_printf_chng_ulong(t_mod *conv, unsigned long num);
void				ft_printf_chng_size_t(t_mod *conv, size_t num);
void				ft_printf_chng_longlong(t_mod *conv, long long num);
void				ft_printf_chng_ulonglong(t_mod *conv,
												unsigned long long num);
void				ft_printf_chng_intmax_t(t_mod *conv, intmax_t num);
void				ft_printf_chng_uintmax_t(t_mod *conv, uintmax_t num);
char				*ft_printf_chng_wchar_t(t_mod *conv, wchar_t chr,
															char *str);
int					ft_printf(const char *s, ...);
size_t				ft_printf_strlen(const char *s);
char				*ft_printf_strdup(const char *s1);
char				*ft_printf_itoa_base(uintmax_t num, int base, int neg);
char				*ft_printf_itoa(int nb);
int					ft_printf_putstr(char const *s, t_mod *conv);
void				ft_printf_strdel(char **as);
int					ft_printf_stric(char const *s, char const *c,
														size_t *index);
char				*ft_printf_strmcat(char const *s1, char const *s2);
char				*ft_printf_strnew(size_t size);
char				*ft_printf_strsub(char const *s, size_t start, size_t len);
int					ft_printf_strchri(char const *s, char const c,
																size_t *index);
char				*ft_printf_strncpy(char *dst, const char *src, size_t len);
char				*ft_printf_strcat(char *s1, const char *s2);
char				*ft_printf_strncat(char *s1, unsigned char const *s2,
																	size_t n);
int					ft_printf_strcmp(const char *s1, const char *s2);
char				*ft_printf_itoa_binary(uintmax_t num, int size);
char				*ft_printf_strcpy(char *dst, char const *src);
int					ft_printf_1chr_nsym(char const *s, char const *c,
																char **s_str);
char				*ft_printf_fstrappend(char *s1, unsigned char c);
char const			*ft_printf_shiftstr(char const *s1, char const *s2);
int					ft_printf_nchr_1sym(char const *s, char const **c,
																char **s_str);
char				*ft_printf_fstrmcat(char *s1, char const *s2);
char				*ft_printf_strupper(char *str);
void				ft_printf_chng_long(t_mod *conv, long num);
void				ft_printf_chng_longlong(t_mod *conv, long long num);
void				ft_printf_chng_char(t_mod *conv, signed char num);
void				ft_printf_chng_uchar(t_mod *conv, unsigned char num);
void				ft_printf_chng_short(t_mod *conv, short num);
void				ft_printf_chng_ushort(t_mod *conv, unsigned short num);
void				ft_printf_chng_int(t_mod *conv, int num);
void				ft_printf_chng_ulonglong(t_mod *conv,
											unsigned long long num);
void				ft_printf_chng_intmax_t(t_mod *conv, intmax_t num);
void				ft_printf_chng_uintmax_t(t_mod *conv, uintmax_t num);
char				*ft_printf_chng_wchar_t(t_mod *conv,
												wchar_t chr, char *str);
void				ft_printf_chng_char(t_mod *conv, signed char num);
void				ft_printf_chng_uchar(t_mod *conv, unsigned char num);
void				ft_printf_chng_short(t_mod *conv, short num);
void				ft_printf_chng_ushort(t_mod *conv, unsigned short num);
void				ft_printf_chng_int(t_mod *conv, int num);
void				ft_printf_chng_uint(t_mod *conv, unsigned int num);
void				ft_printf_chng_ulong(t_mod *conv, unsigned long num);
void				ft_printf_chng_size_t(t_mod *conv, size_t num);
void				ft_printf_get_b(t_mod *conv, va_list args);
void				ft_printf_get_c(t_mod *conv, va_list args);
void				ft_printf_get_cap_c(t_mod *conv, va_list args);
void				ft_printf_get_d(t_mod *conv, va_list args);
void				ft_printf_get_cap_d(t_mod *conv, va_list args);
void				ft_printf_get_i(t_mod *conv, va_list args);
void				ft_printf_get_o(t_mod *conv, va_list args);
void				ft_printf_get_cap_o(t_mod *conv, va_list args);
void				ft_printf_get_p(t_mod *conv, va_list args);
void				ft_printf_get_s(t_mod *conv, va_list args);
void				ft_printf_get_cap_s(t_mod *conv, va_list args);
void				ft_printf_get_u(t_mod *conv, va_list args);
void				ft_printf_get_cap_u(t_mod *conv, va_list args);
void				ft_printf_get_x(t_mod *conv, va_list args);
void				ft_printf_get_cap_x(t_mod *conv, va_list args);
void				ft_printf_get_percent(t_mod *conv, va_list args);
void				ft_printf_proc_flags(t_mod *conv);
char				*ft_printf_frmvdup(char	**str, size_t size);
intmax_t			ft_printf_atoi(char const *str);
void				ft_printf_fstrinsert(char **printit, char *substr,
												size_t strt, size_t end);
char				*ft_printf_fstrmcat_conv(char *s1, char const *s2,
															t_mod *conv);
#endif
