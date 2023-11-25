/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:45:22 by bcastelo          #+#    #+#             */
/*   Updated: 2023/11/25 21:10:36 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief THis function will set some default values , in case
 * the user hasn't provided hem.
 * 
 * @param
 */
void	set_default_values(void)
{
	if (scene()->lights == NULL)
		set_ambient_light(0.2);
}
