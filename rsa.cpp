/*	Program to implement RSA
	User needs to input two prime numbers as asked and a character
	2015kucp1034
*/
#include<bits/stdc++.h>
using namespace std;
int prime(int a)
{
	int i;
	for(i=2;i<a;i++)
	{
		if( a%i==0 )
			return 0;
	}
	return 1;
}

int random_e(int p,int q)
{
	int b;
	b=rand() %100 + 100;
	if( b%(p-1)==0 || b%(q-1)==0 )
		b=random_e(p,q);
	return b;
}

int random_d(int p,int q,int e)
{
	int b;
	b=rand() %100 + 100;
	if( (b*e)%((p-1)*(q-1)) == 1 )
		b=random_d(p,q,e);
	return b;
}

int main()
{
	int p,q,i,j,n;
	long int d,e;
	long int ct,pt;
	int status=0,status1=0;
	char ch;
	printf("Enter two prime numbers p and q between 99 and 999\n");
	scanf("%d %d",&p,&q);
	
	if(p<99 || p>999 || q<99 ||q>999)
	{
		printf("Please enter number in range\n");
		return 0;
	}
	
	i=prime(p);
	if(i==0)
		status=1;
		
	j=prime(p);
	if(j==0)
		status1=1;
	
	if(status==1 || status1==1)
	{
		printf("Number entered are not prime number\n");
		return 0;
	}
	
	//   Calculate n
	
	n=p*q;
	
	// Generate random number e
	
	srand(time(NULL));
	e=random_e(p,q);
	printf("random e %ld\n",e);
	
	// Generate random number d
	
	//srand(time(NULL));
	d=random_d(p,q,e);
	printf("random d %ld\n",d);
	
	//   finding CT
	
	printf("Enter any character\n");
	cin>>ch;
	
	long int sum=0;
	pt=(int)ch;
	for(i=0;i<e;i++)
		sum=sum+pt;
	ct=sum;
	
	ct=ct%n;
	cout<<"Cipher text is "<<(char)ct<<endl;
	
	// finding PT
	
	sum=0;
	for(i=0;i<d;i++)
		sum=sum+ct;
	pt=sum;
	pt= pt%n;
	printf("Decrypted text is in int %ld\n",pt);
	
}
