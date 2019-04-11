

//Implementation of FCFS Scheduling algorithm
//Time complexity: O(n^2)


#include <iostream>

using namespace std;

int main()
{
    int n;

    //Taking inputs
    cout<<"Enter the no of processes: ";
    cin>>n;
    int ct=0,t;
    int p[n],a[n],b[n],c[n];
    cout<<"Enter the arrival time and burst time of the processes respectively:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        p[i]=i;
    }

    //Sorting the given process based on arrival time
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t = a[j];a[j] = a[j+1];a[j+1] = t;
                t = b[j];b[j] = b[j+1];b[j+1] = t;
                t = p[j];p[j] = p[j+1];p[j+1] = t;
            }
        }
    }

    //Formulating gnatt chart
    cout<<"Gnatt Chart:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"P"<<p[i]<<"("<<ct<<"-";
        ct+=b[i];c[i]=ct;
        cout<<ct<<")"<<" ";
    }

    //Printing completion order
    cout<<"Completion Order:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<"P"<<p[i]<<" ";
    }
    cout<<endl;

    //Calculating waiting time
    float s=0;
    for(int i=2;i<=n;i++)
    {
        s+=(c[i-1]-a[i]);
    }
    cout<<"Average Waiting Time: "<<(s/n)<<endl;

    //calculating turn around time
    s=0;
    for(int i=1;i<=n;i++)
    {
        s+=c[i]-a[i];
    }
    cout<<"Average Turn Around Time: "<<(s/n)<<endl;
    return 0;
}
