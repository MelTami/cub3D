/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:17:49 by mvavasso          #+#    #+#             */
/*   Updated: 2023/10/02 20:17:50 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/queue.h"

/**
 * The above code defines functions to create and destroy a queue data structure.
 *
 * @return In the function `queue_create`, a pointer to a newly created `t_queue`
 * structure is being returned.
 */
t_queue	*queue_create(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	queue->len = 0;
	return (queue);
}

/**
 * The function `queue_destroy` is used to free the memory allocated for a queue
 * and all its elements.
 *
 * @param queue The parameter "queue" is a pointer to a structure of type
 * "t_queue".
 *
 * @return In the given code, if the `queue` parameter is `NULL`, the function 
 * will return without performing any further actions. If the `queue` parameter
 * is not `NULL`, the function will free the memory allocated for the queue and 
 * return.
 */
void	queue_destroy(t_queue *queue)
{
	if (!queue)
		return ;
	while (queue->len > 0)
		queue_pop(queue);
	free(queue);
}

/**
 * The function `queue_push` adds a new item with a given value to the end of a
 * queue.
 *
 * @param queue A pointer to a queue structure (t_queue).
 * @param value A pointer to a character array (string) that represents the value
 * to be added to the queue.
 *
 * @return The function does not have a return statement, so it does not
 * explicitly return anything.
 */
void	queue_push(t_queue *queue, char *value)
{
	t_queue_item	*new_item;

	if (!queue || !value)
		return ;
	new_item = (t_queue_item *)malloc(sizeof(t_queue_item));
	if (!new_item)
		return ;
	new_item->value = value;
	new_item->next = NULL;
	if (queue->len > 0)
	{
		new_item->prev = queue->last;
		queue->last->next = new_item;
		queue->last = new_item;
	}
	else
	{
		new_item->prev = NULL;
		queue->first = new_item;
		queue->last = new_item;
	}
	queue->len++;
}

/**
 * The function `queue_pop` removes the last item from a queue and frees the
 * memory associated with it.
 *
 * @param queue A pointer to a queue structure (t_queue)
 *
 * @return In the given code, the function `queue_pop` does not explicitly return
 * any value. Instead, it uses the `return;` statement to exit the function early
 * if certain conditions are met. Therefore, the function does not return
 * anything.
 */
void	queue_pop(t_queue *queue)
{
	t_queue_item	*tmp;

	if (!queue || queue->len == 0)
		return ;
	tmp = queue->last;
	if (queue->len == 1)
	{
		queue->last = NULL;
		queue->first = NULL;
	}
	else
	{
		queue->last = tmp->prev;
		queue->last->next = NULL;
	}
	queue->len--;
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}

/**
 * The function `queue_shift` shifts the first item in a queue and updates the
 * queue accordingly.
 *
 * @param queue A pointer to a queue structure.
 *
 * @return The function does not have a return type specified, so it does not
 * return anything.
 */
void	queue_shift(t_queue *queue)
{
	t_queue_item	*tmp;

	if (!queue || queue->len == 0)
		return ;
	tmp = queue->first;
	if (queue->len == 1)
	{
		queue->first = NULL;
		queue->last = NULL;
	}
	else
	{
		queue->first = tmp->next;
		queue->first->prev = NULL;
	}
	queue->len--;
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}
