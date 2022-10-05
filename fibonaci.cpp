#include<iostream>
using namespace std;
int main()
{
	int num;
	int first=0,second=1,third;
	cout<<endl<<"Enter the Series Element No::::";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		if(i<=1)
		{
			third=i;
		}
		else
		{
			third=first+second;
			first=second;
			second=third;
		}
		cout<<endl<<third<<"\t";
	}
	return 0;
}



