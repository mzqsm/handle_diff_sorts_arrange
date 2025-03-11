#pragma once

typedef int i32;

i32 compare_int(const void* a, const void* b, void* context);

i32 compare_string(const void* a, const void* b, void* context);

i32 compare_struct_name(const void* a, const void* b, void* context);

i32 compare_strcut_age(const void* a, const void* b, void* context);