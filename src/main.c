#include "Vec2i.h"
#include <GameState.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static size_t ship_length(ShipType type) {
  switch (type) {
  case SHIPTYPE_PATROL_BOAT:
    return 2;
  case SHIPTYPE_SUBMARINE:
    return 3;
  case SHIPTYPE_DESTROYER:
    return 3;
  case SHIPTYPE_BATTLESHIP:
    return 4;
  case SHIPTYPE_CARRIER:
    return 5;
  }
}

static Vec2i
orientation_dir(ShipOrientation orientatiom) {
  switch (orientatiom) {
  case SHIPORIENTATION_UP:
    return (Vec2i){.x = 0, .y = -1};
  case SHIPORIENTATION_RIGHT:
    return (Vec2i){.x = 1, .y = 0};
  case SHIPORIENTATION_DOWN:
    return (Vec2i){.x = 0, .y = 1};
  case SHIPORIENTATION_LEFT:
    return (Vec2i){.x = -1, .y = 0};
  }
}

static bool ship_is_hit(uint8_t hits, uint8_t index) {
  return (hits & (1 << index)) != 0;
}

#define ARRAY_SIZE(arr)                                \
  (sizeof(arr) / sizeof((arr)[0])) // Array size

typedef enum ShipHitInfo {
  SHIPINFO_NONE,
  SHIPINFO_ALIVE,
  SHIPINFO_HIT,
} ShipHitInfo;

typedef struct ShipInfo {
  ShipHitInfo hit_info;
  size_t ship_index;
} ShipInfo;

static ShipInfo ship_at(const Ship *ships,
                        size_t ship_count,
                        Position position) {
  for (size_t i = 0; i < ship_count; ++i) {
    const Ship *ship = &ships[i];
    Position ship_origin = ship->position;
    size_t ship_len = ship_length(ship->type);
    Vec2i dir = orientation_dir(ship->orientation);
    for (size_t offset = 0; offset < ship_len;
         ++offset) {
      Vec2i cell_position = Vec2i_add(
          ship_origin, Vec2i_scale(dir, offset));
      if (Vec2i_eq(cell_position, position)) {
        bool is_hit = ship_is_hit(ship->hits, offset);
        ShipHitInfo hit_info =
            is_hit ? SHIPINFO_HIT : SHIPINFO_ALIVE;
        return (ShipInfo){.hit_info = hit_info,
                          .ship_index = i};
      }
    }
  }
  return (ShipInfo){.hit_info = SHIPINFO_NONE,
                    .ship_index = 0};
}

static void print_state(const GameState *state,
                        FILE *file) {
  Size board_size = state->board.size;
  const Player *current_player =
      &state->players[state->current_player];
  const Ship *current_ships = current_player->ships;
  for (size_t y = 0; y < board_size.y; ++y) {
    for (size_t x = 0; x < board_size.x; ++x) {
      Vec2i cell_position = {.x = x + 1, .y = y + 1};
      ShipInfo info =
          ship_at(current_ships,
                  ARRAY_SIZE(current_player->ships),
                  cell_position);
      const Ship *ship =
          &current_ships[info.ship_index];

      const char *cell;
      switch (info.hit_info) {
      case SHIPINFO_ALIVE: {
        if (Vec2i_eq(cell_position, ship->position)) {
          cell = "()";
        } else {
          cell = "[]";
        }
      } break;
      case SHIPINFO_HIT: {
        if (Vec2i_eq(cell_position, ship->position)) {
          cell = "XX";
        } else {
          cell = "××";
        }
      } break;
      case SHIPINFO_NONE: {
        cell = ". ";
      } break;
      }
      fputs(cell, file);
    }
    putc('\n', file);
  }
  fflush(file);
}

int main(int argc, char **argv) {
  GameState state = {
      .board = {.size = {.x = 10, .y = 10}},
      .cursor = {.x = 5, .y = 5},
      .players = {
          [0] = {.name = "Player 1",
                 .name_length = 8,
                 .ships = {
                     [0] = {.position = {3, 2},
                            .type = SHIPTYPE_BATTLESHIP,
                            .orientation =
                                SHIPORIENTATION_DOWN,
                            .hits = 0b00000010},
                     [1] = {.position = {10, 9},
                            .type = SHIPTYPE_CARRIER,
                            .orientation =
                                SHIPORIENTATION_UP,
                            .hits = 0b00001101},
                     [2] = {.position = {10, 10},
                            .type = SHIPTYPE_SUBMARINE,
                            .orientation =
                                SHIPORIENTATION_UP,
                            .hits = 0b00000111},
                 }}}};
  print_state(&state, stdout);
}
