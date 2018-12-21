# PowerSlider
Qt Widget, a slider and a double spinbox !

This small piece of code can ease the setup of GUI when you have to control floating pint values.

A designer plugin is provided to design interface with "PowerSlider" directly in designer.

Manual comming soon.

# compile and install
Pre install compilation results are copied to `Bundle-*` directory depending on compiler and build type.
Installation is done under `lib` and `include` directory of `CMAKE_INSTALL_PREFIX`

So a typical build looks like 
```sh
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=somewhere
make install
```
Then copy the QtDesigner plugin where appropriate, and run designer
```sh
cp somehere/plugins/designer/libPowerSliderPlugin.so ~/.qt/plugins/designer/
QT_PLUGIN_PATH=~/.qt/plugins/ designer
```

designer should have the new widget in his list as in the screen shot here :

![alt text][designer]

[designer]: ./doc/designer.png "designer screenshot"
