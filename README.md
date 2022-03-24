# c json is much simpler and easier to use than cJSON 

    Welcome to try json by c

***

## The following is a detailed demonstration of an internal structure

```C
//
// c json fast parse, type is all design
// https://www.json.org/json-zh.html
//
#ifndef JSON_NULL

#define JSON_NULL           (0u << 0)
#define JSON_TRUE           (1u << 1)
#define JSON_FALSE          (1u << 2)
#define JSON_NUMBER         (1u << 3)
#define JSON_STRING         (1u << 4)
#define JSON_OBJECT         (1u << 5)
#define JSON_ARRAY          (1u << 6)
#define JSON_CONST          (1u << 7)

// JSON_OBJECT or JSON_ARRAY data struct
// |
// child
//     -> next -> ... -> next 
//                          |
//                          child
//                              -> next -> ..
struct json {
    unsigned type;          // C JSON_NULL - JSON_ARRAY and JSON_CONST
    struct json * next;     // type & OBJECT or ARRAY -> 下个结点链表
    struct json * child;    // type & OBJECT or ARRAY -> 对象结点数据

    char * key;             // json 结点的 key
    union {
        char * str;         // type & JSON_STRING -> 字符串
        double num;         // type & JSON_NUMBER -> number
    };
};

// 定义 json 对象类型
//
typedef struct json * json_t;

// json_int - 得到结点的 int 值. 
// double 10 他可以表示十进制的15或16位有效数字.
// int 范围 [-2^63, 2^63-1] 即 -2,147,483,648 到 2,147,483,647 约 9 到 10 位
#define json_int(item) ((int)(item)->num)

#endif//JSON_NULL

//
// json_delete - json 对象销毁
// c        : json 对象
// return   : void
//
extern void json_delete(json_t c);

// json_create  解析字符串构造 json 对象
extern json_t json_create(const char * str);
// json_file 通过文件 path 解析文件内容构造 json 对象
extern json_t json_file(const char * path);
```

***

## Error is inevitable, welcome to exchange

[茉莉花](https://www.youtube.com/watch?v=z8DKtT-_a7w&ab_channel=suatsee6868)

![茉莉花](./茉莉花.jpeg)
