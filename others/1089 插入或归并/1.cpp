#include <iostream>
#include <cstring>
using namespace std;

bool cmp(int *a,int *b,int n){
	for(int i = 0;i<n;i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}

bool isInsert(int *a,int *b, int n){
	int flag = false;
	int aa[n];
	memcpy(aa, a, n * sizeof(int));
	for(int i = 1;i < n;i++){
		int temp = aa[i];
		int k = i-1;
		while(k >= 0 && aa[k] > temp) k--;
		for(int j = i;j > k+1;j--){
			aa[j] = aa[j-1];
		}
		aa[k+1] = temp;
		if(!flag && cmp(aa,b,n)){
			flag = true;
			for(int i = 0;i < n;i++) b[i] = aa[i];
			continue;
		}
		if(flag){
			for(int i = 0;i<n;i++) b[i] = aa[i];
			return true;	
		} 
	}
	return flag;
} 

void merge(int* arr, int left, int mid, int right){
	int *a = new int[right - left + 1];
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			a[k++] = arr[i++];
		} else {
			a[k++] = arr[j++];
		}
	}
	while(i <= mid) a[k++] = arr[i++];
	while(j <= right) a[k++] = arr[j++];
	for (i = 0; i < k; i++) {
		arr[left++] = a[i];
	}
}

bool isMerge(int *a,int *b, int n){
	int flag = false;
	for(int i = 1;i < n;i += i){
		int left = 0;
		int mid = left + i - 1;
		int right = mid + i;
		while(right < n){
			merge(a,left,mid,right);
			left = right + 1;
			mid = left + i - 1;
			right = mid + i;
		}
		if(left < n && mid < n)
			merge(a,left,mid,n-1);
			
		if(!flag && cmp(a,b,n)){
			flag = true;
			for(int i = 0;i < n;i++) b[i] = a[i];
			continue;
		}
		if(flag){
			for(int i = 0;i < n;i++) b[i] = a[i];
			return true;	
		}		
	}
	return flag;
}

int main(){
	int n;
	cin>>n;
	int a[n],aa[n],b[n];
	for(int i = 0;i < n;i++){
		cin>>a[i];
		aa[i] = a[i];
	}
	for(int i = 0;i < n;i++){
		cin>>b[i];
	}
	
	if(isInsert(a,b,n)) cout<<"Insertion Sort"<<endl;
	else{
		cout<<"Merge Sort"<<endl;	
		isMerge(a,b,n);
	} 
	
	for(int i = 0;i < n;i++){
		cout<<b[i];
		if(i != n-1) cout<<" ";
	}
	
	return 0;
} 
