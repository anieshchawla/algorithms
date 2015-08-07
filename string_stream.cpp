#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
   // Complete this function
    vector<int> ints_vec;
    char ch;
    stringstream ss(str);
    int check;
    ss>>check;
    //ints_vec.push_back(check);
    while(ss){
        ints_vec.push_back(check);
        ss>>ch>>check;
    }
    return ints_vec;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
