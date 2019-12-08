#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid,burst_time_1,burst_time_2,io_time,arrival_time,arrival,rt;
    bool done,io;
    bool operator<(const process& p) const
    {
        if(this->rt == p.rt)
            return this->arrival < p.arrival;
        return this->rt < p.rt;
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
    cout<<"\n Enter the details for "<<pno<<" processes <id  arrival_time  burst_time_1 io_time burst_time_2> : \n";
    for(int i=0; i<pno; i++)
    {
        cout<<"\n     Process "<<i+1<<" : ";
        cin>>temp.pid>>temp.arrival_time>>temp.burst_time_1>>temp.io_time>>temp.burst_time_2;
        temp.rt = temp.burst_time_1 + temp.burst_time_2;
        temp.arrival = temp.arrival_time;
        temp.done = temp.io = false;
        job.push_back(temp);
    }
    set<struct process>::iterator it;
    vector<struct process>::iterator i;
    float wt,tat;
    wt=tat=0.0;
    int waiting_time, turn_around_time, completion_time;
    cout <<"\n\n"<<setw(5)<<"PID"<<setw(5)<<"AT"<<setw(5)<<"BT1"<<setw(5)<<"IO"<<setw(5)<<"BT2"<<setw(5)<<"CT"<<setw(5)<<"TAT"<<setw(5)<<"WT"<< endl;
    int j=0,t;
    while(pno>0)
    {
        for (i = job.begin(); i != job.end(); i++)
        {
            if( (*i).arrival_time == j && !(*i).done)
            {
                p.insert((*i));
                (*i).done = true;
            }
        }
        if(!p.empty())
        {
            it=p.begin();
            temp=(*it);
            p.erase(it);
            temp.rt--;
            if(temp.rt <= 0)
            {
                pno--;
                completion_time = j + 1;
                turn_around_time = completion_time - temp.arrival;
                waiting_time = turn_around_time - (temp.burst_time_1+temp.burst_time_2);
                wt+=waiting_time;
                tat+=turn_around_time;
                cout <<"\n"<<setw(5)<<temp.pid<<setw(5)<<temp.arrival_time<<setw(5)<<temp.burst_time_1<<setw(5)<<temp.io_time<<setw(5)<<temp.burst_time_2<<setw(5)<<completion_time<<setw(5)<<turn_around_time<<setw(5)<<waiting_time<< endl;
            }
            else if(temp.rt <= temp.burst_time_2 && !temp.io)
            {
                for (i = job.begin(); i != job.end(); i++)
                {
                    if( (*i).pid == temp.pid)
                    {
                        (*i).done = false;
                        (*i).io = true;
                        (*i).arrival_time = j + 1 + (*i).io_time;
                        (*i).rt = temp.rt;
                    }
                }
            }
            else
                p.insert(temp);
            j++;
        }
        else
            j++;
    }
    float avg_wt,avg_tat;
    avg_wt = wt / nop;
    avg_tat = tat / nop;
    cout<<"\n\n Average Waiting Time     : "<<avg_wt;
    cout<<"\n Average Turn Around Time : "<<avg_tat;
    cout<<"\n\n";
    return 0;
}
