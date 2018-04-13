/* Implementation of Playfair cipher
   User need to enter the key and plain text without space */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string key,plain_text;
	printf("Enter the key string.It will automatically be converted into uppercase\n");
	cin>>key;
	printf("Enter the plain text.It will automatically be converted into uppercase\n");
	cin>>plain_text;
	char table[5][5];
	int i,j,length;
	int row,column,count=0;
	int arr[26] = {0};
	string temp="";
	transform(key.begin(), key.end(),key.begin(), ::toupper);
	transform(plain_text.begin(), plain_text.end(),plain_text.begin(), ::toupper);
	length = key.length();

	for(i=0;i<length;i++)
	{
	    row = count/5;
        column = count%5;
	    if(arr[key[i]-65]==0 && (key[i] == 'I' || key[i] == 'J'))
        {
            count++;
            arr['J'-65] = arr['I'-65] = count;
            table[row][column] = 'I';
        }
		else if(arr[key[i]-65] == 0)
		{
			count++;
			arr[key[i]-65] = count;
			table[row][column] = key[i];
		}
	}
	
	
	for(i=count,j=0;i<25;i++)
	{
		row = i/5;
		column = i%5;
		for(;j<26;j++)
		{
			if(arr[j] == 0)
			{
				arr[j] = i+1;break;
			}
		}
		if(j != 9 )
		{
			table[row][column] = (char)(65+j);
		}
		else
		{
			arr[j] = arr[j-1];
			i--;
		}
		j++;
	}

	length = plain_text.length();
	string temp1 = plain_text;
    if(length%2 == 1)
    {
        temp1=temp1+'X';
        length++;
    }

    for(i=0;i<length;i++)
    {
        temp=temp+temp1[i];
        if(temp1[i] == temp1[i+1])
        {
            temp=temp+'X';
        }
        else
        {
            temp=temp+temp1[i];
        }
    }

	cout<<"The Key Matrix for "<<key<<" is "<<endl;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
        	printf("%d\t",table[i][j]);
        }
        printf("\n");
    }

    int row1,row2,column1,column2;
    string cipher="";
    for(i=0;i<length;i++)
    {
        char a=temp[i],b=temp[i++];
        row1=(arr[a-65]-1)/5;
        row2=(arr[b-65]-1)/5;
        column1=(arr[a-65]-1)%5;
        column2=(arr[b-65]-1)%5;
        if(row1 == row2)
        {
            a = table[row1][(column1+1)%5];
            b = table[row1][(column2+1)%5];
        }
        else if(column1 == column2)
        {
            a = table[(row1+1)%5][column1];
            b = table[(row2+1)%5][column1];
        }
        else
        {
            a = table[row1][column2];
            b = table[row2][column1];
        }
        cipher=cipher+a;
        cipher=cipher+b;
    }
    cout<<"The cipher text of "<<plain_text<<" using key "<<key<<" is "<<cipher<<endl;
}
