/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:24:59 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 10:37:12 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*get_clean_line(char **backup_line)
{
	char	*line;
	char	*new_backup_line;
	size_t	l;
	size_t	has_nl;

	l = 0;
	while ((*backup_line)[l] && (*backup_line)[l] != '\n')
		l++;
	has_nl = ((*backup_line)[l] == '\n');
	line = ft_substr(*backup_line, 0, l + has_nl);
	if (!line)
		return (ft_safe_allocate(NULL, FREE_ONE, *backup_line, NULL));
	new_backup_line = ft_strjoin(NULL, *backup_line + l + has_nl);
	if (!new_backup_line)
		return (
			ft_safe_allocate(NULL, FREE_ONE, line, NULL),
			ft_safe_allocate(NULL, FREE_ONE, *backup_line, NULL));
	ft_safe_allocate(NULL, FREE_ONE, *backup_line, NULL);
	*backup_line = new_backup_line;
	return (line);
}

static char	*get_line(int fd, char *backup_line, char *buffer)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	while (bytes && !is_there_any_newline(backup_line))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (ft_safe_allocate(NULL, FREE_ONE, backup_line, NULL));
		if (bytes == 0)
		{
			if (backup_line && !*backup_line)
				return (ft_safe_allocate(NULL, FREE_ONE, backup_line, NULL));
			return (backup_line);
		}
		buffer[bytes] = 0;
		tmp = ft_strjoin(backup_line, buffer);
		ft_safe_allocate(NULL, FREE_ONE, backup_line, NULL);
		if (!tmp)
			return (NULL);
		backup_line = tmp;
	}
	return (backup_line);
}

char	*get_next_line(int fd)
{
	static char		*backup_line;
	char			buffer[BUFFER_SIZE + 1];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	backup_line = get_line(fd, backup_line, buffer);
	if (!backup_line)
		return (NULL);
	line = get_clean_line(&backup_line);
	return (line);
}
