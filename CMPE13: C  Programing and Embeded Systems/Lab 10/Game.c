// Standard Library
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// User Library
#include "Game.h"
#include "Player.h"
#include "Common.h"

// Define Macros
#define ROOM_TEMPLATE "/room%d.txt"

// Define Variables
static FILE *roomFile;
static size_t length;
static char roomName[10];

typedef struct Room {
    char title[GAME_MAX_ROOM_TITLE_LENGTH];
    uint8_t itemRequired;
    char desc[GAME_MAX_ROOM_DESC_LENGTH];
    uint8_t itemContained;
    uint8_t exitsNorth;
    uint8_t exitsEast;
    uint8_t exitsSouth;
    uint8_t exitsWest;
} Room;

Room roomData;

static void ClearStructData(void)
{
    int i = 0;
    //Clear Title
    while (GAME_MAX_ROOM_TITLE_LENGTH > i) {
        roomData.title[i++] = '\0';
    }

    // Clear Counter
    i = 0;

    //Clear Description
    while (GAME_MAX_ROOM_DESC_LENGTH > i) {
        roomData.desc[i++] = '\0';
    }

    //Clear Data
    roomData.exitsNorth = 0;
    roomData.exitsEast = 0;
    roomData.exitsSouth = 0;
    roomData.exitsWest = 0;
    roomData.itemContained = 0;
    roomData.itemRequired = 0;

}

static void GetRoomDataVersion1(void)
{
    //Counter
    int i = 0;

    // Length of description version 1
    length = fgetc(roomFile);

    //Store Description 1 in Struct
    while (length-- > 0) {
        roomData.desc[i++] = (char) fgetc(roomFile);
    }

    // Items contained Length
    length = fgetc(roomFile);

    //Store Item Required in Struct
    while (length-- > 0) {
        roomData.itemContained = fgetc(roomFile);
        AddToInventory(roomData.itemContained);
    }

    // Check if there are no items and skip empty space
    if (!length) {
        fseek(roomFile, 1, SEEK_CUR);
    }
    //Store North Exit Version 1
    roomData.exitsNorth = fgetc(roomFile);

    // Store East Exit Version 1
    roomData.exitsEast = fgetc(roomFile);

    //Store South Exit Version 1
    roomData.exitsSouth = fgetc(roomFile);

    //Store West Exit Version 1
    roomData.exitsWest = fgetc(roomFile);

}

static void GetRoomDataVersion2(void)
{
    //Counter
    int i = 0;

    GetRoomDataVersion1();

    // Items contained Length
    length = fgetc(roomFile);

    //Store Item Required in Struct
    while (length-- > 0) {
        roomData.itemRequired = fgetc(roomFile);
        AddToInventory(roomData.itemRequired);
    }

    // Length of description version 1
    length = fgetc(roomFile);

    //Store Item Required in Struct
    while (length-- > 0) {
        roomData.desc[i++] = (char) fgetc(roomFile);
    }

    // Items contained Length
    length = fgetc(roomFile);

    //Store Item Required in Struct
    while (length-- > 0) {
        roomData.itemContained = fgetc(roomFile);
        AddToInventory(roomData.itemContained);
    }

    // Check if there are no items and skip empty space
    if (!length) {
        fseek(roomFile, 1, SEEK_CUR);
    }
    //Store North Exit Version 1
    roomData.exitsNorth = fgetc(roomFile);

    // Store East Exit Version 1
    roomData.exitsEast = fgetc(roomFile);

    //Store South Exit Version 1
    roomData.exitsSouth = fgetc(roomFile);

    //Store West Exit Version 1
    roomData.exitsWest = fgetc(roomFile);

}
// Helper Functions

/*
 * This is a helper function that skips over from the begining of the file to
 * the Items Required part. It does not return anything. It sets the pointer from the
 * begining of the file.
 */
static void SkipToItemRequired(void)
{
    int i = 0;
    // Set pointer to beggining of file
    fseek(roomFile, 0, SEEK_SET);

    //Read the length of the title
    length = fgetc(roomFile);

    //Store the title in struct
    while (length-- > 0) {
        roomData.title[i++] = (char) fgetc(roomFile);
    }

    //Read the length of Item Requirement
    length = fgetc(roomFile);

    //Store Item Required in Struct
    while (length-- > 0) {
        roomData.itemRequired = fgetc(roomFile);
    }
}

// Game.h Functions

/**
 * These function transitions between rooms. Each call should return SUCCESS if the current room has
 * an exit in the correct direction and the new room was able to be loaded, and STANDARD_ERROR
 * otherwise.
 * @return SUCCESS if the room CAN be navigated to and changing the current room to that new room
 *         succeeded.
 */
int GameGoNorth(void)
{
    sprintf(roomName, ROOM_TEMPLATE, roomData.exitsNorth);
    roomFile = fopen(roomName, "rb");
    if (roomFile) {
        ClearStructData();
        SkipToItemRequired();
        if (FindInInventory(roomData.itemRequired) == SUCCESS) {
            GetRoomDataVersion1();
        } else {
            GetRoomDataVersion2();
        }
        fclose(roomFile);
        return SUCCESS;
    } else {
        fclose(roomFile);
        return STANDARD_ERROR;
    }

}

/**
 * @see GameGoNorth
 */
