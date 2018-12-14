#ifndef POWERSLIDERPLUGIN_H
#define POWERSLIDERPLUGIN_H

#include <QtDesigner/QDesignerContainerExtension>
#include <QtDesigner/QDesignerCustomWidgetInterface>

#include <QtCore/qplugin.h>
#include <QtGui/QIcon>

#include <QExtensionFactory>


class QDesignerFormEditorInterface;

class PowerSliderPlugin : public QObject, public QDesignerCustomWidgetInterface
{
	Q_OBJECT
	Q_INTERFACES(QDesignerCustomWidgetInterface)
    public:
		PowerSliderPlugin(QObject *parent = 0);
	bool isContainer() const;
	bool isInitialized() const;
	QIcon icon() const;
	QString codeTemplate() const;
	QString domXml() const;
	QString group() const;
	QString includeFile() const;
	QString name() const;
	QString toolTip() const;
	QString whatsThis() const;
	QWidget *createWidget(QWidget *parent);
	void initialize(QDesignerFormEditorInterface *core);
	
private:
	bool initialized;
};
/*
class PowerSliderPropertySheet: public QObject,
                                public QDesignerPropertySheetExtension
{
    Q_OBJECT;
    Q_INTERFACE(QDesignerPropertySheet);
public:

    PowerSliderPropertySheet (PowerSlider *ps, QObjet *parent)
        :QObjet(parent){
        _numAttribute = 3;
        _attribu
    }

    virtual ~PowerSliderPropertySheet (){

    }
    
    virtual int count () const{
        return 3;
    }

    virtual bool hasReset ( int index ) const{
        return true;
    }

    virtual int indexOf ( const QString & name ) const{
    }

    virtual bool isAttribute ( int index ) const{
    }

    virtual bool isChanged ( int index ) const{
    }

    virtual bool isVisible ( int index ) const{
    }

    virtual QVariant property ( int index ) const{
    }

    virtual QString propertyGroup ( int index ) const{
    }

    virtual QString propertyName ( int index ) const{
    }

    virtual bool reset ( int index ){
    }

    virtual void setAttribute ( int index, bool attribute ){
    }

    virtual void setChanged ( int index, bool changed ){
    }

    virtual void setProperty ( int index, const QVariant & value ){
    }

    virtual void setPropertyGroup ( int index, const QString & group ){
    }

    virtual void setVisible ( int index, bool visible ){
    }
  
protected:
    int _numAttribute;
};

class PowerSliderPropertySheetFactory : public QExtensionFactory
{
    Q_OBJECT

    public:
    PowerSliderPropertySheetFactory(QExtensionManager *parent = 0);

protected:
    QObject *createExtension(QObject *object, const QString &iid, QObject *parent) const;
};
*/
#endif // POWERSLIDERPLUGIN_H
