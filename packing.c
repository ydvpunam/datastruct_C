#include<stdio.h>//preprocessor directory
#pragma pack(2)//the block should be in power of two
struct ABC_t{
long a;//4byte
char b;//1 byte
long c;//4bytes
short d;//2 bytes
long e;//4 bytes
};
int main(){
print("%d",sizeof(struct ABC_t))//size in bytes
return 0;
}