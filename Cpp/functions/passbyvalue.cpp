#include<bits/stdc++.h>
using namespace std;

void passbyvalue(int x);
void passbyreference(int *x);
int main()
{
    int betty =13;
    int sandy = 13;
    passbyvalue(betty);
    passbyreference(&sandy);
    cout<<betty<<endl;
    cout<<sandy<<endl;

}
void passbyvalue(int x){
    x =99;
}
void passbyreference(int *x){
    *x = 66;
}