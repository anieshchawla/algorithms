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
class LRUCache: public Cache {
  public:  LRUCache(int capacity);
    //~LRUCache();
    // Node* tail; // double linked list tail pointer
    // Node* head; // double linked list head pointer
    void set(int,int);
    int get(int);
};
LRUCache::LRUCache(int capacity){
    cp = capacity;
    head = new Node(0,0);
    tail = new Node(0,0);
     head->next = tail;
    // head->prev=NULL;
     tail->prev=head;
    // tail->next=NULL;
}
void LRUCache::set(int key,int value){
  map<int,Node*>::iterator it = mp.find(key);
  if (mp.size()==0){
    Node *present= new Node(head,tail,key,value);
    head->next = present;
    tail->prev = present;
    mp[key] = present;
  }
  else {
    if(it!=mp.end()){
      Node *present = it->second;
      present->prev->next = present->next;
      present->next->prev = present->prev;
      present->next = head->next;
      head->next->prev = present;
      head->next = present;
      present->prev = head;
      present->value = value;
    }
    else{

      if(mp.size() < cp){
        Node *present = new Node(head,head->next,key,value);
        head->next->prev = present;
        head->next = present;
        mp[key] = present;
      }
      else{

        map<int,Node*>::iterator del_node = mp.find(tail->prev->key);
        tail->prev = tail->prev->prev;
        Node *present= new Node(head,head->next,key,value);
        head->next->prev = present;
        head->next = present;
        mp[key] = present;
        delete del_node->second;
        mp.erase(del_node);
      }
    }
  }
}
int LRUCache::get(int key){
  int value=-1;
  map<int,Node*>::iterator it;
  it = mp.find(key);
  if(it != mp.end()){
    value = it->second->value;
    set(key,value);
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
