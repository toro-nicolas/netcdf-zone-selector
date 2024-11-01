/*
** SEAGNAL PROJECT, 2024
** netcdf-assembler
** File description:
** The header file of the get_var_value function
*/
/**
 * @file get_values.hh
 * @brief The header file of the get_var_value function
 * @author Nicolas TORO
 */

#include "nc_zone_selector.hh"

#ifndef GET_VALUES_HH_
    #define GET_VALUES_HH_

/**
 * @brief Get an invalid value
 * @note Exit the program
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The invalid value
 */
var_type get_invalid_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                           size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get a byte value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The byte value
 */
var_type get_byte_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                        size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get a char value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The char value
 */
var_type get_char_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                        size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get a short value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The short value
 */
var_type get_short_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                         size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get an int value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The int value
 */
var_type get_int_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                       size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get a float value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The float value
 */
var_type get_float_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                         size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get a double value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The double value
 */
var_type get_double_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                          size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get an unsigned byte value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The unsigned byte value
 */
var_type get_ubyte_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                         size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get an unsigned short value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The unsigned short value
 */
var_type get_ushort_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                          size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get an unsigned int value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The unsigned int value
 */
var_type get_uint_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                        size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get an int64 value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The int64 value
 */
var_type get_int64_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                         size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get an unsigned int64 value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The unsigned int64 value
 */
var_type get_uint64_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                          size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get a string value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The string value
 */
var_type get_string_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                          size_t *in_ai_count, size_t *in_ai_start);

/**
 * @brief Get the value of a variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @return <b>T</b> The value
 */
template <typename T>
T get_var_value(file_information_t & in_s_file, variable_information_t & in_s_current_var,
                size_t *in_ai_start)
{
    static var_type (*get_value_functions[])(file_information_t & in_s_file,
    variable_information_t & in_s_var, size_t *in_ai_count, size_t *in_ai_start) = {
      &get_invalid_value, &get_byte_value, &get_char_value,
      &get_short_value, &get_int_value,
      &get_float_value, &get_double_value, &get_ubyte_value,
      &get_ushort_value, &get_uint_value, &get_int64_value,
      &get_uint64_value, &get_string_value};
    static size_t ai_count[NC_MAX_VAR_DIMS] = {0};

    if (ai_count[0] == 0) { 
        for (int32_t i_count_index = 0; i_count_index < NC_MAX_VAR_DIMS; i_count_index++)
            ai_count[i_count_index] = 1;
    }
    return std::get<T>(get_value_functions[in_s_current_var.i_type](in_s_file, in_s_current_var, ai_count, in_ai_start));
}

#endif /* GET_VALUES_HH_ */
