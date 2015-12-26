#ifndef FALLOUT4SAVEGAME_H
#define FALLOUT4SAVEGAME_H

#include "gamebryosavegame.h"

namespace MOBase { class IPluginGame; }

class Fallout4SaveGame : public GamebryoSaveGame
{
public:
  Fallout4SaveGame(QString const &fileName, MOBase::IPluginGame const *game);
};

#endif // FALLOUT4SAVEGAME_H
