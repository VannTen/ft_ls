/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:26:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/06 19:33:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_DEFS_H
# define PARAMETERS_DEFS_H
# include "parameters_interface.h"
# include "libft.h"
# include <sys/syslimits.h>

typedef void (*t_print)(void*);
struct s_ls_param
{
	char		cur_path[PATH_MAX];
	t_compare	ft_comp;
	t_print		ft_print_entry;
	t_bool		*options;
};

#endif
