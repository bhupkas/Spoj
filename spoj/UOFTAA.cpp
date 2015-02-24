#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;
int main()
	{
		int i,n,j;
		char S3[30],S1[30],S2[30];
		cin>>n;
		getchar();
		scanf("%s",S1);
		S3[0]='F';S3[1]='o';S3[2]='x';S3[3]='e';S3[4]='n';
		S3[5]='\0';
		while(n && (strcmp(S1,S3)))
			{
				n--;
				if(!strcmp(S1,"Scissors"))	{cout<<"Rock"<<endl;	}
				if(!strcmp(S1,"Fox"))		{cout<<"Foxen"<<endl;	}
				if(!strcmp(S1,"Rock"))		{cout<<"Paper"<<endl;	}
				if(!strcmp(S1,"Paper"))		{cout<<"Scissors"<<endl;}
				scanf("%s",S1);
			}
		return 0;
	}