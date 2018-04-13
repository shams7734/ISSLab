/*	Implementation of IDEA 
	2015kucp1034
*/
#include<bits/stdc++.h>
using namespace std;

// Function to convert binary to integer

int convertBinaryToInt(int *a,int n)
{                           
    int x=0,i;
    for(i=0;i<n;i++){
        x = x + a[i]*pow(2,(n-1)-i);
    }
    return x;
}

//Function to convert integer to binary

void convertIntToBinary(long int x,int *a,int n)
{                    
    int i;
    for(i = 0;i<n;i++){
        a[n-1-i] = (x%2);
        x = x/2;
    }
}

int main()
{
	int i,j,l;
	int key[128]={1,0,0,0,1,0,1,0,0,1,1,1,
				  0,0,1,1,1,1,0,1,1,0,1,1,
				  1,1,1,0,1,1,0,1,0,1,1,1,
				  0,0,0,1,0,1,0,1,0,1,1,0,
				  1,0,1,0,1,1,1,0,1,0,0,0,
				  1,0,0,0,1,1,0,0,1,0,1,1,
				  1,0,1,1,1,0,1,0,0,0,1,0,
				  0,0,0,1,0,1,1,1,0,1,0,1,
				  1,1,1,0,1,1,1,0,1,1,0,1,
				  1,0,1,0,1,1,1,0,0,1,0,1,
				  0,1,0,1,0,1,1,1	
				 };
				 
	int text[64]={1,1,0,1,1,1,0,1,
				  0,0,1,1,0,1,0,1,
				  0,1,0,1,1,1,0,1,
				  0,1,1,1,0,1,0,0,
				  1,0,1,1,1,0,1,0,
				  1,1,1,1,0,0,1,1,
				  0,1,1,0,1,1,1,0,
				  1,1,1,0,0,0,1,0
				 };
	int key_mod[128];
	int small_texts[4][16];			 
	int small_keys[52][16];
	
	
	l=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<16;j++)
		{
			small_keys[i][j]=key[l];
			l++;
		}
	}
	
	// key rotation first
	
		for(j=0;j<128;j++)
		{
			key_mod[j]=key[(j-25+128)%128];
		}

	for(i=0;i<128;i++)
		key[i]=key_mod[i];
	
	
	l=0;
	for(i=8;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			small_keys[i][j]=key[l];
			l++;
		}
	}
	
	// key rotation second
	
		for(j=0;j<128;j++)
		{
			key_mod[j]=key[(j-25+128)%128];
		}
	
	for(i=0;i<128;i++)
		key[i]=key_mod[i];
	
	
	l=0;	
	for(i=16;i<24;i++)
	{
		for(j=0;j<16;j++)
		{
			small_keys[i][j]=key[l];
			l++;
		}
	}	
		
	// key rotation third
	
		for(j=0;j<128;j++)
		{
			key_mod[j]=key[(j-25+128)%128];
		}
	
	for(i=0;i<128;i++)
		key[i]=key_mod[i];
	
	
	l=0;	
	for(i=24;i<32;i++)
	{
		for(j=0;j<16;j++)
		{
			small_keys[i][j]=key[l];
			l++;
		}
	}		
		
	// key rotation four
	
		for(j=0;j<128;j++)
		{
			key_mod[j]=key[(j-25+128)%128];
		}
	
	for(i=0;i<128;i++)
		key[i]=key_mod[i];
	
	
	l=0;	
	for(i=32;i<40;i++)
	{
		for(j=0;j<16;j++)
		{
			small_keys[i][j]=key[l];
			l++;
		}
	}		
		
	// key rotation five
	
		for(j=0;j<128;j++)
		{
			key_mod[j]=key[(j-25+128)%128];
		}
	
	for(i=0;i<128;i++)
		key[i]=key_mod[i];
	
	
	l=0;	
	for(i=40;i<48;i++)
	{
		for(j=0;j<16;j++)
		{
			small_keys[i][j]=key[l];
			l++;
		}
	}		
		
	// key rotation six
	
		for(j=0;j<128;j++)
		{
			key_mod[j]=key[(j-25+128)%128];
		}
	
	for(i=0;i<128;i++)
		key[i]=key_mod[i];
	
	
	l=0;	
	for(i=48;i<52;i++)
	{
		for(j=0;j<16;j++)
		{
			small_keys[i][j]=key[l];
			l++;
		}
	}		

