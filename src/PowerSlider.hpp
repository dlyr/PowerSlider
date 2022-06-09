#ifndef __POWERSLIDER_H__
#define __POWERSLIDER_H__

#if defined POWERSLIDER_EXPORT
#    define POWERSLIDER_API Q_DECL_EXPORT
#else
#    define POWERSLIDER_API Q_DECL_IMPORT
#endif

#include <QWidget>

#ifdef POWERSLIDER_DESIGNER_PLUGIN
#    include <QtUiPlugin/QDesignerExportWidget>
#endif

class QSlider;
class QDoubleSpinBox;

class POWERSLIDER_API PowerSlider : public QWidget
{
    Q_OBJECT;
    Q_PROPERTY( double Min READ minimum WRITE setMinimum );
    Q_PROPERTY( double Max READ maximum WRITE setMaximum );
    Q_PROPERTY( double Value READ value WRITE setValue );
    Q_PROPERTY( double SingleStep READ singleStep WRITE setSingleStep );
    Q_PROPERTY( double Precision READ sliderPrecision WRITE setSliderPrecision );

  public:
    PowerSlider( QWidget* parent       = 0,
                 double alignmentValue = 100.0,
                 double minimum        = 0.0,
                 double maximum        = 1.0,
                 double singleStep     = 0.1,
                 int precision         = 1000000 );
    ~PowerSlider();

    double value();
    double minimum();
    double maximum();
    double singleStep();
    int sliderPrecision();

  public slots:
    void setSingleStep( double );
    void setRange( double, double );
    void setMinimum( double );
    void setMaximum( double );
    void setValue( double );

    /// Set slider range, so that one slider is range/precision.
    /// Should be high enough to have smooth variation, use setSingleStep to control how
    /// slider/spinbox behave.
    /// if precision/range is higher than single step, may procduce strange behavior.
    void setSliderPrecision( int precision );

  signals:
    void valueChanged( double );

  private:
    QSlider* slider_;
    QDoubleSpinBox* spinBox_;
    // update if needed
    double sliderEpsilon_;

  private slots:
    void on_slider_valueChanged( int );
    void on_spinBox_valueChanged( double );
};

#endif // __POWERSLIDER_H__
