#include <iostream>
using namespace std;

int main(){
	int n,x;
	cin>>n;
	while(n>0){
		cin>>x;
		int a = 2,b;
		if(x == 1) b = 2;		
		for(int i = 2;i <= x;i++){
			b = a + (i-1)*6;
			a = b;
		}
		cout<<b<<endl;
		n--;
	}
	return 0;
} 
