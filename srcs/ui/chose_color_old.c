/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:31:19 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/23 17:51:40 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

typedef struct			s_test_color
{
	GtkWidget		*widget[3];
	GtkWidget		*entry[3];
	t_pixelbuf		*pixelbuf;
}						t_test_color;

static void				scale_change(GtkWidget *bar, gpointer data)
{
	t_test_color	*color_data;
	int				value[3];
	int				i;
	uint32_t		color;

	color_data = (t_test_color*)data;
	i = 0;
	if (!bar)
		bar = NULL;
	while (i < 3)
	{
		value[i] = (int)gtk_range_get_value(GTK_RANGE(color_data->widget[i]));
		gtk_entry_set_text(GTK_ENTRY(color_data->entry[i]), ft_itoa(value[i]));
		i++;
	}
	color = get_color_gtk(255, (uint8_t)value[0], (uint8_t)value[1],
			(uint8_t)value[2]);
	fill_pixelbuf_in_color(color_data->pixelbuf, color);
	put_pixelbuf_to_widget(color_data->pixelbuf, NULL);
}

static void				entry_change(GtkWidget *widget, gpointer data)
{
	GtkWidget		*bar;
	GtkAdjustment	*adj;
	int				i;
	int				min;
	int				max;

	bar = (GtkWidget*)data;
	i = ft_atoi(gtk_entry_get_text(GTK_ENTRY(widget)));
	adj = gtk_range_get_adjustment(GTK_RANGE(bar));
	min = gtk_adjustment_get_lower(GTK_ADJUSTMENT(adj));
	max = gtk_adjustment_get_upper(GTK_ADJUSTMENT(adj));
	if (i >= min && i <= max)
		gtk_range_set_value(GTK_RANGE(bar), (gdouble)i);
}

static void				contain(GtkWidget *h_scale[3], GtkWidget *entry[3],
		t_test_color *data)
{
	int				i;
	GtkWidget		*box[4];
	GtkWidget		*frame[3];

	i = -1;
	frame[0] = gtk_frame_new("Red");
	frame[1] = gtk_frame_new("Green");
	frame[2] = gtk_frame_new("Blue");
	box[3] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	while (++i < 3)
	{
		box[i] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
		gtk_box_pack_start(GTK_BOX(box[i]), h_scale[i], FALSE, FALSE, 2);
		gtk_box_pack_start(GTK_BOX(box[i]), entry[i], TRUE, FALSE, 2);
		gtk_container_add(GTK_CONTAINER(frame[i]), box[i]);
		gtk_container_add(GTK_CONTAINER(box[3]), frame[i]);
	}
	put_pixelbuf_to_widget(data->pixelbuf, NULL);
	gtk_box_pack_start(GTK_BOX(box[3]), data->pixelbuf->widget, TRUE, FALSE, 2);
	put_widgets_in_new_win(box[3], 200, 300);
}

static t_test_color		*set_data(GtkWidget *h_scale[3], GtkWidget *entry[3])
{
	t_test_color	*data;
	int				i;

	data = (t_test_color*)malloc(sizeof(t_test_color));
	i = -1;
	while (++i < 3)
	{
		data->widget[i] = h_scale[i];
		data->entry[i] = entry[i];
		g_signal_connect(G_OBJECT(h_scale[i]), "value-changed",
				G_CALLBACK(scale_change), (gpointer)data);
	}
	data->pixelbuf = pixelbuf_new(pt_set(50, 50), NULL);
	fill_pixelbuf_in_color(data->pixelbuf, get_color_gtk(0, 0, 0, 0));
	gtk_image_set_from_pixbuf(GTK_IMAGE(data->pixelbuf->widget),
			data->pixelbuf->buf);
	return (data);
}

void					chose_color(GtkWidget *widget, gpointer useless)
{
	GtkAdjustment	*adj[3];
	GtkWidget		*h_scale[3];
	GtkWidget		*entry[3];
	t_test_color	*data;
	int				i;

	if (!widget && !useless)
		useless = NULL;
	i = -1;
	while (++i < 3)
	{
		adj[i] = gtk_adjustment_new(0, 0, 265, 1, 2, 10);
		h_scale[i] = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, adj[i]);
		gtk_scale_set_digits(GTK_SCALE(h_scale[i]), 0);
		entry[i] = gtk_entry_new();
		g_signal_connect(G_OBJECT(entry[i]), "activate",
				G_CALLBACK(entry_change), (gpointer)h_scale[i]);
		gtk_entry_set_text(GTK_ENTRY(entry[i]), "0");
	}
	data = set_data(h_scale, entry);
	contain(h_scale, entry, data);
}
