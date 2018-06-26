/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_from_entry.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:48:07 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/26 15:48:10 by fchevrey         ###   ########.fr       */
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
		if (str[i] == '.')
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
		ft_putendl(&str[i]);
		if (str[i] == ',' || str[i] == '.')
			separator++;
		if (separator > 1 || ((str[i] != ',' && str[i] != '.') &&
					(str[i] > '9' || str[i] < '0')))
			break ;
		i++;
	}
	str[i] = '\0';
	return (str);
}

double		get_double_from_entry(GtkWidget *wid)
{
	char			*str;
	char			*str2;
	double			dst;

	if (!(str = ft_strupper(strdup(gtk_entry_get_text(GTK_ENTRY(wid))))))
		return (0);
	if (!(ft_strcmp(str, "INFINITY")) || !(ft_strcmp(str, "+INFINITY")) 
			|| !(ft_strcmp(str, "INF")) || !(ft_strcmp(str, "+INF")))
	{
		dst = INFINITY;
		gtk_entry_set_text(GTK_ENTRY(wid), "INFINITY");
	}
	else if (!(ft_strcmp(str, "-INFINITY")) || !(ft_strcmp(str, "-INF")))
	{
		dst = -INFINITY;
		gtk_entry_set_text(GTK_ENTRY(wid), "-INFINITY");
	}
	else
	{
		str2 = str_end_digit(str);
		ft_putstr("finale = ");
		ft_putendl(str2);
		gtk_entry_set_text(GTK_ENTRY(wid), str2);
		if ((dst = my_ft_atof(str)) == 0)
			gtk_entry_set_text(GTK_ENTRY(wid), "0");
	}
	ft_strdel(&str);
	return (dst);
}
