#include <iostream>
#include "Polish.h"
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    Polish a(s);
    int i = a.calculate(0);
    cout<<" = "<<i;
}