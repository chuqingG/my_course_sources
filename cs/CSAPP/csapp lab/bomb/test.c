#include <stdio.h>
#include <stdlib.h>

int func4(int x, int y, int z){
  int a = (x - y) >> 31;
  int b = ((x - y) + a) >> 1;
  a = b + y;
  if(a > z){
    b = func4(a - 1, y, z);
    return 2 * b ;
  }
  else if(a < z){
    b = func4(x, a + 1, z);
    return 2 * b + 1;
  }
  else 
    return 0;
}

void dtb(unsigned long num){
  int r;
  r = num % 2;
  if(num >= 2){
    dtb(num/2);
  }
  putchar(r + '0');
}

int main(){
    int i;
    char c;
    int a;
    char s[10];
    printf("%d\n",0x3e8);
    return 0;
}