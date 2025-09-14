#ifndef CORE_PLAYER_H
#define CORE_PLAYER_H

#include "Ship.h"
#include "constants.h"
#include <stddef.h>
#include <stdint.h>

typedef struct PlayerName {
  char data[PLAYER_MAX_NAME_LENGTH];
  size_t length;
} PlayerName;

typedef uint64_t PlayerId;

typedef struct Player {
  Ship ships[SHIP_COUNT];
  PlayerName name;
  PlayerId id;
} Player;

#endif // !CORE_PLAYER_H