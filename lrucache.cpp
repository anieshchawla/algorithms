#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache: public Cache{
    LRUCache(int capacity);
    ~LRUCache;
    private: int present_capacity;
};
LRUCache::LRUCache(int capacity){
    cp = capacity;
    present_capacity=0;
    head->next=NULL;
    head->prev=NULL;
    tail->prev=NULL;
    tail->next=NULL;
}
void LRUCache::set(int key,int value){

}
int LRUCache::get(int key){
  Node* start = head;
  int value=-1;
  map<int,Node*>::iterator it;
  it = mp.find(key)->second;
  if(it != mp.end()){
    value = it->second->value;
  }
  return value;
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
