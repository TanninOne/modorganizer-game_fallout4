#include "fallout4savegame.h"

#include <Windows.h>

Fallout4SaveGame::Fallout4SaveGame(QString const &fileName, MOBase::IPluginGame const *game) :
  GamebryoSaveGame(fileName, game)
{
  FileWrapper file(this, "FO4_SAVEGAME");
  file.skip<unsigned long>(); // header size
  file.skip<unsigned long>(); // header version
  file.read(m_SaveNumber);

  file.read(m_PCName);

  unsigned long temp;
  file.read(temp);
  m_PCLevel = static_cast<unsigned short>(temp);
  file.read(m_PCLocation);

  QString ignore;
  file.read(ignore);   // playtime as ascii hh.mm.ss
  file.read(ignore);   // race name (i.e. BretonRace)

  file.skip<unsigned short>(); // Player gender (0 = male)
  file.skip<float>(2);         // experience gathered, experience required

  FILETIME ftime;
  file.read(ftime);
  //A file time is a 64-bit value that represents the number of 100-nanosecond
  //intervals that have elapsed since 12:00 A.M. January 1, 1601 Coordinated Universal Time (UTC).
  //So we need to convert that to something useful
  SYSTEMTIME ctime;
  ::FileTimeToSystemTime(&ftime, &ctime);

  setCreationTime(ctime);

  file.readImage(384, true);

  file.skip<unsigned char>(); // form version
  file.read(ignore);          // game version
  file.skip<unsigned long>(); // plugin info size

  file.readPlugins();
}
