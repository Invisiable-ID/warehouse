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
	//创建一个匿名的Mutex对象，默认情况下主线程不拥有该Mutex
	g_hMutex = CreateMutex(NULL, FALSE, NULL);//主线程首先创建一个互斥量并设置不拥有它
	HANDLE hWorkerThread[5];//5个线程竞争随机获取它，获取即可操作共享资源g_iResource
	for (int i=0;i<5;++i)
	{
		hWorkerThread[i] = CreateThread(NULL, 0, WorkerThreadProc, NULL, 0, NULL);
	}
	for (int i=0;i<5;++i)
	{
		//等待工作线程退出
		WaitForSingleObject(hWorkerThread[i], INFINITE);
		CloseHandle(hWorkerThread[i]);
	}
	CloseHandle(g_hMutex);
	return 0;
}