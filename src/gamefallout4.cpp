#include "gameFallout4.h"
#include <scopeguard.h>
#include <pluginsetting.h>
#include <igameinfo.h>
#include <executableinfo.h>
#include <gamebryolocalsavegames.h>
#include <utility.h>
#include <memory>
#include <QStandardPaths>
#include <QCoreApplication>
#include <QDebug>


using namespace MOBase;


GameFallout4::GameFallout4()
{
}

bool GameFallout4::init(IOrganizer *moInfo)
{
  if (!GameGamebryo::init(moInfo)) {
    return false;
  }
  m_ScriptExtender = std::shared_ptr<ScriptExtender>(new Fallout4ScriptExtender());
  m_LocalSavegames.reset(new GamebryoLocalSavegames(myGamesPath(), "Fallout4.ini"));
  return true;
}

QString GameFallout4::identifyGamePath() const
{
  return findInRegistry(HKEY_LOCAL_MACHINE, L"Software\\Bethesda Softworks\\Fallout4", L"Installed Path");
}

QString GameFallout4::gameName() const
{
  return "Fallout 4";
}

QString GameFallout4::myGamesFolderName() const
{
  return "Fallout4";
}

QList<ExecutableInfo> GameFallout4::executables()
{
  return QList<ExecutableInfo>()
      << ExecutableInfo("F4SE", findInGameFolder("f4se_loader.exe"))
      << ExecutableInfo("Fallout 4", findInGameFolder("Fallout4.exe"))
      << ExecutableInfo("Fallout Launcher", findInGameFolder("Fallout4Launcher.exe"))
      << ExecutableInfo("LOOT", getLootPath());
         ;
}

QString GameFallout4::name() const
{
  return "Fallout4 Support Plugin";
}

QString GameFallout4::author() const
{
  return "Tannin";
}

QString GameFallout4::description() const
{
  return tr("Adds support for the game Fallout 4");
}

MOBase::VersionInfo GameFallout4::version() const
{
  return VersionInfo(0, 1, 0, VersionInfo::RELEASE_BETA);
}

bool GameFallout4::isActive() const
{
  return qApp->property("managed_game").value<IPluginGame*>() == this;
}

QList<PluginSetting> GameFallout4::settings() const
{
  return QList<PluginSetting>();
}

void GameFallout4::copyToProfile(const QString &sourcePath, const QDir &destinationDirectory,
                               const QString &sourceFileName, const QString &destinationFileName) const
{
  QString filePath = destinationDirectory.absoluteFilePath(destinationFileName.isEmpty() ? sourceFileName
                                                                                         : destinationFileName);
  if (!QFileInfo(filePath).exists()) {
    if (!shellCopy(sourcePath + "/" + sourceFileName, filePath)) {
      // if copy file fails, create the file empty
      QFile(filePath).open(QIODevice::WriteOnly);
    }
  }
}

void GameFallout4::initializeProfile(const QDir &path, ProfileSettings settings) const
{
  if (settings.testFlag(IPluginGame::MODS)) {
    copyToProfile(localAppFolder() + "/Fallout4", path, "plugins.txt");
    copyToProfile(localAppFolder() + "/Fallout4", path, "loadorder.txt");
  }

  if (settings.testFlag(IPluginGame::CONFIGURATION)) {
    if (settings.testFlag(IPluginGame::PREFER_DEFAULTS)
        || !QFileInfo(myGamesPath() + "/fallout4.ini").exists()) {
      copyToProfile(gameDirectory().absolutePath(), path, "fallout4_default.ini", "fallout4.ini");
    } else {
      copyToProfile(myGamesPath(), path, "fallout4.ini");
    }

    copyToProfile(myGamesPath(), path, "fallout4prefs.ini");
  }
}

QString GameFallout4::savegameExtension() const
{
  return "fos";
}

QString GameFallout4::steamAPPId() const
{
  return "377160";
}

QStringList GameFallout4::getPrimaryPlugins()
{
  return { "fallout4.esm" };
}

QIcon GameFallout4::gameIcon() const
{
  return MOBase::iconForExecutable(gameDirectory().absoluteFilePath("Fallout4.exe"));
}

const std::map<std::type_index, boost::any> &GameFallout4::featureList() const
{
  static std::map<std::type_index, boost::any> result {
    { typeid(ScriptExtender), m_ScriptExtender.get() },
    { typeid(LocalSavegames), m_LocalSavegames.get() }
  };

  return result;
}


QStringList GameFallout4::gameVariants() const
{
  return { "Regular" };
}
