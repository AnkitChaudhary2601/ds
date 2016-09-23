#include<cstdio>
#include<climits>

using namespace std;

int kaden(int arr[], int n, int &start, int &end){
	if(n==0) return 0;
	int sum=0, ans = INT_MIN;
	end = -1;
	for(int i=0; i<n; i++){
		sum+=arr[i];
		if(sum < 0){
			localstart = i+1;
			sum = 0;
		}

		if(sum > ans){
			end = i;
			start = localstart;
			ans = sum;
		}
	}

	if(end == -1){
		for(int i=0; i<n; i++)
			if()
	}
}