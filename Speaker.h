#include <iostream>
#include <string>
#include <sstream>
#include <sapi.h> //导入语音头文件
using namespace std;

#pragma once
#pragma comment(lib,"C:\\Program Files (x86)\\Windows Kits\\8.1\\Lib\\winv6.3\\um\\x64\\SAPI.Lib") //导入语音头文件库

class Speaker
{
private:
	void  MSSpeak(LPCWSTR speakContent);

	LPCWSTR s[3] = {
		L"请平举双臂，双腿并拢，面对摄像头",
		L"请向左转90度，侧对摄像头",
	};

public:
	void Speak(long time) {
		if (time == 2)
			this->MSSpeak(s[0]);
		else if (time == 15)
			this->MSSpeak(s[1]);
	}
};