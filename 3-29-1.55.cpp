#include <Windows.h>
#include <iostream>

int main() {
    const int CLICK_COUNT = 1000; // Ҫ���͵ĵ������
    const int INPUT_COUNT = CLICK_COUNT * 2; // ÿ�������Ҫ 2 ���¼�������+�ͷţ�

    INPUT inputs[INPUT_COUNT] = {0};

    // �������е���¼�
    for (int i = 0; i < INPUT_COUNT; i += 2) {
        // ��갴���¼�
        inputs[i].type = INPUT_MOUSE;
        inputs[i].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

        // ����ͷ��¼� 
        inputs[i + 1].type = INPUT_MOUSE;
        inputs[i + 1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    }

    std::cout << "׼������ " << CLICK_COUNT << " �ε������ " << INPUT_COUNT << " �������¼���..." << std::endl;
 	Sleep(3000);
    // һ���Է��������¼�
   	const int BATCH_SIZE = 500; // ÿ������ 500 �ε����1000 ���¼���
	for (int i = 0; i < INPUT_COUNT; i += BATCH_SIZE * 2) {
	    int remaining = INPUT_COUNT - i;
	    int currentBatch = (remaining < BATCH_SIZE * 2) ? remaining : BATCH_SIZE * 2;
	    SendInput(currentBatch, &inputs[i], sizeof(INPUT));
	    Sleep(10); // �����ӳ٣�����ϵͳ�����¼�
	}

    return 0;
}
