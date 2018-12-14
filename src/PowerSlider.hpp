#ifndef __POWERSLIDER_H__
#define __POWERSLIDER_H__

#include <QDomElement>
#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
class QSlider;
class QDoubleSpinBox;

class QDESIGNER_WIDGET_EXPORT PowerSlider : public QWidget {
  Q_OBJECT;
  Q_PROPERTY(double Min READ minimum WRITE setMinimum);
  Q_PROPERTY(double Max READ maximum WRITE setMaximum);
  Q_PROPERTY(double Value READ value WRITE setValue);
  Q_PROPERTY(double SingleStep READ singleStep WRITE setSingleStep);

public:
  PowerSlider(QWidget *parent = 0, double alignmentValue = 100.0);
  ~PowerSlider();
  QDomElement domElement(const QString &name, QDomDocument &document) const;
  void initFromDOMElement(const QDomElement &element);
  double value();
  double minimum();
  double maximum();
  double singleStep();
public slots:
  void setSingleStep(double);
  void setRange(double, double);
  void setMinimum(double);
  void setMaximum(double);

  void setValue(double);
signals:
  void valueChanged(double);

private:
  QSlider *slider_;
  QDoubleSpinBox *spinBox_;
private slots:
  void on_slider_valueChanged(int);
  void on_spinBox_valueChanged(double);
};

#endif // __POWERSLIDER_H__
