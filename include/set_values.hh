/*
** SEAGNAL PROJECT, 2024
** netcdf-assembler
** File description:
** The header file of the set_var_value function
*/
/**
 * @file set_values.hh
 * @brief The header file of the set_var_value function
 * @author Nicolas TORO
 */

#include "nc_zone_selector.hh"

#ifndef SET_VALUES_HH_
    #define SET_VALUES_HH_

/**
 * @brief Set the value of an invalid variable
 * @note Exit the program
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_invalid_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                       size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of a byte variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to set
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void set_byte_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                    size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of a char variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_char_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                    size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of a short variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_short_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                     size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of an int variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_int_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                   size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of a float variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_float_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                     size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of a double variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_double_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                      size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of an unsigned byte variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_ubyte_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                     size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of an unsigned short variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_ushort_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                      size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of an unsigned int variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_uint_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                    size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of an int64 variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_int64_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                     size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of an unsigned int64 variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_uint64_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                      size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of a string variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_string_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                      size_t *in_ai_start, var_type in_value);

/**
 * @brief Set the value of a variable
 * @param in_s_file The file information
 * @param in_s_current_var The current variable information
 * @param in_ai_start The start index
 * @param in_value The value to set
 * @return <b>void</b>
 */
template <typename T>
void set_var_value(file_information_t & in_s_file, variable_information_t & in_s_current_var,
                   size_t *in_ai_start, T in_value)
{
    static void (*set_value_functions[])(file_information_t & in_s_file,
    variable_information_t & in_s_var, size_t *in_ai_start, var_type in_value) = {
      &set_invalid_value, &set_byte_value, &set_char_value,
      &set_short_value, &set_int_value,
      &set_float_value, &set_double_value, &set_ubyte_value,
      &set_ushort_value, &set_uint_value, &set_int64_value,
      &set_uint64_value, &set_string_value};

    set_value_functions[in_s_current_var.i_type](in_s_file, in_s_current_var, in_ai_start, in_value);
}

#endif /* SET_VALUES_HH_ */
