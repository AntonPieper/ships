#ifndef APP_NET_H
#define APP_NET_H

#include <core/Player.h>
#include "intent.h"

typedef struct IntentMessage {
  PlayerId player_id;
  Intent intent;
} IntentMessage;

#endif // !APP_NET_H