/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The main file of the project
*/
/**
 * @file error.cc
 * @brief The file containing the error handling functions
 * @author Nicolas TORO
 */

#include "../include/nc_zone_selector.hh"

void check_error(int error)
{
    if (error != 0) {
        fprintf(stderr, "%s\n", nc_strerror(error));
        exit(1);
    }
}

int set_settings(zone_selector *zone, int argc, char **argv)
{
    static CT_PROJ proj;

    zone->settings = {0};
    zone->settings.x = atof(argv[3]);
    zone->settings.y = atof(argv[4]);
    zone->settings.z = atof(argv[5]);
    zone->settings.north = atof(argv[6]);
    zone->settings.east = atof(argv[7]);
    zone->settings.south = atof(argv[8]);
    zone->settings.west = atof(argv[9]);
    zone->settings.immersion = atof(argv[10]);
    zone->settings.initiale_cord.x = zone->settings.x;
    zone->settings.initiale_cord.y = zone->settings.y;
    zone->settings.initiale_cord.z = zone->settings.z;
    zone->settings.first_corner.x = zone->settings.x - zone->settings.east;
    zone->settings.first_corner.y = zone->settings.y - zone->settings.north;
    zone->settings.first_corner.z = zone->settings.z;
    zone->settings.second_corner.x = zone->settings.x + zone->settings.west;
    zone->settings.second_corner.y = zone->settings.y + zone->settings.south;
    zone->settings.second_corner.z = zone->settings.z - zone->settings.immersion;
    proj.f_utm_to_wgs84(zone->settings.initiale_cord);
    proj.f_utm_to_wgs84(zone->settings.first_corner);
    proj.f_utm_to_wgs84(zone->settings.second_corner);
    zone->settings.initiale_cord.x = fmod(zone->settings.initiale_cord.x, ((zone->settings.initiale_cord.x > 0) ? -180 : 180));
    zone->settings.initiale_cord.y = fmod(zone->settings.initiale_cord.y, ((zone->settings.initiale_cord.x > 0) ? -90 : 90));
    zone->settings.first_corner.x = fmod(zone->settings.first_corner.x, ((zone->settings.first_corner.x > 0) ? -180 : 180));
    zone->settings.first_corner.y = fmod(zone->settings.first_corner.y, ((zone->settings.first_corner.x > 0) ? -90 : 90));
    zone->settings.second_corner.x = fmod(zone->settings.second_corner.x, ((zone->settings.second_corner.x > 0) ? -180 : 180));
    zone->settings.second_corner.y = fmod(zone->settings.second_corner.y, ((zone->settings.second_corner.x > 0) ? -90 : 90));
    return 0;
}

void display_settings(settings_t *settings)
{
    printf("Initiale point: UTM: %f %f %f WGS84: %f %f %f\n",
    settings->x, settings->y, settings->z, settings->initiale_cord.x,
    settings->initiale_cord.y, settings->initiale_cord.z);
    printf("Zone coordinates:   North: %f, East: %f, South: %f, West: %f\n", settings->north, settings->east, settings->south, settings->west);
    printf("First corner: %f %f %f\n", settings->first_corner.x, settings->first_corner.y, settings->first_corner.z);
    printf("Second corner: %f %f %f\n", settings->second_corner.x, settings->second_corner.y, settings->second_corner.z);
}
