#include <QApplication>
#include "PowerSlider.h"
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget *window = new QWidget;
	QVBoxLayout *layout = new QVBoxLayout;
	layout->setMargin(6);
	layout->setSpacing(0);
	PowerSlider *sli = new PowerSlider(NULL, 10000);
	layout->addWidget(sli);
	sli->setRange(0.01,0.3);
	PowerSlider *sli2 = new PowerSlider(NULL, 10000);
	delete sli2;

	window->setLayout(layout);
	window->show();
	return app.exec();
}
