#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   int n;
   for(int k = 0 ; k < t ; k++)
   { 
    int count=0;
    string s;
    cin>>n;
    cin>>s;
      
       while(int i=1){
         for(int j=0;j<n;j++){
            
        
              if(s[j]==0 && j >=1)
              {
                s[j]=1;
                count++;
              }
            else if(s[j]==1 && j>=1)
            {
                s[j]=0;
                count++;
            }
            else if(s[0]==0)
            {
                s[0]=1;
            }
            else
            {     

                continue;
            }
          cout<<count<<endl;
         }
         i--;
       }
            
        
   }
  return 0;
} 