/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:09:11 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:09:11 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_str(char **arr)
{
	int	len;

	len = 0;
	while (arr && arr[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	unsigned char	*p;
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	p = malloc((ft_strlen((const char *)str) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < (size_t)ft_strlen((const char *)str))
	{
		p[i] = (unsigned char)str[i];
		i++;
	}
	p[i] = '\0';
	return ((char *)p);
}

char	**ft_strjoin(char **s1, char **s2)
{
	int		i;
	char	**result;
	size_t	len1;
	size_t	len2;

	i = -1;
	len1 = count_str(s1);
	len2 = count_str(s2);
	result = malloc(sizeof(char *) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	while (++i < (int)len1)
		result[i] = ft_strdup(s1[i]);
	i = -1;
	while (++i < (int)len2)
		result[i + len1] = ft_strdup(s2[i]);
	result[len1 + len2] = NULL;
	freedom(s1);
	freedom(s2);
	return (result);
}

void	ft_puterr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}
