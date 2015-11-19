#include <iostream>

using namespace std;

class Link{
private: 
	Link *prev;
	Link *next;
public:
	string value;
	Link(const string&val,Link *p=0;Link *s=0):  value(val),prev(p),next(s){}
	Link * insert(Link *n);
	Link * add(Link *n);
	Link * erase (Link *n);
	const Link *find(const string &s);
	Link *advance(int n);



};
Link *
Link::insert(Link *n){
	Link *p = this;
	if(n==0) return p;
	if(p==0) return n;
	

}
