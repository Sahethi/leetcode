class LRUCache{
private:
    int cap;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity){
        cap = capacity;
    }

    int get(int key){
        if(cache.find(key) == cache.end()){
            return -1;
        }

        //move it in the front as its the most recently accessed
        auto it = cache[key];
        int value = it->second;

        dll.erase(it);
        dll.push_front({key, value});
        cache[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            //erase the old entry
            dll.erase(cache[key]);
        } else if(dll.size() == cap){
            //remove the least recently used from the back
            auto lru = dll.back();
            cache.erase(lru.first);
            dll.pop_back();
        }

        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};
// class LRUCache {
// private:
//     struct Node{
//         int key;
//         int value;
//         Node* prev;
//         Node* next;
//         Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr){}
//     };

//     int cap;
//     unordered_map<int, Node*> cache;
//     Node* head;
//     Node* tail;

//     void remove(Node* node){
//         node->prev->next = node->next;
//         node->next->prev = node->prev;
//     }

//     void insertInFront(Node* node){
//         node->next = head->next;
//         node->prev = head;
//         head->next->prev = node;
//         head->next = node;
//     }

// public:
//     LRUCache(int capacity) {
//         cap = capacity;
//         head = new Node(0,0);
//         tail = new Node(0,0);
//         head->next = tail;
//         tail->prev = head;
//     }
    
//     int get(int key) {
//         if(cache.find(key) == cache.end()){
//             return -1;
//         }

//         Node* node = cache[key];
//         remove(node);
//         insertInFront(node);
//         return node->value;
//     }
    
//     void put(int key, int value) {
//         if(cache.find(key) != cache.end()){
//             Node* node = cache[key];
//             node->value = value;
//             remove(node);
//             insertInFront(node);
//         }else{
//             if(cache.size() == cap){
//                 Node* lru = tail->prev;
//                 cache.erase(lru->key);
//                 remove(lru);
//                 delete(lru);
//             }
//             Node* node = new Node(key, value);
//             insertInFront(node);
//             cache[key] = node;

//         }
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */