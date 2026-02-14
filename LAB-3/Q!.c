#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*next;
    int data;
};

struct node*add_last(struct node*head,int d){
    struct node*ptr,*temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    if(head==NULL) return temp;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
};

struct node* delete(struct node* head){

    int pos;

    printf("Enter position to delete:\n");
    scanf("%d",&pos);

    struct node *temp=head, *prev=NULL;

    if(pos==1){

        head=temp->next;
        free(temp);
        return head;
    }

    while(pos>1 && temp!=NULL){

        prev=temp;
        temp=temp->next;
        pos--;
    }

    if(temp==NULL){

        printf("Position not found\n");
        return head;
    }

    prev->next=temp->next;

    free(temp);

    return head;
}


struct node*add_after(struct node*head,int d){
    int k;
    printf("Enter the node after whch u want to insert\n");
    scanf("%d",&k);
    struct node*temp,*ptr;
    temp=malloc(sizeof(struct node));
    ptr=head;
    temp->data=d;
    temp->next=NULL;
    while(k>1){
        ptr=ptr->next;
        k--;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
};

struct node*add_before(struct node*head,int d){
    int k;
    printf("Enter the node before whch u want to insert\n");
    scanf("%d",&k);
    struct node*temp,*ptr;
    temp=malloc(sizeof(struct node));
    ptr=head;
    temp->data=d;
    temp->next=NULL;
    while(k>2){
        ptr=ptr->next;
        k--;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
};

struct node*add_beg(struct node*head,int d){
    struct node*ptr=malloc(sizeof(struct node));
    ptr->data=d;
    ptr->next=NULL; //Initiated it by using NULL
    ptr->next=head;
    head=ptr;
    return head;
};

struct node*add_to_emptylist(struct node*head,int d){
        struct node*temp=malloc(sizeof(struct node));
        temp->data=d;
        temp->next=NULL;
        head=temp;
        return head;
};

struct node*search(struct node*head,int d){

    return head;
};

 int count_nodes(struct node*head){
    int count=0;
    struct node*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
};

int main(){
        struct node*head=NULL;
        int e;
        printf("Enter the data u want to enter\n");
        scanf("%d",&e);
        head=add_to_emptylist(head,e);
        head=add_beg(head,e);
        int f;
        printf("Enter the element to inserted at last\n");
        scanf("%d",&f);
        head=add_last(head,f);
        int j;
        printf("Enter the element to inserted after a pos\n");
        scanf("%d",&j);
        head=add_after(head,j);
        int l;
        printf("Enter the element to inserted before a pos\n");
        scanf("%d",&l);
        head=add_before(head,l);
        struct node*temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        int count;

        printf("The count of nodes is %d\n",count_nodes(head));

        int u;
        printf("Enter the element u want to insert\n");
        scanf("%d",&u);
        struct node*temp3=head;
        while(temp3!=NULL){
            if(temp3->data==u){
                    printf("Found at address %p\n",temp);
                }
            temp3=temp3->next;
    }

        head=delete(head);
        struct node*temp2=head;
        while(temp2!=NULL){
            printf("%d ",temp2->data);
            temp2=temp2->next;
        }



        return 0;
}
