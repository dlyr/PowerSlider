#include <QtWidgets>

#include "src/PowerSlider.hpp"

int main( int argc, char* argv[] ) {
    QApplication app( argc, argv );
    QWidget window;
    window.resize( 320, 240 );
    window.setWindowTitle( QApplication::translate( "powerslider", "Power Slider" ) );

    QPushButton* button =
        new QPushButton( QApplication::translate( "powerslider", "Quit" ), &window );

    QVBoxLayout* layout    = new QVBoxLayout();
    double alignementValue = 100000;
    for ( auto i = 0; i < 5; i++ ) {
        PowerSlider* slider = new PowerSlider( &window, alignementValue );
        layout->addWidget( slider );
        slider->setRange( i, pow( 10., double( i ) ) );
    }
    for ( auto i = 0; i < 5; i++ ) {
        PowerSlider* slider = new PowerSlider( &window, alignementValue );
        layout->addWidget( slider );
        slider->setRange( 0., pow( 10., -double( i ) ) );
        slider->setSliderPrecision( 5 + 10 * i );
    }

    layout->addWidget( button );

    window.setLayout( layout );

    window.show();

    button->show();

    QObject::connect( button, &QPushButton::clicked, &app, &QApplication::quit );

    return app.exec();
}
