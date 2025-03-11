#include "head.h"
#include "sort.h"
//定义一个包装器函数便于跨平台。static限制了该函数的作用域仅限于当前的源文件。
static i32 compare_warpper(void* context, const void* a, const void* b)//第一个参数来源于qsort的第五个参数，第2，3个参数也由qsort函数把两个需要比较的元素指针传递给warpper。
{
	callback_pointer compare = (callback_pointer)context;//使compare拥有要调用的compare函数地址。

	return compare(a, b, NULL);//1.return ：返回值给qsort，负值第一个元素在第二个之前，正值第一个元素在第二个之后，为0则不排序. 2. comapre : 调用compare.c中的对应函数,并声明想要的比较函数所需要的参数顺序。
}

void generic_sort(void* array, size_t member, size_t size, callback_pointer function_pointer, void* context)//于主函数中被调用，此时function_pointer地址与要调用的compare类特定函数地址相同。
{
	//typedef i32(*callback_pointer)(const void* a, const void* b, void* context);定义的函数指针形式。
#ifdef _WIN32
	qsort_s(array, member, size, compare_warpper, (void*)function_pointer);//windows平台，此处第四个参数调用一个包装器。第五个参数把要调用的compare类函数地址传递给context。
#else
	qsort_r(array, member, size, compare_warpper, context);//非Windows平台。包装器会直接把context认为是传入的比较函数的地址。
#endif
}

/*
	Windows 的 qsort_s 要求比较函数的原型类似于：int compare(void* context, const void* a, const void* b);
	(qsort_s默认第五个参数传递给比较函数的第一个参数）。

	非 Windows 平台的 qsort_r 在风格不同的情况下要求不同，此处我们只处理了当qsort_r要求比较函数与qsort_s相同的情况。
	当风格为GNU时,必须重新再写一个包装器函数以转换参数顺序。

	若直接传递比较函数的指针，会导致不同平台上参数传递错误，因此需要包装器函数来调整传递参数的顺序


*/