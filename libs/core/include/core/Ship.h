#ifndef CORE_SHIP_H
#define CORE_SHIP_H

#include "types.h"
#include <stdint.h>

typedef enum ShipType {
  SHIPTYPE_PATROL_BOAT,
  SHIPTYPE_SUBMARINE,
  SHIPTYPE_DESTROYER,
  SHIPTYPE_BATTLESHIP,
  SHIPTYPE_CARRIER,
} ShipType;

typedef enum ShipOrientation {
  SHIPORIENTATION_UP,
  SHIPORIENTATION_RIGHT,
  SHIPORIENTATION_DOWN,
  SHIPORIENTATION_LEFT,
} ShipOrientation;

typedef uint8_t HitMask;

typedef struct Ship {
  Position position;
  ShipType type;
  ShipOrientation orientation;
  HitMask hits;
} Ship;

#endif // !CORE_SHIP_H
