/*
4. How do you implement stack (peek(), pop(), push())and queue(enqueue(), 
dequeue(), head()) using a heap. 
*/

struct node{
	int val;
	int timestamp;
	node(){ }
	node(int v, int t):val(v), timestamp(t){ }
};

template<class T>
class heap{
	T pop();
	T push();
	bool isEmpty();
};

//stack --  max heap: sort based on timestamp
class Stack{
	int cur_timestamp = 0;
	heap<node> my_heap;

	int pop(){
		//heap is sorted by the max of timestamp;
		node result = myheap.top();
		myheap.pop();
		return result.val;
    }

    void push(int x){
	    node my_node(x, cur_timestamp);
	    cur_timestamp++;
	    my_heap.push(my_node);
    }
}
