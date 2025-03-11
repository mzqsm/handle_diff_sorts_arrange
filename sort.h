#pragma once

#include <stddef.h>

typedef int i32;

typedef i32(*callback_pointer)(const void* a, const void* b, void* context);

void generic_sort(void* array, size_t member, size_t size, callback_pointer function_pointer, void* context);
