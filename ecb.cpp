/*  Implementation of ECB encryption and decryption .
	2015kucp1034
*/
#include<bits/stdc++.h>
using namespace std;

int  main()
{
	int i,j,len,len1;
	int temp=0,temp1=0;
	string text="jai maheshmati";
	string key="shams ali";
    string buffer[20],buffer1[20];
    
    cout<<"Text is : "<<text<<endl;
    cout<<"Key is : "<<key<<endl;
   
	//  Giving padding by a to plain text
	len=text.length();
	temp=len%8;
	for(i=0;i<8-temp;i++)
	{
		text=text+"a";
	}
	len=text.length();
	cout<<"Text after padding with 'a' is : "<<text<<endl;
	
	// Text to Binary Conversion
	
	int asci[len];
	for(i=0;i<len;i++)
	{
		asci[i]=text[i];
	}
	
	cout<<"Text in binary is : "<<endl;
	for(i=0;i<len;i++)
	{
		ostringstream oss;
		oss<<bitset<8>(asci[i]);
		buffer[i]=oss.str();
		//cout<<buffer[i]<<endl;
	}
	
	temp=len/8;
	string small_text[temp];
	for(i=0;i<temp;i++)
	{
		small_text[i]=text.substr(i*8,(i+1)*8);
		
	}
	
	//  Giving padding by a to key
	
	len1=key.length();
	temp1=len1%8;
	for(i=0;i<8-temp1;i++)
	{
		key=key+"a";
	}
	len1=key.length();
	cout<<"Key after padding with 'a' is : "<<key<<endl;
	
	// Key to Binary Conversion
	
	int asci1[len1];
	for(i=0;i<len1;i++)
	{
		asci1[i]=key[i];
	}
	for(i=0;i<len1;i++)
	{
		ostringstream oss;
		oss<<bitset<8>(asci1[i]);
		buffer1[i]=oss.str();
			
	}
	
	temp1=len1/8;
	string small_key[temp];
	for(i=0;i<temp1;i++)
	{
		small_key[i]=key.substr(i*8,(i+1)*8);
		
	}
	
	
	//  Performing XOR operation
	
	string cipher_buffer[20];
	
	for(i=0;i<len1;i++)
	{
		for(j=0;j<8;j++)
		{
			
			if( (buffer[i][j]=='1') && (buffer1[i][j]=='1') )
			{
				cipher_buffer[i]+="0";
				
			}
				
			else if( (buffer[i][j]=='0') && (buffer1[i][j]=='0') )
			{
				cipher_buffer[i]+="0";
				
			}
				
			else 
			{			
				cipher_buffer[i]+="1";	
			}
		}
		
	}
	
	//   Output 
	
	int cipher[len][8];
	cout<<"Output in binary is "<<endl;
	
	for(i=0;i<len;i++)
	{
		for(j=0;j<8;j++)
		{
			cipher[i][j]=cipher_buffer[i][j]-48;
			cout<<cipher[i][j]<<" ";
		}
			
		cout<<endl;
	}
	
	//  Decryption  process
	
	string plain_text[len];
	
	for(i=0;i<len1;i++)
	{
		for(j=0;j<8;j++)
		{
			
			if( (buffer1[i][j]=='1') && (cipher_buffer[i][j]=='1') )
			{
				plain_text[i]+="0";
				
			}
				
			else if( (buffer1[i][j]=='0') && (cipher_buffer[i][j]=='0') )
			{
				plain_text[i]+="0";
				
			}
				
			else 
			{			
				plain_text[i]+="1";	
			}
		}
		
	}
	
	//   Decryption output
	
	int cipher1[len][8];
	cout<<"Decrypted text in binary is "<<endl;
	
	for(i=0;i<len;i++)
	{
		for(j=0;j<8;j++)
		{
			cipher1[i][j]=plain_text[i][j]-48;
			cout<<cipher1[i][j]<<" ";
		}
			
		cout<<endl;
	}
	
}
