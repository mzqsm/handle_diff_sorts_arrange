#include "head.h"
#include "sort.h"
//����һ����װ���������ڿ�ƽ̨��static�����˸ú���������������ڵ�ǰ��Դ�ļ���
static i32 compare_warpper(void* context, const void* a, const void* b)//��һ��������Դ��qsort�ĵ������������2��3������Ҳ��qsort������������Ҫ�Ƚϵ�Ԫ��ָ�봫�ݸ�warpper��
{
	callback_pointer compare = (callback_pointer)context;//ʹcompareӵ��Ҫ���õ�compare������ַ��

	return compare(a, b, NULL);//1.return ������ֵ��qsort����ֵ��һ��Ԫ���ڵڶ���֮ǰ����ֵ��һ��Ԫ���ڵڶ���֮��Ϊ0������. 2. comapre : ����compare.c�еĶ�Ӧ����,��������Ҫ�ıȽϺ�������Ҫ�Ĳ���˳��
}

void generic_sort(void* array, size_t member, size_t size, callback_pointer function_pointer, void* context)//���������б����ã���ʱfunction_pointer��ַ��Ҫ���õ�compare���ض�������ַ��ͬ��
{
	//typedef i32(*callback_pointer)(const void* a, const void* b, void* context);����ĺ���ָ����ʽ��
#ifdef _WIN32
	qsort_s(array, member, size, compare_warpper, (void*)function_pointer);//windowsƽ̨���˴����ĸ���������һ����װ���������������Ҫ���õ�compare�ຯ����ַ���ݸ�context��
#else
	qsort_r(array, member, size, compare_warpper, context);//��Windowsƽ̨����װ����ֱ�Ӱ�context��Ϊ�Ǵ���ıȽϺ����ĵ�ַ��
#endif
}

/*
	Windows �� qsort_s Ҫ��ȽϺ�����ԭ�������ڣ�int compare(void* context, const void* a, const void* b);
	(qsort_sĬ�ϵ�����������ݸ��ȽϺ����ĵ�һ����������

	�� Windows ƽ̨�� qsort_r �ڷ��ͬ�������Ҫ��ͬ���˴�����ֻ�����˵�qsort_rҪ��ȽϺ�����qsort_s��ͬ�������
	�����ΪGNUʱ,����������дһ����װ��������ת������˳��

	��ֱ�Ӵ��ݱȽϺ�����ָ�룬�ᵼ�²�ͬƽ̨�ϲ������ݴ��������Ҫ��װ���������������ݲ�����˳��


*/