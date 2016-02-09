#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    string input;
    vector<string> words_inp;
    getline(cin,input);
    char *token;
    token = strtok(strdup(input.c_str())," ![,?.\\_'@+]");
    while(token!=NULL){
        words_inp.push_back(token); 
        token = strtok(NULL," ![,?.\\_'@+]");
    }
    cout<<words_inp.size()<<endl;
    for(int i=0;i<words_inp.size();i++) cout<<words_inp[i]<<endl;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


/*void Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ![,?.\\_'@+]")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

int main() {
    string input;
    vector<string> words_inp;
    getline(cin,input);
    //char *token;
    //token = strtok(input," ![,?.\\_'@+]");
    Tokenize(input,words_inp);
    /*while(token!=NULL){
        words_inp.push_back(token); 
        token = strtok(NULL," ![,?.\\_'@+]");
    }
    cout<<words_inp.size()<<endl;
    for(int i=0;i<words_inp.size();i++) cout<<words_inp[i]<<endl;

     Enter your code here. Read input from STDIN. Print output to STDOUT    
    return 0;
}*/