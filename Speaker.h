#include <iostream>
#include <string>
#include <sstream>
#include <sapi.h> //导入语音头文件
using namespace std;

#pragma comment(lib,"SAPI.Lib")
#pragma once

class Speaker
{
private:
	void  MSSpeak(LPCWSTR speakContent);

	LPCWSTR s[4] = {
		L"请退到可以看见全身的位置",
		L"请平举双臂，双腿并拢，面对摄像头",
		L"请向左转90度，侧对摄像头",
		L"测量结束",
	};

public:
	void Speak(long time) {
		if (time == 2)
			this->MSSpeak(s[0]);
		else if (time == 10)
			this->MSSpeak(s[1]);
		else if (time == 20)
			this->MSSpeak(s[2]);
		else if (time == 31)
			this->MSSpeak(s[3]);
	}
};