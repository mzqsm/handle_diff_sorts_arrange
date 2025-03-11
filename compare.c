#include "head.h"
#include "compare.h"
#include "struct.h"

i32 compare_int(const void* a, const void* b, void* context)//a是一个一级指针
{
	(void*)context;

	i32 arg1 = *(const i32*)a;//不能写成const i32 a,这样显示转换的是a本身，而a本身是一个一级指针。
	i32 arg2 = *(const i32*)b;

	return arg1 - arg2;
}

i32 compare_string(const void* a, const void* b, void* context)//这里的a就已经是一个二级指针了。
{
	(void*)context;

	char* string1 = *(const char**)a;//不论我是传递了一个char*形式或者是array[i]形式的字符串，其都是以地址的形式存储在a中的，也就是a就已经是一个二级指针了，而我如果用char* string = char* a的话，就把a从二级指针转化为了一级指针，此时传递给string的地址就不是字符串的地址而是指向字符串的指针的地址，而原来的字符串就访问不到了。而用二级指针的话，const char** a这一步就解释了a是一个二级指针，此时我们再解引用，就实现了字符串地址的赋值。

	char* string2 = *(const char**)b;

	return strncmp(string1, string2, SIZE_MAX);//若str1与str2相同，返回0，若在第一个字符不同处str1的字符大于str2的字符，则返回正值，反之返回负值。
}

i32 compare_struct_name(const void* a, const void* b, void* context)//a是一个一级指针
{
	(void*)context;

	const Person* person1 = (const Person*)a;//把a显示转化为指向一个结构体的一级指针。
	const Person* person2 = (const Person*)b;

	return strncmp(person1->name, person2->name, SIZE_MAX);
}

i32 compare_strcut_age(const void* a, const void* b, void* context)//同上
{
	(void*)context;

	const Person* person1 = (const Person*)a;
	const Person* person2 = (const Person*)b;

	return person1->age - person2->age;
}