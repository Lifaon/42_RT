/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mygtk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:35:30 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/16 18:44:34 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYGTK_H
# define MYGTK_H
# include <gtk/gtk.h>
# include <stdint.h>
# include "libft.h"
# include "libpt.h"

typedef union		u_color
{
	uint32_t		c;
	struct			s_argb
	{
		uint8_t		r;
		uint8_t		g;
		uint8_t		b;
		uint8_t		a;
	}				argb;
}					t_color;
/*
**	Usage of an union for easy color management.
*/

typedef struct	s_pixelbuf
{
	void		*buf;
	uint32_t	*pxl;
	int			sizeline;
	t_point		size;
	void		*widget;
}				t_pixelbuf;

void			put_widgets_in_new_win(GtkWidget *wid, gint x, gint y);
const gchar		*get_label_of_radio_list(GList *radio);
uint32_t		get_color_gtk(uint8_t alpha, uint8_t red, uint8_t green,
		uint8_t blue);
t_pixelbuf		*pixelbuf_new(t_point size, GtkWidget *image);
t_pixelbuf		*pixelbuf_new_from_img(GtkWidget *image);
t_pixelbuf		*pixelbuf_new_from_file(char *filename);
void			pixelbuf_free(t_pixelbuf **pxlbuf);
void			fill_pixelbuf_in_color(t_pixelbuf *pxlbuf, uint32_t color);
void			put_pixelbuf_to_widget(t_pixelbuf *pxlbuf, GtkWidget *img);
void			pt_to_pixelbuf(t_point pt, t_pixelbuf *pxbuf, uint32_t color);
void			fill_img_in_color(GtkWidget *img, uint32_t color);
t_color			get_color_of_img(GtkWidget *img);

#endif
