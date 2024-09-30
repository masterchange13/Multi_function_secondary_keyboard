#include "src/BleKeyboard/BleKeyboard.h"
#include"src/KeyMap/keyMap.h"

BleKeyboard bleKeyboard("masterchange's-Multi-function_secondary_keyboard", "Espressif", 50);

// 定义行和列引脚
const int rows[] = {34, 35, 32, 33};
const int cols[] = {25, 26, 27, 14};
short col_size = 4;
short row_size = 4;

void setup() {
    Serial.begin(115200);
    Serial.println("Starting BLE Keyboard");

    // 初始化BLE键盘
    bleKeyboard.begin();

    // 设置行引脚为输入并启用上拉
    for (int i = 0; i < row_size; i++) {
        pinMode(rows[i], INPUT_PULLDOWN);
    }
//    for (int i = 2; i < row_size; i++) {
//        pinMode(rows[i], INPUT_PULLUP);
//    }

    // 设置列引脚为输出并默认高电平
    for (int i = 0; i < col_size; i++) {
        pinMode(cols[i], OUTPUT);
        digitalWrite(cols[i], LOW);
    }

}

void loop() {
    if (!bleKeyboard.isConnected()) {
        Serial.println("BLE Keyboard not connected");
        delay(1000);
        return;
    }

    // 调试信息：打印所有行引脚的状态
//    Serial.print("Row states: ");
//    for (int i = 0; i < row_size; i++) {
//        Serial.print(digitalRead(rows[i]));
//        Serial.print(" ");
//    }
//    Serial.println();

    // 扫描矩阵键盘
    for (int col = 0; col < col_size; col++) {
        digitalWrite(cols[col], HIGH); // 将当前列设置为低电平

        for (int row = 0; row < row_size; ++row) {
            if (digitalRead(rows[row]) == HIGH) { // 检测按键按下
                functionKey(row, col);
                delay(50); // 简单去抖动处理
            }
        }
        digitalWrite(cols[col], LOW); // 恢复当前列的高电平


//        for (int row = 2; row < 4; row++) {
//            if (digitalRead(rows[row]) == LOW) { // 检测按键按下
//                functionKey(bleKeyboard, row, col);
//                delay(50); // 简单去抖动处理
//            }
//        }
//        digitalWrite(cols[col], HIGH); // 恢复当前列的高电平
    }

    delay(100); // 合理的扫描间隔
}

void functionKey(int row, int col) {

    Serial.print("Key pressed: row ");
    Serial.print(row + 1);
    Serial.print(", col ");
    Serial.println(col + 1);
    if (row == 0) {
        if (col == 0) {
            keyMap11(bleKeyboard);
        } else if (col == 1) {
            keyMap12(bleKeyboard);
        } else if (col == 2) {
            keyMap13(bleKeyboard);
        } else if (col == 3) {
            keyMap14(bleKeyboard);
        }
    }

    else if (row == 1) {
        if (col == 0) {
            keyMap21(bleKeyboard);
        } else if (col == 1) {
            keyMap22(bleKeyboard);
        } else if (col == 2) {
            keyMap23(bleKeyboard);
        } else if (col == 3) {
            keyMap24(bleKeyboard);
        }
    }

    else if (row == 2) {
        if (col == 0) {
            keyMap31(bleKeyboard);
        } else if (col == 1) {
            keyMap32(bleKeyboard);
        } else if (col == 2) {
            keyMap33(bleKeyboard);
        } else if (col == 3) {
            keyMap34(bleKeyboard);
        }
    }

    else if (row == 3) {
        if (col == 0) {
            keyMap41(bleKeyboard);
        } else if (col == 1) {
            keyMap42(bleKeyboard);
        } else if (col == 2){
            keyMap43(bleKeyboard);
        } else if (col == 3) {
            keyMap44(bleKeyboard);
        }
    }
}