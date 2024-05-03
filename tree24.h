#include"node.h"
#include<iostream>
using namespace std;
class Tree24{
    Node* root;
    int size;
public:
    Tree24(){
        root = NULL;
        size = 0;
    }

    void insert(int num){
        if(!root){
            root = new Node(num,NULL);
        } else {
            Node* w = search(num);
            bool res = w->addKey(num);
            while(!res){
                Node* u;
                int pos;
                if(w == root){
                    u = new Node(w->getData(2),NULL);
                    root = u;
                    pos = 0;
                    res = true;
                } else {
                    u = w->getParent();
                    res = u->addKey(w->getData(2));
                    pos = u->indexOf(w->getData(2));
                }
                Node* wp = new Node(w->getData(0),u);
                wp->addKey(w->getData(1));
                Node* w2p = new Node(w->getData(3),u);
                u->insertChildren(wp,w2p,pos);
                w = u;
            }
        }
        size++;
    }

    Node* search(int num){
        return searchHelp(root,num);
    }

    Node* searchHelp(Node* n,int num){
        int index = n->getSize();
        for(int i=0; i<n->getSize(); i++){
            if(num == n->getData(i)){
                return n;
            } else if(num < n->getData(i)){
                index = i;
                break;
            }
        }
        if(!n->getChild(index)){
            return n;
        }
        return searchHelp(n->getChild(index),num);
    }

    void print(){
        root->print();
        cout << endl << "Size: " << size;
    }
};