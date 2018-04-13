#include<bits/stdc++.h>
using namespace std;

void digital()
{
	char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char b[10]={'0','1','2','3','4','5','6','7','8','9'};
	int i,j,k,length,len=0;
	char *str[4],*str2[4];
	for(i=0;i<len;i++)
	{
		length=strlen(str[i]);
		for(k=0;k<length;k++)
		{
			for(j=0;j<26;j++)
			{
				if(str[i][k]==a[j])
				{
					str2[i][k]=a[(j+3+26)%26];
					k++;
				}
			}
		
			for(j=0;j<10;j++)
			{
				if(str[i][k]==b[j])
				{
					str2[i][k]=b[(j+3+10)%10];
					k++;
				}
			}
		}
	}
}

int main()
{
	int i,len=0,n;
	char *str[4];
	int *ab;
	//char *str2[4];
	
	FILE *fp;
	fp=fopen("file.txt","r");
    fscanf(fp,"%d",&n);
    ab=(int*)malloc((n+1)*sizeof(int));
    n=0;
    for(i=0;i<=n;i++)
    {
        fscanf(fp,"%d",&ab[i]);
    }
	//str[i]='\0';
	len=i-1;
	fclose(fp);
	
	
	fp=fopen("file1.txt","a");
	
	for(i=0;i<len;i++)
	{
		fprintf(fp,"%s\n",str[i]);
	}
	
	fclose(fp);
	
}
