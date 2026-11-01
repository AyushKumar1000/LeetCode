class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtEnd(Node* node) {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }

    void moveToEnd(Node* node) {
        removeNode(node);
        insertAtEnd(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        moveToEnd(node);

        return node->value;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;
            moveToEnd(node);

            return;
        }

        // Cache is full
        if (mp.size() == capacity) {
            Node* lru = head->next;

            mp.erase(lru->key);
            removeNode(lru);

            delete lru;
        }

        Node* node = new Node(key, value);

        mp[key] = node;
        insertAtEnd(node);
    }
};