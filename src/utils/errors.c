/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:47:20 by simao             #+#    #+#             */
/*   Updated: 2023/11/25 19:03:06 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Displays an error message and exits the program. 
 * 
 * @param error the error message to display on the console.
 */
void	send_error(char *error)
{
	ft_putstr("\n", 2);
	ft_putstr("Error: ", 2);
	ft_putstr(error, 2);
	ft_putstr("\n\n", 2);
	end_program();
}

/**
 * @brief Displays an error message and exits the program. 
 * 
 * @param error the error message to display on the console.
 */
void	send_error_and_close_fd(char *error, int fd)
{
	close(fd);
	send_error(error);
}
