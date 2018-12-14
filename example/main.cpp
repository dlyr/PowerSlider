#include <QtWidgets>

#include "src/PowerSlider.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QWidget window;
  window.resize(320, 240);
  window.setWindowTitle(QApplication::translate("powerslider", "Power Slider"));

  QPushButton *button =
      new QPushButton(QApplication::translate("powerslider", "Quit"), &window);

  QVBoxLayout *layout = new QVBoxLayout();

  for (auto i = 0; i < 5; i++) {
    PowerSlider *slider = new PowerSlider(&window);
    layout->addWidget(slider);
  }

  layout->addWidget(button);

  window.setLayout(layout);

  window.show();

  button->show();

  QObject::connect(button, &QPushButton::clicked, &app, &QApplication::quit);

  return app.exec();
}
