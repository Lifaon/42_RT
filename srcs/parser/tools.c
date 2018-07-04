/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:46:20 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/04 01:28:13 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_point	parse_point(char *str, int *index)
{
	t_point	ret;
	int		i;

	i = -1;
	ret = (t_point){0, 0};
	while (str[++i] && str[i] != '[');
	if (!str[i])
		return (ret);
	ret.x = ft_atoi(str + (++i));
	while (str[++i] && str[i] != ']' && str[i] != ',');
	if (str[i] != ',')
		return (ret);
	ret.y = ft_atoi(str + (++i));
	while (str[++i] && str[i] != ']');
	*index += i;
	return (ret);
}

double	parse_nb(char *str, int *index)
{
	int i;

	i = -1;
	while (str[++i] && str[i] != ':');
	*index += i;
	return (my_atof(str + i + 1));
}

t_vec	parse_vec(char *str, int *index)
{
	t_vec	ret;
	int		i;

	i = -1;
	while (str[++i] && str[i] != '[');
	if (!str[i])
		return (ret);
	ret.x = my_atof(str + (++i));
	while (str[++i] && str[i] != ']' && str[i] != ',');
	if (str[i] != ',')
		return (ret);
	ret.y = my_atof(str + (++i));
	while (str[++i] && str[i] != ']' && str[i] != ',');
	if (str[i] != ',')
		return (ret);
	ret.z = my_atof(str + (++i));
	while (str[++i] && str[i] != ']');
	if (str[i] == ']')
		*index += i;
	return (ret);
}

t_color	parse_color_2(char *str, int *index, t_color ret, int i)
{
	int nb;

	while (str[++i] && str[i] != ']' && str[i] != ',');
	if (str[i] != ',')
		return (ret);
	nb = abs(ft_atoi(str + (++i)));
	ret.argb.b = nb <= 255 ? nb : 255;
	while (str[++i] && str[i] != ']' && str[i] != ',');
	if (str[i] != ',')
		return (ret);
	nb = abs(ft_atoi(str + (++i)));
	ret.argb.a = nb <= 255 ? nb : 255;
	while (str[++i] && str[i] != ']');
	if (str[i] == ',')
		*index += i;
	return (ret);
}

t_color	parse_color(char *str, int *index)
{
	t_color	ret;
	int		nb;
	int		i;

	ret.c = 0xFF000000;
	i = -1;
	while (str[++i] && str[i] != '[');
	if (!str[i])
		return (ret);
	nb = abs(ft_atoi(str + (++i)));
	ret.argb.r = nb <= 255 ? nb : 255;
	while (str[++i] && str[i] != ']' && str[i] != ',');
	if (str[i] != ',')
		return (ret);
	nb = abs(ft_atoi(str + (++i)));
	ret.argb.g = nb <= 255 ? nb : 255;
	return (parse_color_2(str, index, ret, i));
}
