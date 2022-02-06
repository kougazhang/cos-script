#include <conio.h>
#include <iostream>
#include <Windows.h>

int getCursorPos();

int main() {
  getCursorPos();
}

// 获取鼠标坐标，这个坐标并不能直接作为 mouse_event 中 x,y 的参数
int getCursorPos() {
  while (1) {
    POINT pt = {0,0};
    GetCursorPos(&pt);
    printf("x=%d,y=%d\n", pt.x,pt.y);
    Sleep(3000);
  }
}
