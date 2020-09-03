#include "iostream"
#include <string>
#include <windows.h>

bool g_bTaskCompleted = false;
std::string g_TaskResult;//����һ���ַ�����
HANDLE g_hTaskEvent = NULL;//�����¼�

DWORD _stdcall WorkerThreadProc(LPVOID IpThreadParameter)
{
	Sleep(3000);
	g_TaskResult = "task completed";
	g_bTaskCompleted = true;
	//�����¼��ź�
	SetEvent(g_hTaskEvent);
	return 0;
}
int main()
{
	//�������ֶ����á���ʼ���ź�
	g_hTaskEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	HANDLE hworkerthread = CreateThread(NULL, 0, WorkerThreadProc, NULL, 0, NULL);
	DWORD dwResult = WaitForSingleObject(g_hTaskEvent, INFINITE);
	if (dwResult==WAIT_OBJECT_0)
	{
		std::cout << g_TaskResult << std::endl;
	}
	CloseHandle(hworkerthread);
	CloseHandle(g_hTaskEvent);
	return 0;
}