 #include<iostream>
 using namespace std;
 /*int main(){

    char button;
    cout<<"Input a character : ";
    cin>>button;

    switch(button){
        case 'a':
        cout<<"Hello"<<endl;
        break;
        case 'b':
        cout<<"Namaste"<<endl;
        break;
        case 'c' :
        cout<<"Salut"<<endl;
        break;
        case 'd' :
        cout<<"Hola"<<endl;
        break;
        case 'e' :
        cout<<"Ciao"<< endl;
        break;

        default :
        cout<<"No a Valid Input";
    }



    return 0;
 }*/

 int main(){
    int n1,n2;
    cout<<"Input the 2 numbers : ";
    cin>>n1>>n2;

    char op ;
    cout<<"Input an operator";
    cin>>op;
    switch(op){
        
        case '+' :
            cout<<n1+n2<<endl;
        break;
        case'-' :
              cout<<n1-n2<<endl;
            break;
        case '*':
               cout<<n1*n2<<endl;
          break;
        case '/':
        cout<<n1/n2<<endl;
         break;
        default:
        cout<<"Enter a valid input ";
         break;
         
         }
      return 0 ;
 }