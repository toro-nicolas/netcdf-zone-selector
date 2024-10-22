/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The main file of the project
*/
/**
 * @file main.cc
 * @brief The main file of the project
 * @author Nicolas TORO
 */

#include "../include/nc_zone_selector.hh"

int display_help(char **argv)
{
    dprintf(1, "Usage: %s <input.nc> <output.nc> <x_center> <y_center> <z_center> <east> <west> <north> <south> <immersion>\n", argv[0]);
    return 1;
}

int main(int argc, char **argv)
{
    zone_selector zone;

    if (argc != 11 || set_settings(&zone, argc, argv))
        return display_help(argv);
    display_settings(&zone.settings);
    open_file(argv[1], NC_NOWRITE, &zone.file_infos_input.file_id);
    get_infos(&zone.file_infos_input);
    nc_create(argv[2], NC_NETCDF4, &zone.file_infos_output.file_id);
    get_infos(&zone.file_infos_output);

    copy_dimensions(&zone);
    copy_global_attributes(&zone.file_infos_input, &zone.file_infos_output);
    copy_variables(&zone);


    close_file(zone.file_infos_input.file_id);
    close_file(zone.file_infos_output.file_id);
}
