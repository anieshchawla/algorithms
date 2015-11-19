
#include "checking.hpp"
#include <signal.h>
/*#define size_of_me(type) (char *)(&type+1)-(char*)(&type)
*/
using namespace std;
typedef int* INT_PTR;

void segfault_catch(int signal, siginfo_t *si, void *arg){
	cout<<"there is seg fault at "<<si->si_addr<<endl;
	exit(0);
}

// template <typename type>
// 	int size_of_me(type T){
// 		return ((char*)(&T+1) - (char*)(&T));
// 	}
//
// checking_class::checking_class(){}
// checking_class::~checking_class(){}
// int
// checking_class::mult_node(struct node check_node){
// 	int ans = this->mult(check_node.i,check_node.i);
// 	return ans;
//
// }

int main()
{
	//---------------------------------------------------------------------------
/*	string name,temp;
	getline(cin,name);
	cout<<name<<endl;
	std::vector<string> v_names;
	stringstream ss(name);
	while(ss>>temp) v_names.push_back(temp);
	for(int i=0;i<v_names.size();i++){
		cout<<v_names[i]<<endl;
	}*/
//---------------------------------------------------------------------------

/*	cin.unsetf(ios::dec);
	cin.unsetf(ios::hex);
	cin.unsetf(ios::oct);*/
	/*int a,b,c,d;
	cin>>a>>hex>>b>>oct>>c>>d;
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;*/

//---------------------------------------------------------------------------
/*	char ch;
	while(cin.get(ch)){
		if(isspace(ch)) cout<<"space"<<endl;
		if(isdigit(ch)) cout<<"digit "<<ch<<endl;
		else if(isalpha(ch)) cout<<"alpha "<<ch<<endl;
		else cout<<"operator "<<ch<<endl;
	}*/
//---------------------------------------------------------------------------
	/*	int a =0;
		double d;
		cout<<"int size "<<size_of_me(a)<<" size of double "<<size_of_me(d) <<endl;*/
//---------------------------------------------------------------------------
/*unsigned long long int a = LLONG_MAX*2-1;
unsigned long long int b = LLONG_MAX*2;
check();
cout<<"value of b is "<<b<<endl;
//cout<<LLONG_MAX<<" "<<LLONG_MIN<<endl;
if(a<b) cout<<"this is happeneing"<<endl;*/
//---------------------------------------------------------------------------
/*const char *c = "/home/aniesh/Desktop/coding/input.txt";
const char *name = "README.md";
string final;
final = (string)c;
final.append("/"+(string)name);
//cout<<final<<endl;
int fd = open(c,O_WRONLY | O_APPEND);
cout<<fd<<endl;
if(fd<0) return 1;
close(fd);
ifstream ifs(c);
if(ifs.is_open())cout<<"file is open "<<endl;
int fl = open(c,O_WRONLY | O_APPEND);
if(fl<0) cout<<"we won't be able to open"<<endl;
else cout<<"fl is "<<fl<<endl;
close(fl);*/
//---------------------------------------------------------------------------
/*char *d = "hello babucha";
//d = (char *)malloc((sizeof(char)) * 50);
char s[10]="worldthi";
memcpy(d,s+2,8);
//d = (char*)(s);
cout<<"string is "<<d<<endl;
//free(d);*/
//---------------------------------------------------------------------------
/*node NO;
NO.i = 11212;
NO.ch = "hello world!!";
cout<<"NO.i= "<<NO.i<<" NO.ch= "<<NO.ch<<endl;
checking_class my_check;
int mul = my_check.mult_node(NO);
cout<<"mul= "<<mul<<endl;
	return 0;*/
//---------------------------------------------------------------------------
/*for(int i=0;i<10;i++) display();*/
//---------------------------------------------------------------------------
INT_PTR x ;
struct sigaction sa;
//memset(&sa,0,sizeof(sigaction));
//sigemptyset(&sa.sa_mask);
sa.sa_sigaction =  segfault_catch;
//sa.sa_flags = SA_SIGINFO;

sigaction(SIGSEGV,&sa,NULL);
*x=190;
}
