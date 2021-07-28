#ifndef Dexarm_arduino_h
#define Dexarm_arduino_h
#include "HardwareSerial.h"

class Dexarm
{
public:
    Dexarm(HardwareSerial* serial);
    void begin(int8_t rxd, int8_t txd);
    void start();
    void send_cmd(const char *string);
    void go_home();
    void set_workorigin();
    void set_module_type(int module_type);
    void go_to_max_poistion();
    void move_to(float x, float y, float z, int feedrate = 2000);
    void fast_move_to(float x, float y, float z, int feedrate = 2000);
    void delay_s(int value);
    void delay_ms(int value);
    void soft_gripper_pick();
    void soft_gripper_place();
    void soft_gripper_nature();
    void soft_gripper_stop();
    void air_picker_pick();
    void air_picker_place();
    void air_picker_nature();
    void air_picker_stop();
    void laser_on(int value);
    void laser_off();
    void conveyor_belt_forward(float speed);
    void conveyor_belt_backward(float speed);
    void conveyor_belt_stop();
    void sliding_rail_init();
    void rotary_relative_rotate(int angle);
    void rotary_absolute_rotate(int angle);
private:
    typedef enum
    {
        Read_State_Wait_idle = 0,
        Read_State_Wait_o = 1,
        Read_State_Wait_k = 2,
    } Read_State;
    HardwareSerial *_serial;
    uint8_t _read_State;
};

#endif