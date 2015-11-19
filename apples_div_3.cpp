#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(){
	int N,apple_count=0,count_all=0,count_non_div=0,lowest_two[2]={1001,1001};
	cin>>N;
	int apple_array[N];
	for(int i=0;i<N;i++){
		int apple;
		cin>>apple;
		count_all+=apple;
		if(apple%3==0) {
			apple_count+=apple;
			apple_array[i]=0;
		}
		else {
			apple_array[i]=apple;
			if(apple<lowest_two[1]){
				if(apple<lowest_two[0]) {
					lowest_two[1]=lowest_two[0];
					lowest_two[0]=apple;
				}
				else lowest_two[1]=apple;
			}
			count_non_div+=0;
		}
	}
/*cout<<"count_all "<<count_all<<endl;
cout<<"lowest "<<lowest_two[0]<<" 2nd lowest "<<lowest_two[1]<<endl;*/
	if(count_all%3==0){
		cout<<count_all<<endl;
	}
	else{
		int removed_apple=lowest_two[0];
		if((count_all - removed_apple)%3==0) cout<< (count_all-removed_apple)<<endl;
		else{
			if(lowest_two[1]!=1001){
				if((count_all- lowest_two[1])%3 == 0) cout<<(count_all- lowest_two[1] )<<endl;
				else cout<<(count_all- lowest_two[1]-removed_apple)<<endl;
			}
			else{
				cout<<apple_count<<endl;
			}
		}

	}
	return 0;
}