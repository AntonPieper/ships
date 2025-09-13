#ifndef CORE_GAMEPHASE_H
#define CORE_GAMEPHASE_H

#include <stddef.h>
typedef enum GamePhaseType {
  GAMEPHASE_START_MENU,
  GAMEPHASE_SETUP,
  GAMEPHASE_PLAY,
} GamePhaseType;

typedef enum StartMenuButton {
  STARTMENUBUTTON_NONE,
  STARTMENUBUTTON_PLAY,
  STARTMENUBUTTON_QUIT,
} StartMenuButton;

typedef struct GamePhaseMenu {
  StartMenuButton selected_option;
} GamePhaseMenu;

typedef enum PlayerSetupPhase {
  PLAYERSETUPPHASE_ENTER_NAME,
  PLAYERSETUPPHASE_PLACE_SHIPS,
} PlayerSetupPhase;

typedef struct GamePhaseSetup {
  PlayerSetupPhase player_setup_phase;
} GamePhaseSetup;

typedef enum PlayerAttsckPhase {
  PLAYERATTACKPHASE_TRANSITION,
  PLAYERATTACKPHASE_SELECT_TARGET,
  PLAYERATTACKPHASE_SHOW_RESULT,
} PlayerAttackPhase;

typedef struct GamePhasePlay {
  PlayerAttackPhase player_attack_phase;
} GamePhasePlay;

typedef struct GamePhase {
  GamePhaseType type;
  union {
    GamePhaseMenu as_menu;
    GamePhaseSetup as_setup;
    GamePhasePlay as_play;
  };
} GamePhase;

#endif // !CORE_GAMEPHASE_H
