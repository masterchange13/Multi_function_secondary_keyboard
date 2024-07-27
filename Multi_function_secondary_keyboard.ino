#include "src/BleKeyboard/BleKeyboard.h"

BleKeyboard bleKeyboard("masterchange's Multi-function secondary keyboard", "Espressif", 50);

// 定义行和列引脚
const int rows[] = {32, 2, 3, 4};
const int cols[] = {33, 6, 17, 18};

// 定义按键映射
const uint8_t keymap[4][4] = {
        {KEY_NUM_0, KEY_F1, KEY_F2, KEY_F3},
        {KEY_F4, KEY_F5, KEY_F6, KEY_F7},
        {KEY_F8, KEY_F9, KEY_F10, KEY_F11},
        {KEY_F12, KEY_F1, KEY_F1, KEY_F1}
};

short col_size = 4;
short row_size = 4;

void setup() {
    Serial.begin(115200);
    Serial.println("Starting BLE Keyboard");

    // 初始化BLE键盘
    bleKeyboard.begin();

    // 设置行引脚为输入并启用上拉
    for (int i = 0; i < row_size; i++) {
        pinMode(rows[i], INPUT_PULLUP);
    }

    // 设置列引脚为输出并默认高电平
    for (int i = 0; i < 1; i++) {
        pinMode(cols[i], OUTPUT);
        digitalWrite(cols[i], HIGH);
    }

}

void loop() {
    if (!bleKeyboard.isConnected()) {
        Serial.println("BLE Keyboard not connected");
        delay(1000);
        return;
    }

    Serial.println("i am running");
    // 扫描矩阵键盘
    for (int col = 0; col < col_size; col++) {
        digitalWrite(cols[col], LOW); // 将当前列设置为低电平

        for (int row = 0; row < row_size; row++) {
            if (digitalRead(rows[row]) == LOW) { // 检测按键按下
                Serial.print("Key pressed: ");
                Serial.println(keymap[row][col]); // 打印按键值
                bleKeyboard.press(keymap[row][col]);
                delay(20); // 简单去抖动处理
                while (digitalRead(rows[row]) == LOW); // 等待按键释放
                bleKeyboard.release(keymap[row][col]);
                Serial.print("Key released: ");
                Serial.println(keymap[row][col]); // 打印按键释放
                delay(20); // 简单去抖动处理
            }
        }

        digitalWrite(cols[col], HIGH); // 恢复当前列的高电平
    }

    delay(100); // 合理的扫描间隔
}
