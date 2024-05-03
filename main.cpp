#include<iostream>
#include"Tree24.h"

using namespace std;
int main(int argc, char** argv){
    Tree24* n = new Tree24();
    n->insert(13);
    n->print();
    cout<<endl;
    cout<<"Searching for 4: ";
    n->search(4)->print();
    cout<<endl;
    n->insert(4);
    n->insert(17);
    n->insert(5);
    n->insert(26);
    n->print();
    return 0;
}
