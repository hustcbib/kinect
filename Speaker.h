#include <iostream>
#include <string>
#include <sstream>
#include <sapi.h> //��������ͷ�ļ�
using namespace std;

#pragma once
#pragma comment(lib,"C:\\Program Files (x86)\\Windows Kits\\8.1\\Lib\\winv6.3\\um\\x64\\SAPI.Lib") //��������ͷ�ļ���

class Speaker
{
private:
	void  MSSpeak(LPCWSTR speakContent);

	LPCWSTR s[3] = {
		L"��ƽ��˫�ۣ�˫�Ȳ�£���������ͷ",
		L"������ת90�ȣ��������ͷ",
	};

public:
	void Speak(long time) {
		if (time == 2)
			this->MSSpeak(s[0]);
		else if (time == 15)
			this->MSSpeak(s[1]);
	}
};