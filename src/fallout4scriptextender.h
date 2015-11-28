#ifndef FALLOUT3SCRIPTEXTENDER_H
#define FALLOUT3SCRIPTEXTENDER_H

#include "gamebryoscriptextender.h"

class Fallout4ScriptExtender : public GamebryoScriptExtender
{
public:
  Fallout4ScriptExtender(GameGamebryo const *game);

  virtual QString name() const override;

  virtual QStringList saveGameAttachmentExtensions() const override;

};

#endif // FALLOUT3SCRIPTEXTENDER_H
