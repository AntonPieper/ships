#ifndef CORE_GAMEPHASE_H
#define CORE_GAMEPHASE_H

#include "phases/phase_play.h"
#include "phases/phase_setup.h"
#include "phases/phase_start_menu.h"
#include <stddef.h>

typedef enum GamePhaseType {
  GAMEPHASE_START_MENU,
  GAMEPHASE_SETUP,
  GAMEPHASE_PLAY,
} GamePhaseType;

typedef struct GamePhase {
  GamePhaseType type;
  union {
    GamePhaseMenu as_menu;
    GamePhaseSetup as_setup;
    GamePhasePlay as_play;
  };
} GamePhase;

#endif // !CORE_GAMEPHASE_H
