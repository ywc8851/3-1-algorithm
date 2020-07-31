#include <fstream> 
#include <iostream> 
using namespace std; 
 
int main() {
	int tree[1001][2];  
	int level[1001]; 
	int cnt[1001]; 
	int n; 
	ifstream ifs("input.txt"); 
	ifs >> n; 
	while (n--) {   
		
		for (int i = 0; i <= 1001; i++) { 
			
			tree[i][0] = 0; 
			tree[i][1] = 0; 
			level[i] = 0; 
			cnt[i] = 0; 
		} 
		level[1] = 1; // loot level=1 
		int node; 
		ifs >> node;  
		for (int i = 0; i < node; i++) { 
	         
			int parent, child1, child2; 
			ifs >> parent >> child1 >> child2; 
			if (child1 != -1) { 
				tree[parent][0] = child1; 
			    level[child1] = level[parent] + 1; 
			} 
			else { 
				tree[parent][0] = child1; 
			}  
			if (child2 != -1) { 
				tree[parent][1] = child2; 
				level[child2] = level[parent] + 1; 
			} else {
				tree[parent][1] = child2; 
			} 
		} 
		int max_level = 0; 
		for (int i = 1; i <= node; i++) { 
			cnt[level[i]]++; 
			if (max_level < level[i]) max_level = level[i]; 
		} int result = 0;
		for (int i = 1; i <= max_level; i++) { 
			if (result < cnt[i]) { 
				result = i; 
			}
		}  
		cout << result << '\n'; 
	} 
}

