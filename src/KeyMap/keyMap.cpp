//
// Created by mao on 2024/7/27.
//

#include "keyMap.h"
#include "../BleKeyboard/BleKeyboard.h"
#include <Arduino.h>

#define SHIFT 0x80
#define KEY_R 0x72

// 开机
void keyMap11(BleKeyboard bleKeyboard)
{
    bleKeyboard.press(KEY_SPACE);
    delay(20);
    bleKeyboard.release(KEY_SPACE);
    bleKeyboard.press(KEY_NUM_ENTER);
    delay(20);
    bleKeyboard.release(KEY_NUM_ENTER);
    delay(20);
}

// 关机
void keyMap12(BleKeyboard bleKeyboard)
{
    uint8_t q = 0x14;
    uint8_t Q = q | SHIFT;
    uint8_t KEY_Q = q | SHIFT;
    bleKeyboard.press(KEY_LEFT_GUI);
    delay(20);
    bleKeyboard.press(KEY_LEFT_SHIFT);
    delay(20);
    bleKeyboard.press(KEY_Q);
    delay(20);
    bleKeyboard.release(KEY_LEFT_GUI);
    delay(20);
    bleKeyboard.release(KEY_LEFT_SHIFT);
    delay(20);
    bleKeyboard.release(KEY_Q);
    delay(20);
}

// reboot
void keyMap13(BleKeyboard bleKeyboard)
{

}

void keyMap14(BleKeyboard bleKeyboard)
{

}

// 打开/关闭音乐
void keyMap21(BleKeyboard bleKeyboard)
{
    bleKeyboard.press(KEY_MEDIA_PLAY_PAUSE);
    delay(20);
    bleKeyboard.release(KEY_MEDIA_PLAY_PAUSE);
    delay(20);
}

void keyMap22(BleKeyboard bleKeyboard)
{

}

void keyMap23(BleKeyboard bleKeyboard)
{

}

void keyMap24(BleKeyboard bleKeyboard)
{

}

// 运行代码ctrl + F5
void keyMap31(BleKeyboard bleKeyboard)
{
    bleKeyboard.press(KEY_LEFT_CTRL);
    delay(20);
    bleKeyboard.press(KEY_F5);
    delay(20);
    bleKeyboard.release(KEY_LEFT_CTRL);
    delay(20);
    bleKeyboard.release(KEY_F5);
    delay(20);
}

// terminal
void keyMap32(BleKeyboard bleKeyboard) {
//    const uint8_t KEY_R = 0x72; // 'r' 键的键码
    bleKeyboard.press(KEY_LEFT_GUI);
    delay(40);
    bleKeyboard.press(KEY_R);
    delay(40);
    bleKeyboard.release(KEY_LEFT_GUI);
    bleKeyboard.release(KEY_R);
    delay(100);

    bleKeyboard.print("powershell");
    delay(200);

    bleKeyboard.press(KEY_RETURN);
    delay(20);
    bleKeyboard.release(KEY_RETURN);
    delay(20);
}

//machine browser
void keyMap33(BleKeyboard bleKeyboard)
{
    bleKeyboard.press(KEY_MEDIA_LOCAL_MACHINE_BROWSER);
    delay(20);
    bleKeyboard.release(KEY_MEDIA_LOCAL_MACHINE_BROWSER);
    delay(20);
}

// edge browser
void keyMap34(BleKeyboard bleKeyboard)
{
    bleKeyboard.press(KEY_LEFT_GUI);
    delay(20);
    bleKeyboard.press(KEY_R);
    delay(20);
    bleKeyboard.release(KEY_LEFT_GUI);
    bleKeyboard.release(KEY_R);
    delay(20);

    bleKeyboard.print("msedge");
    delay(200);

    bleKeyboard.press(KEY_RETURN);
    delay(20);
    bleKeyboard.release(KEY_RETURN);
    delay(20);
}

// qq
void keyMap41(BleKeyboard bleKeyboard)
{
    bleKeyboard.press(KEY_LEFT_GUI);
    delay(20);
    bleKeyboard.press(KEY_R);
    delay(20);
    bleKeyboard.release(KEY_LEFT_GUI);
    bleKeyboard.release(KEY_R);
    delay(200);

    bleKeyboard.print("qq");
    delay(200);

    bleKeyboard.press(KEY_RETURN);
    delay(20);
    bleKeyboard.release(KEY_RETURN);
    // 启动慢，需要长延时
    delay(2000);

    bleKeyboard.press(KEY_RETURN);
    delay(20);
    bleKeyboard.release(KEY_RETURN);
    delay(20);
}

// steam
void keyMap42(BleKeyboard bleKeyboard)
{
    bleKeyboard.press(KEY_LEFT_GUI);
    delay(40);
    bleKeyboard.press(KEY_R);
    delay(40);
    bleKeyboard.release(KEY_LEFT_GUI);
    bleKeyboard.release(KEY_R);
    delay(100);

    bleKeyboard.print("steam");
    delay(200);

    bleKeyboard.press(KEY_RETURN);
    delay(20);
    bleKeyboard.release(KEY_RETURN);
    delay(20);
}

void keyMap43(BleKeyboard bleKeyboard)
{

}

void keyMap44(BleKeyboard bleKeyboard)
{

}