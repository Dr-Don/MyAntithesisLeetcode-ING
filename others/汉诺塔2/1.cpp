#include <iostream>
#include <cmath>
using namespace std;

int dp[65];

int hanoi3(int n){
	if(n == 1) return 1;
	return hanoi3(n-1)*2+1;
}

void hanoi4(){
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for(int i = 3;i < 65;i++){
		int temp = 0xfffffff;
		for(int j = 1;j < i;j++){
			if(2*dp[j] + pow(2,i-j)-1 < temp)
				temp = 2*dp[j] + pow(2,i-j)-1 ;
		}
		dp[i] = temp;
	} 
}

int main(){
	int x;
	hanoi4();
	while(cin>>x){
		cout<<dp[x]<<endl;
	} 
	return 0;
} 
