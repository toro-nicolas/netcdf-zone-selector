/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The header file of the project
*/
/**
 * @file nc_zone_selector.h
 * @brief The header file of the project
 * @author Nicolas TORO
 */

#include <netcdf.h>
//#include <hdf5.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include "../lib/proj.hh"

#ifndef NC_ZONE_SELECTOR_H_
    #define EMODNC_ZONE_SELECTOR_H_

typedef struct dim_id_s {
    int old_id = -1;
    int new_id = -1;
} dim_id;

typedef struct settings_s {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    double north = 0.0;
    double east = 0.0;
    double south = 0.0;
    double west = 0.0;
    double immersion = 0.0;
    double3_t initiale_cord = {0.0, 0.0, 0.0};
    double3_t first_corner = {0.0, 0.0, 0.0};
    double3_t second_corner = {0.0, 0.0, 0.0};
} settings_t;

typedef struct file_informations_s {
    int file_id = 0;
    int nb_dimensions = 0;
    int nb_variables = 0;
    int nb_attributes = 0;
    int unlimited_dimensions_id = 0;
} file_informations;

typedef struct variable_informations_s {
    int id = 0;
    char var_name[NC_MAX_NAME + 1] = {0};
    nc_type type = 0;
    int ndims = 0;
    int dimids[NC_MAX_VAR_DIMS] = {0};
    int natts = 0;
    size_t dims_size[NC_MAX_VAR_DIMS] = {0};
    size_t data_size = 0;
} variable_informations;

typedef struct zone_selector_s {
    settings_t settings = {0};
    file_informations file_infos_input = {0};
    file_informations file_infos_output = {0};
    dim_id dim_lat_id = {-1};
    dim_id dim_lon_id = {-1};
    dim_id dim_depth_id = {-1};
} zone_selector;

size_t get_dimension_size(int file_id, const char *dim_name);
void copy_dimensions(zone_selector *zone);
void copy_variables(zone_selector *zone);
void copy_global_attributes(file_informations *file_infos_input, file_informations *file_infos_output);
void copy_variable_attributes(file_informations *file_infos_input, file_informations *file_infos_output, int var_id);
void check_error(int error);
int set_settings(zone_selector *zone, int argc, char **argv);
void display_settings(settings_t *settings);
void open_file(char *path, int mode, int *file_id);
void get_infos(file_informations *file_infos);
void close_file(int file_id);

#endif /* NC_ZONE_SELECTOR_H_ */
