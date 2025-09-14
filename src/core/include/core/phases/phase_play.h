#ifndef CORE_PHASES_PHASE_PLAY_H
#define CORE_PHASES_PHASE_PLAY_H

typedef enum PlayerAttackPhase {
  PLAYERATTACKPHASE_TRANSITION,
  PLAYERATTACKPHASE_SELECT_TARGET,
  PLAYERATTACKPHASE_SHOW_RESULT,
} PlayerAttackPhase;

typedef struct GamePhasePlay {
  PlayerAttackPhase player_attack_phase;
} GamePhasePlay;

#endif // !CORE_PHASES_PHASE_PLAY_H