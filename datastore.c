#include<stdio.h>
int a;//default value 0//global veriable
int b=3;//stored in data //global veriable
static int c;//created in .bss//global veriable
static int d=2;//in data//global veriable
int main(){
//register int h=1;//heap
//but may be created in heap else stack.and also if created in heap will not give address.
	int e=12;//stack
	int f;//stack
	static int g=57;//data
	static int j;//created in .bss 
	printf(".bss%d\tdata%d\t.bss%d\tdata%d\tstack%d\tstack%d\t.bss%d\n",&a,&b,&c,&d,&e,&f,&g);
	return 0;
}
	
