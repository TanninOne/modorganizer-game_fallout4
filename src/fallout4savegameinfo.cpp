#include "fallout4savegameinfo.h"

#include "fallout4savegame.h"
#include "gamegamebryo.h"

Fallout4SaveGameInfo::Fallout4SaveGameInfo(GameGamebryo const *game) :
  GamebryoSaveGameInfo(game)
{
}

Fallout4SaveGameInfo::~Fallout4SaveGameInfo()
{
}

const MOBase::ISaveGame *Fallout4SaveGameInfo::getSaveGameInfo(const QString &file) const
{
  return new Fallout4SaveGame(file, m_Game);
}

