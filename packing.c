#include<stdio.h>//preprocessor directory
//if not packed size would be different as per arrangement in declaration 
#pragma pack(2)//this is in the form of block of 2bytes
//the block should be in power of two
//initially block of 4bytes (size of long)was there
//but now of block two
struct ABC_t{
long a;//4byte
char b;//1 byte
long c;//4bytes
short d;//2 bytes
long e;//4 bytes
};
//__attribute__ can also be used for packing
int main(){
printf("%d",sizeof(struct ABC_t));//size in bytes
return 0;
}
