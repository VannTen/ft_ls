# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2017/04/11 18:32:27 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Define target and sources

TARGET := ft_ls

SRC :=\
	list_repertory.c\
	get_file.c\
	get_file_infos.c\
	comp_file.c\
	treat_file.c\
	file_mode_and_perms.c\
	path_tools.c\
	set_params.c\
	destroy_file.c\
	long_format.c\
	field_long_format.c\
	is_file.c\
	main.c
#	set_options.c\
#	set_one_options.c\
# Directories

SRC_DIR :=
OBJ_DIR := object
INC_DIR := includes
DEP_DIR := .dep
TEST_DIR := test

# Dependencies

LIBRARY := libft
OBJECTS :=
ELSE :=

# Sub directories

SUBDIRS :=
