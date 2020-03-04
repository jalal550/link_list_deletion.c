#include<stdio.h>
#include<stdlib.h>
typedef struct Node node;
struct Node
{
    int value;
    node*next;
};
node*head=NULL;
int main()
{
    node *a=(node*)malloc(sizeof(node));
    node *b=(node*)malloc(sizeof(node));
    node *c=(node*)malloc(sizeof(node));
    node *d=(node*)malloc(sizeof(node));

    head=a;

    a->value=1;
    a->next=b;

    b->value=2;
    b->next=c;

    c->value=3;
    c->next=d;

    d->value=4;
    d->next=NULL;

    printf("Before deletion\n");
    print_all(head);

    pop_at(1);
    // delete_first_value(head);
    //delete_last_value( head);

    printf("After deletion\n");
    print_all(head);

    return 0;

}
void print_all(node *x)

{
    if(x==NULL)
    {

        printf("linked list is empty\n");
        return 0;
    }
    while(x)
    {
        printf("%p\t %d\t %p\n",x,x->value,x->next);
        x = x->next;


    }
}
pop_at(int pos)
{
    if(head==NULL)
    {
        printf("linked list is empty");
        return;
    }
    node*temp,*prev;
    temp=head;
    int i=0;
    if(pos==1)
    {

        head=head->next;
        free (temp);
        return;
    }
    i=1;
    while(temp->next)
    {
        prev=temp;
        temp=temp->next;
        i++;
        if(pos==i)
        {
            prev->next=temp->next;
            free(temp);
            return;
        }
    }
    printf("Index out of range");
}
