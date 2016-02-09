#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test;
    cin>>test;
    while(test){
        test--;
        vector<int> input_nos;
        int num;
        cin>>num;
        for(int i=0;i<num;i++){
            int inp;
            cin >> inp;
            input_nos.push_back(inp);
        }
        sort(input_nos.begin(),input_nos.end());
        int count=1,max_count=1;
        for(int i=1;i<input_nos.size();i++){
            if((input_nos[i] == (input_nos[i-1]+1))) count++;
            else if(input_nos[i] == input_nos[i-1]) continue;
            else{
                if(count>max_count) max_count = count;
                count=1;
            }
            if(count >  max_count) max_count = count;
        }
        cout<<max_count<<endl;
    }
    return 0;
}
