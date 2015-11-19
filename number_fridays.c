
f(x){return(x+(x+3)/4-(x+99)/100+!!x)%7;}
main(int x,char**v)
{
int y=atoi(v[1])%400,a=f(y+1);
putchar('1'+((f(y)&3)==1)+(a>2&&a-5));
}