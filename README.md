![alt text][logo]

# PowerSlider Qt Widget

## Presentation

Qt Widget, a slider and a double spinbox !

This small piece of code can ease the setup of GUI when you have to control floating point values.

A designer plugin is provided to design interface with "PowerSlider" directly in designer.

Manual comming soon (well, or not, expect if someone ask :D )

## compile and install

Default installation is `PowerSlider/Bundle-*` directory depending on compiler and build type.

Designer plugin need Qt5 UiTools package (debian pkg `qttools5-dev`), to skip designer plugin build add `-DBUILD_DESIGNER_PLUGIN=Off` to `cmake` call.

Installation is done under `lib` and `include` directory of `CMAKE_INSTALL_PREFIX`

So a typical build looks like

```sh
cmake -B build -DCMAKE_INSTALL_PREFIX=somewhere
cmake --build build --target install
```

Then copy the QtDesigner plugin to the appropriate place, and run designer

```sh
cp somehere/plugins/designer/libPowerSliderPlugin.so ~/.qt/plugins/designer/
QT_PLUGIN_PATH=~/.qt/plugins/ designer
```

designer should have the new widget in his list as in the screen shot here :

![alt text][designer]

[designer]: ./doc/designer.png "designer screenshot"
[logo]: ./assets/icon.svg "PowerSlider logo"

## use in you project

We use `example` as an example for this case.
Configure package find in your `CMakeLists.txt` (e.g. `(find_package PowerSlider)`) and give `PowerSlider_DIR` to `cmake` invocation

```sh
cmake example -B build-example -DPowerSlider_DIR=`pwd`/PowerSlider/Bundle-GNU-Release/lib/cmake/PowerSlider
cmake --build build-example
```
