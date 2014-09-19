/*
Q30 Assume that in a web server, 90% of the users revisited the webpage urls that they 
surfed yesterday three times on average for each url. Then how can we speed up the 
url parsing process?
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Entry{
public:
    int val_; //stands for actual url_node content
    Entry* prev_;
    Entry* next_; 
    Entry(){ }
    Entry(int v):val_(v),prev_(NULL),next_(NULL){ }
};

class Cache{
public:
    int capacity_;
    int count_;
    Entry* head_; //most recent url_node
    Entry* tail_; //least recent url_node
    unordered_map<int, Entry*> mapping_;

    Cache(int capacity){ 
        capacity_ = capacity;
        count_ = 0;
        head_ = new Entry(0);
        tail_ = new Entry(0);
    }
    
    void Remove(){
        Entry* prev_tail = tail_->prev_;
        mapping_.erase(tail_->val_);
        delete tail_;
        cout<<"Remove tail "<<tail_->val_<<endl;
        count_--;
        //update tail
        tail_ = prev_tail;
        tail_->next_ = NULL;
        return;
    }

    void Insert(int x){
        Entry* node = new Entry(x);
        //base case: empty cache
        if(count_ == 0){
            delete head_;
            head_ = node;
            delete tail_;
            tail_ = node;
            count_++;
            mapping_[x] = node;
            return;
        }
        if(count_ == capacity_){
            cout<<"cache is full."<<endl;
            Remove();
        }
        //update head
        Entry* next_node = head_;
        head_ = node;
        head_->next_ = next_node;            
        next_node->prev_ = head_;
        count_++;
        mapping_[x] = node;
        return;
    }
    
    Entry* Get(int key){
        if(mapping_.find(key)!= mapping_.end()){
            Entry* node = mapping_[key];
            Entry* prev_node = node->prev_;
            Entry* next_node = node->next_;
            //update priority -- detach
            prev_node->next_ = next_node;
            next_node->prev_ = prev_node;
            //update priority -- connect to head 
            Entry* prev_head = head_;
            head_ = node;
            head_->prev_ = NULL;
            head_->next_ = prev_head;
            prev_head->prev_ = head_;      
        }
        else{
            Insert(key);
        }
        return head_;
    }

    void Print(){
        Entry* cur = head_;
        while(cur){
            cout<<cur->val_<<" ";
            cur = cur->next_;
        }
        cout<<endl;
    }
};

int main(){
    Cache cache = Cache(3);
    for(int i = 0; i < 6; i++){
        cache.Insert(i);
        cache.Print();
    }
    for(int j = 10; j < 20; j++){
        cache.Get(j);
        cache.Print();
    }
    return 0;
}

/*
The way to build priority: using list
head: most recent url
tail: out-dated url

To find url node quickly, use hash table
<url_string, url_node>  <===> <key, value>

To get access to previous url_node, use double linked_list
*/