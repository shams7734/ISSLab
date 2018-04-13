/*	Decryption of caeser cipher . Plain text is given in the code and also the key is fixed.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[50]="abcdefghijklmnopqrstuvwxyz";
	char b[50]="defsabc";
	char c[50];
	int i,j,k,key=3;
	printf("input string is %s \n",b);
	j=strlen(b);
	for(i=0;i<j;i++)
	{
		for(k=0;k<26;k++)
		{
			if(b[i]==a[k])
			{
				c[i]=a[(k+26-key)%26];
			}
				
		}	
	}
	printf("Decrypted string is %s \n",c);
}
