/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:47:20 by simao             #+#    #+#             */
/*   Updated: 2023/11/25 17:47:04 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	end_program(void)
{
	if (scene()->spheres != NULL)
		free(scene()->spheres);
	if (scene()->planes != NULL)
		free(scene()->planes);
	if (scene()->cylinders != NULL)
		free(scene()->cylinders);
	if (scene()->lights != NULL)
		free(scene()->lights);
	if (scene()->line != NULL)
		free_matrix(scene()->line); 
	if (scene()->line_buffer != NULL)
		free(scene()->line_buffer); 
	exit(0);
}
