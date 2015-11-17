#ifndef FALLOUT3DATAARCHIVES_H
#define FALLOUT3DATAARCHIVES_H


#include <gamebryodataarchives.h>
#include <iprofile.h>
#include <QString>
#include <QStringList>

class Fallout4DataArchives : public GamebryoDataArchives
{

public:

  virtual QStringList vanillaArchives() const override;
  virtual QStringList archives(const MOBase::IProfile *profile) const override;

private:

  virtual void writeArchiveList(MOBase::IProfile *profile, const QStringList &before) override;

};

#endif // FALLOUT3DATAARCHIVES_H
