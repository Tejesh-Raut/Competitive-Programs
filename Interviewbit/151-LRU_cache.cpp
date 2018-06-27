/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRUCache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

 NOTE: If you are using any global variables, make sure to clear them in the constructor. 
Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 

*/

deque<int> mydeque;
map<int, int> M;
int cap;

LRUCache::LRUCache(int capacity) {
    mydeque.clear();
    M.clear();
    cap = capacity;
}

int LRUCache::get(int key) {
    if(M.find(key)==M.end()){
        return -1;
    }
    else{
        mydeque.erase(std::remove(mydeque.begin(), mydeque.end(), key), mydeque.end());
        mydeque.push_back(key);
        return M[key];
    }
}

void LRUCache::set(int key, int value) {
    if(M.find(key)==M.end()){
        mydeque.push_back(key);
        if(mydeque.size()>cap){
            M.erase(mydeque.front());
            mydeque.pop_front();
        }
    }
    else{
        mydeque.erase(std::remove(mydeque.begin(), mydeque.end(), key), mydeque.end());
        mydeque.push_back(key);
    }
    
    M[key] = value;
}
