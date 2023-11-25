/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:47:20 by simao             #+#    #+#             */
/*   Updated: 2023/11/25 17:59:57 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	validate_rgb_values(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		send_error("Ambient lightning RGB colors must be between 0-255\n");
}

void	validate_normal_vector(int x, int y, int z)
{
	if (x > 1.0 || y > 1.0 || z > 1.0 || x < -1.0 || y < -1.0 || z < -1.0)
		send_error("Normal vectors must be between -1.0 and 1.0\n");
}

float	validate_fov(float fov)
{
	if (fov < 0 || fov > 180)
		send_error("Camera field of view must be between 0 and 180\n");
	return (fov);
}

void	validate_plane_values(char **plane_point, char **plane_normal, \
							char **plane_color, char **line)
{
	if (!plane_point[0] || !plane_point[1] || !plane_point[2])
	{
		free_matrix(plane_point);
		free_matrix(plane_normal);
		free_matrix(plane_color);
		send_error("Plane point values must be provided in format: x,y,z\n");
	}
	if (!plane_normal[0] || !plane_normal[1] || !plane_normal[2])
	{
		free_matrix(plane_point);
		free_matrix(plane_normal);
		free_matrix(plane_color);
		send_error("Plane normal values must be provided in format: x,y,z\n");
	}
	if (!plane_color[0] || !plane_color[1] || !plane_color[2])
	{
		free_matrix(plane_point);
		free_matrix(plane_normal);
		free_matrix(plane_color);
		send_error("Color values must be in format: R,G,B. range 0-255.\n");
	}
}

void	validate_cyl_values(char **cyl_point, char **cyl_normal, \
							char **cyl_color, char **line)
{
	if (!cyl_point[0] || !cyl_point[1] || !cyl_point[2])
	{
		free_matrix(cyl_point);
		free_matrix(cyl_normal);
		free_matrix(cyl_color);
		send_error("Cylinder values must be provided in format: x,y,z\n");
	}
	if (!cyl_normal[0] || !cyl_normal[1] || !cyl_normal[2])
	{
		free_matrix(cyl_point);
		free_matrix(cyl_normal);
		free_matrix(cyl_color);
		send_error("Cyl normal values must be provided in format: x,y,z\n");
	}
	if (!cyl_color[0] || !cyl_color[1] || !cyl_color[2])
	{
		free_matrix(cyl_point);
		free_matrix(cyl_normal);
		free_matrix(cyl_color);
		send_error("Color values must be in format: R,G,B. range 0-255.\n");
	}
}
