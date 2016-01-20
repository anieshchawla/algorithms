#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

bool func_q(int *array,int i,int sum){
	if(i<0) return false;
	if(*(array+i)==sum)	return true;
	else{
		 bool ans1= func_q(array,i-1,sum);
		 if(ans1) return true;
		 else{
		 	bool ans2= func_q(array,i-1,sum - *(array+i));
			if(ans2) return true; 	
		 }
		return false;
	}
}

int main(){
	int testcase;
	cin>>testcase;
	while(testcase>0){
		testcase--;
		int no_of_items,sum=0;
		cin>>no_of_items;
		int items[no_of_items] ;
		for(int i=0;i<no_of_items;i++){
			cin>>items[i];
			sum+=items[i];
		}
		if((sum%2) !=0 ) cout<<"NO"<<endl;
		else{
			int sum_in_single_box = sum/2;
			bool ans;
			for(int i=0;i<no_of_items;i++){
				ans = func_q(items,i,sum);
				if(ans) {
					cout<<"YES"<<endl;
					break;
				}
			}
			if(!ans) cout<<"NO"<<endl;
		}
	}
}