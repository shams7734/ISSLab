/*  Modified caeser cipher 
	Input string is given in the code . The user only needs to enter the value of key.
*/
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	char a[50]="abcdefghijklmnopqrstuvwxyz";
	char b[50]="abcpxyz";
	char c[50];
	int i,j,k,key;
	printf("Enter the value of key\n");
	scanf("%d",&key);
	printf("input string is %s \n",b);
	j=strlen(b);
	for(i=0;i<j;i++)
	{
		for(k=0;k<26;k++)
		{
			if(b[i]==a[k])
			{
				c[i]=a[(k+26+key)%26];
			}
				
		}	
	}
	printf("Cipher string is %s \n",c);
}
