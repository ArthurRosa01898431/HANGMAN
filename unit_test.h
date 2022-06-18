#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);

Status test_get_size_on_init_default_returns_0(char* buffer, int length);

Status test_arosa_my_string_destroys_nullfies_valid_object(char* buffer, int length);

Status test_arosa_my_string_init_c_string_put_correct_c_string(char* buffer, int length);

Status test_arosa_my_string_get_capacity_returns_correct_capacity(char* buffer, int length);

Status test_arosa_my_string_get_size_returns_correct_size(char* buffer, int length);

Status test_arosa_my_string_compare_identical_strings_return_0(char* buffer, int length);

Status test_arosa_my_string_extraction_returns_failure_when_object_is_null(char* buffer, int length);

Status test_arosa_get_size_on_my_string_insertion_with_valid_object_returns_0(char* buffer, int length);

Status test_arosa_get_size_on_my_string_push_back_returns_size_plus_1(char* buffer, int length);

Status test_arosa_my_string_insertion_returns_0_when_size_equal_0(char* buffer, int length);

Status test_arosa_get_capacity_on_my_string_push_back_when_size_greater_than_or_equal_to_capacity_returns_capacity_times_2(char* buffer, int length);

Status test_arosa_my_string_push_back_returns_0_when_object_is_NULL(char* buffer, int length);

Status test_arosa_my_string_at_on_init_default_returns_NULL(char* buffer, int length);

Status test_arosa_get_size_on_my_string_pop_back_returns_size_minus_one(char* buffer, int length);

Status test_arosa_my_string_at_on_my_string_c_str_when_idex_is_size_returns_NULL(char* buffer, int length);

Status test_arosa_my_string_concat_returns_FAILURE_when_Append_String_is_NULL(char* buffer, int length);

Status test_arosa_my_string_empty_on_init_default_returns_TRUE(char* buffer, int length);

Status test_arosa_my_string_empty_on_init_c_string_returns_FALSE(char* buffer, int length);

Status test_arosa_my_string_concat_worked_succefully_with_two_valid_strings(char* buffer, int length);

Status test_arosa_my_string_pop_back_on_init_default_returns_0(char* buffer, int length);

Status test_arosa_my_string_at_out_of_bounds_on_init_default_c_string_returns_NULL(char* buffer, int length);

Status test_arosa_get_capacity_on_init_default_returns_7(char* buffer, int length);

Status test_arosa_get_size_on_my_string_init_c_string_returns_c_string_length(char* buffer, int length);


Status test_arosa_get_capacitiy_on_my_string_init_c_string_returns_c_string_length_plus_one(char* buffer, int length);

//add
//
//
Status test_nwright_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_nwright_compare_on_init_default_returns_0(char* buffer, int length);
Status test_nwright_my_string_init_c_string_with_string_Hello(char* buffer, int length);
Status test_nwright_size_with_string_Hello_returns_5(char* buffer, int length);
Status test_nwright_capacity_with_string_Hello_returns_6(char* buffer, int length);
Status test_nwright_compare_with_string_Hello_returns_0(char* buffer, int length);
Status test_nwright_extraction_and_insertion_using_simple(char* buffer, int length);
Status test_nwright_push_back_with_init_default_returns_SUCCESS(char* buffer, int length);
Status test_nwright_push_back_with_init_default_updates_size(char* buffer, int length);
Status test_nwright_pop_back_with_init_default_and_push_back_char_a_returns_success(char* buffer, int length);
Status test_nwright_pop_back_with_init_default_and_push_back_char_a_updates_size(char* buffer, int length);
Status test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_success(char* buffer, int length);
Status test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_5(char* buffer, int length);
Status test_nwright_my_string_at_0_with_init_default_returns_NULL(char* buffer, int length);
Status test_nwright_my_string_at_negative_1_with_init_default_returns_NULL(char* buffer, int length);
Status test_nwright_my_string_at_10_with_init_default_returns_NULL(char* buffer, int length);
Status test_nwright_my_string_at_0_with_string_hello(char* buffer, int length);
Status test_nwright_my_string_at_negative_1_with_string_hello(char* buffer, int length);
Status test_nwright_my_string_at_10_with_string_hello(char* buffer, int length);
Status test_nwright_c_str_with_init_defaults_returns_string(char* buffer, int length);
Status test_nwright_c_str_with_init_defaults_has_size_0(char* buffer, int length);
Status test_nwright_c_str_with_string_hello_returns_string(char* buffer, int length);
Status test_nwright_c_str_with_string_hello_has_size_5(char* buffer, int length);
#endif
