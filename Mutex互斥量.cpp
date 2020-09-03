#include <windows.h>
#include <string>
#include <iostream>

HANDLE g_hMutex = NULL;
int g_iResource = 0;

DWORD _stdcall WorkerThreadProc(LPVOID IpThreadParameter)
{
	DWORD dwThreadID = GetCurrentThreadId();
	while (true)
	{
		if (WaitForSingleObject(g_hMutex,1000)==WAIT_OBJECT_0)
		{
			g_iResource++;
			std::cout << "thread:" << dwThreadID << "become mutex owner,resourceNo:" << g_iResource << std::endl;
			ReleaseMutex(g_hMutex);
		}
		Sleep(1000);
	}
	return 0;
}
int main()
{
	//����һ��������Mutex����Ĭ����������̲߳�ӵ�и�Mutex
	g_hMutex = CreateMutex(NULL, FALSE, NULL);//���߳����ȴ���һ�������������ò�ӵ����
	HANDLE hWorkerThread[5];//5���߳̾��������ȡ������ȡ���ɲ���������Դg_iResource
	for (int i=0;i<5;++i)
	{
		hWorkerThread[i] = CreateThread(NULL, 0, WorkerThreadProc, NULL, 0, NULL);
	}
	for (int i=0;i<5;++i)
	{
		//�ȴ������߳��˳�
		WaitForSingleObject(hWorkerThread[i], INFINITE);
		CloseHandle(hWorkerThread[i]);
	}
	CloseHandle(g_hMutex);
	return 0;
}