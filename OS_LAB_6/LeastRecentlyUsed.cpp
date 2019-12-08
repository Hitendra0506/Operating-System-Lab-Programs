#include<bits/stdc++.h>
using namespace std;
int main()
{
    int fno=3,pno=20;
    int pages[20]= {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int frames[3]= {0};
    list<int> f;
    f.resize(fno,0);
    int i,j,k = 0,lru;
    for(i=0; i<pno; i++)
    {
        if(find(f.begin(),f.end(),pages[i])!=f.end())
        {
            cout<<"\n HIT ";
            f.remove(pages[i]);
            f.push_back(pages[i]);
        }
        else
        {
            cout<<"\n MIS ";
            k++;
            lru = f.front();
            f.pop_front();
            f.push_back(pages[i]);
            for(j=0; j<fno; j++)
            {
                if(lru == frames[j])
                {
                    frames[j] = pages[i];
                    break;
                }
            }
        }
        cout<<" >> Page: "<<pages[i]<<" =>";
        for(j=0; j<fno; j++)
                 cout<<"  "<<frames[j];
        }
    cout<<"\n\n Page Fault : "<<k<<"\n\n";
    return 0;
}

