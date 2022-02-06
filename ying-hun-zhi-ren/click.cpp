// 萌小虎成长记自动学习脚本
// 参考教程：
// 获取屏幕大小：https://blog.csdn.net/yp18792574062/article/details/88351342
// 鼠标事件：https://www.bilibili.com/read/cv4954650/
// 首先使用 getCursorPos 进行调试，捕捉要点击的点 x,y

#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
 
using namespace std;

int leftClick(long x, long y, int width, int height);

class ScriptTiger {
  public:
    int sleepSec;
    int click(int x, int y);
};

int main(int argc, char* argv[]) {
  int sleepSec=0;
  int x=0;
  int y=0;
  char ch;
  while((ch=getopt(argc,argv,"s:x:y:"))!=-1) {
    switch (ch) {
      case 's':
	sleepSec = atoi(optarg);
	break;
      case 'x':
        x = atoi(optarg);
        break;
      case 'y':
        y = atoi(optarg);
        break;
      default:
        cout << "invalid: " << ch << endl;
	break;	
    }
  } 
  cout << "sleepSec: " << sleepSec << "; x: " << x << "; y: " << y << endl;
  if (sleepSec == 0 || x == 0 || y == 0) {
    cout << "invalid params, exit." << endl;
    return -1;
  }
  ScriptTiger tiger;
  tiger.sleepSec = sleepSec;
  tiger.click(x,y);
  return 0;
}

int ScriptTiger::click(int x, int y) {
  // 获取屏幕大小
  int width = GetSystemMetrics(SM_CXSCREEN);
  int height =  GetSystemMetrics(SM_CYSCREEN);
  cout << width << "; " << height << endl;
  // 定位到 cos 窗口, 首次点击无效
  leftClick(x, y, width, height);
  // 点击
  while (1) {
    leftClick(x, y, width, height);
    cout << "leftClick finished: " << x << ", " << y << " sleep " << sleepSec << endl;
    Sleep(sleepSec*1000);
  }
  return 0;
}

// 鼠标移动到指定位置并单击
int leftClick(long x, long y, int width, int height) {
  mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE,
      x* 65536 / width, y * 65536 / height, 0, 0 );
  return 0;
}
