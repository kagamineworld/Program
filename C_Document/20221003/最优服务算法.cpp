#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a[1000],n,i,j,k;
	double exam=0;
	cout<<"������˿͸����Լ��ֱ�����������Ҫ�ķ���ʱ�䣺"<<endl;
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
	cout<<setprecision(2)<<fixed<<"��Сƽ���ȴ�ʱ��Ϊ:"<<exam/n<<endl;
	return 0;
}