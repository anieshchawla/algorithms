#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    cin>>n>>m;
    int weighted_path_array[n][n];
    while(m>0){
      int node1,node2,weight;
      cin>>node1>>node2>>weight;
      weighted_path_array[node1][node2]=weight;
      weighted_path_array[node2][node1]=weight;
    }
    int starting_node;
    cin>>starting_node;
    
    return 0;
}
