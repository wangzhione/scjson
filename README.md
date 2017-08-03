## scjson is much simpler and easier to use than cJSON 

        tstr is The TSTR is a simple c string, Welcome to try scjson

### The following is a detailed demonstration of an internal structure

```C
// json中几种数据结构和方式定义, 对于程序开发而言最难的还是理解思路(思想 or 业务)
#define CJSON_NULL      (0u << 0)
#define CJSON_FALSE     (1u << 0)
#define CJSON_TRUE      (1u << 1)
#define CJSON_NUMBER    (1u << 2)
#define CJSON_STRING    (1u << 3)
#define CJSON_ARRAY     (1u << 4)
#define CJSON_OBJECT    (1u << 5)

struct cjson {
	struct cjson * next;	// 采用链表结构处理, 放弃二叉树结构, 优化内存
	struct cjson * child;	// type == ( CJSON_ARRAY or CJSON_OBJECT ) 那么 child 就不为空

	unsigned char type;     // 数据类型 CJSON_XXXX, 一个美好的意愿
	char * key;             // json内容那块的 key名称 	
	union {
		char * vs;      // type == CJSON_STRING, 是一个字符串 	
		double vd;      // type == CJSON_NUMBER, 是一个num值, ((int)c->vd) 转成int 或 bool
	};
};

//定义cjson_t json类型
typedef struct cjson * cjson_t;

//
// cjson_delete - 删除json串内容  
// c		: 待释放json_t串内容
// return	: void
//
extern void cjson_delete(cjson_t c);

//
// cjson_newxxx - 通过特定源, 得到内存中json对象
// str		: 普通格式的串
// path		: json 文件路径
// return	: 解析好的 json_t对象, 失败为 NULL
//
extern cjson_t cjson_newstr(const char * str);

```