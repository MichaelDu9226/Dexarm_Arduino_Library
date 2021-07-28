Arduino library for Dexarm
==========

Arduino library for Dexarm

Tested on Dexarm Extension Moule V1(ESP32 WROVER) & Arduino 1.8.15

### Manual installation on Arduino

To install this library, just place this entire folder as a subfolder in your Arduino installation

When installed, this library should look like:

- Arduino\libraries\Dexarm_Arduino_Library(this library's folder)
- Arduino\libraries\Dexarm_Arduino_Library\Dexarm_arduino.cpp(the library source file)
- Arduino\libraries\Dexarm_Arduino_Library\Dexarm_arduino.h(the library header file)
- Arduino\libraries\Dexarm_Arduino_Library\examples(the examples in the "open" menu)
- Arduino\libraries\Dexarm_Arduino_Library\readme.mdthis file)

### Building on Arduino

`#include "Dexarm_arduino.h"`

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

### TODO
- Get current position
- Get current front Module
- More test

### API
- Dexarm(HardwareSerial* serial);
- void begin(int8_t rxd, int8_t txd);
- void start();
- void send_cmd(const char *string);
- void go_home();
- void set_workorigin();
- void set_module_type(int module_type);
- void go_to_max_poistion();
- void move_to(float x, float y, float z, int feedrate = 2000);
- void fast_move_to(float x, float y, float z, int feedrate = 2000);
- void delay_s(int value);
- void delay_ms(int value);
- void soft_gripper_pick();
- void soft_gripper_place();
- void soft_gripper_nature();
- void soft_gripper_stop();
- void air_picker_pick();
- void air_picker_place();
- void air_picker_nature();
- void air_picker_stop();
- void laser_on(int value);
- void laser_off();
- void conveyor_belt_forward(float speed);
- void conveyor_belt_backward(float speed);
- void conveyor_belt_stop();
- void sliding_rail_init();
- void rotary_relative_rotate(int angle);
- void rotary_absolute_rotate(int angle);
