#include<iostream>
using namespace std;
int step = 0;
class ListNode{

 public:
    int data;
    ListNode* next;
    
    ListNode(int data){
      this->data=data;
      this->next=NULL;
    }
};


bool hasCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = (fast->next)->next;
            step++;
            
            if(slow == fast){
                return true;
                //cout << step << endl;
            }
        }
        
        return false;
}

int main(){
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = third;

    bool ans = hasCycle(head);
    if(ans == 1){
        cout << "In the Linked List cycle is decected." << endl;
        cout << "At step = " << step; 
    }
    else{
        cout << "In the Linked List cycle is not detected" << endl;
        
    }
    
    
}