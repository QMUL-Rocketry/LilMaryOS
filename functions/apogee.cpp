#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class rocket{
    public:
        string name;
};

void changer1(rocket *r, string x){
    r->name = x;
    cout << r->name << endl;
};


int main() {
    printf("Hello world");
    rocket r;
    r.name = "hello";
    cout << r.name << endl;
    changer1(&r, "change");
    cout << "r: " + r.name << endl;
    return 0;
}