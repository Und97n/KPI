#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    float val;
    node* next;
} typedef list;




void insert(list* head, float val){
    if(head->next != 0){
        insert(head->next,val);
    }else{
        head->next = (list*)malloc(sizeof(list));
        head->next->val = val;
        head->next->next = 0;
    }
}

void print(list* head){
    cout << head->val << " ";
    if(head->next != 0){
        print(head->next);
    }else{
        cout << endl;
    }
}


void freall(list *head){
    if(head->next != 0) freall(head->next);
    free(head);

}

void append_revert(list * head){
    if(head->next != 0) append_revert(head->next);
    insert(head,head->val);
}







int main()
{
    int n;
    cout << "Enter n:"<<endl;
    cin >> n;

    list* head = (list*)malloc(sizeof(int));
    for(int i = 0;i<n;i++){
        insert(head,i+0.5);
    }
    print(head);
    append_revert(head);
    print(head);
    freall(head);

    return 0;
}
