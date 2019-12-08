#include<bits/stdc++.h>
using namespace std;
int main()
{
    int fno=3,pno=20,i,j,k = 0,opt,f;
    int pages[20]= {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6},frames[3]= {0};

    for(i=0; i<pno; i++)
    {
        if(find(frames,frames+3,pages[i])!=frames+3)
            cout<<"\n HIT ";
        else
        {
            cout<<"\n MIS ";
            k++;
            f=INT_MIN;
            for(j=0; j<fno; j++)
            {
                if(find(pages+i,pages+20,frames[j]) != pages+20)
                    f = max(f,find(pages+i,pages+20,frames[j])-pages);
                else
                {
                    opt = frames[j];
                    break;
                }
                opt = pages[f];
            }
            for(j=0; j<fno; j++)
            {
                if(opt == frames[j])
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

