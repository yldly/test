#include <Windows.h>
#include <iostream>

int main() {
    const int CLICK_COUNT = 1000; // 要发送的点击次数
    const int INPUT_COUNT = CLICK_COUNT * 2; // 每个点击需要 2 个事件（按下+释放）

    INPUT inputs[INPUT_COUNT] = {0};

    // 构造所有点击事件
    for (int i = 0; i < INPUT_COUNT; i += 2) {
        // 鼠标按下事件
        inputs[i].type = INPUT_MOUSE;
        inputs[i].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

        // 鼠标释放事件 
        inputs[i + 1].type = INPUT_MOUSE;
        inputs[i + 1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    }

    std::cout << "准备发送 " << CLICK_COUNT << " 次点击（共 " << INPUT_COUNT << " 个输入事件）..." << std::endl;
 	Sleep(3000);
    // 一次性发送所有事件
   	const int BATCH_SIZE = 500; // 每批发送 500 次点击（1000 个事件）
	for (int i = 0; i < INPUT_COUNT; i += BATCH_SIZE * 2) {
	    int remaining = INPUT_COUNT - i;
	    int currentBatch = (remaining < BATCH_SIZE * 2) ? remaining : BATCH_SIZE * 2;
	    SendInput(currentBatch, &inputs[i], sizeof(INPUT));
	    Sleep(10); // 短暂延迟，避免系统丢弃事件
	}

    return 0;
}
