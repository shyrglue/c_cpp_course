#include <iostream>
using namespace std;
template <class T>
class Node {
private:
	T data;
public:
	Node* next;
	Node();
	Node(const T& data, Node<T>* nt = 0);
	T& getData();
};

template <class T>
Node<T>::Node() {
	data = 0;
	next = NULL;
}

template <class T>
Node<T>::Node(const T& d, Node<T>* nt) {
	data = d;
	next = nt;
}

template <class T>
T& Node<T>::getData() {
	return data;
}

/*
* 在LinkedList的设计中，采用了附加指针front和rear，即链表的结构为front->a1->a2->...->rear
*/
template <class T>
class LinkedList {
public:
	Node<T> *front, *rear; //表头和表尾指针
	void clear(); //清空链表：释放所有节点的内存空间，被析构函数使用


	LinkedList(); //构造函数
	~LinkedList(); //析构函数

	void insertFront(const T& item); //在表头插入节点
	T deleteFront(); //删除表头节点
	void insertRear(const T& item); //在表尾插入节点
	void insertRear(LinkedList<T>& other); //在表尾插入另一个表

	void print() const; //打印链表
};

//构造函数
template <class T>
LinkedList<T>::LinkedList() {
    front=new Node<T>();
    rear=new Node<T>();
    front->next=rear;
}

//清空链表：释放所有节点的内存空间，被析构函数和operator=使用
template <class T>
void LinkedList<T>::clear() {
	Node<T>* temp;
	while (front->next != rear) {
		temp = front->next;
		front->next = temp->next;
		delete temp;
	}
}

//析构函数
template <class T>
LinkedList<T>::~LinkedList() {
	LinkedList::clear();
	delete front;
	delete rear;
}

//在表头插入节点
template <class T>
void LinkedList<T>::insertFront(const T& item) {
	Node<T>* n = new Node<T>(item, front);
	front = n;
}

//删除表头节点
template <class T>
T LinkedList<T>::deleteFront() {
	Node<T>* temp = front->next;
	front->next = temp->next;
	T value = temp->getData();
	delete temp;
	return value;
}

//在表尾插入节点
template <class T>
void LinkedList<T>::insertRear(const T& item) {
	Node<T>* temp = front;
	while (temp->next != rear)
		temp = temp->next;
	Node<T> *n = new Node<T>(item, rear);
	temp->next= n;
}

//在表尾插入另一个表
template <class T>
void LinkedList<T>::insertRear(LinkedList<T>& other){
	Node<T>* temp = front;
	while (temp->next != rear)
		temp = temp->next;
	temp->next = other.front->next;
	other.front->next = other.rear;
	while (temp->next != other.rear)
		temp = temp->next;
	temp->next = rear;
}

//打印链表
template <class T>
void LinkedList<T>::print() const {
	Node<T>* temp = front->next;
	while (temp != rear) {
		std::cout << temp->getData() << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}


/**********  Begin  **********/
template <class T>
class Queue : public LinkedList<T>{
    public:
    
    void push(T);
    T pop();
    Queue(){} //构造函数
	~Queue(){} //析构函数
};
template <class T>
void Queue<T>::push(T a)
{
        this->insertRear(a);
}

template <class T>
T Queue<T>::pop()
{
        T n=this->front->next->getData();
        this->front=this->front->next;
        return n;
}
/**********  End  **********/

#include <iostream>
using namespace std;

int main()
{
    int item;
    Queue<int> q;
    // cout << "输入5个要插入的元素" << endl;
    for (int i = 0; i < 5; i ++) {
        cin >> item;
        q.push(item);
    }
    for (int i = 0; i < 5; i ++)
        // cout << "取出元素" << q.pop() << endl;
        cout<<q.pop()<<" ";
    cout<< endl;
    return 0;
}
