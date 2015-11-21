#include <iostream>
#include <deque>
#define FOR(start,end) for(int i=start;i<end;i++)
using namespace std;
int find_next_max(deque<int>* que){
  int max=0;
  FOR(0,(*que).size()){
    if(max<(*que)[i]) max = (*que)[i];
  }
  return max;
}
void printKMax(int arr[], int n, int k){
   //Write your code here.
    deque<int> subarray_que;
    int local_max=0;
    FOR(0,k){
      if(local_max < arr[i]) local_max = arr[i];
        subarray_que.push_front(arr[i]);
    }
    cout<<local_max;
    FOR(k,n){
      int pop_element = subarray_que[k-1];
      subarray_que.pop_back();
      if(pop_element == local_max) local_max = find_next_max(&subarray_que);
      if(local_max < arr[i]) local_max = arr[i];
      subarray_que.push_front(arr[i]);
      cout<<" "<<local_max;

    }
    cout<<'\n';


}
int main(){

   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