// Texts in 16 bits 
	
	l=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<16;j++)
		{
			small_texts[i][j]=text[l];
			l++;
		}
	}
		
	// The IDEA encryption process consist of the following 14 steps in each of the 8 rounds .
	
		
		long int k[52]={0};
		long int p[4]={0};
		long int status=0;
		long int step1=0,step2=0,step3=0,step4=0,step7=0,step8=0,step9=0,step10=0;
		int temp[16]={0},temp1[16]={0};
		int step5[16]={0},step6[16]={0},step11[16]={0},step12[16]={0},step13[16]={0},step14[16]={0};
		for(j=0;j<52;j++)
		{
			k[j]=convertBinaryToInt(small_keys[j],16);
			
		}	
		
		
	for(i=0;i<8;i++)
	{
		
		p[4]={0};
		step1=0,step2=0,step3=0,step4=0,step7=0,step8=0,step9=0,step10=0;
		step5[16]={0},step6[16]={0},step11[16]={0},step12[16]={0},step13[16]={0},step14[16]={0};
		
			for(j=0;j<4;j++)
			{
				p[j]=convertBinaryToInt(small_texts[j],16);
			}
					
			//  step 1
		
			step1=(p[0]*k[0+(i*6)]) % 65537 ;
			
			//   step 2
			
			step2=(p[1]+k[1+(i*6)]) % 65536 ;
			
			//  step 3
			
			step3=(p[2]+k[2+(i*6)]) % 65536 ;
			
			//    step 4
			
			step4=(p[3]*k[3+(i*6)]) % 65537 ;
			
			//  step 5
			
			convertIntToBinary(step1,temp,16);
			convertIntToBinary(step3,temp1,16);
			for(j=0;j<16;j++)
				step5[j]=temp[j]^temp1[j];
				
			//   step6
			
			temp[16]={0};temp1[16]={0};
			convertIntToBinary(step2,temp,16);
			convertIntToBinary(step4,temp1,16);
			for(j=0;j<16;j++)
				step6[j]=temp[j]^temp1[j];
				
			//   step 7
			
			status=convertBinaryToInt(step5,16);
			step7=(status*k[4+(i*6)]) % 65537 ;
			
			//   step 8
			
			status=0;
			status=convertBinaryToInt(step6,16);
			step8=(status+step7) % 65536 ;
			
			//  step 9
			
			step9=(step8*k[5+(i*6)]) % 65537 ;
			
			//  step 10
			
			step10=(step7+step9) % 65536 ;
			
			// step 11
			
			small_texts[0][16]={0};
			temp[16]={0};temp1[16]={0};
			convertIntToBinary(step1,temp,16);
			convertIntToBinary(step9,temp1,16);
			for(j=0;j<16;j++)
			{
				step11[j]=temp[j]^temp1[j];
				small_texts[0][j]=step11[j];
			}
			
				
			//  step 12
			
			small_texts[1][16]={0};
			temp[16]={0};temp1[16]={0};
			convertIntToBinary(step3,temp,16);
			convertIntToBinary(step9,temp1,16);
			for(j=0;j<16;j++)
			{
				step12[j]=temp[j]^temp1[j];
				small_texts[1][j]=step12[j];
			}
			
			//   step 13
			
			small_texts[2][16]={0};
			temp[16]={0};temp1[16]={0};
			convertIntToBinary(step2,temp,16);
			convertIntToBinary(step10,temp1,16);
			for(j=0;j<16;j++)
			{
				step13[j]=temp[j]^temp1[j];
				small_texts[2][j]=step13[j];
			}
				
			//   step 14
			
			small_texts[3][16]={0};
			temp[16]={0};temp1[16]={0};
			convertIntToBinary(step4,temp,16);
			convertIntToBinary(step10,temp1,16);
			for(j=0;j<16;j++)
			{
				step14[j]=temp[j]^temp1[j];
				small_texts[3][j]=step14[j];
			}
				
			
			
	}
	
	//   Output generation process
	
		status=0;
		//  step 1
		
		step1=0;
		status=convertBinaryToInt(small_texts[0],16);
		step1=(status*k[0+(i*6)]) % 65537 ;
		
		status=0;
		//  step 2
		
		step2=0;
		status=convertBinaryToInt(small_texts[1],16);
		step2=(status+k[1+(i*6)]) % 65536 ;
		
		status=0;
		//  step 3
		
		step3=0;
		status=convertBinaryToInt(small_texts[2],16);
		step3=(status+k[2+(i*6)]) % 65536 ;
		
		status=0;
		//  step 4
		
		step4=0;
		status=convertBinaryToInt(small_texts[3],16);
		step4=(status*k[3+(i*6)]) % 65537 ;

	//	Printing the cipher text
	
		temp[16]={0};temp1[16]={0};
		printf("The cipher text in binary is \n");
		convertIntToBinary(step1,temp,16);
		convertIntToBinary(step2,temp1,16);
		for(j=0;j<16;j++)
			printf("%d ",temp[j]);
		printf("\n");
		for(j=0;j<16;j++)
			printf("%d ",temp1[j]);
		printf("\n");
	
		temp[16]={0};temp1[16]={0};
		convertIntToBinary(step1,temp,16);
		convertIntToBinary(step2,temp1,16);
		for(j=0;j<16;j++)
			printf("%d ",temp[j]);
		printf("\n");
		for(j=0;j<16;j++)
			printf("%d ",temp1[j]);
		printf("\n");
		
}
