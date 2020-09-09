#include <iostream>
using namespace std;

/*²Î¿¼£ºhttps://blog.csdn.net/qq_33557479/article/details/50886653*/

long int a[32] = {0}; 

void helper(){
	a[0] = 1;
	a[2] = 3;
	for(int i = 4;i < 32;i+=2){
		a[i] = 4*a[i-2] - a[i-4];
	}
}

int main(){
	int x;
	helper();
	while(cin>>x){
		if(x == -1) break;
		cout<<a[x]<<endl;
	}
	return 0;
}
