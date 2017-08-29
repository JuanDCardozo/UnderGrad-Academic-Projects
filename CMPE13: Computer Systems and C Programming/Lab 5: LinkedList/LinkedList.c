// Standard Libraries
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// User Libraries
#include "Common.h"
#include "LinkedList.h"

/**
 * This function compares two strings and returns which one is bigger. It takes in two structs
 * and returns which of the structs contains the longest string.
 * @param ListItems
 * @return Returns which struct is the longest
 */
int CompareStringSize(ListItem*firstItem, ListItem*secondItem)
{
    int first = 0, second = 0;


    if ((firstItem->data) != NULL) {
        first = strlen(firstItem->data);
    }
    if (secondItem->data != NULL) {
        second = strlen(secondItem->data);
    }

    if (first > second) {
        return 1;
    } else if (first < second) {
        return -1;
    } else {
        return 0;
    }
}

/**
 * This function starts a new linked list. Given an allocated pointer to data it will return a
 * pointer for a malloc()ed ListItem struct. If malloc() fails for any reason, then this function
 * returns NULL otherwise it should return a pointer to this new list item. data can be NULL.
 *
 * @param data The data to be stored in the first ListItem in this new list. Can be any valid
 *             pointer value.
 * @return A pointer to the malloc()'d ListItem. May be NULL if an error occured.
 */
ListItem *LinkedListNew(char *data)
{
    ListItem *newItem = malloc(sizeof (ListItem));
    if (newItem != NULL) {
        newItem->data = data;
        newItem->nextItem = NULL;
        newItem->previousItem = NULL;
    }
    return newItem;
}

/**
 * This function will remove a list item from the linked list and free() the memory that the
 * ListItem struct was using. It doesn't, however, free() the data pointer and instead returns it
 * so that the calling code can manage it.  If passed a pointer to NULL, LinkedListRemove() should
 * return NULL to signal an error.
 *
 * @param item The ListItem to remove from the list.
 * @return The data pointer from the removed item. May be NULL.
 */
char *LinkedListRemove(ListItem *item)
{
    ListItem*tmp = LinkedListNew(NULL);
    tmp->nextItem = item->nextItem;
    item->previousItem = item->nextItem;
    item->nextItem = item->previousItem;
    tmp->data = item->data;

    free(item);
    return tmp->data;
}

/**
 * This function returns the total size of the linked list. This means that even if it is passed a
 * ListItem that is not at the head of the list, it should still return the total number of
 * ListItems in the list. A NULL argument will result in 0 being returned.
 *
 * @param list An item in the list to be sized.
 * @return The number of ListItems in the list (0 if `list` was NULL).
 */
int LinkedListSize(ListItem *list)
{
    int counter = 1;
    list = LinkedListGetFirst(list);

    while (list->nextItem != NULL) {
        ++counter;
        list = list->nextItem;
    }

    if (list == NULL) {
        counter = 0;
    }
    return counter;
}

/**
 * This function returns the head of a list given some element in the list. If it is passed NULL,
 * it will just return NULL. If given the head of the list it will just return the pointer to the
 * head anyways for consistency.
 *
 * @param list An element in a list.
 * @return The first element in the list. Or NULL if provided an invalid list.
 */
ListItem *LinkedListGetFirst(ListItem *list)
{
    while (list->previousItem != NULL) {
        list = list->previousItem;
    }
    return list;
}

/**
 * This function allocates a new ListItem containing data and inserts it into the list directly
 * after item. It rearranges the pointers of other elements in the list to make this happen. If
 * passed a NULL item, InsertAfter() should still create a new ListItem, just with no previousItem.
 * It returns NULL if it can't malloc() a new ListItem, otherwise it returns a pointer to the new
 * item. The data parameter is also allowed to be NULL.
 *
 * @param item The ListItem that will be before the newly-created ListItem.
 * @param data The data the new ListItem will point to.
 * @return A pointer to the newly-malloc()'d ListItem.
 */
ListItem *LinkedListCreateAfter(ListItem *item, char *data)
{
    ListItem*newItem = LinkedListNew(data);

    if (item->nextItem == NULL) {
        // The next item  of the list is the newItems data
        item->nextItem = newItem;

        //Set the nextItem pointer of the NewItem to NULL as it is the end of
        newItem->nextItem = NULL;

        //Points back to the previous
        newItem->previousItem = item;

        //Put the data into the newItem
        newItem->data = data;
    } else {//If it is not the first item

        // Put the data into the newItem
        newItem->data = data;

        // Points to the nextItem from Item
        newItem->nextItem = item->nextItem;

        // Items next points to the newItem's data
        item->nextItem = newItem;

        // newItem points back to items 
        newItem->previousItem = item;

    }
    return newItem;
}

