#ifndef FALLOUT3SCRIPTEXTENDER_H
#define FALLOUT3SCRIPTEXTENDER_H


#include <scriptextender.h>


class Fallout4ScriptExtender : public ScriptExtender
{
public:
  virtual QString name() const override;

  virtual QString loaderName() const override;

  virtual QStringList saveGameAttachmentExtensions() const override;

};

#endif // FALLOUT3SCRIPTEXTENDER_H
