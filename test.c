#include "scjson.h"

int main(int argc, char * argv[]) {
    	// 测试json 串
	char jstr[] = "{\n\"name\": \"Jack (\\\"Bee\\\") Nimble\", \n\"format\": {\"type\":[1, 3, 4, 5.66], \n\"height\":     1080, \n\"interlace\":  false}\n}";

	printf("源码串 :\n %s\n", jstr);

	// 先生成 json 对象
	cjson_t root = cjson_newstr(jstr);
	if (root == NULL) {
		puts("jstr 解析失败! 程序退出中....");
		exit(EXIT_FAILURE);
	}

	//这里简单测试输出内容
	char * njstr = cjson_getstr(root);

	if (njstr == NULL) {
		puts("输出内容失败,程序退出中!");
		cjson_delete(root);
		exit(EXIT_FAILURE);
	}

	//合法范围直接输出 内容
	printf("解析串 :\n %s\n", njstr);

	//解析完需要释放
	free(njstr);

	//解析好 一定要注意释放操作
	cjson_delete(root);
}
