/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_change_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 18:06:40 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/23 18:56:57 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

t_color		*get_color_obj(void)
{
	return (&g_data->objs[g_data->ui->page_obj].color);
}

void		scale_change_color(GtkWidget *widget, gpointer param)
{
	t_color			*color;
	uint8_t			value[3];
	uint32_t		color;
	t_pixel_buf		*pixbuf;

	pixbuf = (t_pixel_buf*)param;
	while (i < 3)
	{
		value[i] = (uint8_t)gtk_range_get_value(GTK_RANGE(color_data->widget[i]));
		gtk_entry_set_text(GTK_ENTRY(color_data->entry[i]), ft_itoa(value[i]));
		i++;
	}
	color = get_color_gtk(255, (uint8_t)value[0], (uint8_t)value[1],
			(uint8_t)value[2]);
	fill_pixelbuf_in_color(pixelbuf, color);
	put_pixelbuf_to_widget(pixelbuf, NULL);
}
	if (!widget && !param)
		return ;
	color = get_color_obj();
	value = (uint8_t)gtk_range_get_value(GTK_RANGE(widget));
}
