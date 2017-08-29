// Standard Library
#include <stdint.h>

// User Library
#include "Player.h"
#include "Common.h"

// Variables
static uint8_t inventory[INVENTORY_SIZE];
static int counter = 0;

/**
 * Adds the specified item to the player's inventory if the inventory isn't full.
 * @param item The item number to be stored: valid values are 0-255.
 * @return SUCCESS if the item was added, STANDARD_ERRROR if the item couldn't be added.
 */
int AddToInventory(uint8_t item)
{
    if (counter < INVENTORY_SIZE) {
        inventory[counter++] = item;
        return SUCCESS;
    } else {
        return STANDARD_ERROR;
    }
}

/**
 * Check if the given item exists in the player's inventory.
 * @param item The number of the item to be searched for: valid values are 0-255.
 * @return SUCCESS if it was found or STANDARD_ERROR if it wasn't.
 */
int FindInInventory(uint8_t item)
{
    int i = 0;
    while (i < INVENTORY_SIZE) {
        if (item == inventory[i++]) {
            return SUCCESS;
        }
    }
    return STANDARD_ERROR;
}