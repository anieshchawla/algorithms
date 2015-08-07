#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test>0){
		test--;
		int sudoku[9][9];
		for(int i=0;i<9;i++){
			for (int j=0;j<9;j++){
				scanf("%d",&sudoku[i][j]);
			}
		}
		vector<vector<vector<int> > > swap;
		
	}
	return 0;
}