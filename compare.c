#include "head.h"
#include "compare.h"
#include "struct.h"

i32 compare_int(const void* a, const void* b, void* context)//a��һ��һ��ָ��
{
	(void*)context;

	i32 arg1 = *(const i32*)a;//����д��const i32 a,������ʾת������a������a������һ��һ��ָ�롣
	i32 arg2 = *(const i32*)b;

	return arg1 - arg2;
}

i32 compare_string(const void* a, const void* b, void* context)//�����a���Ѿ���һ������ָ���ˡ�
{
	(void*)context;

	char* string1 = *(const char**)a;//�������Ǵ�����һ��char*��ʽ������array[i]��ʽ���ַ������䶼���Ե�ַ����ʽ�洢��a�еģ�Ҳ����a���Ѿ���һ������ָ���ˣ����������char* string = char* a�Ļ����Ͱ�a�Ӷ���ָ��ת��Ϊ��һ��ָ�룬��ʱ���ݸ�string�ĵ�ַ�Ͳ����ַ����ĵ�ַ����ָ���ַ�����ָ��ĵ�ַ����ԭ�����ַ����ͷ��ʲ����ˡ����ö���ָ��Ļ���const char** a��һ���ͽ�����a��һ������ָ�룬��ʱ�����ٽ����ã���ʵ�����ַ�����ַ�ĸ�ֵ��

	char* string2 = *(const char**)b;

	return strncmp(string1, string2, SIZE_MAX);//��str1��str2��ͬ������0�����ڵ�һ���ַ���ͬ��str1���ַ�����str2���ַ����򷵻���ֵ����֮���ظ�ֵ��
}

i32 compare_struct_name(const void* a, const void* b, void* context)//a��һ��һ��ָ��
{
	(void*)context;

	const Person* person1 = (const Person*)a;//��a��ʾת��Ϊָ��һ���ṹ���һ��ָ�롣
	const Person* person2 = (const Person*)b;

	return strncmp(person1->name, person2->name, SIZE_MAX);
}

i32 compare_strcut_age(const void* a, const void* b, void* context)//ͬ��
{
	(void*)context;

	const Person* person1 = (const Person*)a;
	const Person* person2 = (const Person*)b;

	return person1->age - person2->age;
}