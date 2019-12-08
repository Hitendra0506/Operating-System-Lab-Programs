#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid,burst_time,arrival_time;
    bool done;
    bool operator<(const process& p) const
    {
        return this->burst_time < p.burst_time;
    }
};

int main()
{

    int pno,nop;
    cout<<"\n Enter number of processes : ";
    cin>>pno;
    nop=pno;
    vector<struct process> job;
    set<struct process> p;
    struct process temp;
    cout<<"\n Enter the details for "<<pno<<" processes <id  arrival_time  burst_time> : \n";

    for(int i=0; i<pno; i++)
    {
        cout<<"\n     Process "<<i+1<<" : ";
        cin>>temp.pid>>temp.arrival_time>>temp.burst_time;
        job.push_back(temp);
    }

    set<struct process>::iterator it;
    vector<struct process>::iterator i;

    float wt,tat;
    wt=tat=0.0;

    int waiting_time, turn_around_time, completion_time;

    cout <<"\n\n"<<setw(5)<<"PID"<<setw(5)<<"AT"<<setw(5)<<"BT"<<setw(5)<<"CT"<<setw(5)<<"TAT"<<setw(5)<<"WT"<< endl;

    int j=0,t;
    while(pno>0)
    {
        for (i = job.begin(); i != job.end(); i++)
        {

            if( (*i).arrival_time <= j && !(*i).done)
            {
                p.insert((*i));
                (*i).done = true;
            }
        }

        it=p.begin();
        temp=(*it);
        p.erase(it);
        j+=temp.burst_time;
        pno--;
        completion_time = j;
        turn_around_time = completion_time - temp.arrival_time;
        waiting_time = turn_around_time - temp.burst_time;

        wt+=waiting_time;
        tat+=turn_around_time;

        cout <<"\n"<<setw(5)<<temp.pid<<setw(5)<<temp.arrival_time<<setw(5)<<temp.burst_time<<setw(5)<<completion_time<<setw(5)<<turn_around_time<<setw(5)<<waiting_time<< endl;

    }


    float avg_wt,avg_tat;

    avg_wt = wt / nop;
    avg_tat = tat / nop;

    cout<<"\n\n Average Waiting Time     : "<<avg_wt;
    cout<<"\n Average Turn Around Time : "<<avg_tat;
    cout<<"\n\n";

    return 0;
}
