#include<iostream>
using namespace std;
int main()
{
    int table[6][2];
    for(int i=0;i<6;i++)
    {

    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=0;
    
    
   
    for(int i=1;i<n;i++)
    {
        count++;
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0)
        {
            count++;
            arr[j+1]=arr[j];
            j--;
        }
        count++;
        arr[j+1]=current;
    }
    table[i][0]=n;
    table[i][1]=count;
    
  
    cout<<endl;
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}