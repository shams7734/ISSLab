/*	Cracking of monoalphabetic cipher.No input to be taken from user.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k,l;
	int count=0;
	char a[50]="abcdefghijklmnopqrstuvwxyz";
	char text[10]="abcd";
	char crack[10];
	for(i=0;i<26;i++)
	{
		crack[0]=a[i];
		for(j=0;j<26;j++)
		{
			crack[1]=a[j];
			for(k=0;k<26;k++)
			{
				crack[2]=a[k];
				for(l=0;l<26;l++)
				{
					crack[3]=a[l];
					count++;
					if( strcmp(crack,text) == 1 )
					{
						printf("Cracked in %d iterations\n",count-1);
						exit(0);
					}
				}
			}
		}
	}
	printf("Cracked in %d iterations\n",count);
}
