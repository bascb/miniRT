/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:34:54 by simao             #+#    #+#             */
/*   Updated: 2023/11/24 18:09:40 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Multiplies the color of the object by the cooeficient of light
 * @param itsct the intersection object
 * @param ray the ray vector we shot from the camera
 * @param p the point of intersection. It is the origin plus dt.
 * @param dt the direction of the ray times the distance of "t".
*/
t_Color	sphr_color(t_Intersection itsct, t_Vector ray, t_Vector p, t_Vector dt)
{
	t_Vector	n;

	n = vector_sub(p, itsct.clst_sp->center);
	return (
		color_mult(itsct.clst_sp->color, \
		calc_light(p, n, vector_mult(dt, -1), itsct.clst_sp->spec)));
}

/**
 * @brief Performs the calculus to find the distance at which the ray intersect
 * with a sphere.
 * @param O The origin of the ray.
 * @param D The direction of the ray.
 * @param sphere The sphere to intersect with.
 * @returns t_Point (t1 and t2). The intersection points.
*/
t_Point	intrscts_sphr(t_Vector O, t_Vector D, t_Sphere sphere)
{
	float		a;
	float		b;
	float		c;
	float		discriminant;
	t_Point		intersections;

	a = dot_product(D, D);
	b = 2 * dot_product(vector_sub(O, sphere.center), D);
	c = dot_product(vector_sub(O, sphere.center), \
	vector_sub(O, sphere.center)) - sphere.radius * sphere.radius;
	discriminant = b * b - 4.0f * a * c;
	intersections.t1 = (-b + sqrt(discriminant)) / (2 * a);
	intersections.t2 = (-b - sqrt(discriminant)) / (2 * a);
	if (discriminant < 0)
	{
		intersections.t1 = (float)INT_MAX;
		intersections.t2 = (float)INT_MAX;
	}
	return (intersections);
}
