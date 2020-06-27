class LRUCache {
public:
    class ListNode{
      public:
        int key;
        int value;
        ListNode* n;
        ListNode* p;
    };
    unordered_map<int,ListNode*>mp;
    ListNode* head=new ListNode();
    ListNode* tail=new ListNode();
    int totalItemsInCache;
    int maxcapacity;
    // Initialaize our doubly linked list.
    // Initialize the maxcapacity and the number of elementd present in the cache.
    LRUCache(int capacity) {
        totalItemsInCache=0;
        maxcapacity=capacity;
        head->n=tail;
        tail->p=head;
    }
    // Work in the get function of the datastructure.
    int get(int key) {
        ListNode* node=mp[key];
        if(node==NULL){
            return -1;
        }
        MoveToTheHead(node);
        return node->value;
    }
    // Work in the put function of the datastructure.
    void put(int key, int value) {
        ListNode* node=mp[key];
        if(node==NULL){
            ListNode* root=new ListNode();
            root->key=key;
            root->value=value;
            mp[key]=root;
            addToFront(root);
            totalItemsInCache++;
            if(totalItemsInCache>maxcapacity){
                RemoveNodeFromTheEnd();
            }
        }else{
            node->value=value;
            MoveToTheHead(node);
        }
    }
    void MoveToTheHead(ListNode* node){
        removenode(node);
        addToFront(node);
    }
    void addToFront(ListNode* node){
        node->p=head;
        node->n=head->n;
        head->n->p=node;
        head->n=node;
    }
    void removenode(ListNode* node){
        ListNode* prevNode=node->p;
        ListNode* nextNode=node->n;
        prevNode->n=nextNode;
        nextNode->p=prevNode;
    }
    void RemoveNodeFromTheEnd(){
        ListNode* node=tail->p;
        removenode(node);
        mp.erase(node->key);
        totalItemsInCache--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */