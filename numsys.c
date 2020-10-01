#include<stdio.h>
int main(){
	unsigned char c=0x6;//hexadecimal
	unsigned char b=09;//octal
	 unsigned char a=69;//full 8bits is free no bit for sign
	printf("%d\t",a);//decimal print
	printf("%c\t",a);//character print
	printf("0x%x\t",a);//hexadecimal
	printf("0%o\t",a);//octal
	//printf("%b\t",a);//binary//this may not work
	return 0;
}
