/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_mel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricschmi <ricschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:05:31 by ricschmi          #+#    #+#             */
/*   Updated: 2023/07/30 19:15:49 by ricschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

void *ft_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *destination = (unsigned char *)dest;
    const unsigned char *source = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        destination[i] = source[i];
    }

    return dest;
}

void *ft_realloc(void *ptr, size_t new_size) 
{
    if (ptr == NULL)
        return malloc(new_size);
    if (new_size == 0) 
	{
        free(ptr);
        return NULL;
    }
    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return NULL;
    size_t old_size = sizeof(ptr);
    size_t copy_size = (old_size < new_size) ? old_size : new_size;
    ft_memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    return new_ptr;
}


