#include <stdio.h>

int floatFloat2Int(unsigned uf) {
  int sign = uf >> 31;  //由于uf是无符号数，这里只可能是0或1
  int exp = ((uf & 0x7f800000) >> 23) - 127;
  int frac = (uf & 0x007fffff) | 0x00800000;  //需要加上1
  //int t = (uf & 0x7f80000) ;
  //printf("%x %d\n",t,t);
  printf("%x %d\n",exp,exp);
  printf("%x %d\n",frac,frac);
  if(exp < 0)
    return 0;
  if(!(uf & 0x7fffffff))
    return 0;
  if(exp > 31) //NaN or infinite
    return 0x80000000;
  if(exp > 23)
    frac = frac << (exp - 23);
  else 
    frac = frac >> (23 - exp);
    printf("%x %d\n",frac,frac);
  if(frac >> 31)
    return 0x80000000;
  else if(sign)
    return ~frac + 1;
  else 
    return frac;
}

int main(){
    int out;
    unsigned uf = 0x3f800001;
    out = floatFloat2Int(uf);
    //printf("%f\n",0x3f800000);
    printf("%x %d\n",out,out);
    return 0;
}