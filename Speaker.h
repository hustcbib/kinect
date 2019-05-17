#include <iostream>
#include <string>
#include <sstream>
#include <sapi.h> //��������ͷ�ļ�
using namespace std;

#pragma comment(lib,"SAPI.Lib")
#pragma once

class Speaker
{
private:
	void  MSSpeak(LPCWSTR speakContent);

	LPCWSTR s[4] = {
		L"���˵����Կ���ȫ���λ��",
		L"��ƽ��˫�ۣ�˫�Ȳ�£���������ͷ",
		L"������ת90�ȣ��������ͷ",
		L"��������",
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