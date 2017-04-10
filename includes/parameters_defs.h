/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:26:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/10 14:00:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_DEFS_H
# define PARAMETERS_DEFS_H
# include "parameters_interface.h"
# include "libft.h"
# include <sys/syslimits.h>
# include <sys/dir.h>

typedef void	(*t_print)(void*);
typedef void	*(*t_get)(const char *file_name,
		char *parent_path, int path_len);
typedef void	(*t_loop_through)(t_btree *entries, t_iter f);
typedef void	(*t_loop_through_2)(t_btree *entries, t_iter_two f, void*);
struct s_ls_param
{
	t_compare			ft_comp;
	t_print				ft_print_entry;
	t_get				ft_get_file;
	t_loop_through		ft_loop_through;
	t_loop_through_2	ft_loop_through_2;
	t_iter_two			ft_subdir;
	t_destroy			ft_destroy_file;
	t_bool		*options;
	int			options_number;
};

#endif
