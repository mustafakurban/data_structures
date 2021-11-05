#include <iostream>
#include <string.h>

#define STRCPY(s,s_ata,N) if(strlen(s) < N) strcpy(s_ata,s);  \
						 else			   strcpy(s_ata,"\0");


int main()
{
	char a[3],b[9];


	STRCPY("mustafa",a,3);
	STRCPY("Balim",b,9);

	printf("a matrix : %s,b matrix : %s",a,b);
}
