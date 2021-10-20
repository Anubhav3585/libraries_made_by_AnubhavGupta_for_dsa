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

        while(temp!=last)
        {
            head=head->next;
            delete temp;
            temp=head;
        }

        delete last;
    }

    int count()
    {
        node <m> *temp=head;
        int c=0;
        while(temp!=last)
        {
            c++;
            temp=temp->next;
        }

        if(temp==last)
        c++;

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
            last->next=head;
            return;
        }

        newnode->next=head;
        head=newnode;
        last->next=head;
    }

    void insertAtEnd(int key)
    {
        node <m>* newnode=(node <m>*)new node<m>;
        newnode->data=key;
        if(head==NULL)
        {
            head=newnode;
            last=newnode;
            last->next=head;
            return;
        }

        last->next=newnode;
        last=last->next;
        last->next=head;
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

            newnode->next=temp->next;
            temp->next=newnode;
            if(temp==last)
            {
                last=temp->next;
                last->next=head;    
            }
            
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
        last->next=head;
        return data;
    }

    int deletingLast()
    {
        int data=-1;
        node <m>*temp=head;
        if(head!=NULL)
        {
            if(head==last)
            {
                data=head->data;
                delete head;
                head=NULL;
                last=NULL;
                return data;
            }

            while(temp->next!=last)
            {
                temp=temp->next;
            }

            data=last->data;
            delete last;
            
            last=temp;
            last->next=head;
        }
        
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
            last->next=head;
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
        if(head!=NULL)
        {
            node <m>*temp=head;
            while(temp!=last)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }

            cout<<temp->data<<endl;
        }
        else
        {
            cout<<"linked list is empty"<<endl;
        }
    }

    int search(int key)
    {
        if(head!=NULL)
        {
            node <m>*temp=head;

            while(temp!=last)
            {
                if(key==temp->data)
                {
                    return 1;
                }
                temp=temp->next;
            }

            if(temp->data==key)
            {
                return 1;
            }

            return 0;
        }
        else
        {
            cout<<"list is empty"<<endl;
        }
    }

    int sort()
    {
        if(count()>1)
        {
            node <m>*temp=head;
            while(temp!=last)
            {
                if(temp->data<temp->next->data)
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