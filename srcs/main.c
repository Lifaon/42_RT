/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/10 20:04:27 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	print_parsed_data(t_data data)
{
	for (int i = 0; i < 1; i++)
	{
		printf("CAM nb : %d;\n", i + 1);
		printf("pos = %f, %f, %f\n", \
			data.cams[i].pos.x, data.cams[i].pos.y, data.cams[i].pos.z);
		printf("dir = %f, %f, %f\n", \
			data.cams[i].dir.x, data.cams[i].dir.y, data.cams[i].dir.z);
		printf("fov = %f\n\n", data.cams[i].fov);
	}
	for (int i = 0; i < data.nb_lights; i++)
	{
		printf("LIGHT nb : %d;\n", i + 1);
		printf("is_para = %d\n", data.lights[i].is_para);
		printf("color = %u, %u, %u, %u\n", data.lights[i].color.argb.r, \
			data.lights[i].color.argb.g, data.lights[i].color.argb.b, data.lights[i].color.argb.a);
		printf("r = %f\n", data.lights[i].r);
		printf("pos = %f, %f, %f\n", \
			data.lights[i].pos.x, data.lights[i].pos.y, data.lights[i].pos.z);
		printf("dir = %f, %f, %f\n\n", \
			data.lights[i].dir.x, data.lights[i].dir.y, data.lights[i].dir.z);
	}
	for (int i = 0; i < data.nb_objects; i++)
	{
		printf("OBJECT nb : %d;\n", i + 1);
		printf("r = %f\n", data.objs[i].r);
		printf("spec = %f\n", data.objs[i].spec);
		printf("color = %u, %u, %u, %u\n", data.objs[i].color.argb.r, \
			data.objs[i].color.argb.g, data.objs[i].color.argb.b, data.objs[i].color.argb.a);
		printf("pos = %f, %f, %f\n", \
			data.objs[i].pos.x, data.objs[i].pos.y, data.objs[i].pos.z);
		printf("dir = %f, %f, %f\n", \
			data.objs[i].dir.x, data.objs[i].dir.y, data.objs[i].dir.z);
		printf("normal = %f, %f, %f\n\n", \
			data.objs[i].normal.x, data.objs[i].normal.y, data.objs[i].normal.z);
	}
}

/*int		main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		ft_putendl("Usage : ./rt \'file_name\'");
		exit(-1);
	}
	parse(&data, av[1]);
	print_parsed_data(data);
	exit_all(&data);
	return (0);
}*/

int		main(int ac, char **av)
{
	t_data	data;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		ft_putstr("SDL_Init error :");
		ft_putendl(SDL_GetError());
		return (0);
	}
	data_init(&data, ac, av);
	draw_image(&data);
	//print_parsed_data(data);
	ft_event(&data);
	return (0);
}