/**
 * LinkedListSwapData() switches the data pointers of the two provided ListItems. This is most
 * useful when trying to reorder ListItems but when you want to preserve their location. It is used
 * within LinkedListSort() for swapping items, but probably isn't too useful otherwise. This
 * function should return STANDARD_ERROR if either arguments are NULL, otherwise it should return
 * SUCCESS. If one or both of the data pointers are NULL in the given ListItems, it still does
 * perform the swap and returns SUCCESS.
 *
 * @param firstItem One of the items whose data will be swapped.
 * @param secondItem Another item whose data will be swapped.
 * @return SUCCESS if the swap worked or STANDARD_ERROR if it failed.
 */
int LinkedListSwapData(ListItem *firstItem, ListItem *secondItem)
{
    if (firstItem == NULL || secondItem == NULL) {
        return STANDARD_ERROR;
    } else {
        //Create space in the heap to store temporary data
        ListItem*temp = malloc(sizeof (ListItem));

        //Temprary store the first items data
        temp->data = firstItem->data;

        // Switch the first and the second values
        firstItem->data = secondItem->data;

        //Put the value of first into second items
        secondItem->data = temp->data;

        //Free the memory used by temp
        free(temp);

        return SUCCESS;
    }
}

/**
 * LinkedListSort() performs a selection sort on list to sort the elements into decending order. It
 * makes no guarantees of the addresses of the list items after sorting, so any ListItem referenced
 * before a call to LinkedListSort() and after may contain different data as only the data pointers
 * for the ListItems in the list are swapped. This function sorts the strings in ascending order
 * first by size (with NULL data pointers counting as 0-length strings) and then alphabetically
 * ascending order. So the list [dog, cat, duck, goat, NULL] will be sorted to [NULL, cat, dog,
 * duck, goat]. LinkedListSort() returns SUCCESS if sorting was possible. If passed a NULL pointer
 * for either argument, it will do nothing and return STANDARD_ERROR.
 *
 * @param list Any element in the list to sort.
 * @return SUCCESS if successful or STANDARD_ERROR is passed NULL pointers.
 */
int LinkedListSort(ListItem *list)
{
    // Create Temporary ListItem
    ListItem*temp = malloc(sizeof (ListItem));

    //Check for Errors
    if ((list == NULL) || (temp == NULL)) {
        return STANDARD_ERROR;
    } else {

        //Find First Item
        LinkedListGetFirst(list);

        //Put the next item in temp to compare
        temp = list->nextItem;

        //Sorting Algorithm by Length
        while ((list->nextItem) != NULL) {
            // Check the current item with all of the items of the list
            while ((temp->nextItem != NULL)) {
                if (CompareStringSize(list, temp) >= 0) {
                    //Swap the items
                    LinkedListSwapData(list, temp);
                }
                temp = temp->nextItem;
            } // Inner While

            // Check the tail
            if ((temp->nextItem == NULL)) {
                if (CompareStringSize(list, temp) >= 1) {
                    //Swap the items
                    LinkedListSwapData(list, temp);
                }
            }// End of outer if

            list = list->nextItem;
            temp = list->nextItem;

        } //End of Big While
    } // End of Else

    //Free the temprary struct memory on the heap
    free(temp);
    return SUCCESS;
}

/**
 * LinkedListPrint() prints out the complete list to stdout. This function prints out the given
 * list, starting at the head if the provided pointer is not the head of the list, like "[STRING1,
 * STRING2, ... ]" If LinkedListPrint() is called with a NULL list it does nothing, returning
 * STANDARD_ERROR. If passed a valid pointer, prints the list and returns SUCCESS.
 *
 * @param list Any element in the list to print.
 * @return SUCCESS or STANDARD_ERROR if passed NULL pointers.
 */
int LinkedListPrint(ListItem *list)
{
    if (list == NULL) {
        return STANDARD_ERROR;
    }
    list = LinkedListGetFirst(list);
    while ((list != NULL)) {
        if ((list->previousItem) == NULL) {
            //Print Head item
            printf("[%s,", list->data);
        } else if ((list->nextItem) == NULL) {
            //Print tail item
            printf("%s]\n", list->data);
        } else {
            // Print list item
            printf("%s,", list->data);
        }
        list = list->nextItem;
    }
    return SUCCESS;

}
