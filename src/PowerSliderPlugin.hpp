#ifndef POWERSLIDERPLUGIN_H
#define POWERSLIDERPLUGIN_H

#include <QtCore/qplugin.h>
#include <QtGui/QIcon>
#include <QtUiPlugin/QDesignerCustomWidgetInterface>

class QDesignerFormEditorInterface;

class PowerSliderPlugin : public QObject,
                          public QDesignerCustomWidgetInterface {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
  Q_INTERFACES(QDesignerCustomWidgetInterface)
public:
  PowerSliderPlugin(QObject *parent = nullptr);

  bool isContainer() const override;
  bool isInitialized() const override;
  QIcon icon() const override;
  QString domXml() const override;
  QString group() const override;
  QString includeFile() const override;
  QString name() const override;
  QString toolTip() const override;
  QString whatsThis() const override;
  QWidget *createWidget(QWidget *parent) override;
  void initialize(QDesignerFormEditorInterface *core) override;

private:
  bool initialized{false};
};
#endif // POWERSLIDERPLUGIN_H
