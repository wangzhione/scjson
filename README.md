# c json is much simpler and easier to use than cJSON 

    Welcome to try json by c

***

## The following is a detailed demonstration of an internal structure

```C
//
// c json fast parse, type is all design
//
#ifndef JSON_NULL

#define JSON_NULL           (0u << 0)
#define JSON_BOOL           (1u << 1)
#define JSON_NUMBER         (1u << 2)
#define JSON_STRING         (1u << 3)
#define JSON_OBJECT         (1u << 4)
#define JSON_ARRAY          (1u << 5)
#define JSON_CONST          (1u << 6)

struct json {
    unsigned char type;     // CJSON_NULL - JSON_ARRAY and JSON_CONST
    struct json * next;     // type & OBJECT or ARRAY -> 下个节点链表
    struct json * chid;     // type & OBJECT or ARRAY -> 对象节点数据

    char * key;             // json 节点的 key
    union {
        char * str;         // type & STRING -> 字符串
        double num;         // type & NUMBER -> number
    };
};

// 定义 json 对象类型
//
typedef struct json * json_t;

//
// json_int - 得到节点的 int 值
// item     : json 节点
//          : 返回 number int 值
//
#define json_int(item) ((int)(item)->num)

#endif//JSON_NULL

//
// json_delete - json 对象销毁
// c        : json 对象
// return   : void
//
extern void json_delete(json_t c);

//
// json_file - 通过文件构造 json 对象
// json_create  - 通过字符串构造 json 对象
// str      : 字符串
// path     : 文件路径
// return   : json_t 对象
//
extern json_t json_file(const char * path);
extern json_t json_create(const char * str);
```

***

## Error is inevitable, welcome to exchange

[茉莉花](https://music.163.com/#/song?id=239755)

![茉莉花](./茉莉花.jpeg)
