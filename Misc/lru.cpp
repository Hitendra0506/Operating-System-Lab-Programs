#include<bits/stdc++.h> 
using namespace std; 

int main() 
{ 

	int fno=3,pno=20;
	int pages[20]={1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	
	set<int> pg; 
	set<int>::iterator it;

	map<int, int> recent; 

	int i,j,k = 0; 
	
	for (i=0; i<pno; i++) 
	{ 
		if (pg.size() < fno) 
		{ 
			if (pg.find(pages[i])==pg.end()) 
			{ 
				pg.insert(pages[i]); 
				k++; 
			} 
			recent[pages[i]] = i; 
		} 

		
		else
		{ 
			if (pg.find(pages[i]) == pg.end()) 
			{ 
				int lru = INT_MAX, val; 
				for (it=pg.begin(); it!=pg.end(); it++) 
				{ 
					if (recent[*it] < lru) 
					{ 
						lru = recent[*it]; 
						val = *it; 
					} 
				} 

				pg.erase(val); 

				pg.insert(pages[i]); 

			        k++; 
			} 

			recent[pages[i]] = i; 
		} 
	}

        cout<<"\n Page Fault : "<<k<<"\n\n"; 
	return 0; 
} 

