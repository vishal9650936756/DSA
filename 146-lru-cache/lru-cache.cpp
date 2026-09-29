class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;

    Node* head; // dummy head: most recently used side
    Node* tail; // dummy tail: least recently used side

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void makeRecent(Node* node) {
        remove(node);
        insertAtFront(node);
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
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];

        // Accessing it makes it most recently used.
        makeRecent(node);

        return node->value;
    }

    void put(int key, int value) {
        // Key already exists.
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;

            makeRecent(node);
            return;
        }

        // Insert new node.
        Node* node = new Node(key, value);
        cache[key] = node;
        insertAtFront(node);

        // Exceeded capacity: remove least recently used node.
        if (cache.size() > capacity) {
            Node* lru = tail->prev;

            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};