/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The file containing the set values functions
*/
/**
 * @file set_values.cc
 * @brief The file containing the set values functions
 * @author Nicolas TORO
 */

#include "../include/nc_zone_selector.hh"

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
                       size_t *in_ai_start, var_type in_value)
{
    DEBUG;
    fprintf(stderr, RED BOLD "Set an invalid value:" RESET RED " %s: %s\n" RESET, 
    in_s_file.ac_path, in_s_var.ac_var_name);
    free(in_ai_start);
    std::exit(EXIT_FAILURE);
}

/**
 * @brief Set the value of a byte variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_count The number of values to set
 * @param in_ai_start The values index
 * @return <b>void</b>
 */
void set_byte_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                    size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_schar(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<signed char>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of a char variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_char_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                    size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_text(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<char>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of a short variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_short_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                     size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_short(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<short>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of an int variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_int_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                   size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_int(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<int>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of a float variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_float_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                     size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_float(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<float>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of a double variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_double_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                      size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_double(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<double>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of an unsigned byte variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_ubyte_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                     size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_ubyte(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<unsigned char>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of an unsigned short variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_ushort_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                      size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_ushort(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<unsigned short>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of an unsigned int variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_uint_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                    size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_uint(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<unsigned int>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of an int64 variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_int64_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                     size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_longlong(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<long long>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of an unsigned int64 variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_uint64_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                      size_t *in_ai_start, var_type in_value)
{
    int32_t ec = nc_put_var1_ulonglong(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &std::get<unsigned long long>(in_value));
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Set the value of a string variable
 * @param in_s_file The file information
 * @param in_s_var The variable information
 * @param in_ai_start The values index
 * @param in_value The value to set
 * @return <b>void</b>
 */
void set_string_value(file_information_t & in_s_file, variable_information_t & in_s_var,
                      size_t *in_ai_start, var_type in_value)
{
    const char *value = std::get<char *>(in_value);
    int32_t ec = nc_put_var1_string(in_s_file.i_file_id, in_s_var.i_id, in_ai_start, &value);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Set variable value:" RESET RED " %s: %s: %s\n" RESET, 
        in_s_file.ac_path, in_s_var.ac_var_name, strerror(ec));
        free(in_ai_start);
        std::exit(EXIT_FAILURE);
    }
}

