/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The main file of the project
*/
/**
 * @file variables.cc
 * @brief The main file of the project
 * @author Nicolas TORO
 */

#include "../include/nc_zone_selector.hh"

void fill_dimensions_variables(zone_selector *zone, variable_informations *current_var)
{
    size_t count = 1;
    size_t start = 0;

    if (strcmp(current_var->var_name, "lat") == 0) {
        if (current_var->type == NC_FLOAT) {
            float *lat_data = (float *)calloc(1, sizeof(float));
            for (size_t i = 0; i < get_dimension_size(zone->file_infos_input.file_id, "lat"); i++) {
                check_error(nc_get_vara_float(zone->file_infos_input.file_id, current_var->id, &i, &count, lat_data));
                if ((zone->settings.first_corner.y < zone->settings.second_corner.y &&
                lat_data[0] >= zone->settings.first_corner.y && lat_data[0] <= zone->settings.second_corner.y) ||
                (zone->settings.first_corner.y > zone->settings.second_corner.y &&
                (lat_data[0] >= zone->settings.first_corner.y || lat_data[0] <= zone->settings.second_corner.y))) {
                    check_error(nc_put_var1_float(zone->file_infos_output.file_id, current_var->id, &start, &lat_data[0]));
                    start++;
                }
            }
        } else if (current_var->type == NC_DOUBLE) {
            double *lat_data = (double *)calloc(1, sizeof(double));
            for (size_t i = 0; i < get_dimension_size(zone->file_infos_input.file_id, "lat"); i++) {
                check_error(nc_get_vara_double(zone->file_infos_input.file_id, current_var->id, &i, &count, lat_data));
                if ((zone->settings.first_corner.y < zone->settings.second_corner.y &&
                lat_data[0] >= zone->settings.first_corner.y && lat_data[0] <= zone->settings.second_corner.y) ||
                (zone->settings.first_corner.y > zone->settings.second_corner.y &&
                (lat_data[0] >= zone->settings.first_corner.y || lat_data[0] <= zone->settings.second_corner.y))) {
                    check_error(nc_put_var1_double(zone->file_infos_output.file_id, current_var->id, &start, &lat_data[0]));
                    start++;
                }
            }
        }
    } else if (strcmp(current_var->var_name, "lon") == 0) {
        if (current_var->type == NC_FLOAT) {
            float *lon_data = (float *)calloc(1, sizeof(float));
            for (size_t i = 0; i < get_dimension_size(zone->file_infos_input.file_id, "lon"); i++) {
                check_error(nc_get_vara_float(zone->file_infos_input.file_id, current_var->id, &i, &count, lon_data));
                if ((zone->settings.first_corner.x < zone->settings.second_corner.x &&
                lon_data[0] >= zone->settings.first_corner.x && lon_data[0] <= zone->settings.second_corner.x) ||
                (zone->settings.first_corner.x > zone->settings.second_corner.x &&
                (lon_data[0] >= zone->settings.first_corner.x || lon_data[0] <= zone->settings.second_corner.x))) {
                    check_error(nc_put_var1_float(zone->file_infos_output.file_id, current_var->id, &start, &lon_data[0]));
                    start++;
                }
            }
        } else if (current_var->type == NC_DOUBLE) {
            double *lon_data = (double *)calloc(1, sizeof(double));
            for (size_t i = 0; i < get_dimension_size(zone->file_infos_input.file_id, "lon"); i++) {
                check_error(nc_get_vara_double(zone->file_infos_input.file_id, current_var->id, &i, &count, lon_data));
                if ((zone->settings.first_corner.x < zone->settings.second_corner.x &&
                lon_data[0] >= zone->settings.first_corner.x && lon_data[0] <= zone->settings.second_corner.x) ||
                (zone->settings.first_corner.x > zone->settings.second_corner.x &&
                (lon_data[0] >= zone->settings.first_corner.x || lon_data[0] <= zone->settings.second_corner.x))) {
                    check_error(nc_put_var1_double(zone->file_infos_output.file_id, current_var->id, &start, &lon_data[0]));
                    start++;
                }
            }
        }
    } else if (strcmp(current_var->var_name, "depth") == 0) {
        if (current_var->type == NC_FLOAT) {
            float *depth_data = (float *)calloc(1, sizeof(float));
            for (size_t i = 0; i < get_dimension_size(zone->file_infos_input.file_id, "depth"); i++) {
                check_error(nc_get_vara_float(zone->file_infos_input.file_id, current_var->id, &i, &count, depth_data));
                if ((zone->settings.first_corner.z < zone->settings.second_corner.z &&
                depth_data[0] >= zone->settings.first_corner.z && depth_data[0] <= zone->settings.second_corner.z) ||
                (zone->settings.first_corner.z > zone->settings.second_corner.z &&
                (depth_data[0] >= zone->settings.first_corner.z || depth_data[0] <= zone->settings.second_corner.z))) {
                    check_error(nc_put_var1_float(zone->file_infos_output.file_id, current_var->id, &start, &depth_data[0]));
                    start++;
                }
            }
        } else if (current_var->type == NC_DOUBLE) {
            double *depth_data = (double *)calloc(1, sizeof(double));
            for (size_t i = 0; i < get_dimension_size(zone->file_infos_input.file_id, "depth"); i++) {
                check_error(nc_get_vara_double(zone->file_infos_input.file_id, current_var->id, &i, &count, depth_data));
                if ((zone->settings.first_corner.z < zone->settings.second_corner.z &&
                depth_data[0] >= zone->settings.first_corner.z && depth_data[0] <= zone->settings.second_corner.z) ||
                (zone->settings.first_corner.z > zone->settings.second_corner.z &&
                (depth_data[0] >= zone->settings.first_corner.z || depth_data[0] <= zone->settings.second_corner.z))) {
                    check_error(nc_put_var1_double(zone->file_infos_output.file_id, current_var->id, &start, &depth_data[0]));
                    start++;
                }
            }
        }
    }
}

