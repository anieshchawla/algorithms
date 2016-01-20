#include <iostream>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test>0){
      test --;
    	int number;
    	cin>>number;
    	for(int i=1;i<=number;i++){
        bool print_num = true;
    		if(i%3==0){
    			cout<<"Fizz";
          print_num = false;
    			}
    		if(i%5==0) {
          cout<<"Buzz";
          print_num = false;
        }
    		if(print_num){
    			cout<<i;
    		}
    		cout<<endl;
    	}
    }
    return 0;
}
