#include<iostream>
using namespace std;
/*int main(){
    for(int i = 0 ; i <=100;i++){
        if(i%3==0){
            continue;
        }
        cout<<i<<endl;
    }

}*/

/*
int main(){
    int n ;
    cin>>n;
    int i ;
    for(int i = 2; i<n;i++){
        if(n%i==0){
            cout<<"Non prime"<<endl;
            break;
        }
    }
    if (i==n) {
        cout<<"Prime"<<endl;
        }
    
    return 0;
}*/
int main(){
    
  
   
    int a,b;
    cin>>a>>b;
    
    for(int num=a;num<=b;num++){
        int i;
        for( i = 2; i<num;i++){
            if(num%i==0){
            
                 break;
            }
       }
    
    if (i==num){
        cout<<num<<endl;
        }
    }
    return 0;
}