int GameGoEast(void)
{

    sprintf(roomName, ROOM_TEMPLATE, roomData.exitsEast);
    roomFile = fopen(roomName, "rb");
    if (roomFile) {
        ClearStructData();
        SkipToItemRequired();
        if (FindInInventory(roomData.itemRequired) == SUCCESS) {
            GetRoomDataVersion1();
        } else {
            GetRoomDataVersion2();
        }
        fclose(roomFile);
        return SUCCESS;
    } else {
        fclose(roomFile);
        return STANDARD_ERROR;
    }
}

/**
 * @see GameGoNorth
 */
int GameGoSouth(void)
{
    sprintf(roomName, ROOM_TEMPLATE, roomData.exitsSouth);
    roomFile = fopen(roomName, "rb");
    if (roomFile) {
        ClearStructData();
        SkipToItemRequired();
        if (FindInInventory(roomData.itemRequired) == SUCCESS) {
            GetRoomDataVersion1();
        } else {
            GetRoomDataVersion2();
        }
        fclose(roomFile);
        return SUCCESS;
    } else {
        fclose(roomFile);
        return STANDARD_ERROR;
    }
}

/**
 * @see GameGoNorth
 */
int GameGoWest(void)
{
    sprintf(roomName, ROOM_TEMPLATE, roomData.exitsWest);
    roomFile = fopen(roomName, "rb");
    if (roomFile) {
        ClearStructData();
        SkipToItemRequired();
        if (FindInInventory(roomData.itemRequired) == SUCCESS) {
            GetRoomDataVersion1();
        } else {
            GetRoomDataVersion2();
        }
        fclose(roomFile);
        return SUCCESS;
    } else {
        fclose(roomFile);
        return STANDARD_ERROR;
    }

}

/**
 * This function sets up anything that needs to happen at the start of the game. This is just
 * setting the current room to STARTING_ROOM and loading it. It should return SUCCESS if it succeeds
 * and STANDARD_ERROR if it doesn't.
 * @return SUCCESS or STANDARD_ERROR
 */
int GameInit(void)
{
    sprintf(roomName, ROOM_TEMPLATE, STARTING_ROOM);
    roomFile = fopen(roomName, "rb");

    if (roomFile) {
        ClearStructData();
        SkipToItemRequired();
        if (FindInInventory(roomData.itemRequired) == SUCCESS) {
            GetRoomDataVersion1();
        } else {
            GetRoomDataVersion2();
        }
        fclose(roomFile);
        return SUCCESS;
    } else {
        fclose(roomFile);
        return STANDARD_ERROR;
    }
}

/**
 * Copies the appropriate room title as a NULL-terminated string into the provided character array.
 * The appropriate room means the first room description that the Player has the required items to
 * see. Only a NULL-character is copied if there was an error so that the resultant output string
 * length is 0.
 * @param desc A character array to copy the room title into. Should be GAME_MAX_ROOM_TITLE_LENGTH+1
 *             in length in order to allow for all possible titles to be copied into it.
 * @return The length of the string stored into `title`. Note that the actual number of chars
 *         written into `title` will be this value + 1 to account for the NULL terminating
 *         character.
 */
int GameGetCurrentRoomTitle(char *title)
{
    int i = 0;
    while (i < GAME_MAX_ROOM_TITLE_LENGTH) {
        title[i] = roomData.title[i];
        ++i;
    }
    return (strlen(title) + 1);
}

/**
 * GetCurrentRoomDescription() copies the description of the current room into the argument desc as
 * a C-style string with a NULL-terminating character. The room description is guaranteed to be less
 * -than-or-equal to GAME_MAX_ROOM_DESC_LENGTH characters, so the provided argument must be at least
 * GAME_MAX_ROOM_DESC_LENGTH + 1 characters long. Only a NULL-character is copied if there was an
 * error so that the resultant output string length is 0.
 * @param desc A character array to copy the room description into.
 * @return The length of the string stored into `desc`. Note that the actual number of chars
 *          written into `desc` will be this value + 1 to account for the NULL terminating
 *          character.
 */
int GameGetCurrentRoomDescription(char *desc)
{
    int i = 0;
    while (i < GAME_MAX_ROOM_DESC_LENGTH) {
        desc[i] = roomData.desc[i];
        ++i;
    }
    return (strlen(desc) + 1);
}

//

/**
 * This function returns the exits from the current room in the lowest-four bits of the returned
 * uint8 in the order of NORTH, EAST, SOUTH, and WEST such that NORTH is in the MSB and WEST is in
 * the LSB. A bit value of 1 corresponds to there being a valid exit in that direction and a bit
 * value of 0 corresponds to there being no exit in that direction. The GameRoomExitFlags enum
 * provides bit-flags for checking the return value.
 *
 * @see GameRoomExitFlags
 *
 * @return a 4-bit bitfield signifying which exits are available to this room.
 */
uint8_t GameGetCurrentRoomExits(void)
{
    uint8_t bitfield = 0;
    if (roomData.exitsNorth != 0) {
        bitfield |= GAME_ROOM_EXIT_NORTH_EXISTS;
    }

    if (roomData.exitsEast != 0) {
        bitfield |= GAME_ROOM_EXIT_EAST_EXISTS;
    }
    if (roomData.exitsSouth != 0) {
        bitfield |= GAME_ROOM_EXIT_SOUTH_EXISTS;
    }
    if (roomData.exitsWest != 0) {
        bitfield |= GAME_ROOM_EXIT_WEST_EXISTS;
    }
    return bitfield;
}
