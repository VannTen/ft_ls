/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:26:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 18:21:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_DEFS_H
# define PARAMETERS_DEFS_H
# include "parameters_interface.h"
# include "libft.h"
# include "long_format.h"
# include <sys/syslimits.h>
# include <sys/dir.h>
# include <stddef.h>

struct s_ls_param
{
	t_compare			ft_comp;
	t_print				ft_print_entry;
	t_get				ft_get_file;
	t_loop_through		ft_loop_through;
	t_loop_through_2	ft_loop_through_2;
	t_iter_two			ft_subdir;
	t_destroy			ft_destroy_file;
	t_btree				*error_tree;
	t_bool				*options;
	int					options_number;
	t_fields			*temp_fields;
	char				*parent_path;
	size_t				path_len_max;
	t_bool				has_error;
	t_bool				is_first;
	t_bool				put_dir_name_before;
	const char			*prog_name;
};

#endif
