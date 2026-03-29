/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:24:01 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/29 14:40:21 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H 
# define VECTOR_H 

#define VECTOR_INIT_CAPACITY 6
#define UNDEFINE  -1
#define SUCCESS 0

#define VECTOR_INIT(vec) t_vector vec;\
 vector_init(&vec)

typedef struct s_vector_list
{
	void		**items;
	int		capacity;
	int		total;
}		t_vector_list;

typedef struct s_vector t_vector;

struct	s_vector
{
	t_vector_list vector_list;  /**< List to store vector elements */
	int (*pfVectorTotal)(t_vector *); /**< Retrieves the total number of elements in the vector */
	int (*pfVectorResize)(t_vector *, int); /**< Resizes the vector to a new capacity */
	int (*pfVectorAdd)(t_vector *, void *); /**< Adds an element to the vector */
	int (*pfVectorSet)(t_vector *, int, void *); /**< Sets an element at a specific index in the vector */
	void *(*pfVectorGet)(t_vector *, int); /**< Retrieves an element from the vector */
	int (*pfVectorDelete)(t_vector *, int); /**< Deletes an element from the vector */
	int (*pfVectorFree)(t_vector *); /**< Frees the memory allocated for the vector */
};

void	vector_init(t_vector* v);

#endif
