/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:55:50 by smagalha          #+#    #+#             */
/*   Updated: 2023/11/25 20:22:12 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		send_error("Please provide only a .rt file as program input\n");
	set_canvas(960, 540);
	set_viewport();
	parse_file(argv);
	set_mlx();
	srand(time(NULL));
	mlx_hook(mlibx()->win, 2, 0, key_press, NULL);
	mlx_hook(mlibx()->win, 17, 17, close_window, NULL);
	render();
	mlx_loop(mlibx()->mlx);
	return (1);
}
