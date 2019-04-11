

//Implementation of RoundRobin Scheduling algorithm
//Time complexity: O(n^2)


#include <iostream>

using namespace std;

int main()
{
    int n;
    //Taking inputs for processes..
    cout<<"Enter the no of processes: ";
    cin>>n;
    int ct=0,t,tq,i,j,s=0,si=0;
    int p[n],a[n],b[n],c[n],cal[n],com[n],f[n];

    cout<<"Enter the arrival time and burst time of the processes respectively:"<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        p[i]=i;s+=b[i];c[i]=b[i];f[i] = 0;
    }
    si = s;
    cout<<"Enter the time quanta:"<<endl;cin>>tq;
    int q[s];

    //Sorting processes..
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t = a[j];a[j] = a[j+1];a[j+1] = t;
                t = b[j];b[j] = b[j+1];b[j+1] = t;
                t = p[j];p[j] = p[j+1];p[j+1] = t;
            }
        }
    }
    j = 1;
    int k=1;

    while(s>0){


        //Enqueueing for the first time only..
        if(s==si)
        {
            t=j;
            for(i=1;i<=n;i++){
                if((ct>=a[i])&&(b[i]!=0)&&(f[i]!=1)){
                    //enqueue
                    q[j++] = p[i];f[i] = 1;
                }
            }
        }
        //calculating current time, decrementing burst time

        if(b[q[t]]<tq)
        {
            //Considering those process who have current burst time less than time quanta...
            ct+=b[q[t]];s-=b[q[t]];b[q[t]]=0;cal[q[t]] = ct;com[k++] = q[t];

        }

        else{
            b[q[t]]-=tq;ct+=tq;s-=tq;

            for(i=1;i<=n;i++){
            if((ct>=a[i])&&(b[i]!=0)&&(f[i]!=1)){
                //Process selection and enqueue
                q[j++] = p[i];f[i] = 1;
            }
        }
            if(b[q[t]]==0){ cal[q[t]]=ct;com[k++] = p[q[t]]; }
            else{
                    //dequeue
                    q[j++] = q[t];
            }
        }
        t=t+1;


    }
    //forming gnatt chart
    cout<<"Gnatt Chart:"<<endl;
    int tmp=0;
    for(i=1;i<j;i++){
        cout<<"P"<<q[i]<<"("<<tmp<<"-";
        tmp+=tq;
        if(cal[q[i]]<tmp)
        {
            tmp-=tmp-cal[q[i]];
            cout<<tmp<<") ";
        }
        else
            cout<<tmp<<") ";
    }
    float wt=0,tat=0;
    for(i=1;i<=n;i++){
        wt+=(cal[i]-c[i]-a[i]);//calculating waiting time
        tat+=(cal[i]-a[i]);//calculating turn around time
    }
    cout<<endl;
    //Printing completion order
    cout<<"Completion Order:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<"P"<<com[i]<<" ";
    }
    cout<<endl;
    cout<<"Waiting time: "<<(wt/n)<<endl;
    cout<<"Turn Around time: "<<(tat/n)<<endl;

    return 0;
}
