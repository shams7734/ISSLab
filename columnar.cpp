/*  Implementation of Single Columnar Transportation Technique.
	In this user needs to input the number of column and the plain text .
	2015kucp1034
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,k,key;
	int length;
	char str[100];
	printf("Enter number of columns\n");
	scanf("%d",&key);
	vector<char > ch[key];
	printf("Enter the plain text\n");
	scanf("%s",str);
	length=strlen(str);
	
	k=0;
	
	for(i=0;k<length;)
	{
		if(i==key)
			i=0;
		ch[i].push_back(str[k]);
		i++;k++;
	}
	
	printf("The encrypted text\n");
	for(i=0;i<key;i++)
	{
		for(auto it=ch[i].begin();it<ch[i].end();it++)
		{
			printf("%c",*it);
		}
	}
	printf("\n");
}
