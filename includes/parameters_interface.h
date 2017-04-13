/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:35:10 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 18:25:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_INTERFACE_H
# define PARAMETERS_INTERFACE_H
# define CONST_SYNOPSIS_INIT "alrRt"
# include "libft.h"
# include <stddef.h>

enum	e_ls_opt
{
	ALL_FILES,
	LONG_FORMAT,
	REVERSE_ORDER,
	RECURSIVE,
	SORT_BY_MODIF_TIME,
	OPT_NBR
};

typedef struct s_ls_param	t_ls_param;

typedef void	(*t_print)(void*);
typedef void	*(*t_get)(const char *file_name,
		t_ls_param *param, size_t path_len);
typedef void	(*t_loop_through)(t_btree *entries, t_iter f);
typedef void	(*t_loop_through_2)(t_btree *entries, t_iter_two f, void*);

t_ls_param *settle_param(int arg_count, const char **arg_values);

#endif
