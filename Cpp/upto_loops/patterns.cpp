#include<iostream>
using namespace std;

// Rectangle pattern
/*
int main(){

    int r,c ;
    cout<<"Input no of rows and coloumns\n";
    cin>>r>>c;

    for(int i = 1 ; i<= r; i++){
        for(int j=1;j<=c;j++){
            cout<<"*";
        }
        cout<<endl;
    }



    return 0;
}*/


//Hollow Rectangle pattern

int main(){

    int r,c ;
    cout<<"Input no of rows and coloumns : \n";
    cin>>r>>c;

    for(int i = 1 ; i<= r; i++){
        for(int j=1;j<=c;j++){
            if(i==1 || i == r){
            cout<<"*";
            }
            else if( j == 1 || j== c){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }



    return 0;
}