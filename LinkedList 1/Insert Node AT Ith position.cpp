
#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;

        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void print(node *head){
    cout <<"Your Linked list : ";
    while(head!=NULL){
        cout << head->data<<" ";
        head = head->next;
    }
}
void InsertIthPos(node* &head,int i,int data){
    if(i == 0){
        node *tail = head ;
        node *newnode = new node(data);
        newnode->next = tail;
        head = newnode;
    }
    else{
        node *tail = head;
        while(tail!= NULL){
            if(i-1 == 0){
                node *temp = tail->next;
                node *newnode = new node(data);
                tail->next = newnode;
                tail = newnode;
                tail ->next = temp;
            }
            i--;
            tail = tail-> next;
        }
    }
}
node* takeInput(){
    int data;
    cin >> data;
    node* head = NULL;
    node* tail = NULL;
    while(data != -1){
        node *newnode = new node(data);

        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}


int main(){
    node* head = takeInput();
    print(head);
    cout << endl;
    int data,i;
    cout<< "Enter the Data : ";
    cin >> data;
    cout << endl;
    cout << "Enter the I th position :";
    cin >> i;
    cout << endl;
    InsertIthPos(head,i,data);
    print(head);
}
