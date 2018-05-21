/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mygtk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:35:30 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/21 16:13:16 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYGTK_H
# define MYGTK_H
//# include "gtk.h"
# include <gtk/gtk.h>
# include "libft.h"
# include "libpt.h"

typedef struct	s_pixelbuf
{
	GdkPixbuf		*buf;
	uint32_t	*pxl;
	int			sizeline;
	t_point		size;
	GtkWidget	*widget;
}				t_pixelbuf;

typedef union		u_color
{
	uint32_t		c;
	struct			s_argb
	{
		uint8_t		b;
		uint8_t		g;
		uint8_t		r;
		uint8_t		a;
	}				argb;
}					t_color;

void			put_widgets_in_new_win(GtkWidget *wid, gint x, gint y);
const gchar		*get_label_of_radio_list(GList *radio);
uint32_t		get_color_gtk(uint8_t alpha, uint8_t red, uint8_t green,
		uint8_t blue);
t_pixelbuf		*pixelbuf_new(t_point size, GtkWidget *image);
void			fill_pixelbuf_in_color(t_pixelbuf *pxlbuf, uint32_t color);
void			put_pixelbuf_to_widget(t_pixelbuf *pxlbuf, GtkWidget *img);
void			pt_to_pixelbuf(t_point pt, t_pixelbuf *pxbuf, uint32_t color);

#endif
