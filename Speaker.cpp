#include "Speaker.h"

void  Speaker::MSSpeak(LPCWSTR speakContent)// speakContent为LPCWSTR型的字符串,调用此函数即可将文字转为语音
{
	ISpVoice *pVoice = NULL;

	//初始化COM接口
	if (FAILED(::CoInitialize(NULL)))
		MessageBox(NULL, (LPCWSTR)L"COM接口初始化失败！", (LPCWSTR)L"提示", MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);

	//获取SpVoice接口
	HRESULT h = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);

	if (SUCCEEDED(h))
	{
		pVoice->SetVolume((USHORT)100); //设置音量，范围是 0 -100
		pVoice->SetRate(1); //设置速度，范围是 -10 - 10
		h = pVoice->Speak(speakContent, 0, NULL);

		pVoice->Release();

		pVoice = NULL;
	}

	//释放com资源
	::CoUninitialize();
}