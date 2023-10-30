/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* f,Node* s) {

    if(f==NULL) {
        return s;
    }
    if(s==NULL) {
        return f;
    }

    Node* head=new Node(-1);
    Node* tmp=head;

    while(f!=NULL && s!=NULL) {
        if(f->data > s->data) {
            tmp->child = s;
            tmp = s;
            s=s->child;
        }
        else {
            tmp->child = f;
            tmp = f;
            f=f->child;
        }
    }
    while(f!=NULL) {
        tmp->child = f;
        tmp = f;
        f=f->child;
    }
    while(s!=NULL) {
        tmp->child = s;
        tmp = s;
        s=s->child;
    }
    return head->child;
}

Node* flattenLinkedList(Node* head) 
{
    if(head==NULL || head->next==NULL) {
        return head;
    }

    Node* down=head;

    Node* right=flattenLinkedList(head->next);

    down->next=NULL;

    Node* ans=merge(down,right);

    return ans;

}

