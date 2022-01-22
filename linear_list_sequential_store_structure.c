#include <stdio.h>

typedef int element_t;

#define MAX_SIZE  20

typedef struct  {
    element_t elements[MAX_SIZE];
    int length;
} list_t;

/**
 * list_init - Initialize a list structure
 * @list list_t structure to be initialized.
 */
void list_init(list_t *list)
{
    list->length = 0;
}

/**
 * list_empty - test whether list is  list_empty
 * @list the list to test.
 */
int list_empty(list_t *list)
{
    return list->length == 0;
}

/**
 * list_clear - clear the all of elements of list
 * @list the list to clear.
 */
void list_clear(list_t *list)
{
    list->length = 0;
}

/**
 * list_get_element - get element value by specific position
 * @list a list contains a zero or more elements.
 * @pos the position in the list.
 * @element return element value.
 */ 
int list_get_element(list_t *list, int pos, element_t *element)
{
    if (pos <= 0 || pos > MAX_SIZE) {
        return 0;
    }
    
    if (pos > list->length) {
        return 0;
    }

    /* O(1) */
    *element = list->elements[pos - 1];
    
    return pos;
}

/**
 * list_pos - find position of element in the list
 * @list the list to search
 * @element the element value search for
 */
int list_pos(list_t *list, element_t element)
{
    int i;
    
    if (list->length <= 0) {
        return 0;
    }
    
    /* O(n) */
    for (i = 0; i < list->length; i++) {
        if (element == list->elements[i]) {
            return i + 1;
        }
    }
    
    return 0;
}

/**
 * list_insert - insert new element into list
 * @list the list want to insert in
 * @pos the position insert to
 * @element element want to insert
 */
int list_insert(list_t *list, int pos, element_t element)
{
    int i;
    
    if (list->length == MAX_SIZE) {
        return 0;
    }
    
    if (pos < 1 || pos > (list->length + 1)) {
        return 0;
    }
    
    /* O (n) */
    if (pos <= list->length) {
        for (i = list->length - 1; i >= (pos - 1); i--) {
            list->elements[i + 1] = list->elements[i];
        }
    }
    list->elements[pos - 1] = element;
    list->length++;
    
    return pos;
}

/**
 * list_del - delete element
 * @list the list wnat to delete
 * @pos delete element's position
 * @element deleted element
 */
int list_del(list_t *list, int pos, element_t *element)
{
    int i;
    
    if (list->length == 0) {
        return 0;
    }
    
    if (pos < 1 || pos > list->length) {
        return 0;
    }
    
    *element = list->elements[pos - 1];
    
    /* O(n) */
    if (pos < list->length) {
        for (i = pos; i < list->length; i++) {
            list->elements[i - 1] = list->elements[i];
        }
    }
    list->length--;
    
    return pos;
}

/**
 * list_length - return length of list_length
 * @list target list
 */
int list_length(list_t *list)
{
    return list->length;
}
