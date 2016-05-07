#ifndef FALLOUT4GAMEPLUGINS_H
#define FALLOUT4GAMEPLUGINS_H


#include <gamebryogameplugins.h>
#include <iplugingame.h>
#include <imoinfo.h>
#include <map>


class Fallout4GamePlugins : public GamebryoGamePlugins
{
public:
  Fallout4GamePlugins(MOBase::IOrganizer *organizer);

protected:
  virtual void writePluginList(const MOBase::IPluginList *pluginList,
                               const QString &filePath) override;
  virtual bool readPluginList(MOBase::IPluginList *pluginList,
                              const QString &filePath,
                              bool useLoadOrder) override;

private:
  std::map<QString, QByteArray> m_LastSaveHash;
};

#endif // FALLOUT4GAMEPLUGINS_H
