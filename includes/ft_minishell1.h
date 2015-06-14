/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:11:24 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/14 19:00:44 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <signal.h>
# include <pwd.h>

typedef struct		s_lenv
{
	char			*name;
	char			*value;
	struct s_lenv	*next;
}					t_lenv;

void				env_push_back(t_lenv **list, char *name, char *value);
t_lenv				*create_list(char **tab);
char				**list_to_char(t_lenv *list);
t_lenv				*ft_env_relink(t_lenv *env, char *name);
t_lenv				*core(t_lenv *env, char *line);
void				exec_core(t_lenv *env, char **param);
char				**check_exec_param(t_lenv *env, char **param);
char				*check_exec(char *str, t_lenv *env);
int					check_param(char *str);
t_lenv				*ft_parse(t_lenv *env, char **param);
void				ft_setenv(t_lenv **env, char **param);
t_lenv				*get_lenv(t_lenv *env, char *str);
void				ft_unset_env(t_lenv **env, char **param);
void				ft_cd(t_lenv **env, char **param);
int					change_oldpwd(t_lenv **env);
int					check_error(char *new_path, char *path);
int					check_path_spe(char *path);
int					check_path(t_lenv *env, char *path);
void				change_pwd(t_lenv **env);
void				cd_home(t_lenv **env);
void				cd_env(t_lenv **env, char *path);
void				cd_env_old(t_lenv **env);
void				ft_exit(char **param);
void				print_prompt();
int					g_bool;

#endif
