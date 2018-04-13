/*  Hill Cipher.
	User needs to input the plain text.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	 int i,j,k,r1,r2,c1,c2,status,temp=0,sum=0;
	 string a;
	 printf("Enter the plain text\n");
	 cin>>a;
	 char b[50]="abcdefghijklmnopqrstuvwxyz";
	 status=(int)a.length();
	 int mat2[status][1];
	 int mat1[status][status];
	 r1=status;
	 c1=status;
	 r2=status;
	 c2=1;
	 int ans[r1][c2];
	 
	 for(i=0;i<status;i++)
	 {
	 	for(j=0;j<26;j++)
	 	{
	 		if(a[i]==b[j])
	 			mat2[i][0]=j;
	 	}
	 }
	 
	 printf("Enter the elements of %d*%d matrix1\n",status,status);
	 for(i=0;i<r1;i++)
	 {
	 	for(j=0;j<c1;j++)
	 		scanf("%d",&mat1[i][j]);
	 }
	
	 if(c1==r2)
	 { 
		  for (i = 0; i < r1; i++) {
		  for (j = 0; j < c2; j++) {
		    for (k = 0; k < r2; k++) {
		      sum = sum + mat1[i][k]*mat2[k][j];
		    }
	 
		    ans[i][j] = sum;
		    sum = 0;
		  }
		  
		  }
		  
		  printf("Matrix after multiplication is\n");
		  
		  for(i=0;i<r1;i++)
		  {
	 	   	for(j=0;j<c2;j++)
	 	   		printf("%d\t",ans[i][j]);
	 	   	printf("\n");
	 	  }
	 	  
	 	  printf("Cipher matrix is\n");
	 	  for(i=0;i<r1;i++)
		  {
	 	   	for(j=0;j<c2;j++)
	 	   		printf("%d\t",ans[i][j]%26);
	 	   	printf("\n");
	 	  }
	 	  
	 	 printf("Cipher text is \t");
	 	 for(i=0;i<r1;i++)
	 	 {
	 	 	for(j=0;j<c2;j++)
	 	 	{
		 	 	temp=(ans[i][j]%26);
		 	 	printf("%c",b[temp]);
	 	 	}
	 	 }
	 	 printf("\n"); 
     }
	 
	 else
	 	printf("Matrix multiplication not possible\n");	
	
}
