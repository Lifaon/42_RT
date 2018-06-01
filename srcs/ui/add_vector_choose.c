/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector_choose.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:48:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/01 19:49:00 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

GtkSizeGroup	*add_vector_choose(t_wid_data *wid_d, char *label, t_vec *vec)
{
	t_widget_vec	*wid_vec;
	char			*str;
	char			s[3];

	wid_vec = wid_vec_new(NULL, vec);
	ft_strcpy(s, "x ");
	while (s[0] <= 'z')
	{
		str = ft_strjoin(s, label);
		if (s[0] == 'x')
			if (make_entry_and_scale(wid_d, str, wid_vec, vec->x) < 1)
				return (NULL);
		if (s[0] == 'y')
			if (make_entry_and_scale(wid_d, str, wid_vec, vec->y) < 1)
				return (NULL);
		if (s[0] == 'z')
			if (make_entry_and_scale(wid_d, str, wid_vec, vec->z) < 1)
				return (NULL);
		ft_strdel(&str);
		s[0] = s[0] + 1;
	}
	return (wid_vec->group);
}
