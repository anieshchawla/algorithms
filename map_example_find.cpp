#include <iostream>
#include <map>

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

int main ()
{
  std::map<int,Node*> mymap;
  std::map<int,Node*>::iterator it;
Node head(0,0);
Node first(11,100);
head.next = &first;
first.prev = &head;
Node second(12,200);
second.prev = &first;
first.next = &second;
mymap[11] = &first;
mymap[12] = &second;
it = mymap.find(12);
std::cout<<"size is "<<mymap.size()<<'\n';
if(it != mymap.end()){
    std::cout<<"mymap[11] value is = "<<it->second->value<<'\n';
}
else{
  std::cout<<"couldn't find what is requested"<<'\n';
}

  // mymap['a']=50;
  // mymap['b']=100;
  // mymap['c']=150;
  // mymap['d']=200;
// int second = mymap.find('b')->second;
//   it = mymap.find('b');
//   if (it != mymap.end())
//     mymap.erase (it);

  // print content:
  // std::cout << "elements in mymap:" << '\n';
  // std::cout << "a => " << mymap.find('a')->second << '\n';
  // std::cout << "c => " << mymap.find('c')->second << '\n';
  // std::cout << "d => " << mymap.find('d')->second << '\n';
  // std::cout <<"second =>"<<second<<'\n';

  return 0;
}
