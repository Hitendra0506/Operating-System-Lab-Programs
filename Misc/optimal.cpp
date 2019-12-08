#include <bits/stdc++.h> 
using namespace std; 


bool search(int key, vector<int>& fr) 
{ 
	for (int i = 0; i < fr.size(); i++) 
		if (fr[i] == key) 
			return true; 
	return false; 
} 


int predict(int pg[], vector<int>& fr, int pn, int index) 
{ 
	
	int res = -1, farthest = index; 
	for (int i = 0; i < fr.size(); i++) { 
		int j; 
		for (j = index; j < pn; j++) { 
			if (fr[i] == pg[j]) { 
				if (j > farthest) { 
					farthest = j; 
					res = i; 
				} 
				break; 
			} 
		} 

		
		if (j == pn) 
			return i; 
	} 

	
	return (res == -1) ? 0 : res; 
} 

	


int main() 
{ 
	int page[20]={1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	int pno = 20; 
	int fno = 3; 
	
	vector<int> frames; 

	
	int hit = 0; 
	for (int i = 0; i < pno; i++) { 

		
		if (search(page[i], frames)) { 
			hit++; 
			continue; 
		} 

		

		 
		if (frames.size() < fno) 
			frames.push_back(page[i]); 

		
		else { 
			int j = predict(page, frames, pno, i + 1); 
			frames[j] = page[i]; 
		} 
	} 
	cout << "\n\n Page Fault : " << pno - hit <<"\n\n"; 
	return 0; 
} 

