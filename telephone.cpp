#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


int main(){
	int test;
	cin>>test;
	while(test>0){
		test--;
		int n,last_num=-1,count=0,num;
		cin>>n;
		cin>>num;
		for(int i=1;i<n;i++){
			int val;
			cin>>val;
			if (val!=num){
				if(last_num!=i-1){
					count+=2;
					last_num=i;
				}
				else count++;
				num=val;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
