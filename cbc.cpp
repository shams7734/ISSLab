/*  Implementation of CBC 
	Shams Ali
	2015KUCP1034
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j;
	int len,status;
	string text="welcome to cryptography and network security";
	string buffer[100];
	
	int temp[64];
	
	int iv[64]= { 1,0,1,0,1,0,1,0,
				  1,0,1,0,1,0,1,0,
				  1,0,1,0,1,0,1,0,
				  1,0,1,0,1,0,1,0,
				  1,0,1,0,1,0,1,0,
				  1,0,1,0,1,0,1,0,
				  1,0,1,0,1,0,1,0,
				  1,0,1,0,1,0,1,0,
				};
	
	//binary conversion of text
	
	len=text.length();
	status=len/8;
	cout<<len<<endl;
	int pt[status+1][64];
	
	int asci[len];
	for(i=0;i<len;i++)
	{
		asci[i]=text[i];
	}
	
	for(i=0;i<len;i++)
	{
		ostringstream oss;
		oss<<bitset<8>(asci[i]);
		buffer[i]=oss.str();
		//cout<<"binary "<<buffer[i]<<endl;	
	}
	
	for(j=0;j<status+1;j++)
	{
		for(i=0;i<8;i++)
		{
			pt[j][i]=buffer[0][i];
			pt[j][i+8]=buffer[1][i];
			pt[j][i+16]=buffer[2][i];
			pt[j][i+24]=buffer[3][i];
			pt[j][i+32]=buffer[4][i];
			pt[j][i+40]=buffer[5][i];
			pt[j][i+48]=buffer[6][i];
			pt[j][i+56]=buffer[7][i];
		}
	}
	
	
	int ct[64];
	int temp1[64];
	
	for(i=0;i<64;i++)
	{
		ct[i]=iv[i];
	}
	
	cout<<"Encrypted text is "<<endl;
	
	for(i=0;i<status+1;i++)
	{
		//  XOR process
	
		for(j=0;j<64;j++)
		{
			temp[j]=(pt[i][j]-48)^ct[j];
		}
		
		//  Key Encryption process
		
		for(j=0;j<64;j++)
		{
			temp1[j]=temp[(j+4)%64];
			ct[j]=temp1[j];
			printf("%d ",ct[j]);
		} 
		
		printf("\n");
		
	}
	
	// Output in BINARY is  Each 8 bit binary represents one character
	
	 /* 1 1 0 1 1 1 0 0  1 1 1 1 1 1 0 0  0 1 1 0 1 1 0 0  1 0 0 1 1 1 0 0  0 1 0 1 1 1 0 0  0 1 1 1 1 1 0 0  1 1 1 1 1 0 0 0
	    1 0 1 0 1 1 0 1 
	     	  
	    1 0 1 1 1 0 0 1  1 0 0 1 0 0 0 0  0 0 0 0 1 1 1 1  1 1 1 1 0 0 1 1  0 0 1 1 0 0 0 1  0 0 0 1 1 0 0 1  1 1 0 1 1 0 0 0 
	    1 1 0 1 1 0 1 0 
	    
		1 1 1 0 1 1 1 1  0 1 0 1 0 1 1 0  0 0 1 1 1 0 0 1  0 0 0 0 0 1 0 1  1 1 1 0 0 1 1 1  0 1 0 0 1 0 1 1  1 1 0 1 1 1 1 1 
		1 0 1 0 1 1 0 0 
		
		1 0 0 0 0 0 1 1  0 0 1 1 0 1 0 1  0 1 0 1 0 1 1 0  0 1 1 0 1 0 0 0  1 0 0 0 0 0 1 0  0 1 1 0 1 0 1 1  1 0 1 0 1 0 0 0 
	    1 1 0 0 1 0 0 1 
	    
		0 1 0 0 0 1 0 1  0 0 0 0 0 0 1 1  1 0 1 0 0 0 0 0  1 0 1 1 1 1 1 0  1 1 0 1 0 0 0 0  0 1 1 0 1 1 0 0  1 1 0 1 1 1 1 0  
		1 0 0 1 1 1 1 1 
		
		0 0 1 0 0 1 1 0  0 1 1 0 1 1 0 0  1 1 0 0 1 1 0 1  1 1 0 1 1 0 1 1  1 1 1 1 0 0 0 0  0 0 0 1 1 0 1 1  1 0 1 1 1 0 1 1  
		1 1 1 1 0 0 1 1

*/

}
