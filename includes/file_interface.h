/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:15:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/06 19:30:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_INTERFACE_H
# define FILE_INTERFACE_H
# include <sys/dir.h>

/*
** Print functions, also add directories to the list if recursive option is set
** Implementation file : treat_file.c
*/

void	do_something_with_it(void *entry);
void	do_something_with_it_2(void *entry);
int		get_block_nbr(void *file);

/*
** Comparison functions
** Implentation file : comp_file.c
*/

int		comp_alpha(void *entry_1, void *entry_2);
int		comp_time(void *entry_1, void *entry_2);

/*
** Get files functions
** Obtain the file, which is a different object depending
** on the options which are set
*/

void	*get_dir_entry(DIR *dir, char *parent_path, int path_len);
void	*get_stat_dir(DIR *dir, char *parent_path, int path_len);
void	add_to_sub_dirs_list(void *entry, void *list_dir);

#endif
