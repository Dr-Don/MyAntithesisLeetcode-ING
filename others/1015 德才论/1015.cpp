#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
	int id;
	int dScore;
	int cScore;
	int sum;
}; 

bool mySort(Student a,Student b){
	return (a.sum == b.sum)?(a.dScore == b.dScore)?(a.id < b.id):(a.dScore > b.dScore):(a.sum > b.sum);	
}

int main(){
	int n,l,h;
	cin>>n>>l>>h;
	vector<Student> students1;
	vector<Student> students2;
	vector<Student> students3;
	vector<Student> students4;
	while(n>0){
		Student newS;
		cin>>newS.id>>newS.dScore>>newS.cScore;
		newS.sum = newS.cScore + newS.dScore;
		if(newS.cScore >= l && newS.dScore >=l){
			if(newS.cScore >= h && newS.dScore >= h) students1.push_back(newS);
			else if(newS.dScore >= h) students2.push_back(newS);
			else if(newS.cScore < h && newS.dScore < h && newS.cScore <= newS.dScore) students3.push_back(newS);
			else students4.push_back(newS);
		}		
		n--;
	}
	
	int len1 = students1.size();
	int len2 = students2.size();
	int len3 = students3.size();
	int len4 = students4.size();
	sort(students1.begin(),students1.end(),mySort);
	sort(students2.begin(),students2.end(),mySort);
	sort(students3.begin(),students3.end(),mySort);
	sort(students4.begin(),students4.end(),mySort);
	
	cout<<len1 + len2 + len3 + len4<<endl;
	for(int i = 0;i < len1;i++){
		cout<<students1[i].id<<" "<<students1[i].dScore<<" "<<students1[i].cScore;
		cout<<endl; 
	}
	for(int i = 0;i < len2;i++){
		cout<<students2[i].id<<" "<<students2[i].dScore<<" "<<students2[i].cScore;
		cout<<endl; 
	}
	for(int i = 0;i < len3;i++){
		cout<<students3[i].id<<" "<<students3[i].dScore<<" "<<students3[i].cScore;
		cout<<endl; 
	}
	for(int i = 0;i < len4;i++){
		cout<<students4[i].id<<" "<<students4[i].dScore<<" "<<students4[i].cScore;
		if(i != len4 - 1) cout<<endl; 
	}
	return 0;
}
