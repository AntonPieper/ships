#include <app/intent.h>
#include <core/GameState.h>
#include <stdio.h>

static ReduceResult intent_reduce_new_game(
    const GameState *restrict old,
    const Intent *restrict intent);
static ReduceResult intent_reduce_set_player_name(
    const GameState *restrict old,
    const Intent *restrict intent);
static ReduceResult intent_reduce_commit_placement(
    const GameState *restrict old,
    const Intent *restrict intent);
static ReduceResult intent_reduce_attack_at(
    const GameState *restrict old,
    const Intent *restrict intent);
static ReduceResult intent_reduce_quit(
    const GameState *restrict old,
    const Intent *restrict intent);

ReduceResult intent_reduce(
    const GameState *restrict old,
    const Intent *restrict intent) {
  // Static Dispatcher
  switch (intent->type) {
    case INTENTTYPE_NEW_GAME:
      return intent_reduce_new_game(old, intent);
    case INTENTYPE_SET_PLAYER_NAME:
      return intent_reduce_set_player_name(old, intent);
    case INTENTTYPE_COMMIT_PLACEMENT:
      return intent_reduce_commit_placement(old,
                                            intent);
    case INTENTTYPE_ATTACK_AT:
      return intent_reduce_attack_at(old, intent);
    case INTENTTYPE_QUIT:
      return intent_reduce_quit(old, intent);
  }
}

static ReduceResult intent_reduce_new_game(
    const GameState *restrict old,
    const Intent *restrict intent) {
  return (ReduceResult){
      .effect = REDUCEEFFECT_INVALID,
      .state = *old,
  };
}

static ReduceResult intent_reduce_set_player_name(
    const GameState *restrict old,
    const Intent *restrict intent) {
  return (ReduceResult){
      .effect = REDUCEEFFECT_INVALID,
      .state = *old,
  };
}

static ReduceResult intent_reduce_commit_placement(
    const GameState *restrict old,
    const Intent *restrict intent) {
  return (ReduceResult){
      .effect = REDUCEEFFECT_INVALID,
      .state = *old,
  };
}

static ReduceResult intent_reduce_attack_at(
    const GameState *restrict old,
    const Intent *restrict intent) {
  return (ReduceResult){
      .effect = REDUCEEFFECT_INVALID,
      .state = *old,
  };
}

static ReduceResult intent_reduce_quit(
    const GameState *restrict old,
    const Intent *restrict intent) {
  return (ReduceResult){
      .effect = REDUCEEFFECT_INVALID,
      .state = *old,
  };
}

void print_intent(const Intent *intent) {
  switch (intent->type) {
    case INTENTTYPE_NEW_GAME: {
      const IntentNewGame *v = &intent->as_new_game;
      printf("NewGame(size=(%d, %d))", v->size.x,
             v->size.y);
    } break;
    case INTENTYPE_SET_PLAYER_NAME: {
      const IntentSetPlayerName *v =
          &intent->as_set_player_name;
      printf("SetPlayerName(%*s)", (int)v->name.length,
             v->name.data);
    } break;
    case INTENTTYPE_COMMIT_PLACEMENT: {
      printf("CommitPlacement");
    } break;
    case INTENTTYPE_ATTACK_AT: {
      const IntentAttackAt *v = &intent->as_attack_at;
      printf("AttackAt(at=(%d, %d))", v->at.x, v->at.y);
    } break;
    case INTENTTYPE_QUIT: {
      printf("Quit");
    } break;
  }
}