#ifndef SKYRIMSAVEGAMEINFO_H
#define SKYRIMSAVEGAMEINFO_H

#include "gamebryosavegameinfo.h"

class GameGamebryo;

class Fallout4SaveGameInfo : public GamebryoSaveGameInfo
{
public:
  Fallout4SaveGameInfo(GameGamebryo const *game);
  ~Fallout4SaveGameInfo();

  virtual MOBase::ISaveGame const *getSaveGameInfo(QString const &file) const override;
};

#endif // SKYRIMSAVEGAMEINFO_H
