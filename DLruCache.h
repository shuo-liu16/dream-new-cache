// 前向声明
template<typename Key, typename Value> class KLruCache;

template<typename Key, typename Value>
class LruNode
{
private:
    Key key_;
    Value value_;  // 修正变量名为小写
    size_t accessCount_; // 访问次数
    std::shared_ptr<LruNode<Key, Value>> prev_;
    std::shared_ptr<LruNode<Key, Value>> next_;

public:
    LruNode(Key key, Value value)
        : key_(key), 
        value_(value),
        accessCount_(1),
        prev_(nullptr), 
        next_(nullptr) 
    {}

    // 节点访问方法
    // 提供必要的访问器
    Key getKey() const { return key_; }
    Value getValue() const { return value_; }
    void setValue(const Value& value) { value_ = value; }
    size_t getAccessCount() const { return accessCount_; }
    void incrementAccessCount() { ++accessCount_; }

    // 允许缓存类访问私有成员，修正模板参数为Key
    friend class KLruCache<Key, Value>;
};