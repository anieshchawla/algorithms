#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define mod_num 1000000007
#define ulli unsigned long long int
#define fori(n) for(ulli i = 0;i<n;i++)
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string input;
    cin>>input;
    ulli length = input.size();
    ulli mult_factor[length];
    ulli multple_10 = 1;
    fori(length){
    	if (i==0) mult_factor[i] = 1;
    	else mult_factor[i]=(mult_factor[i-1]+multple_10)%mod_num;
    	multple_10*=10;
    	multple_10%=mod_num;
    }
    ulli ans=0;
    fori(length){
    	ulli _input = (ulli)(input[i]-48);
    	ans+=(((i+1)*_input*mult_factor[length-i-1])%mod_num);
    	ans = ans%mod_num;
    }
    cout<<ans<<endl;


    return 0;
}
