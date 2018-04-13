/* Railfence encrytpion.
   User needs to enter the text without space and the key .  
*/
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
	int i,j,key,size,status=0;
	char text[100];
	printf("Enter the plain text\n");
	scanf("%s",text);
	size=strlen(text);
	printf("Enter the key\n");
	scanf("%d",&key);
	vector<char> ch[key];
	j=0;
	
	for(i=0;i<size;i++)
	{
		if(j==0)
			{status=0;}
		if(j==key-1)
			{status=1;}
		
		if(status==0)
		{
			ch[j].push_back(text[i]);
			
		}
		else if(status==1)
		{
			ch[j].push_back(text[i]);
		}
		(status==0)?j++:j--;
		
		
	}
	
	for(i=0;i<key;i++)
		{
			for(auto it=ch[i].begin();it!=ch[i].end();it++)
			{
				printf("%c",*it);
			}
	
		}
		printf("\n");
}
