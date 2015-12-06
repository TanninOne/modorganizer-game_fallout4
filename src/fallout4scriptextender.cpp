#include "fallout4scriptextender.h"

#include <QString>
#include <QStringList>

Fallout4ScriptExtender::Fallout4ScriptExtender(GameGamebryo const *game) :
  GamebryoScriptExtender(game)
{
}

QString Fallout4ScriptExtender::name() const
{
  return "f4se";
}

QStringList Fallout4ScriptExtender::saveGameAttachmentExtensions() const
{
  return { };
}
