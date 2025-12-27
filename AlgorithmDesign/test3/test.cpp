#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s = "gg";
    s = "hello" + s + " " + s;
    cout << s;
    return 0;
}