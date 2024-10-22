/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The main file of the project
*/
/**
 * @file file.cc
 * @brief The file containing the NetCDF file functions
 * @author Nicolas TORO
 */

#include "../include/nc_zone_selector.hh"

void open_file(char *path, int mode, int *file_id)
{
    check_error(nc_open(path, mode, file_id));
}

void get_infos(file_informations *file_infos)
{
    check_error(nc_inq(file_infos->file_id, &file_infos->nb_dimensions,
        &file_infos->nb_variables, &file_infos->nb_attributes,
        &file_infos->unlimited_dimensions_id));
}

void close_file(int file_id)
{
    check_error(nc_close(file_id));
}
