/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:39:42 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/30 17:02:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options_interface.h"
#include "unix_usage_interface.h"
#include "parameters_defs.h"

static	t_bool *init_default_options(void)
{
	static t_bool options[OPT_NBR];

	options[ALL_FILES] = FALSE;
	options[LONG_FORMAT] = FALSE;
	options[REVERSE_ORDER] = FALSE;
	options[RECURSIVE] = FALSE;
	options[SORT_BY_MODIF_TIME] = FALSE;
	return (options);
}

int	set_options(const char **arg_list, t_bool **ls_options)
{
	const t_apply_opt	apply_options[OPT_NBR] = {CONST_APPLY_OPT_INIT};
	const char			synopsis[OPT_NBR] = {CONST_SYNOPSIS_INITIALIZER};
	t_bool				*options;
	int					opt_specified_nbr;

	options = init_default_options();
	opt_specified_nbr =
		apply_cmdline_opt(synopsis, arg_list, options, apply_options);
	*ls_options = options;
	return (opt_specified_nbr);
}
