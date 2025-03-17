#pragma once 

namespace DreamCache {
    template <typename Key, typename Value>
    class DICachePolicy {
    public:
        virtual ~DICachePolicy() {};
        
        // 添加缓存接口
        virtual void put(Key key, Value value) = 0;
        
        // 修正函数重载冲突：统一返回Value，通过bool参数版本返回存在性
        virtual bool get(Key key, Value& value) = 0;  // 传出值+返回存在性
        virtual Value get(Key key) = 0;               // 直接返回值
    };
} // namespace DreamCache 