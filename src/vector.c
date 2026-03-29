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
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int vector_resize(t_vector *v, int capacity);
int vector_push_back(t_vector *v, void *item);
int vector_set(t_vector *v, int index, void *item);
void *vector_get(t_vector *v, int index);
int vector_delete(t_vector *v, int index);
int vector_free(t_vector *v);
int vector_total(t_vector *v);

bool vector_init(t_vector *v) {
  v->pfVectorTotal = vector_total;
  v->pfVectorResize = vector_resize;
  v->pfVectorAdd = vector_push_back;
  v->pfVectorSet = vector_set;
  v->pfVectorGet = vector_get;
  v->pfVectorFree = vector_free;
  v->pfVectorDelete = vector_delete;
  v->vector_list.capacity = VECTOR_INIT_CAPACITY;
  v->vector_list.total = 0;
  v->vector_list.items = malloc(sizeof(void *) * v->vector_list.capacity);
  if (!v->vector_list.items) {
    ft_putstr_fd("Memory allocation failed in vector_init\n", 2);
    return (false);
  }
  return (true);
}

int vector_total(t_vector *v) {
  int totalCount = UNDEFINE;
  if (v) {
    totalCount = v->vector_list.total;
  }
  return totalCount;
}

int vector_resize(t_vector *v, int capacity) {
  int status = UNDEFINE;
  if (v) {
    void **items_copy = malloc(sizeof(void *) * capacity);
    if (!items_copy)
      return (status);
    ft_memcpy(items_copy, v->vector_list.items,
              sizeof(void *) * v->pfVectorTotal(v));
    if (items_copy) {
      free(v->vector_list.items);
      v->vector_list.items = items_copy;
      v->vector_list.capacity = capacity;
      status = SUCCESS;
    }
  }
  return (status);
}

int vector_push_back(t_vector *v, void *item) {
  int status = UNDEFINE;
  if (v) {
    if (v->vector_list.capacity == v->vector_list.total) {
      status = vector_resize(v, v->vector_list.capacity * 2);
      if (status != UNDEFINE) {
        v->vector_list.items[v->vector_list.total++] = item;
      }
    } else {
      v->vector_list.items[v->vector_list.total++] = item;
      status = SUCCESS;
    }
  }
  return status;
}

int vector_set(t_vector *v, int index, void *item) {
  int status = UNDEFINE;
  if (v) {
    if ((index >= 0) && (index < v->vector_list.total)) {
      v->vector_list.items[index] = item;
      status = SUCCESS;
    }
  }
  return status;
}

void *vector_get(t_vector *v, int index) {
  void *readData = NULL;
  if (v) {
    if ((index >= 0) && (index < v->vector_list.total)) {
      readData = v->vector_list.items[index];
    }
  }
  return readData;
}

int vector_delete(t_vector *v, int index) {
  int status = UNDEFINE;
  int i = 0;
  if (v) {
    if ((index < 0) || (index >= v->vector_list.total))
      return status;
    v->vector_list.items[index] = NULL;
    for (i = index; (i < v->vector_list.total - 1); ++i) {
      v->vector_list.items[i] = v->vector_list.items[i + 1];
      v->vector_list.items[i + 1] = NULL;
    }
    v->vector_list.total--;
    if ((v->vector_list.total > 0) &&
        ((v->vector_list.total) == (v->vector_list.capacity / 4))) {
      vector_resize(v, v->vector_list.capacity / 2);
    }
    status = SUCCESS;
  }
  return status;
}

int vector_free(t_vector *v) {
  int status = UNDEFINE;
  int total = v->pfVectorTotal(v);
  if (v) {
    for (int i = 0; i < total; i++) {
      void *temp = v->pfVectorGet(v, i);
      free(temp);
    }
    free(v->vector_list.items);
  }
  return status;
}
