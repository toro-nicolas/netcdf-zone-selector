/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The main file of the project
*/
/**
 * @file attributs.cc
 * @brief The main file of the project
 * @author Nicolas TORO
 */

#include "../include/nc_zone_selector.hh"

void copy_attributes_byte(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    signed char *value = (signed char *)calloc(att_len, sizeof(signed char));

    nc_get_att_schar(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_schar(file_infos_output->file_id, var_id, att_name, NC_BYTE, att_len, value);
    free(value);
}

void copy_attributes_char(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    char *value = (char *)calloc(att_len, sizeof(char));

    nc_get_att_text(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_text(file_infos_output->file_id, var_id, att_name, att_len, value);
    free(value);
}

void copy_attributes_short(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    short *value = (short *)calloc(att_len, sizeof(short));

    nc_get_att_short(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_short(file_infos_output->file_id, var_id, att_name, NC_SHORT, att_len, value);
    free(value);
}

void copy_attributes_int(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    int *value = (int *)calloc(att_len, sizeof(int));

    nc_get_att_int(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_int(file_infos_output->file_id, var_id, att_name, NC_INT, att_len, value);
    free(value);
}

void copy_attributes_float(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    float *value = (float *)calloc(att_len, sizeof(float));

    nc_get_att_float(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_float(file_infos_output->file_id, var_id, att_name, NC_FLOAT, att_len, value);
    free(value);
}

void copy_attributes_double(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    double *value = (double *)calloc(att_len, sizeof(double));

    nc_get_att_double(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_double(file_infos_output->file_id, var_id, att_name, NC_DOUBLE, att_len, value);
    free(value);
}

void copy_attributes_ubyte(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    unsigned char *value = (unsigned char *)calloc(att_len, sizeof(unsigned char));

    nc_get_att_ubyte(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_ubyte(file_infos_output->file_id, var_id, att_name, NC_UBYTE, att_len, value);
    free(value);
}

void copy_attributes_ushort(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    unsigned short *value = (unsigned short *)calloc(att_len, sizeof(unsigned short));

    nc_get_att_ushort(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_ushort(file_infos_output->file_id, var_id, att_name, NC_USHORT, att_len, value);
    free(value);
}

void copy_attributes_uint(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    unsigned int *value = (unsigned int *)calloc(att_len, sizeof(unsigned int));

    nc_get_att_uint(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_uint(file_infos_output->file_id, var_id, att_name, NC_UINT, att_len, value);
    free(value);
}

void copy_attributes_int64(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    long long *value = (long long *)calloc(att_len, sizeof(long long));

    nc_get_att_longlong(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_longlong(file_infos_output->file_id, var_id, att_name, NC_INT64, att_len, value);
    free(value);
}

void copy_attributes_uint64(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    unsigned long long *value = (unsigned long long *)calloc(att_len, sizeof(unsigned long long));

    nc_get_att_ulonglong(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_ulonglong(file_infos_output->file_id, var_id, att_name, NC_UINT64, att_len, value);
    free(value);
}

void copy_attributes_string(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name)
{
    char **value = (char **)calloc(att_len, sizeof(char *));

    nc_get_att_string(file_infos_input->file_id, var_id, att_name, value);
    nc_put_att_string(file_infos_output->file_id, var_id, att_name, att_len, (const char **)value);
    free(value);
}

void copy_global_attributes(file_informations *file_infos_input, file_informations *file_infos_output)
{
    static void (*copy_attributes[])(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name) = {
      NULL, &copy_attributes_byte, &copy_attributes_char, &copy_attributes_short,
      &copy_attributes_int, &copy_attributes_float, &copy_attributes_double,
      &copy_attributes_ubyte, &copy_attributes_ushort, &copy_attributes_uint,
      &copy_attributes_int64, &copy_attributes_uint64, &copy_attributes_string};

    for (int att = 0; att < file_infos_input->nb_attributes; att++) {
        char att_name[NC_MAX_NAME + 1];
        nc_type type = 0;
        size_t att_len = 0;

        check_error(nc_inq_attname(file_infos_input->file_id, NC_GLOBAL, att, att_name));
        check_error(nc_inq_att(file_infos_input->file_id, NC_GLOBAL, att_name, &type, &att_len));
        if (type < 0 || type > 12)
            type = 0;
        copy_attributes[type](file_infos_input, file_infos_output, NC_GLOBAL, att_len, att_name);
    }
}

void copy_variable_attributes(file_informations *file_infos_input, file_informations *file_infos_output, int var_id)
{
    static void (*copy_attributes[])(file_informations *file_infos_input, file_informations *file_infos_output,
    int var_id, int att_len, char *att_name) = {
      NULL, &copy_attributes_byte, &copy_attributes_char, &copy_attributes_short,
      &copy_attributes_int, &copy_attributes_float, &copy_attributes_double,
      &copy_attributes_ubyte, &copy_attributes_ushort, &copy_attributes_uint,
      &copy_attributes_int64, &copy_attributes_uint64, &copy_attributes_string};
    int nb_attributes = 0;

    check_error(nc_inq_varnatts(file_infos_input->file_id, var_id, &nb_attributes));
    for (int att = 0; att < nb_attributes; att++) {
        char att_name[NC_MAX_NAME + 1];
        nc_type type = 0;
        size_t att_len = 0;

        check_error(nc_inq_attname(file_infos_input->file_id, var_id, att, att_name));
        check_error(nc_inq_att(file_infos_input->file_id, var_id, att_name, &type, &att_len));
        copy_attributes[type](file_infos_input, file_infos_output, var_id, att_len, att_name);
    }
}
