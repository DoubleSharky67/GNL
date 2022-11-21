/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:18:48 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/10/26 12:16:50 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char	*get_next_line(int fd);

int		ft_strlen_line(const char *s, char c);
void	ft_bzero(void *s, int n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, int start, int len);

#endif
