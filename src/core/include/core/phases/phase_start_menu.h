#ifndef CORE_PHASES_PHASE_START_MENU_H
#define CORE_PHASES_PHASE_START_MENU_H

typedef enum StartMenuButton {
  STARTMENUBUTTON_NONE,
  STARTMENUBUTTON_PLAY,
  STARTMENUBUTTON_QUIT,
} StartMenuButton;

typedef struct GamePhaseMenu {
  StartMenuButton selected_option;
} GamePhaseMenu;

#endif // !CORE_PHASES_PHASE_START_MENU_H