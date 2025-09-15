#ifndef APP_INTENT_H
#define APP_INTENT_H

#include <core/GameState.h>

typedef enum IntentType {
  INTENTTYPE_NEW_GAME,
  INTENTYPE_SET_PLAYER_NAME,
  INTENTTYPE_COMMIT_PLACEMENT,
  INTENTTYPE_ATTACK_AT,
  INTENTTYPE_QUIT,
} IntentType;

typedef struct IntentNewGame {
  Size size;
} IntentNewGame;

typedef struct IntentSetPlayerName {
  PlayerName name;
} IntentSetPlayerName;

typedef struct IntentAttackAt {
  Position at;
} IntentAttackAt;

typedef struct Intent {
  IntentType type;
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

void print_intent(const Intent *intent);

#endif /* ifndef APP_INTENT_H */
