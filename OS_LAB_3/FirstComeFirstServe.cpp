#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid,burst_time,arrival_time;

    bool operator<(const process& p) const
    {
        return this->arrival_time < p.arrival_time;
    }
};

int main()
{

    int i,pno;
    cout<<"\n Enter number of processes : ";
    cin>>pno;

    set<struct process> p;
    struct process temp;
    cout<<"\n Enter the details for "<<pno<<" processes <id  arrival_time  burst_time> : \n";

    for(i=0; i<pno; i++)
    {
        cout<<"\n     Process "<<i+1<<" : ";
        cin>>temp.pid>>temp.arrival_time>>temp.burst_time;
        p.insert(temp);
    }

    set<struct process>::iterator it;

    float wt,tat;
    int st=0;
    wt=tat=0.0;

    int waiting_time, turn_around_time, completion_time;

    cout <<"\n\n"<<setw(5)<<"PID"<<setw(5)<<"AT"<<setw(5)<<"BT"<<setw(5)<<"CT"<<setw(5)<<"TAT"<<setw(5)<<"WT"<< endl;

    for (it = p.begin(); it != p.end(); it++)
    {
        waiting_time = max((st - (*it).arrival_time),0);
        turn_around_time = (*it).burst_time + waiting_time;
        completion_time = turn_around_time + (*it).arrival_time;
        st += (*it).burst_time;
        wt+=waiting_time;
        tat+=turn_around_time;
        cout <<"\n"<<setw(5)<<(*it).pid<<setw(5)<<(*it).arrival_time<<setw(5)<<(*it).burst_time<<setw(5)<<completion_time<<setw(5)<<turn_around_time<<setw(5)<<waiting_time<< endl;
    }

    float avg_wt,avg_tat;

    avg_wt = wt/pno;
    avg_tat = tat/pno;

    cout<<"\n\n Average Waiting Time     : "<<avg_wt;
    cout<<"\n Average Turn Around Time : "<<avg_tat;
    cout<<"\n\n";

    return 0;
}
