#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid,burst_time,arrival_time,rt;
    bool done;
};

int main()
{

    int i,pno,nop,q = 2;
    cout<<"\n Enter number of processes : ";
    cin>>pno;
    nop = pno;
    vector<struct process> p;
    struct process temp;
    cout<<"\n Enter the details for "<<pno<<" processes <id  arrival_time  burst_time> : \n";

    for(i=0; i<pno; i++)
    {
        cout<<"\n     Process "<<i+1<<" : ";
        cin>>temp.pid>>temp.arrival_time>>temp.burst_time;
        temp.rt= temp.burst_time;
        p.push_back(temp);
    }

    int it=0;
    float wt,tat;
    int st=0;
    wt=tat=0.0;

    int waiting_time, turn_around_time, completion_time,cs=0;

    cout <<"\n\n"<<setw(5)<<"PID"<<setw(5)<<"AT"<<setw(5)<<"BT"<<setw(5)<<"CT"<<setw(5)<<"TAT"<<setw(5)<<"WT"<< endl;


    int j=0;
    bool  flag = false;
    while(pno>0)
    {
        if(p[it].rt <= q && p[it].rt > 0)
        {
            j+=p[it].rt;
            p[it].rt = 0;
            flag = true;
        }
        else if(p[it].rt>0)
        {
            j += q;
            p[it].rt-=q;
        }

        if(p[it].rt==0 && flag)
        {
            pno--;

            completion_time = j;
            turn_around_time = completion_time - p[it].arrival_time;
            waiting_time = turn_around_time - p[it].burst_time;

            wt+=waiting_time;
            tat+=turn_around_time;
            cout <<"\n"<<setw(5)<<p[it].pid<<setw(5)<<p[it].arrival_time<<setw(5)<<p[it].burst_time<<setw(5)<<completion_time<<setw(5)<<turn_around_time<<setw(5)<<waiting_time<< endl;
            flag = false;
        }


        if (it == nop-1)
        {
            it =0;
        }
        else if( p[it+1].arrival_time <= j)
        {
            it++;
        }
        else
        {
            it = 0;
        }

    }

    float avg_wt,avg_tat;

    avg_wt = wt/nop;
    avg_tat = tat/nop;

    cout<<"\n\n Average Waiting Time     : "<<avg_wt;
    cout<<"\n Average Turn Around Time : "<<avg_tat;
    cout<<"\n\n";

    return 0;
}
