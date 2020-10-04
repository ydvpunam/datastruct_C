#include <stdio.h>
#include <malloc.h>

int a; //in .bss
int b = 10; //in data
static int c; //in .bss
static int d = 20; //in data

int *pa; // pointer created in .bss and points toward NULL
int *pb = &a; // pointer created in data and points toward .bss

static int *pc; // pointer created in .bss and points toward NULL
static int *pd = &b; //pointer created in data and points toward data

int main()
{	

	//static int *f2=&f1; //invalid f1 should be declared first i.e before f2
	//static int f1;
	
	//int *f2=&f1;; //this is also invalid as this is called before the declaration of f1
	//static int f1;	


	
	int e; //in stack
	int f = 30; //in stack
	static int g; //in .bss
	static int h = 40; //in data
	int *pe; // pointer created in stack and points toward garbage
	int *pz = &e; // pointer created in stack and points toward stack
	int *py = &h; // pointer created in stack and points toward data
	static int *pf; // pointer created in .bss and points toward NULL
	static int *pg;
	pg= &f; //if declared and defined together than invalid assignment (WHY???)
	//static int *pg = &g; // pointer created in data and points toward .bss....valid 
	
	int ph = (int) malloc(sizeof(int)); // pointer created in stack and points toward heap
	static int *pi;
	pi	= (int*) malloc(sizeof(int)); //  if declared and defined together than invalid assignment (WHY???)
	
	printf("The address of a: 0x%x\n", &a);
	printf("The address of b: 0x%x\n", &b);
	printf("The address of c: 0x%x\n", &c);
	printf("The address of d: 0x%x\n", &d);
	printf("The address of e: 0x%x\n", &e);
	printf("The address of f: 0x%x\n", &f);
	printf("The address of g: 0x%x\n", &g);
	printf("The address of h: 0x%x\n", &h);
	
	printf("The address of pa: 0x%x\n", &pa);
	printf("The address of pb: 0x%x\n", &pb);
	printf("The address of pc: 0x%x\n", &pc);
	printf("The address of pd: 0x%x\n", &pd);
	printf("The address of pe: 0x%x\n", &pe);
	printf("The address of pf: 0x%x\n", &pf);
	printf("The address of pg: 0x%x\n", &pg);
	printf("The address of ph: 0x%x\n", &ph);
	printf("The address of pz: 0x%x\n", &pz);
	printf("The address of py: 0x%x\n", &py);
	printf("The address of pi: 0x%x\n", &pi);
	
	printf("The address in pa: 0x%x\n", pa);
	printf("The address in pb: 0x%x\n", pb);
	printf("The address in pc: 0x%x\n", pc);
	printf("The address in pd: 0x%x\n", pd);
	printf("The address in pe: 0x%x\n", pe);
	printf("The address in pf: 0x%x\n", pf);
	printf("The address in pg: 0x%x\n", pg);
	printf("The address in ph: 0x%x\n", ph);
	printf("The address in pz: 0x%x\n", pz);
	printf("The address in py: 0x%x\n", py);
	printf("The address in pi: 0x%x\n", pi);
	
	return 0;
}
