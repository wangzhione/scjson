#include "json.h"

//
// json main run ...
//
int main(int argc, char * argv[]) {
    const char * jtr = "{\"name\" : \"nihao\", \"nums\" : -123,  }";
    json_t r = json_create(jtr);
    if (NULL == r) {
        fprintf(stderr, "json_create is err %s\n", jtr);
        return EXIT_FAILURE;
    }
    printf("r type = %d\n", r->type);

    char * str = json_print(r);
    printf("jstr = %s\n", jtr);
    printf("str  = %s\n", str);
    free(str);
    json_delete(r);
    
    // 第二轮开始测试
    jtr = "{\n\"name\": \"Jack (\\\"Bee\\\") 你好\", \n\"format\": {\"type\":[1, 3, 4, 5.66], \n\"height\":     1080, \n\"interlace\":  false}\n}";
    r = json_create(jtr);
    if (NULL == r) {
        fprintf(stderr, "json_create is err jstr %s\n", jtr);
        return EXIT_FAILURE;
    }
    str = json_print(r);
    printf("str  = %s\n", str);
    free(str);
    json_delete(r);
    return EXIT_SUCCESS;
}
