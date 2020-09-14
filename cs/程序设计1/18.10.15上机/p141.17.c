#include <stdio.h>
int main()
{
	char a,b,c;
	for(a='x';a<='z';a++)
	  {
	    if(a=='x')continue; 
	    for(b='x';b<='z';b++)
	      {
	        if(a==b)continue;
	        for(c='x';c<='z';c++)
			  {
	      		if(c=='x'||c=='z')continue;
	      		if(b==c||a==c)continue;
	      		printf("A-%c\nB-%c\nC-%c\n",a,b,c);
		      }
		  }
	  }
	return 0;
}
