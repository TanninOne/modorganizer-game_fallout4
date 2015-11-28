#include "fallout4scriptextender.h"

#include <QString>
#include <QStringList>

QString Fallout4ScriptExtender::name() const
{
  return "f4se";
}

QString Fallout4ScriptExtender::loaderName() const
{
  return name() + "_loader.exe";
}

QStringList Fallout4ScriptExtender::saveGameAttachmentExtensions() const
{
  return { };
}
