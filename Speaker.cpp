#include "Speaker.h"

void  Speaker::MSSpeak(LPCWSTR speakContent)// speakContentΪLPCWSTR�͵��ַ���,���ô˺������ɽ�����תΪ����
{
	ISpVoice *pVoice = NULL;

	//��ʼ��COM�ӿ�
	if (FAILED(::CoInitialize(NULL)))
		MessageBox(NULL, (LPCWSTR)L"COM�ӿڳ�ʼ��ʧ�ܣ�", (LPCWSTR)L"��ʾ", MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);

	//��ȡSpVoice�ӿ�
	HRESULT h = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);

	if (SUCCEEDED(h))
	{
		pVoice->SetVolume((USHORT)100); //������������Χ�� 0 -100
		pVoice->SetRate(1); //�����ٶȣ���Χ�� -10 - 10
		h = pVoice->Speak(speakContent, 0, NULL);

		pVoice->Release();

		pVoice = NULL;
	}

	//�ͷ�com��Դ
	::CoUninitialize();
}