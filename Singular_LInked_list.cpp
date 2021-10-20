#include<iostream>
using namespace std;

template<class T>
class node
{
    public:
    node <T>*next;
    T data;

    node()
    {
        next=NULL;
        data=0;
    }
};

template<class m>
class linkedlist
{
    public:
    node <m>*head;
    node <m>*last;
    linkedlist()
    {
        head=NULL;
        last=NULL;
    }
    ~linkedlist()
    {
        node <m>*temp=head;

        while(temp!=NULL)
        {
            head=head->next;
            delete temp;
            temp=head;
        }
    }

    int count()
    {
        node <m> *temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }

        return c;
    }

    void insertAtBeg(int key)
    {
        node <m>* newnode=(node <m>*)new node<m>;
        newnode->data=key;
        if(head==NULL)
        {
            head=newnode;
            last=newnode;
            return;
        }

        newnode->next=head;
        head=newnode;
    }

    void insertAtEnd(int key)
    {
        node <m>* newnode=(node <m>*)new node<m>;
        newnode->data=key;
        if(head==NULL)
        {
            head=newnode;
            last=newnode;
            return;
        }

        last->next=newnode;
        last=last->next;
    }

    void insertAtPos(int key,int pos)
    {
        if(pos <=count())
        {
            node <m>* temp=head;

            if(pos==0)
            {
                insertAtBeg(key);
                return;
            }
            node <m>* newnode=(node <m>*)new node<m>;
            newnode->data=key;

            for(int x=0;x<pos-1;++x)
            {
                temp=temp->next;
            }

            if(temp==last)
            {
                last=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }

    int deletingBeg()
    {
        int data=-1;
        if(head==NULL)
        {
            cout<<"list is empty nothing to delete"<<endl;
            return data;
        }

        if(head==last)
        {
            data=head->data;
            delete head;
            head=NULL;
            last=NULL;
            return data;
        }

        node <m>*temp=head;
        head=head->next;
        data=temp->data;
        return data;
    }

    int deletingLast()
    {
        int data=-1;
        if(head==NULL)
        {
            cout<<"list is empty nothing to delete"<<endl;
            return data;
        }

        if(head==last)
        {
            data=head->data;
            delete head;
            head=NULL;
            last=NULL;
            return data;
        }

        node <m>*temp=head;
        node <m>*temp1=head;

        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        data=temp->data;
        if(last==temp)
        {
            last=temp1;
        }
        delete temp;
        temp1->next=NULL;
        return data;
    }

    int deletingPos(int pos)
    {
        int data=-1;
        if(count()>pos)
        {
            node <m>*temp=head;
            if(pos==0)
            {
                head=head->next;
                data=temp->data;
                delete temp;
                return data;
            }

            for(int c=0;c<pos-1;++c)
            {
                temp=temp->next;
            }

            if(pos==count()-1)
            {
                last=temp;
            }
            node <m>*deleted=temp->next;
            data=temp->next->data;
            temp->next=temp->next->next;
            delete deleted;
            return data;

        }
        else
        {
            cout<<"Invalid position"<<endl;   
            return data;
        }
    }

    void traverse()
    {
        node<m>* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int search(int key)
    {
        node <m>*temp=head;

        while(temp!=NULL)
        {
            if(key==temp->data)
            {
                return 1;
            }
            temp=temp->next;
        }

        return 0;
    }

    int issort()
    {
        if(count()>1)
        {
            node<m>*temp=head;

            while(temp->next!=NULL)
            {
                if(temp->data<=temp->next->data)
                {
                    temp=temp->next;
                    continue;
                }
                return 0;
            }

            return 1;
        }
        else
        {
            return 1;
        }
    }
};


int main()
{
    linkedlist<int> a;
    a.insertAtBeg(3);
    a.insertAtBeg(2);
    a.insertAtBeg(1);
    a.insertAtBeg(12);

    cout<<a.issort()<<endl;
    a.traverse();
    return 0;
}
