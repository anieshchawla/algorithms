#include<iostream>
using namespace std;

class Test
{
private:
	int *ptr;
	const char* ch;
public:
	Test (int i = 0,char *name ="")	 { ptr = new int(i);ch = name; }
	~Test();
	void setValue (int i) { *ptr = i; }
	void print()		 { cout << *ptr<<" char "<<ch << endl; }
	Test & operator = (const Test &t);
};
Test::~Test(){
	delete ptr,ch;
}

Test & Test::operator = (const Test &t)
{
// Check for self assignment
if(this != &t){
	*ptr = *(t.ptr);
	ch = (t.ch);
}
return *this;
}

int main()
{
	Test t1(100,"aniesh");
	Test t2;
	t2 = t1;
	t1.setValue(10);
	t2.print();
	return 0;
}