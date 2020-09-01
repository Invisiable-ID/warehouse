#include<Windows.h>
#include<list>
#include<iostream>
#include<string>

CRITICAL_SECTION g_cs;//临界区
int g_number = 0;
DWORD _stdcall WorkerThreadProc(LPVOID IpThreadParameter)
{
	DWORD dwThreadID = GetCurrentThreadId();
	while (true)
	{
		EnterCriticalSection(&g_cs);
		std::cout << "EnterCriticalSection,ThreadID: " << dwThreadID << std::endl;
		g_number++;
		SYSTEMTIME st;
		//获取当前系统时间

		GetLocalTime(&st);
		char szMsg[64] = { 0 };
		printf("[Year]%d	[Month]%d	[Day]%d	[Hour]%d	[Minute]%d	[Second]%d	[Milliseconds]%d	NO.%d,ThreadID: %d.", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, g_number, dwThreadID);
		std::cout << szMsg << std::endl;
		LeaveCriticalSection(&g_cs);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	InitializeCriticalSection(&g_cs);//初始化临界区
	HANDLE hWorkerThread1 = CreateThread(NULL, 0, WorkerThreadProc, NULL, 0, NULL);
	HANDLE hWorkerThread2 = CreateThread(NULL, 0, WorkerThreadProc, NULL, 0, NULL);
	HANDLE hWorkerThread3 = CreateThread(NULL, 0, WorkerThreadProc, NULL, 0, NULL);
	//WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds)
	WaitForSingleObject(hWorkerThread1, INFINITE);
	WaitForSingleObject(hWorkerThread2, INFINITE);
	WaitForSingleObject(hWorkerThread3, INFINITE);
	//关闭线程句柄
	CloseHandle(hWorkerThread1);
	CloseHandle(hWorkerThread2);
	CloseHandle(hWorkerThread3);
	//删除临界区对象
	DeleteCriticalSection(&g_cs);
	return 0;
}