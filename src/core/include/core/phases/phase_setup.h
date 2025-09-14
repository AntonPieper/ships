#ifndef CORE_PHASES_PHASE_SETUP_H
#define CORE_PHASES_PHASE_SETUP_H

typedef enum PlayerSetupPhase {
  PLAYERSETUPPHASE_ENTER_NAME,
  PLAYERSETUPPHASE_PLACE_SHIPS,
} PlayerSetupPhase;

typedef struct GamePhaseSetup {
  PlayerSetupPhase player_setup_phase;
} GamePhaseSetup;

#endif // !CORE_PHASES_PHASE_SETUP_H