#include "struct.h"
#include "sort.h"
#include "head.h"
#include "compare.h"

i32 main()
{
	i32 int_array[] = { 1,5,8,6,0,4,44,22,33,66 };

	size_t member_in_int_array = sizeof(int_array) / sizeof(int_array[0]);

	generic_sort(int_array, member_in_int_array, sizeof(i32), compare_int, NULL);//ÉıĞòÅÅĞò

	printf("IntArray = ");

	for (size_t i = 0; i < member_in_int_array; i++)
	{
		printf("%d ", int_array[i]);
	}

	printf("\n");

	const char* string_array[] = { "frank", "kevin", "peter", "bob" };

	size_t member_in_string_array = sizeof(string_array) / sizeof(string_array[0]);

	generic_sort(string_array, member_in_string_array, sizeof(char*), compare_string, NULL);//×ÖÄ¸ÉıĞòÅÅĞò

	printf("StringArray = ");

	for (size_t i = 0; i < member_in_string_array; i++)
	{
		printf("%s ", string_array[i]);
	}

	printf("\n");

	Person person_info[] = {
		{"kevin",20},
		{"alice",30},
		{"ken",25},
		{"haru",13},
		{"riki",18}
	};

	size_t member_in_struct_array = sizeof(person_info) / sizeof(person_info[0]);

	generic_sort(person_info, member_in_struct_array, sizeof(Person), compare_strcut_age, NULL);//ÄêÁä´óĞ¡ÉıĞòÅÅĞò¡£

	printf("Person's info :");

	for (size_t i = 0; i < member_in_struct_array; i++)
	{
		printf("%s %d   ", person_info[i].name, person_info[i].age);
	}

	return EXIT_SUCCESS;
}