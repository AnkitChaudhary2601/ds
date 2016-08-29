#include<cstdio>
#include<cstring>

// using namespace std;

void swap(char* str, int i, int j){
	if(i == j) return;
	int tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

void rightShift(char* str, int i, int j){
	if(i == j) return;
	int tmp = str[j];
	for(int k=j; k>i ;k--)
		str[k] = str[k-1];
	str[i] = tmp;
}

void leftShift(char* str, int i, int j){
	if(i==j) return;
	int tmp = str[i];
	for(int k=i; k<j; k++)
		str[k] = str[k+1];
	str[j] = tmp;
}

void permute(char* str, int start, int end){
	if(start==end){
		printf("%s\n", str);
		return;
	}

    // for non sorted permutation
	for(int i=start; i<=end; i++){
		swap(str, start, i);
		permute(str, start+1, end);
		swap(str, start, i);
	}
}

void permuteSorted(char* str, int start, int end){
	if(start==end){
		printf("%s\n", str);
		return;
	}

	// for sorted order permutation
	for(int i=start; i<=end; i++){
		rightShift(str, start, i);
		permute(str, start+1, end);
		leftShift(str, start, i);
	}
}

// bug in below function, this will not print distinct, eg : aabb
void permuteDistinct(char* str, int start, int end){
	if(start==end){
		printf("%s\n", str);
		return;
	}

	for(int i=start; i<=end; i++){
		if(i==start || str[i]!=str[start]){
			printf("%d %d\n",start, i);
			swap(str, start, i);
			permuteDistinct(str, start+1, end);
			swap(str, start, i);
		}
	}
}

int main(){
	char str[101];
	scanf("%s", str);
	permuteDistinct(str, 0, strlen(str)-1);
}