#ifndef GAMEFALLOUT4_H
#define GAMEFALLOUT4_H


#include "fallout4scriptextender.h"
#include "fallout4dataarchives.h"
#include <gamegamebryo.h>
#include <QFileInfo>


class GameFallout4 : public GameGamebryo
{
  Q_OBJECT
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
  Q_PLUGIN_METADATA(IID "org.tannin.GameFallout4" FILE "gamefallout4.json")
#endif

public:

  GameFallout4();

  virtual bool init(MOBase::IOrganizer *moInfo) override;

public: // IPluginGame interface

  virtual QString gameName() const override;
  virtual QList<MOBase::ExecutableInfo> executables() const override;
  virtual void initializeProfile(const QDir &path, ProfileSettings settings) const override;
  virtual QString savegameExtension() const override;
  virtual QString steamAPPId() const override;
  virtual QStringList getPrimaryPlugins() const override;
  virtual QStringList gameVariants() const override;
  virtual QString getGameShortName() const override;
  virtual QStringList getIniFiles() const override;
  virtual QStringList getDLCPlugins() const override;
//what load order mechanism?
//  virtual LoadOrderMechanism getLoadOrderMechanism() const = 0;
  virtual int getNexusModOrganizerID() const override;
  virtual int getNexusGameID() const override;

public: // IPlugin interface

  virtual QString name() const override;
  virtual QString author() const override;
  virtual QString description() const override;
  virtual MOBase::VersionInfo version() const override;
  virtual bool isActive() const override;
  virtual QList<MOBase::PluginSetting> settings() const override;

protected:

  virtual std::map<std::type_index, boost::any> featureList() const override;

private:

  virtual QString identifyGamePath() const override;
  virtual QString myGamesFolderName() const override;

  QString localAppFolder() const;
  void copyToProfile(const QString &sourcePath, const QDir &destinationDirectory,
                     const QString &sourceFileName, const QString &destinationFileName = QString()) const;

private:

  std::shared_ptr<ScriptExtender> m_ScriptExtender { nullptr };
  std::shared_ptr<DataArchives> m_DataArchives { nullptr };

};

#endif // GAMEFallout4_H
