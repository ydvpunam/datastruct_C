#include<stdio.h>
int main(){
	 unsigned char a=69;
	print("%d\t",a);//decimal print
	print("%c\t",a);//character print
	print("0x%x\t",a);//hexadecimal
	print("0%o\t",a);//octal
	print("%b\t",a);//binary
	return 0;
}
