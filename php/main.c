#include <stdio.h>
#include <stdlib.h>
#define SAPI_API
#define ABC char 
#define PHPAPI
#define zif_ "zif_"
#define zim_ "zim_"
#define ZEND_FN(name) zif_##name
#define ZEND_MN(name) zim_##name
#define ZEND_FENTRY(zend_name, name, arg_info, flags)	{ #zend_name, name, arg_info, (uint32_t) (sizeof(arg_info)/sizeof(int), flags },

#define ZEND_FE(name, arg_info)						ZEND_FENTRY(name, ZEND_FN(name), arg_info, 0)
#define ZEND_ME(classname, name, arg_info, flags)	ZEND_FENTRY(name, ZEND_MN(classname##_##name), arg_info, flags)

typedef void (*func)(int x,int b);

SAPI_API void show(){
	printf("show\r\n");
}

void zif_test() {
	printf("zif_test");
}
void ma(int x, int b) {
	printf("bb");
}
void main()
{
	ABC a = 's';
	printf("a=%c\r\n",a);
	show();
	func b = ma;
	b(1,2);
	//printf("zend_fn=%s\n", ZEND_ME(test,"show","abc",1));
	
	return;
}

