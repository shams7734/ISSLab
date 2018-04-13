/*	Monoalphabetic cipher . Plain text is given in the code.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,len;
	char a[50]="abcdefghijklmnopqrstuvwxyz";
	char b[50]="pqdbezstucaxfihlkynrgmjowv";
	char text[50]="abcpqrxyz";
	char c[50];
	len=strlen(text);
	printf("Plain text is %s\n",text);
	for(i=0;i<len;i++)
	{
		for(j=0;j<26;)
		{
			if(text[i]==a[j])
			{
				c[i]=b[j];
				j++;
			}
			else 
				j++;
		}
	}
	c[i]='\0';
	printf("Cipher text is %s\n",c);
}
