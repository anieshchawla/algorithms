#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int max_sum(int * array, int length){
    int best_sum = 0,present_sum=0,val=0;
    for(int i=0;i<length;i++){
        val = present_sum+array[i];
        if(val>0) present_sum = val;
        else present_sum = 0;
        if(best_sum<present_sum) best_sum=present_sum;
    }
    return best_sum;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test;
    cin>>test;
    while(test){
        int n,sum_ncont=0,sum_cont=0,largest_value;
        cin>>n;
        int array[n];
        for(int i=0;i<n;i++){
            cin>>array[i];
            if(array[i]>0){
                sum_ncont+=array[i];
            }
            if(i==0) largest_value = array[i];
            if(largest_value < array[i]) largest_value = array[i];
        }
        if(largest_value < 0) {
            sum_ncont = largest_value;
            sum_cont = largest_value;
        }
        else{
            sum_cont = max_sum(array,n);
        }
        cout<<sum_cont<<" "<<sum_ncont<<endl;
        test --;
    }
    return 0;
}
