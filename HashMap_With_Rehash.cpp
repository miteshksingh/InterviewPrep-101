struct node{
    int key;
    int val;
    node* next;
    node(int key, int val):key(key), val(val), next(NULL){}
};
class MyHashMap {
private:
    vector<node*> bucket;
    int capacity;
    int size;
    float lf;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        capacity=20;
        size=0;
        lf=0.7;
        bucket=vector<node*>(capacity);
        for(int i=0; i<capacity; i++){
            bucket[i] = NULL;
        }

        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash=hashFun(key);
        
        if(bucket[hash]==NULL){
            bucket[hash] = new node(key, value);
            size++;
        }
        else{
            node* head=bucket[hash];
            while(head->next!=NULL && head->key!=key) 
                head=head->next;
            
            if(head->key==key)  
                head->val=value;
            
            else{
                head->next=new node(key, value);
                size++;
            }
        }
        
        float currlf=size/capacity;
        if(currlf>lf)
            rehash();
        

    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {

        int hash=hashFun(key);
        
        if(bucket[hash]==NULL)
            return -1;
        else{
            node* head=bucket[hash];
            while(head != NULL && head->key != key)
                head=head->next;
            
            if(head!=NULL && head->key == key)
                return head->val;
            
            else
                return -1;
        }
        
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int val=get(key);
        
        if(val == -1)
            return;
      
        else{
            int hash=hashFun(key);
            node* head=bucket[hash];
            
            if(head->key==key){
                bucket[hash] = head->next;
                size--;
                delete(head);
            }
            else{
                node* prev = NULL;
                while(head != NULL && head->key != key){
                    prev = head;
                    head = head->next;
                }
                prev->next = head->next;
                size--;
                delete head;
            }
            
        }
        
    }
    
    int hashFun(int key){
        return key%capacity;
    }
    
    void rehash(){

        vector<pair<int, int>> allElements;
        
        for(int i=0; i<capacity; i++){
            if(bucket[i] != NULL){
                node* head=bucket[i];
                
                while(head != NULL){
                    allElements.push_back({head->key, head->val});
                    node *temp=head;
                    head=head->next;
                    delete(temp);
                }
            }
        }

        capacity=2*capacity;
        bucket=vector<node*>(capacity);
        for(int i=0; i<capacity; i++)
            bucket[i]=NULL;
            

        for(auto pair: allElements){
            put(pair.first, pair.second);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
