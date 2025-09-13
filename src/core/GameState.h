#ifndef CORE_GAMESTATE_H
#define CORE_GAMESTATE_H

#include "GamePhase.h"
#include "Vec2i.h"
#include <stddef.h>
#include <stdint.h>

typedef enum ShipType {
  SHIPTYPE_PATROL_BOAT,
  SHIPTYPE_SUBMARINE,
  SHIPTYPE_DESTROYER,
  SHIPTYPE_BATTLESHIP,
  SHIPTYPE_CARRIER,
} ShipType;

#define SHIP_COUNT 10
#define PLAYER_COUNT 2
#define PLAYER_MAX_NAME_LENGTH 32

typedef Vec2i Position;
typedef Vec2i Size;

typedef uint64_t Id;

typedef enum ShipOrientation {
  SHIPORIENTATION_UP,
  SHIPORIENTATION_RIGHT,
  SHIPORIENTATION_DOWN,
  SHIPORIENTATION_LEFT,
} ShipOrientation;

typedef struct Ship {
  Position position;
  ShipType type;
  ShipOrientation orientation;
  uint8_t hits;
} Ship;

typedef struct PlayerName {
  char data[PLAYER_MAX_NAME_LENGTH];
  size_t length;
} PlayerName;

typedef struct Player {
  PlayerName name;
  Ship ships[SHIP_COUNT];
} Player;

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
