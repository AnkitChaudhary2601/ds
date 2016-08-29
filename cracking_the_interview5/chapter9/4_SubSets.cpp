#include<cstdio>
#include<vector>

using namespace std;

vector<vector<int> > getAllSubSets(int n){
	
	if(n==0) {
		vector<vector<int> > v;
		return v;
	}

	vector<vector<int> > subset = getAllSubSets(n-1);
	vector<vector<int> > sets(subset);
	for(int i=0; i<subset.size();i++){
		subset[i].push_back(n);
		sets.push_back(subset[i]);
	}
	vector<int> v;
	v.push_back(n);
	sets.push_back(v);
	return sets;
}

vector<int> convertIntToSet(int arr[], int n){
	vector<int> set;
	int index = 0;
	for(int i=1; i<=n ; i <<= 1){ // left shift i 
		if((n&i) == i) // if ith bit is set then include arr[index]
			set.push_back(arr[index]);
		index++;
	}
	return set;
}

vector<vector<int> > getAllSubSets2(int arr[], int n){
	vector<vector<int> > allSubSets;
	if(n<=0) {
		return allSubSets;
	}
	
	int max = 1<<n;
	for(int i=0; i<max; i++){
		vector<int> subsets = convertIntToSet(arr, i);
		allSubSets.push_back(subsets);
	}

	return allSubSets;
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d", arr+i);

	vector<vector<int> > sets = getAllSubSets2(arr, n); 
	for(int i=0;i<sets.size();i++){
		printf("Subset %d : ", i);
		for(int j=0;j<sets[i].size() ;j++){
			printf("%d ", sets[i][j]);
		}
		printf("\n");
	}
}