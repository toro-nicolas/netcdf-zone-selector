/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The file containing the get values functions
*/
/**
 * @file get_values.cc
 * @brief The file containing the get values functions
 * @author Nicolas TORO
 */

#include "../include/nc_zone_selector.hh"

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
                           size_t *in_ai_count, size_t *in_ai_start)
{
    DEBUG;
    fprintf(stderr, RED BOLD "Get an invalid value:" RESET RED " %s: %s\n" RESET, 
    in_s_file.ac_path, in_s_var.ac_var_name);
    free(in_ai_start);
    std::exit(EXIT_FAILURE);
}

/**
 * @brief Get a byte value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The byte value
 */
var_type get_byte_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                        size_t *in_ai_count, size_t *in_ai_start)
{
    signed char out_value[1] = {0};
    int32_t ec = nc_get_vara_schar(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get a char value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The char value
 */
var_type get_char_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                        size_t *in_ai_count, size_t *in_ai_start)
{
    char out_value[1] = {0};
    int32_t ec = nc_get_vara_text(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get a short value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The short value
 */
var_type get_short_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                         size_t *in_ai_count, size_t *in_ai_start)
{
    short out_value[1] = {0};
    int32_t ec = nc_get_vara_short(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get an int value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The int value
 */
var_type get_int_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                       size_t *in_ai_count, size_t *in_ai_start)
{
    int out_value[1] = {0};
    int32_t ec = nc_get_vara_int(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get a float value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The float value
 */
var_type get_float_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                         size_t *in_ai_count, size_t *in_ai_start)
{
    float out_value[1] = {0};
    int32_t ec = nc_get_vara_float(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get a double value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The double value
 */
var_type get_double_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                          size_t *in_ai_count, size_t *in_ai_start)
{
    double out_value[1] = {0};
    int32_t ec = nc_get_vara_double(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get an unsigned byte value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The unsigned byte value
 */
var_type get_ubyte_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                         size_t *in_ai_count, size_t *in_ai_start)
{
    unsigned char out_value[1] = {0};
    int32_t ec = nc_get_vara_ubyte(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get an unsigned short value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The unsigned short value
 */
var_type get_ushort_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                          size_t *in_ai_count, size_t *in_ai_start)
{
    unsigned short out_value[1] = {0};
    int32_t ec = nc_get_vara_ushort(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get an unsigned int value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The unsigned int value
 */
var_type get_uint_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                        size_t *in_ai_count, size_t *in_ai_start)
{
    unsigned int out_value[1] = {0};
    int32_t ec = nc_get_vara_uint(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get an int64 value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The int64 value
 */
var_type get_int64_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                         size_t *in_ai_count, size_t *in_ai_start)
{
    long long out_value[1] = {0};
    int32_t ec = nc_get_vara_longlong(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get an unsigned int64 value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The unsigned int64 value
 */
var_type get_uint64_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                          size_t *in_ai_count, size_t *in_ai_start)
{
    unsigned long long out_value[1] = {0};
    int32_t ec = nc_get_vara_ulonglong(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}

/**
 * @brief Get a string value
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to display
 * @param in_ai_start The values index
 * @return <b>var_type</b> The string value
 */
var_type get_string_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                          size_t *in_ai_count, size_t *in_ai_start)
{
    char *out_value[1] = {0};
    int32_t ec = nc_get_vara_string(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, in_ai_count, out_value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
    return out_value[0];
}
