#include<iostream>
using namespace std;


int main(){
    int x = 256+97;
    int *y = &x;
    char *z = (char *)y;
    cout<<*z<<endl;

}

