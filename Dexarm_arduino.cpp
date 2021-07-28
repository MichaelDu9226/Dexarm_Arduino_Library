#include "Dexarm_arduino.h"
#include "HardwareSerial.h"

Dexarm::Dexarm(HardwareSerial* serial)
{
    _serial = serial;
}

void Dexarm::begin(int8_t rxd, int8_t txd)
{
    _serial->begin(1000000, SERIAL_8N1, rxd, txd);
    _serial->println("");
}

void Dexarm::send_cmd(const char *string)
{
    _serial->println(string);

    _read_State = Read_State_Wait_o;
    while (1)
    {
        while (_serial->available())
        {
            uint8_t ch = _serial->read();
            //Serial.println((char)ch);
            switch (_read_State)
            {
            case Read_State_Wait_o:
                if (ch == 0x6F)
                {
                    _read_State = Read_State_Wait_k;
                    //Serial.println("get o");
                }
                else
                {
                }
                break;
            case Read_State_Wait_k:
                if (ch == 0x6B)
                {
                    _read_State = Read_State_Wait_idle;
                    //Serial.println("get k");
                }
                else
                {
                    _read_State = Read_State_Wait_o;
                    //Serial.println("not get k");
                }
                break;
            }
            if (_read_State == Read_State_Wait_idle)
            {
                _read_State = Read_State_Wait_o;
                return;
            }
        }
    }
}

void Dexarm::go_home()
{
    send_cmd("M1112");
}

void Dexarm::set_workorigin()
{
    send_cmd("G92 X0 Y0 Z0");
}

void Dexarm::go_to_max_poistion()
{
    send_cmd("M1111");
}

void Dexarm::set_module_type(int module_type)
{
    char send_buffer[200];
    snprintf(send_buffer, 200, "M888 P%d", module_type);
    send_cmd(send_buffer);
}

void  Dexarm::move_to(float x, float y, float z, int feedrate)
{
    char send_buffer[200];
    snprintf(send_buffer, 200, "G1 F%d X%f Y%f Z%f", feedrate, x, y, z);
    send_cmd(send_buffer);
}

void  Dexarm::fast_move_to(float x, float y, float z, int feedrate)
{
    char send_buffer[200];
    snprintf(send_buffer, 200, "G0 F%d X%f Y%f Z%f", feedrate, x, y, z);
    send_cmd(send_buffer);
}

void  Dexarm::delay_s(int value)
{
    char send_buffer[200];
    snprintf(send_buffer, 200, "G4 S%d", value);
    send_cmd(send_buffer);
}

void  Dexarm::delay_ms(int value)
{
    char send_buffer[200];
    snprintf(send_buffer, 200, "G4 P%d", value);
    send_cmd(send_buffer);    
}

void  Dexarm::soft_gripper_pick()
{
    send_cmd("M1001"); 
}

void  Dexarm::soft_gripper_place()
{
    send_cmd("M1000");
}

void  Dexarm::soft_gripper_nature()
{
    send_cmd("M1002");
}

void  Dexarm::soft_gripper_stop()
{
    send_cmd("M1003");
}

void  Dexarm::air_picker_pick()
{
    send_cmd("M1000");
}

void  Dexarm::air_picker_place()
{
    send_cmd("M1001");
}

void  Dexarm::air_picker_nature()
{
    send_cmd("M1002");
}

void  Dexarm::air_picker_stop()
{
    send_cmd("M1003");
}

void  Dexarm::laser_on(int value)
{
    char send_buffer[200];
    snprintf(send_buffer, 200, "M3 S%d", value);
    send_cmd(send_buffer);   
}

void  Dexarm::laser_off()
{
    send_cmd("M3 S0");
}

void  Dexarm::conveyor_belt_forward(float speed)
{
    char send_buffer[200];
    snprintf(send_buffer, 200, "M2012 F%f D0", speed);
    Serial.println(send_buffer);
    send_cmd(send_buffer); 
}

void  Dexarm::conveyor_belt_backward(float speed)
{
    char send_buffer[200];
    snprintf(send_buffer, 200, "M2012 F%f D1", speed);
    Serial.println(send_buffer);
    send_cmd(send_buffer);
}

void  Dexarm::conveyor_belt_stop()
{
    send_cmd("M2013");
}

void  Dexarm::sliding_rail_init()
{
    send_cmd("M2005");
}

void  Dexarm::rotary_relative_rotate(int angle)
{
    char send_buffer[200];
    snprintf(send_buffer, 200, "M2101 R%d", angle);
    Serial.println(send_buffer);
    send_cmd(send_buffer);
}

void  Dexarm::rotary_absolute_rotate(int angle)
{
    char send_buffer[200];
    snprintf(send_buffer, 200, "M2101 P%d", angle);
    Serial.println(send_buffer);
    send_cmd(send_buffer);
}
/*
    void fast_move_to(int x, int y, int z, int e, int feedrate = 2000, int mode = 1);
    void dealy_s(int value);
    void dealy_ms(int value);
    void soft_gripper_pick();
    void soft_gripper_place();
    void soft_gripper_nature();
    void soft_gripper_stop();
    void air_picker_pick();
    void air_picker_place();
    void air_picker_nature();
    void air_picker_stop();
    void laser_on();
    void laser_off();
    void conveyor_belt_forward();
    void conveyor_belt_backward();
    void conveyor_belt_stop();
    void sliding_rail_init();
    */