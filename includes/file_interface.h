/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:15:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/09 15:14:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_INTERFACE_H
# define FILE_INTERFACE_H
# include "libft.h"
# include <sys/dir.h>

struct s_file;

/*
** Print functions, also add directories to the list if recursive option is set
** Implementation file : treat_file.c
*/

void	print_name(void *entry);
void	print_name_stat(void *entry);
void	print_long_format(void *entry);
int		get_block_nbr(void *file);

/*
** Comparison functions
** Implentation file : comp_file.c
*/

int		comp_alpha_stat(const void *entry_1, const void *entry_2);
int		comp_alpha_dir_entry(const void *entry_1, const void *entry_2);
int		comp_time(const void *entry_1, const void *entry_2);

/*
** Get files functions
** Obtain the file, which is a different object depending
** on the options which are set
*/

void	*get_dir_entry(DIR *dir, char *parent_path, int path_len,
		t_bool take_dotfiles);
void	*get_stat_dir(DIR *dir, char *parent_path, int path_len,
		t_bool take_dotfiles);
void	add_to_sub_dirs_list_stat(void *entry, void *list_dir);
void	add_to_sub_dirs_list_dirent(void *entry, void *list_dir);

/*
** Destroyers
** Implementation file : destroy_file.c
*/

void	dir_entry_destroy(void **direntry);
void	stat_entry_destroy(void **s_file);

#endif