void set_variables_header(zone_selector *zone)
{
    for (int var = 0; var < zone->file_infos_input.nb_variables; var++) {
        variable_informations current_var = {0};
        current_var.id = var;
        current_var.data_size = 1;

        check_error(nc_inq_var(zone->file_infos_input.file_id, current_var.id,
          current_var.var_name, &current_var.type, &current_var.ndims,
          current_var.dimids, &current_var.natts));
        check_error(nc_def_var(zone->file_infos_output.file_id, current_var.var_name,
        current_var.type, current_var.ndims, current_var.dimids, &current_var.id));
        copy_variable_attributes(&zone->file_infos_input, &zone->file_infos_output, current_var.id);
        fill_dimensions_variables(zone, &current_var);
    }
}

void set_variables_data(zone_selector *zone)
{
    double *depth_data = (double *)calloc(1, sizeof(double));
    /*int var_id, int att_len, char *att_name) = {
      NULL, &copy_attributes_byte, &copy_attributes_char, &copy_attributes_short,
      &copy_attributes_int, &copy_attributes_float, &copy_attributes_double,
      &copy_attributes_ubyte, &copy_attributes_ushort, &copy_attributes_uint,
      &copy_attributes_int64, &copy_attributes_uint64, &copy_attributes_string};*/

    for (int var = 0; var < zone->file_infos_input.nb_variables; var++) {
        variable_informations current_var = {0};
        current_var.id = var;
        current_var.data_size = 1;
        size_t count = 1;
        size_t start[2] = {0};

        check_error(nc_inq_var(zone->file_infos_input.file_id, current_var.id,
          current_var.var_name, &current_var.type, &current_var.ndims,
          current_var.dimids, &current_var.natts));
        if (strcmp(current_var.var_name, "lat") == 0 || strcmp(current_var.var_name, "lon") == 0
        || strcmp(current_var.var_name, "depth") == 0)
            continue;
        if (current_var.type == NC_DOUBLE) {
            //check_error(nc_put_var1_double(zone->file_infos_output.file_id, current_var.id, start, &depth_data[0]));
            for (int index = 0; index < current_var.ndims; index++)
                check_error(nc_inq_dimlen(zone->file_infos_input.file_id,
                current_var.dimids[index], &current_var.dims_size[index]));
            for (int index = 0; index < current_var.ndims; index++)
                current_var.data_size *= current_var.dims_size[index];
            printf("Data size: %zu\n", current_var.data_size);
        }
        
    }
}

void copy_variables(zone_selector *zone)
{
    set_variables_header(zone);
    set_variables_data(zone);
}