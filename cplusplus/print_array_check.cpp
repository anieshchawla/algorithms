#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

void func_q(int *input_array,int sum, int no_of_items){
	if(no_of_items==0) return;
	for(int i=0;i<no_of_items;i++) {
		cout<<*(input_array+i);
	}
	cout<<endl;
	return;

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
		
		int sum_in_single_box = sum/2;
		for(int i=0;i<no_of_items;i++){
			func_q((int *)(items+i),sum_in_single_box,no_of_items-i);	
		}
		
	}
}