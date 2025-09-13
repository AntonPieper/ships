#ifndef APP_INTENT_H
#define APP_INTENT_H

#include "GameState.h"

typedef enum IntentType {
  INTENTTYPE_NEW_GAME,
  INTENTYPE_SET_PLAYER_NAME,
  INTENTTYPE_COMMIT_PLACEMENT,
  INTENTTYPE_ATTACK_AT,
  INTENTTYPE_QUIT,
} IntentKind;

typedef struct IntentNewGame {
  Size size;
} IntentNewGame;

typedef struct IntentSetPlayerName {
  PlayerName name;
} IntentSetPlayerName;

typedef struct IntentAttackAt {
  Position attack_positon;
} IntentAttackAt;

typedef struct Intent {
  IntentKind type;
  union {
    IntentNewGame as_new_game;
    IntentSetPlayerName as_set_player_name;
    IntentAttackAt as_attack_at;
  };
} Intent;

typedef enum ReduceEffect {
  REDUCEEFFECT_NONE,
  REDUCEEFFECT_INVALID,
  REDUCEEFFECT_SUCCESS,
} ReduceEffect;

typedef struct ReduceResult {
  GameState state;
  ReduceEffect effect;
} ReduceResult;

ReduceResult
intent_reduce(const GameState *restrict old,
              const Intent *restrict intent);

#endif /* ifndef APP_INTENT_H */
