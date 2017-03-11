#include <iostream>
#include <map>
using namespace std;
int m=1000000007;
map<long long,long long> Byte;

int byte (long long int n)
{
    if(Byte.count(n))return Byte[n];
    long long int k=n/2;
    long long int b=byte(k-1)%m;
    long long int c=byte(k-2)%m;
    long long int a=(c+b)%m;
    long long int d=(a+b)%m;
    if(n%2==0)return Byte[n]=((a*b)%m+(b*c)%m)%m;
    if(n%2==1)return Byte[n]=((d*b)%m+(a*c)%m)%m;
}

int main()
{
    int t;
    cin>>t;
    int j;
    int A[1000];
    Byte[0]=1;
    Byte[1]=2;
    Byte[2]=3;
    Byte[3]=5;
    for(j=0; j<t; j++)
    {
        long long int n;
        cin>>n;
        A[j]=byte(n);
    }
    for(j=0; j<t; j++)cout<<A[j]<<endl;
}
