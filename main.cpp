#include <iostream>

using namespace std;

#define N 100

typedef struct lnode{
    int data;
    struct lnode * next;
}lnode,* link_list;

void Creat(int n,link_list&l){
    int i;
    lnode *r,*p;
    l=new lnode;
    l->next=NULL;
    r=l;
    for(i=0;i<n;++i){
        p=new lnode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}

int locate(link_list&l){
    int MINISIZE,j,count;
    lnode *p;
    p=l->next;
    j=1;
    MINISIZE=p->data;
    count=1;
    while(p->next){
        ++j;
        if(MINISIZE>p->data){
            MINISIZE=p->data;
            count=j;
        }
    }
    return count;
}

void Delete(int i,link_list&l){
    int j;
    lnode *p,*q;
    p=l;
    j=0;
    while(p->next&&(i<j-1)){
        p=p->next;
        ++j;
    }
    q=p->next;
    p->next=q->next;
    delete q;
}

int main() {
    int n,i;
    link_list l;
    link_list p;
    l=new lnode;
    l->next=NULL;
    while (cin>>n){
        Creat(n,l);
        if(n==1){
            cout<<endl;
            continue;
        }
        else{
            i=locate(l);
            Delete(i,l);
            p=l->next;
        }
        while(p->next){
            cout<<p->data<<' ';
            p=p->next;
        }
        cout<<p->data<<endl;
    }
    return 0;
}
