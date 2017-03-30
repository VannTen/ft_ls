/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:20:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/30 18:22:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "options_interface.h"

int main(int argc,const char **argv)
{
	t_bool *options;

	if (argc > 1)
		set_options(argv + 1, &options);
	if (options[0])
		return (1);
	return (0);
}
