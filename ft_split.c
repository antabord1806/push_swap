/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:08:50 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:08:50 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

static size_t	ft_count_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static int	ft_str_fill(char **arr_aloc, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			arr_aloc[i] = malloc((len + 1) * sizeof(char));
			if (!arr_aloc[i])
				return (0);
			ft_strlcpy(arr_aloc[i], s - len, len + 1);
			i++;
		}
	}
	arr_aloc[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	nwords;
	char	**arr_aloc;

	if (!s)
		return (NULL);
	nwords = ft_count_words(s, c);
	arr_aloc = malloc((nwords + 1) * sizeof(char *));
	if (!arr_aloc)
		return (NULL);
	ft_str_fill(arr_aloc, s, c);
	if (!arr_aloc)
		return (NULL);
	arr_aloc[nwords] = NULL;
	return (arr_aloc);
}
