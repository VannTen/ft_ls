/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mode_and_perms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:36:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/05 15:18:04 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mode_and_perms_interface.h"
#include "libft.h"
#include <sys/stat.h>

char	read_permission(mode_t mode, enum e_perm_category perm_category)
{
	const mode_t read_perm[] =
	{
		S_IRUSR,
		S_IRGRP,
		S_IROTH
	};
	int index;

	index = 0;
	while (index < PERM_CAT_NBR)
	{
		if ((mode & read_perm[perm_category]) == read_perm[perm_category])
			return ('r');
		index++;
	}
	return ('-');
}

char	write_permission(mode_t mode, enum e_perm_category perm_category)
{
	const mode_t write_perm[] =
	{
		S_IWUSR,
		S_IWGRP,
		S_IWOTH
	};
	int index;

	index = 0;
	while (index < PERM_CAT_NBR)
	{
		if ((mode & write_perm[perm_category]) == write_perm[perm_category])
			return ('w');
		index++;
	}
	return ('-');
}

char	execution_permission(mode_t mode, enum e_perm_category perm_category)
{
	const mode_t exec_perm[] = {S_IXUSR, S_IXGRP, S_IXOTH};

	if ((mode & exec_perm[perm_category]) == exec_perm[perm_category])
	{
		if ((perm_category == OWNER && (mode & S_ISUID) == S_ISUID) ||
				(perm_category == GROUP && (mode & S_ISGID) == S_ISGID))
			return('s');
		if (perm_category == OTHER && (mode & S_ISVTX) == S_ISVTX)
			return ('t');
		return ('x');
	}
	else
	{
		if ((perm_category == OWNER && (mode & S_ISUID) == S_ISUID) ||
				(perm_category == GROUP && (mode & S_ISGID) == S_ISGID))
			return('S');
		if (perm_category == OTHER && (mode & S_ISVTX) == S_ISVTX)
			return ('T');
		return ('-');
	}
}


char	file_type(mode_t mode)
{
	const mode_t file_types[] = {
		S_IFREG,
		S_IFLNK,
		S_IFIFO,
		S_IFCHR,
		S_IFDIR,
		S_IFBLK,
		S_IFSOCK,
		S_IFWHT
	};
	const char	file_identifier[] = "-lpcdbsw";
	int	index;

	mode = mode & S_IFMT;
	index = 0;
	while (file_identifier[index] != '\0')
	{
		if (mode == file_types[index])
			return (file_identifier[index]);
		else
			index++;
	}
	exit(EXIT_FAILURE);
}

/*
** The mode_field parameter is expected to be always a array of size 7
*/

void	fill_mode_field(char *mode_field, mode_t mode)
{
	mode_field[FILETYPE] = file_type(mode);
	mode_field[OWNER_READ] = read_permission(mode, OWNER);
	mode_field[OWNER_WRITE] = write_permission(mode, OWNER);
	mode_field[OWNER_EXE] = execution_permission(mode, OWNER);
	mode_field[GROUP_READ] = read_permission(mode, GROUP);
	mode_field[GROUP_WRITE] = write_permission(mode, GROUP);
	mode_field[GROUP_EXE] = execution_permission(mode, GROUP);
	mode_field[OTHER_READ] = read_permission(mode, OTHER);
	mode_field[OTHER_WRITE] = write_permission(mode, OTHER);
	mode_field[OTHER_EXE] = execution_permission(mode, OTHER);
	mode_field[MODE_ARRAY_SIZE] = '\0';
}
