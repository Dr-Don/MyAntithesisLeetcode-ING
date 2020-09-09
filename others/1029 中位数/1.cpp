 #include <iostream>
 #include <cmath>
 using namespace std;
 
 int main(){
 	int n,m,temp,res;
 	scanf("%d",&n);
 	temp = n+1;
 	
 	int a[temp];
 	for(int i = 0;i<n;i++){
	 	scanf("%d",&a[i]);	
	}
	cin>>m;
	int mid = (n+m+1)/2;
	int i = 0,cnt = 0;
	while(m > 0){
		scanf("%d",&temp);
		while(a[i] <= temp && i < n && mid){
			mid--;
			i++;			
		}
		if(mid == 0){
			res = a[--i];
			break;
		}
		mid--;
		if(mid == 0){
			res = temp;
			break;
		}
		m--;
	}
	if(mid){
		while(mid--){
			a[i++];
		}
		res = a[--i];
	}
	printf("%d",res);
	return 0;
 }
