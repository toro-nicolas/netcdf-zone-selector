/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The main file of the project
*/
/**
 * @file dimensions.cc
 * @brief The main file of the project
 * @author Nicolas TORO
 */

#include "../include/nc_zone_selector.hh"

size_t get_dimension_size(int file_id, const char *dim_name)
{
    int dimid = 0;
    size_t dim_len = 0;
    
    check_error(nc_inq_dimid(file_id, dim_name, &dimid));
    check_error(nc_inq_dimlen(file_id, dimid, &dim_len));
    return dim_len;
}

void copy_dimensions(zone_selector *zone)
{

    for (int dim = 0; dim < zone->file_infos_input.nb_dimensions; dim++) {
        char dim_name[NC_MAX_NAME + 1];
        size_t dim_len = 0;
        int dim_id = 0;

        check_error(nc_inq_dim(zone->file_infos_input.file_id, dim, dim_name, &dim_len));
        if (strcmp(dim_name, "lat") == 0) {
            zone->dim_lat_id.old_id = dim;
            check_error(nc_def_dim(zone->file_infos_output.file_id, "lat", NC_UNLIMITED, &zone->dim_lat_id.new_id));
        } else if (strcmp(dim_name, "lon") == 0) {
            zone->dim_lon_id.old_id = dim;
            check_error(nc_def_dim(zone->file_infos_output.file_id, "lon", NC_UNLIMITED, &zone->dim_lon_id.new_id));
        } else if (strcmp(dim_name, "depth") == 0) {
            zone->dim_depth_id.old_id = dim;
            check_error(nc_def_dim(zone->file_infos_output.file_id, "depth", NC_UNLIMITED, &zone->dim_depth_id.new_id));
        } else
            nc_def_dim(zone->file_infos_output.file_id, dim_name, dim_len, &dim_id);
    }
}
