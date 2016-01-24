#ifndef FALLOUT4SAVEGAME_H
#define FALLOUT4SAVEGAME_H

#include "gamebryosavegame.h"

class Fallout4SaveGame : public GamebryoSaveGame
{
public:
  Fallout4SaveGame(QString const &fileName);
};

#endif // FALLOUT4SAVEGAME_H
