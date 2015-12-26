#ifndef FALLOUT4SCRIPTEXTENDER_H
#define FALLOUT4SCRIPTEXTENDER_H

#include "gamebryoscriptextender.h"

class GameGamebryo;

class Fallout4ScriptExtender : public GamebryoScriptExtender
{
public:
  Fallout4ScriptExtender(GameGamebryo const *game);

  virtual QString name() const override;

  virtual QStringList saveGameAttachmentExtensions() const override;

};

#endif // FALLOUT4SCRIPTEXTENDER_H
