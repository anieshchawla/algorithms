
#include <iostream>
#include <random>
#include <algorithm>
#define fori for(int i=1;i<5;i++)
using namespace std;

void sorting_2d(int ar[][2]){
        std::qsort(ar, 5, sizeof(*ar),
        [](const void *arg1, const void *arg2)
        {
            int const *lhs = static_cast<int const*>(arg1);
            int const *rhs = static_cast<int const*>(arg2);
            if (lhs[0] < rhs[0]) return -1;
            if  (lhs[0] > rhs[0]) return 1;
            return 0;
        });

}
void sorting_2d_second_col(int ar[][2]){
        std::qsort(ar, 5, sizeof(*ar),
        [](const void *arg1, const void *arg2)
        {
            int const *lhs = static_cast<int const*>(arg1);
            int const *rhs = static_cast<int const*>(arg2);
            if (lhs[1] < rhs[1]) return -1;
            if  (lhs[1] > rhs[1]) return 1;
            return 0;
        });

}

int main()
{
    int ar[5][2];
    bool try_second = false,got_solution=true;
    for(int i=0;i<5;i++){
        cin>>ar[i][0]>>ar[i][1];
    }
    sorting_2d(ar);
    fori{
        if(ar[i][0]<=ar[i-1][0]){
            try_second = true;
            break;
        }
            if(ar[i][1]<=ar[i-1][1]){
            try_second = true;
            break;
        }
    }
    if(try_second){
    
        sorting_2d_second_col(ar);
            fori{
            if(ar[i][0]<=ar[i-1][0]){
                got_solution = false;
                break;
            }
                if(ar[i][1]<=ar[i-1][1]){
                got_solution = false;
                break;
            }
        }
    }
    if(got_solution) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}