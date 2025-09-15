#ifndef CORE_GAMESTATE_H
#define CORE_GAMESTATE_H

#include "GamePhase.h"
#include "Player.h"
#include "constants.h"
#include "types.h"
#include <stddef.h>
#include <stdint.h>

typedef struct Board {
  Size size;
} Board;

typedef struct GameState {
  Id snapshot_id;
  Position cursor;
  size_t current_player;
  Player players[PLAYER_COUNT];
  Board board;
  GamePhase phase;
} GameState;

#endif // !CORE_GAMESTATE_H
