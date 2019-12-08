#include<bits/stdc++.h>
using namespace std;

int main()
{
    int fno=3,pno=20;
    int pages[20]= {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int frames[3]= {0};
    int i,j,k=-1;

    for(i=0; i<pno; i++)
    {
        for(j=0; j<fno; j++)
        {
            if(frames[j]==pages[i])
                break;
        }

        if(j==fno)
        {
            k++;
            frames[k%3]=pages[i];
            cout<<"\n MIS ";
        }
        else
            cout<<"\n HIT ";

        cout<<" >> Page: "<<pages[i]<<" =>";
        for(j=0; j<fno; j++)
        {
            cout<<"  "<<frames[j];
        }
    }
    cout<<"\n\n Page Fault : "<<k+1<<"\n\n";
    return 0;
}
