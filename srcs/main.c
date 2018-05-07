/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/07 14:29:22 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		mouse_actions(int key, int x, int y, t_data *data)
{
	return (0);
}

int		key_actions(int key, t_data *data)
{
	if (key == K_ESC)
		exit_all(data);
	return (0);
}

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
		printf("ambi = %f\n", data.objs[i].ambi);
		printf("diff = %f\n", data.objs[i].diff);
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

int		main(int ac, char **av)
{
	t_data	data;
	t_obj	*objs;
	t_ray	light;

	/*data_init(&data);
	//	là j'initialise les objets : sphère et plan, et la lumière de manière
	//	dégueulasse
	objs = (t_obj *)malloc(sizeof(t_obj) * 2);
	objs[0].r = 200;
	objs[0].c.x = 0;
	objs[0].c.y = 0;
	objs[0].c.z = 1300;
	objs[0].oc = vec_substract(data.ray.o, objs[0].c);
	objs[0].intersect = intersect_sphere;
	objs[0].get_normal = get_sphere_normal;
	objs[1].c.x = 0;
	objs[1].c.y = 0;
	objs[1].c.z = 1300;
	objs[1].norm.x = 0;
	objs[1].norm.y = -1;
	objs[1].norm.z = 0.1;
	objs[1].norm = vec_normalize(objs[1].norm);
	objs[1].oc = vec_substract(data.ray.o, objs[1].c);
	objs[1].intersect = intersect_plane;
	objs[1].get_normal = get_plane_normal;
	light.o.x = -400;
	light.o.y = 150;
	light.o.z = 900;
	draw_image(&data, objs, light);
	mlx_mouse_hook(data.mlx.win, mouse_actions, &data);
	mlx_hook(data.mlx.win, 2, 3, key_actions, &data);
	mlx_hook(data.mlx.win, 17, 0, exit_all, &data);
	return (mlx_loop(data.mlx.mlx));*/
	if (ac > 1)
		parse(&data, av[1]);
	else
	{
		ft_putendl("patate");
		return (0);
	}
	print_parsed_data(data);
	exit_all(&data);
	return (0);
}
