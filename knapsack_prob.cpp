/*Mr. Dorsey Dawson recently stole X grams of gold from ACME Jewellers. He is now on a train back home. To avoid getting caught by the police, he has to convert all the gold he has into paper money. He turns into a salesman and starts selling the gold in the train.

There are N passengers who have shown interest in buying the gold. The ith passenger agrees to buy ai grams of gold by paying $_vi_. Dawson wants to escape from the police and also maximize the profit. Can you help him maximize the profit?

Note: The ith passenger would buy exactly ai grams if the transaction is successful.

Input Format 
The first line contains two space separated integers, N _X_, where N is the number of passengers who agreed to buy and X is the stolen amount of gold (in grams). 
N lines follow. Each line contains two space separated integers - vi and ai, where vi is the the value which the ith passenger has agreed to pay in exchange for ai grams of gold.

Output format: 
If it's possible for Dorsey to escape, print the maximum profit he can enjoy, otherwise print "Got caught!" (quotes are for clarity)

Constraints 
1 <= X <= 5000 
1 <= N <= 106 
all vi's and ai's are less than or equal to 106 and greater than 0.

Sample input #00

4 10
460 4
590 6
550 5
590 5
Sample output #00

1140
Sample input #01

4 9
100 5
120 10
300 2
500 3
Sample output #01

Got caught!*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//int cache[5002][1000002];

int max_profit(int grams, int money_offering[][2],int present_candidate,int profit,int max_candidate){
	if (grams==0) return profit;
	if(grams < 0) return 0;
	if(max_candidate < present_candidate) return 0;
	//if(cache[grams][present_candidate-1]!=0) return cache[grams][present_candidate-1];
	int present_value_offered = money_offering[present_candidate][0];
	int grams_taken = money_offering[present_candidate][1];
	present_candidate++;
	return max(max_profit(grams - grams_taken,money_offering,present_candidate,profit+present_value_offered,max_candidate), max_profit(grams,money_offering,present_candidate,profit,max_candidate));

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int grams,people_interested;
    cin>>people_interested>>grams;
    int money_bid[people_interested][2];
    for(int i=0;i<people_interested;i++){
    	cin>>money_bid[i][0]>>money_bid[i][1];
    }
    int ans = max_profit(grams,money_bid,0,0,people_interested-1);
    if(ans>0) cout<<ans<<endl;
    else cout<<"Got caught"<<endl;

    return 0;
}