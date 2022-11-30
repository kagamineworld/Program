#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a[1000],n,i,j,k;
	double exam=0;
	cout<<"请输入顾客个数以及分别输入他们需要的服务时间："<<endl;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++) 
	{
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
	}
    
	for(i=0;i<n;i++)
    {
		exam+=a[i]*(n-i);
        cout<<exam<<a[i]<<endl;
        // cout<<exam<<"+"<<a[i]<<"x"<<(n-i)<<"="<<(exam+=a[i]*(n-i))<<endl;
        
    }
    cout<<exam<<endl;
	cout<<setprecision(2)<<fixed<<"最小平均等待时间为:"<<exam/n<<endl;
	return 0;
}