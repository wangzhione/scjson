## c json is much simpler and easier to use than cJSON 

    Welcome to try json by c

***

### The following is a detailed demonstration of an internal structure

```C
//
// c json fast parse, type is all design
//

#ifndef _STRUCT_JSON

#define JSON_NULL       (0u << 0)
#define JSON_TRUE       (1u << 0)
#define JSON_FALSE      (1u << 1)
#define JSON_NUMBER     (1u << 2)
#define JSON_STRING     (1u << 3)
#define JSON_OBJECT     (1u << 4)
#define JSON_ARRAY      (1u << 5)

struct json {
    unsigned char type;         // CJSON_NULL - JSON_ARRAY
    struct json * next;         // type = OBJECT or ARRAY 结点采用链表链接
    struct json * chid;         // type = OBJECT or ARRAY 时候 chid 结点就有数据

    char * keys;                // json 结点的 key 名称串
    union {
        char * vals;            // type == STRING 就是个 字符串
        double vald;            // type == NUMBER 就是个 number
    };
};

//
// 定义 json 对象类型
//
typedef struct json * json_t;

//
// json_vali - 得到结点的 int 值
// item     : 处理的结点
//          : 返回 number int 值
//
#define json_vali(item) ((int)(item)->vald)

#define _STRUCT_JSON
#endif//_STRUCT_JSON

//
// json_delete - json 对象销毁
// c        : json 对象
// return   : void
//
extern void json_delete(json_t c);

//
// json_file - 通过 path   路径构造 json 对象
// json_create  - 通过 char * 对象构造 json 对象
// str      : const char * 字符串
// path     : 文件路径
// return   : json_t 对象
//
extern json_t json_file(const char * path);
extern json_t json_create(const char * str);

```

***

### Error is inevitable, welcome to exchange

[茉莉花](https://music.163.com/#/song?id=239755)

![茉莉花](./茉莉花.jpeg)
