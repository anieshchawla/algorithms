#include <stdio.h>

#define bool int
using namespace std;
bool two_power (int a)

{

 if (a == 0)

 return 0;

 while (a != 1)

 {

 if (a%2 != 0) return 0;

 a = a/2;
 printf("value of a %d \n",a);

 }

 return 1;

}

int main()

{

 two_power(6)? printf("Yes\n"): printf("No\n");

 two_power(17)? printf("Yes\n"): printf("No\n");

 two_power(16)? printf("Yes\n"): printf("No\n");

 

 return 0;

}