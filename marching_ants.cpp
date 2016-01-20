#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;


std::vector<pair<int,int> > merge(vector<pair<int,int> > &ant){
	int size = ant.size();
	if(size==1)return ant;
	vector<pair<int, int> > res;
	res.pb(ant[0]);
	for(int i=1;i<size;i++){
		if(ant[i].first <= res.back().second){
			res.back().second = max(ant[i].second,res.back().second);
		}
		else{
			res.pb(ant[i]);
		}
	}
	return res;

}

int main() {
	int N;
	cin>>N;
	int x,y,d,ans=0;
	std::vector<pair<int,int> > ant_x_cordinate;
	for(int i=0;i<N;i++){
		cin>>x>>y>>d;
		ant_x_cordinate.pb(mp(x,x+d));
	}
	sort(ant_x_cordinate.begin(),ant_x_cordinate.end());
	ant_x_cordinate =  merge(ant_x_cordinate);
	for(int j=0;j<ant_x_cordinate.size();j++){
		ans+=(ant_x_cordinate[j].second - ant_x_cordinate[j].first +1);
	}
	cout<<ans<<endl;

	return 0;
}
