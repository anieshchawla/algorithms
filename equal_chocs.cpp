#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Test;
    cin>>Test;
    while(Test){
    	Test--;
    	int N,count = 0,count2=0;
    	std::vector<int> chocs_with_people;
    	cin>>N;
    	while(N){
    		int cointern_choc;
    		cin>>cointern_choc;
    		chocs_with_people.push_back(cointern_choc);
    		N--;
    	}
    	N = chocs_with_people.size();
    	sort(chocs_with_people.begin(),chocs_with_people.end());
    	int increased_by = 0;
    	for(int i = 0;i<N-1;i++){
    		int check = chocs_with_people[i+1]+increased_by - chocs_with_people[i];
    		if(check){
    			int que5 = check/5;
    			int rem2 = (check%5)/2;
    			int rem1 = (check%5)%2;
    			count += que5+rem2+rem1;
    			increased_by = que5*5+rem2*2+rem1;
    			//cout<<"increased_by "<<increased_by<<" que5 "<<que5<<" rem2 "<<rem2<<" rem1 "<<rem1<<" check "<<check<<endl;
    		}
    	}
    	chocs_with_people[0]-=1;
    	increased_by=0;
    	for(int i = 0;i<N-1;i++){
    		int check = chocs_with_people[i+1]+increased_by - chocs_with_people[i];
    		if(check){
    			int que5 = check/5;
    			int rem2 = (check%5)/2;
    			int rem1 = (check%5)%2;
    			count2 += que5+rem2+rem1;
    			increased_by = que5*5+rem2*2+rem1;
    			//cout<<"increased_by "<<increased_by<<" que5 "<<que5<<" rem2 "<<rem2<<" rem1 "<<rem1<<" check "<<check<<endl;
    		}
    	}
    	if(count>(count2+1)) cout<<count2+1<<endl;
    	else cout<<count<<endl;

    }   
    return 0;
}
