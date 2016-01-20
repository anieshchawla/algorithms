#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Color{
  map<string,string> map_type;
} ;
struct ShoeSize{
  map<string,Color*> map_color;
};

struct Companies{
  map<int,ShoeSize*> map_size;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, Companies*> map_company;
    int N,pairs;
    cin>>N;
    while(N>0){
        int size;
        string company,color,type;
        cin>>company>>size>>color>>type;
        map<string,Companies*>::iterator it_company = map_company.find(company);
        if(it_company!=map_company.end()){
          map<int,ShoeSize*>::iterator it_shoesize = it_company->second->map_size.find(size);
          if(it_shoesize!=it_company->second->map_size.end()){
            map<string,Color*>::iterator it_color = it_shoesize->second->map_color.find(color);
            if(it_color != it_shoesize->second->map_color.end() ){
              map<string,string>::iterator it_type = it_color->map_type.find(type);
              if(it_type != it_color)
            }
            else{
              Color *new_color = new Color;
              it_shoesize->second->map_color[color] = new_color;
              new_color->map_type[type] = type;
            }
          }
          else{
            ShoeSize *new_size = new ShoeSize;
            Color *new_color = new Color;
            it_company->second->map_size[size] = new_size;
            new_size->map_color[color] = new_color;
            new_color->map_type[type] = type;
          }

        }
        else{
          Companies *new_comp = new Companies;
          ShoeSize *new_size = new ShoeSize;
          Color *new_color = new Color;
          map_company[company] = new_comp;
          new_comp->map_size[size] = new_size;
          new_size->map_color[color] = new_color;
          new_color->map_type[type] = type;

          }
        }
    return 0;
}
