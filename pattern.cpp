#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"size: ";
    cin>>size;
    int arr[size];
    cout<<"enter elements: ";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    int x;
    cout<<"value of x:";
    cin>>x;
    for(int i=0; i<size;i++)
    {
        
        sum=sum+arr[i]*pow(x,i);
    }
    cout<<"answer is: "<<sum;
    return 0;
}