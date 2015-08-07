#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		T--;
		int n,k,count=1,bit_flip_count=0;
		scanf("%d %d",&n,&k);
		cout<<"the value of n "<<n<<" k "<<k<<endl;
		int array[n],new_array[n];
		scanf("%d",&array[0]);
		for(int i=1;i<n;i++){
			scanf("%d",&array[i]);
			if(array[i]==array[i-1]){
				count++;
			}
			else{
				count=1;
			}
			if(count%k==0){
				array[i]&=1;
				bit_flip_count++;
				count=1;
			}

		}
		cout<<"bit_flip_count "<<bit_flip_count<<endl;
	}
	return 0;
}