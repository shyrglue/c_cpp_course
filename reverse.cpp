#include<iostream>
using namespace std;

template<typename T>
struct MyListNode
{
	T val;
	MyListNode<T> * next;
	MyListNode<T>(T v)
	{
		val =v;
		next=NULL;
	}
};

template<typename T>
class MyList
{
	MyListNode<T> * head;
	MyListNode<T> * tail;
	public:
	MyList<T>()
	{
		head=NULL;
		tail=NULL;
	}
	~MyList<T>()
	{
		if(head==NULL) return;
		MyListNode<T> *temp=head,*temp2=head;
		do{
			temp2=temp2->next;
			delete temp;
			temp=temp2;
		}while(temp!=NULL);
	}
	void print()
	{
		MyListNode<T> *temp=head;
		while(temp!=NULL)
		{
			if(temp->next!=NULL)
			cout<<temp->val<<" ";
			else
			cout<<temp->val<<endl;
			temp=temp->next;
		}
	}
	void push(T val){
		if(head==NULL){
			head=new MyListNode<T>(val);
			tail=head;
		}
		else{
			tail->next=new MyListNode<T>(val);
			tail=tail->next;
		}
	}
	void reverse()
	{
		if(head==NULL)
		return;
		if(head->next==NULL)
		return;
		MyListNode<T> *temp=head,*temp2=head->next,*temp3=head->next;
		do{
			temp3=temp3->next;
			temp2->next=temp;
			temp=temp2;
			temp2=temp3;
		}while(temp3!=NULL);

		tail=head;
		head=temp;
		tail->next=NULL;
	}
};
int main()
{
	int m,n;
	cin>>m>>n;
	MyList<int> a;
	MyList<double> b;
	for(int i=0;i<m;i++)
	{
		int t;
		cin>>t;
		a.push(t);
	}
	a.print();
	a.reverse();
	a.print();
	for(int i=0;i<n;i++)
	{
		double t;
		cin>>t;
		b.push(t);
	}
	b.print();
	b.reverse();
	b.print();
}

