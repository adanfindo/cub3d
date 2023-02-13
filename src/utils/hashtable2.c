/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:29:34 by afindo          #+#    #+#             */
/*   Updated: 2022/08/31 14:04:48 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

static int	hashfunction(char *key, int n_buckets)
{
	int	hashvalue;

	hashvalue = 0;
	while (*key)
	{
		hashvalue = hashvalue + 31 * *key;
		key++;
	}
	return (hashvalue % n_buckets);
}

void	hashtable_add(t_hashlist ***hashtable, int size, char *key, int value)
{
	t_hashlist	*new;

	new = hashlist_new(key, value);
	hashlist_addfront(hashtable[hashfunction(key, size)], new);
}

int	hashtable_get(t_hashlist ***hashtable, int size, char *key)
{
	t_hashlist	**bucket;
	t_hashlist	*temp;

	bucket = hashtable[hashfunction(key, size)];
	temp = *bucket;
	while (temp)
	{
		if (!ft_strncmp(key, temp->key, ft_strlen(key) + 1))
			return (temp->value);
		temp = temp->next;
	}
	return (-1);
}

void	hashtable_delete(t_hashlist	***hashtable)
{
	int	i;

	i = 0;
	while (hashtable[i])
	{
		hashlist_clear(hashtable[i]);
		i++;
	}
	free(hashtable);
}

t_hashlist	***hashtable_init(int n_buckets)
{
	t_hashlist	***hashtable;
	int			i;

	hashtable = ft_calloc(n_buckets + 1, sizeof(t_hashlist **));
	if (!hashtable)
		return (NULL);
	i = 0;
	while (i < n_buckets)
	{
		hashtable[i] = malloc(sizeof(t_hashlist **));
		if (!hashtable[i])
		{
			hashtable_delete(hashtable);
			return (NULL);
		}
		*(hashtable[i]) = NULL;
		i++;
	}
	return (hashtable);
}
