#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    if(t<1 || t>10)
    {
        return 0;
    }
    for(int i=0;i<t;i++)
    {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int sum=0;
    int flag =1 ;
    for(int x=a+1;x<=c;x++)
    {
    for(int y=b+1;y<=d;y++)
    {
            if( (x*y)%(a*b) == 0)
            {
                
              cout<<x<<" "<<y<<endl;
              flag=1;
              if(flag == 1){
        break;
    }
    else{
        continue;
    }
            }
            
            else
            {
                sum++;
            }
    }
    
    }
    
    if(sum==(c-a)*(d-b))
    {
        cout<<"-1"<<" "<<"-1"<<endl;
    }
    }
    return 0;
}