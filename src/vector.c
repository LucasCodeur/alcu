/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:23:01 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/29 14:50:19 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include <stdlib.h>

int vectorResize(t_vector *v, int capacity);
int vectorPushBack(t_vector *v, void *item);
int vectorSet(t_vector *v, int index, void *item);
void *vectorGet(t_vector *v, int index);
int vectorDelete(t_vector *v, int index);
int vectorFree(t_vector *v);
int vectorTotal(t_vector *v);

void vector_init(t_vector *v)
{
    // Initialize function pointers
    v->pfVectorTotal = vectorTotal;
    v->pfVectorResize = vectorResize;
    v->pfVectorAdd = vectorPushBack;
    v->pfVectorSet = vectorSet;
    v->pfVectorGet = vectorGet;
    v->pfVectorFree = vectorFree;
    v->pfVectorDelete = vectorDelete;
    // Allocate memory and check for failure
    v->vector_list.capacity = VECTOR_INIT_CAPACITY;
    v->vector_list.total = 0;
    v->vector_list.items = malloc(sizeof(void *) * v->vector_list.capacity);
    if (!v->vector_list.items)
    {
        ft_putstr_fd("Memory allocation failed in vector_init\n", 2);
        exit(EXIT_FAILURE);
    }
}

int vectorTotal(t_vector *v)
{
    int totalCount = UNDEFINE;
    if(v)
    {
        totalCount = v->vector_list.total;
    }
    return totalCount;
}

int vectorResize(t_vector *v, int capacity)
{
    int  status = UNDEFINE;
    if(v)
    {
        void **items = realloc(v->vector_list.items, sizeof(void *) * capacity);
        if (items)
        {
            v->vector_list.items = items;
            v->vector_list.capacity = capacity;
            status = SUCCESS;
        }
    }
    return status;
}

int vectorPushBack(t_vector *v, void *item)
{
    int  status = UNDEFINE;
    if(v)
    {
        if (v->vector_list.capacity == v->vector_list.total)
        {
            status = vectorResize(v, v->vector_list.capacity * 2);
            if(status != UNDEFINE)
            {
                v->vector_list.items[v->vector_list.total++] = item;
            }
        }
        else
        {
            v->vector_list.items[v->vector_list.total++] = item;
            status = SUCCESS;
        }
    }
    return status;
}

int vectorSet(t_vector *v, int index, void *item)
{
    int  status = UNDEFINE;
    if(v)
    {
        if ((index >= 0) && (index < v->vector_list.total))
        {
            v->vector_list.items[index] = item;
            status = SUCCESS;
        }
    }
    return status;
}

void *vectorGet(t_vector *v, int index)
{
    void *readData = NULL;
    if(v)
    {
        if ((index >= 0) && (index < v->vector_list.total))
        {
            readData = v->vector_list.items[index];
        }
    }
    return readData;
}

int vectorDelete(t_vector *v, int index)
{
    int  status = UNDEFINE;
    int i = 0;
    if(v)
    {
        if ((index < 0) || (index >= v->vector_list.total))
            return status;
        v->vector_list.items[index] = NULL;
        for (i = index; (i < v->vector_list.total - 1); ++i)
        {
            v->vector_list.items[i] = v->vector_list.items[i + 1];
            v->vector_list.items[i + 1] = NULL;
        }
        v->vector_list.total--;
        if ((v->vector_list.total > 0) && ((v->vector_list.total) == (v->vector_list.capacity / 4)))
        {
            vectorResize(v, v->vector_list.capacity / 2);
        }
        status = SUCCESS;
    }
    return status;
}

int vectorFree(t_vector *v)
{
    int  status = UNDEFINE;
    int     total = v->pfVectorTotal(v);
    if(v)
    {
        for (int i = 0; i < total; i++)
        {
            void * temp = v->pfVectorGet(v, i);
            free (temp);
        }
        free(v->vector_list.items);
    }
    return status;
}
