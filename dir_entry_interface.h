/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_entry_interface.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:34:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 17:39:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIR_ENTRY_INTERFACE_H
# define DIR_ENTRY_INTERFACE_H
# include <sys/types.h>
# include <sys/dir.h>

void	*get_dir_entry(DIR *dir);
void	do_something_with_it(void *entry);
int		comp_alpha(void *entry_1, void *entry_2);

#endif
