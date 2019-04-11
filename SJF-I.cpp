

//Implementation of SJF-I Scheduling algorithm
//Time complexity: O(n^2)



#include <iostream>

using namespace std;

int main()
{
    int n;
    //Taking inputs
    cout<<"Enter the no of processes: ";
    cin>>n;
    int ct=0,t,i,j;
    int p[n],a[n],b[n],c[n];
    cout<<"Enter the arrival time and burst time of the processes respectively:"<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        p[i]=i;
    }

    //Sorting process based on their arrival time and burst time..
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if((a[j]>a[j+1])||((a[j]==a[j+1])&&(b[j]>b[j+1])))
            {
                t = a[j];a[j] = a[j+1];a[j+1] = t;
                t = b[j];b[j] = b[j+1];b[j+1] = t;
                t = p[j];p[j] = p[j+1];p[j+1] = t;
            }
        }
    }
    int com[n],mi;
    t = p[1];com[1] = p[1];ct+=b[1];c[1] = ct;p[1] = -1;
    int cou = n-1;j=2;

    //Forming gnatt chart..
    cout<<"Gnatt Chart:"<<endl;
    cout<<"P"<<p[1]<<"(0-"<<ct<<") ";
    while(cou>0){
        mi = 9999;

        //Calculating min..
        for(i=1;i<=n;i++){
            if((p[i]!=-1)&&(a[i]<=ct)&&(b[i]<mi)){
                t = i;mi = b[i];
            }
        }

        //Selecting process and incrementing current time
        cout<<"P"<<t<<"("<<ct<<"-";
        ct+=b[t];c[j] =ct;com[j] = p[t];p[t] = -1;j++;cou--;
        cout<<ct<<") ";
    }
    cout<<endl;
    //Printing completion order
    cout<<"Completion Order:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<"P"<<com[i]<<" ";
    }
    cout<<endl;
    float s=0;

    //calculating waiting time
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
