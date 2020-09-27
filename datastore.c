#include<stdio.h>
int a;//default value 0
int b=3;//stored in data 
static int c;//created in .bss
static int d=2;//in data
int main(){
//register int h=1;
//may be created in heap else stack.and also if created in heap will not give address.
	int e=12;//stack
	int f;//stack
	static int g=57;//data
	print(".bss%d\tdata%d\t.bss%d\tdata%d\tstack%d\tstack%d\t.bss%d\n",&a,&b,&c,&d,&e,&f,&g)
	return 0;
}
	