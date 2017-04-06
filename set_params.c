/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:56:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/06 19:35:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parameters_defs.h"
#include "file_interface.h"

t_ls_param *settle_param(int arg_count, char **arg_values)
{
	static t_ls_param	params;

	(void)arg_count;
	(void)arg_values;
	params.ft_comp = &comp_alpha;
	params.ft_print_entry = do_something_with_it_2;
	return (&params);
}
