

//Implementation of SJF-II Scheduling algorithm
//Time complexity: O(n^2)


#include <iostream>

using namespace std;

int main()
{
    int n;
    //taking inputs
    cout<<"Enter the no of processes: ";
    cin>>n;
    int ct=0,t,i,j,s=0;
    int p[n],a[n],b[n],c[n];
    //Sorting of the given inputs
    cout<<"Enter the arrival time and burst time of the processes respectively:"<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        p[i]=i;s+=b[i];c[i]=b[i];
    }
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
    int com[n],k,cal[n],mi,q[s];
    j=1;k=0;
    int ctr, pCtr=-1;
    //Making Gnatt Chart..
    cout<<"Gnatt Chart:"<<endl;
    while(s>0){

        //Finding min..
        mi = 9999;
        for(i=1;i<=n;i++){
            if((a[i]<=ct)&&(b[i]<mi)&&(b[i]>0)){
                t = i;mi = b[i];
            }
        }
        //Selecting process..
        ctr = p[t];
        if (pCtr!=ctr) {
            if (pCtr==-1) { cout << "P"<<ctr<<"("<< ct<<"-";}
            else if (s>1){
                cout << ct<< ") ";
                cout << "P"<<ctr<<"("<< ct<<"-";
            } else { cout << ct+1<< ") "; }
        } else {
            if (s==1) { cout << ct+1<< ") "; }
        }
        //Decreasing burst time and increasing the current time..
        b[t]-=1;ct+=1;
        s--;

        pCtr = ctr;//Setting current process on pCtr in order to make the proper Gnatt Chart..

        if(b[t]==0){
            cal[t] = ct;com[j++] = t;
        }

    }
    float wt=0,tat=0;
    for(i=1;i<=n;i++){
        wt+=(cal[i]-c[i]-a[i]);//Calculating waiting time
        tat+=(cal[i]-a[i]);//Calculating turn around time
    }
    //Completion Order printing...
    cout<<"Completion Order:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<"P"<<com[i]<<" ";
    }
    cout<<endl;
    //Waiting Time printing...
    cout<<"Waiting time: "<<(wt/n)<<endl;
    //Turn Around Time printing...
    cout<<"Turn Around time: "<<(tat/n)<<endl;
    return 0;
}
