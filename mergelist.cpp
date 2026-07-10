#include <iostream>
#include<list>
#include<vector>
using namespace std;
class Node{

    public:
    Node *next;
  
    int value;

    Node(){
        value=0;
        next=NULL;
    }

    Node(int val){
        value=val;
       
        next=NULL;
    }


};


    void insertbyhead(int val,Node *&head,Node *&tail){

        Node *temp=new Node(val);

        if(tail==NULL){
            tail=temp;
            head=temp;
            return;
        }
        tail->next=temp;
        tail=tail->next;
       

    }


    void print(Node *&head){

        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->next<<" ";
            temp=temp->next;
        }

    }


    void sort(Node *&t1,Node *&t2,Node *&temp){

        while(t1!=NULL && t2!=NULL){

            if(t1->value<=t2->value){
                temp->next=t1;
                t1=t1->next;
                temp=temp->next;
            }
            else{
                temp->next=t2;
                t2=t2->next;
                temp=temp->next;
            }
        }

        while(t1!=NULL){
            temp->next=t1;
            temp=temp->next;
            t1=t1->next;
        }
        while(t2!=NULL){
            temp->next=t2;
            temp=temp->next;
            t2=t2->next;
        }
    }
void solve() {
    
    int k;
    cout<<"K: "<<endl;
    cin>>k;
    vector<Node*>lists(k,NULL);
    for(int i=0;i<k;++i){

        int n;
        cout<<"N: "<<endl;
        cin>>n;
        Node *head=NULL,*tail=NULL;
        for(int j=0;j<n;++j){
            int val;
            cout<<"Val: "<<endl;
            cin>>val;

            insertbyhead(val,head,tail);

        }
        lists[i]=head;

    }

    
    Node *dummy=new Node();
    Node *temp=dummy;
    Node *t1=lists[0],*t2=lists[1];
    cout<<lists[0]->value<<" "<<lists[1]->value<<endl;
    sort(t1,t2,temp);

    
   
    

    int count=2;
    while(count<k){

        temp=dummy;
        t1=temp->next;
        t2=lists[count];
        sort(t1,t2,temp);
        count++;
    }
    temp=dummy->next;
    while(temp!=NULL){
        cout<<temp->next<<" ";
        temp=temp->next;
    }
    
}

int main() {
    int t, i = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
    return 0;
}