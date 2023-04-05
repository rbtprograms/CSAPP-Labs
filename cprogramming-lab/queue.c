/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new() 
{
  queue_t *queue = malloc(sizeof(queue_t));
  // what if malloc returns null?
  if (!queue) {
    return NULL;
  }
  queue->head = NULL;
  queue->tail = NULL;
  queue->cnt = 0;
  return queue;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
  list_ele_t *next;
  list_ele_t *ele = q->head;
  while(ele->next) {
    next = ele->next;
    free(ele);
    ele = next;
  }
  free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
  // this makes no attempt to handle errors and assumes everything goes smoothly so sue me
  list_ele_t *ele = malloc(sizeof(list_ele_t));
  //happens if malloc returns NULL because there is no memory available
  if (!ele) {
    return false;
  }
  ele->value = v;
  ele->next = q->head;
  q->head = ele;
  q->cnt++;
  return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
  /* You need to write the complete code for this function */
  /* Remember: It should operate in O(1) time */
  list_ele_t *ele = malloc(sizeof(list_ele_t));
  //happens if malloc returns NULL because there is no memory available
  if (!ele) {
    return false;
  }
  ele->value = v;
  ele->next = NULL;
  // set the element as the next item and then make it the tail
  q->tail->next = ele;
  q->tail = ele;
  q->cnt++;
  return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  *Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
  /* You need to fix up this code. */
  if (!q || !q->head) {
    return false;
  }
  list_ele_t *head = q->head;
  q->head = q->head->next;
  q->cnt--;
  if (vp) {
    *vp = head->value;
  }
  free(head);
  return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
  if (!q || !q->head) {
    return 0;
  }
  return q->cnt;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
  /* You need to write the code for this function */
  //WORK IN PROGRESS
}

