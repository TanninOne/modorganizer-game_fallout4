#include "fallout4savegameinfo.h"

#include "fallout4savegame.h"

const MOBase::ISaveGame *Fallout4SaveGameInfo::getSaveGameInfo(const QString &file) const
{
  return new Fallout4SaveGame(file);
}

