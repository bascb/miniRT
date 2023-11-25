/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:47:20 by simao             #+#    #+#             */
/*   Updated: 2023/11/25 19:02:10 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Redirects the given line according 
 * to the identifier to the correct parser function.
 * 
 * @param **line a .rt file line splitted by spaces " "
 */
void	redirect_line(char **line)
{
	if (!ft_strncmp(line[0], "C", 1))
		parse_camera(line);
	if (!ft_strncmp(line[0], "A", 1))
		parse_ambient(line);
	if (!ft_strncmp(line[0], "L", 1))
		parse_light(line);
	if (!ft_strncmp(line[0], "sp", 2))
	{
		validate_line_values(line);
		parse_sphere(line);
	}
	if (!ft_strncmp(line[0], "pl", 2))
	{
		validate_line_values(line);
		parse_plane(line);
	}
	if (!ft_strncmp(line[0], "cy", 2))
	{
		validate_line_values(line);
		parse_cylinder(line);
	}
	if (!ft_strncmp(line[0], "NIGHT", 5))
		scene()->background = 1;
}

/**
 * @brief Sets the end of every line to '\0'
 * 
 * @param buffer the line to which we set a null terminator.
 */
void	end_file(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (i != 0)
		buffer[i] = '\0';
}

/**
 * @brief Check if the line has one of the valid identifiers 
 * from the subject or if it is only a empty line.
 * 
 * @param buffer the line read by get_next_line.
 * @returns returns 1 or 0. When 1 the file should continue 
 * to be read on parse_file.
 */
int	check_identifier(char *buffer)
{
	char	**line;

	end_file(buffer);
	if (!ft_strncmp(buffer, "\n", 2))
		return (1);
	line = ft_split(buffer, ' ');
	scene()->line = line;
	if (!line)
		return (0);
	if (!ft_strncmp(line[0], "C", 1) || !ft_strncmp(line[0], "A", 1) \
		|| !ft_strncmp(line[0], "L", 1) || !ft_strncmp(line[0], "sp", 2) \
		|| !ft_strncmp(line[0], "pl", 2) || !ft_strncmp(line[0], "cy", 2) \
		|| !ft_strncmp(line[0], "NIGHT", 5) || !ft_strncmp(line[0], "DAY", 3))
		redirect_line(line);
	else
		send_error("Valid identifiers are :\n A\n C\n L\n sp\n pl\n cy\n \
		NIGHT\n MAke sure to leave a space after each one\n");
	free_matrix(line);
	scene()->line = NULL;
	return (1);
}

/**
 * @brief Check if the file is the right type and extension : .rt
 * 
 * @param file the file name 
 */
int	valid_file_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 3] == '.' && file[i - 2] == 'r' && file[i - 1] == 't')
		return (1);
	return (0);
}

/**
 * @brief Check if the file extension is valid and 
 * check each line for the valid identifiers.
 * 
 * @param argv The command line arguments provided by the user.
 */
int	parse_file(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (valid_file_extension(argv[1]) == 0 || fd == -1)
		send_error_and_close_fd("Please provide a .rt file", fd);
	scene()->line_buffer = get_next_line(fd);
	if (!scene()->line_buffer)
		send_error_and_close_fd("File is empty", fd);
	while (scene()->line_buffer)
	{
		if (!check_identifier(scene()->line_buffer))
		{
			free(scene()->line_buffer);
			close(fd);
			return (0);
		}
		free(scene()->line_buffer);
		scene()->line_buffer = get_next_line(fd);
	}
	free(scene()->line_buffer);
	close(fd);
	return (1);
}
