/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_from_entry.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:48:07 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/28 20:44:39 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static double	my_ft_atof(char const *str)
{
	double		n;
	int			i;
	int			k;
	double		signe;

	i = 0;
	n = 0;
	k = 0;
	if (!str)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	signe = (str[i - 1] == '-') ? -1 : 1;
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i++] - 48);
		if (str[i] == '.' || str[i] == ',')
			k = i++;
	}
	while (k != 0 && str[++k])
		signe = signe * 10.0;
	return (n / signe);
}

static char		*str_end_digit(char *str)
{
	int		i;
	int		separator;

	if (!str)
		return (NULL);
	i = 0;
	separator = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == ',' || str[i] == '.')
			separator++;
		if ((separator > 1) || ((str[i] != ',' && str[i] != '.') &&
					(str[i] > '9' || str[i] < '0')))
			break ;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		get_infinity(GtkWidget *wid, double *dst, char *str,  int mode)
{
	if ((mode == MODE_PLUS_INF || mode == MODE_BOTH_INF) &&
	(!(ft_strcmp(str, "INFINITY")) || !(ft_strcmp(str, "+INFINITY")) 
			|| !(ft_strcmp(str, "INF")) || !(ft_strcmp(str, "+INF"))))
	{
		*dst = INFINITY;
		gtk_entry_set_text(GTK_ENTRY(wid), "inf");
		ft_strdel(&str);
		return (1);
	}
	else if ((mode == MODE_LESS_INF || mode == MODE_BOTH_INF) &&
	(!(ft_strcmp(str, "-INFINITY")) || !(ft_strcmp(str, "-INF"))))
	{
		*dst = -INFINITY;
		gtk_entry_set_text(GTK_ENTRY(wid), "-inf");
		ft_strdel(&str);
		return (1);
	}
	return (0);
}

double		get_double_from_entry(GtkWidget *wid, int infinity_mode, double min, double max)
{
	char			*str;
	char			*str2;
	double			dst;

	if (!(str = ft_strupper(strdup(gtk_entry_get_text(GTK_ENTRY(wid))))))
		return (0);
	if (infinity_mode != MODE_NO_INF)
		if (get_infinity(wid, &dst, str, infinity_mode))
			return (dst);
	str2 = str_end_digit(str);
	dst = my_ft_atof(str);
	ft_strdel(&str);
	str = ft_dbtoa(dst);
	gtk_entry_set_text(GTK_ENTRY(wid), str);
	ft_strdel(&str);
	if (min != -INFINITY && dst < min)
	{
		str = ft_itoa(min);
		gtk_entry_set_text(GTK_ENTRY(wid), str);
		dst = min;
	}
	else if (max != INFINITY && dst > max)
	{
		str = ft_itoa(max);
		gtk_entry_set_text(GTK_ENTRY(wid), str);
		dst = max;
	}
	ft_strdel(&str);
	return (dst);
}
