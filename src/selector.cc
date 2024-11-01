/*
** EPITECH PROJECT, 2024
** netcdf-zone-selector
** File description:
** The selector.c
*/
/**
 * @file selector.c
 * @brief The selector.c
 * @author Nicolas TORO
 */

#include "../include/nc_zone_selector.hh"

/**
 * @brief The selector class constructor
 * @param in_c_variables_map The variables map
 */
selector::selector(boost::program_options::variables_map & in_c_variables_map)
{
    _str_mode = in_c_variables_map["mode"].as<std::string>();
    if (_str_mode == "range") {
        _d_lon_ref = (in_c_variables_map.count("lon_ref") ? in_c_variables_map["lon_ref"].as<double>() : _d_lon_ref);
        _d_lat_ref = (in_c_variables_map.count("lat_ref") ? in_c_variables_map["lat_ref"].as<double>() : _d_lat_ref);
        _d_depth_ref = (in_c_variables_map.count("depth_ref") ? in_c_variables_map["depth_ref"].as<double>() : _d_depth_ref);
        _d_lon_east = (in_c_variables_map.count("lon_east") ? in_c_variables_map["lon_east"].as<double>() : _d_lon_east);
        _d_lon_west = (in_c_variables_map.count("lon_west") ? in_c_variables_map["lon_west"].as<double>() : _d_lon_west);
        _d_lat_north = (in_c_variables_map.count("lat_north") ? in_c_variables_map["lat_north"].as<double>() : _d_lat_north);
        _d_lat_south = (in_c_variables_map.count("lat_south") ? in_c_variables_map["lat_south"].as<double>() : _d_lat_south);
        _d_depth_up = (in_c_variables_map.count("depth_up") ? in_c_variables_map["depth_up"].as<double>() : _d_depth_up);
        _d_depth_down = (in_c_variables_map.count("depth_down") ? in_c_variables_map["depth_down"].as<double>() : _d_depth_down);
        if (in_c_variables_map.count("lon1") || in_c_variables_map.count("lat1")
        || in_c_variables_map.count("depth1") || in_c_variables_map.count("lon2")
        || in_c_variables_map.count("lat2") || in_c_variables_map.count("depth2")) {
            std::cerr << YELLOW BOLD "WARNING: " RESET YELLOW
                << "You are using the range mode, the cubic mode variables will be ignored." RESET << std::endl;
        }
    } else if (_str_mode == "cubic") {
        _d_lon1 = (in_c_variables_map.count("lon1") ? in_c_variables_map["lon1"].as<double>() : _d_lon1);
        _d_lat1 = (in_c_variables_map.count("lat1") ? in_c_variables_map["lat1"].as<double>() : _d_lat1);
        _d_depth1 = (in_c_variables_map.count("depth1") ? in_c_variables_map["depth1"].as<double>() : _d_depth1);
        _d_lon2 = (in_c_variables_map.count("lon2") ? in_c_variables_map["lon2"].as<double>() : _d_lon2);
        _d_lat2 = (in_c_variables_map.count("lat2") ? in_c_variables_map["lat2"].as<double>() : _d_lat2);
        _d_depth2 = (in_c_variables_map.count("depth2") ? in_c_variables_map["depth2"].as<double>() : _d_depth2);
        if (in_c_variables_map.count("lat_ref") || in_c_variables_map.count("lon_ref")
        || in_c_variables_map.count("depth_ref") || in_c_variables_map.count("lat_north")
        || in_c_variables_map.count("lat_south") || in_c_variables_map.count("lon_east")
        || in_c_variables_map.count("lon_west") || in_c_variables_map.count("depth_up")
        || in_c_variables_map.count("depth_down")) {
            std::cerr << YELLOW BOLD "WARNING: " RESET YELLOW
                << "You are using the cubic mode, the range mode variables will be ignored." RESET << std::endl;
        }
    }

    _s_input_file.ac_path = (char *)in_c_variables_map["input"].as<std::string>().c_str();
    open_file(_s_input_file, NC_NOWRITE);
    get_info(_s_input_file);
    _s_output_file.ac_path = (char *)in_c_variables_map["output"].as<std::string>().c_str();
    create_file(_s_output_file, NC_NETCDF4);

    std::cout << "Selector created." << std::endl;
}

/**
 * @brief The selector class destructor
 */
selector::~selector()
{
    close_file(_s_input_file);
    close_file(_s_output_file);
    std::cout << "Selector clean." << std::endl;
}

/**
 * @brief Check the longitude value and correct it
 * @param in_d_lon The longitude value to check
 * @return <b>void</b>
 */
void check_longitude(double & in_d_lon)
{
    while (in_d_lon > 180.0)
        in_d_lon -= 360.0;
    while (in_d_lon < -180.0)
        in_d_lon += 360.0;
}

/**
 * @brief Check the latitude value and correct it
 * @param in_d_lat The latitude value to check
 * @return <b>void</b>
 */
void check_latitude(double & in_d_lat)
{
    while (in_d_lat > 90.0)
        in_d_lat -= 180.0;
    while (in_d_lat < -90.0)
        in_d_lat += 180.0;
}

/**
 * @brief Execute the selector from the range mode
 * @return <b>void</b>
 */
void selector::range() {
    std::string str_proj_definition = "+proj=tmerc +lat_0=" +
        std::to_string(_d_lat_ref) + " +lon_0=" + std::to_string(_d_lon_ref)
        + " +ellps=WGS84 +datum=WGS84 +units=m";
    PJ_CONTEXT *ps_proj_context = proj_context_create();
    PJconsts *ps_proj = proj_create(ps_proj_context, str_proj_definition.c_str());
    if (ps_proj == nullptr) {
        std::cerr << RED BOLD "ERROR: " RESET RED "Projection error." RESET << std::endl;
        std::exit(EXIT_FAILURE);
    }

    PJ_COORD s_coord1_xy = proj_coord(_d_lon_west, _d_lat_south, 0, 0);
    PJ_COORD s_coord2_xy = proj_coord(_d_lon_east, _d_lat_north, 0, 0);
    PJ_COORD s_coord1_latlon = proj_trans(ps_proj, PJ_INV, s_coord1_xy);
    PJ_COORD s_coord2_latlon = proj_trans(ps_proj, PJ_INV, s_coord2_xy);

    _d_lon1 = proj_todeg(s_coord1_latlon.lp.lam);
    _d_lat1 = proj_todeg(s_coord1_latlon.lp.phi);
    _d_depth1 = _d_depth_up;
    _d_lon2 = proj_todeg(s_coord2_latlon.lp.lam);
    _d_lat2 = proj_todeg(s_coord2_latlon.lp.phi);
    _d_depth2 = _d_depth_down;

    std::cout << BOLD UNDERLINE "Selected range:" RESET << std::endl;
    std::cout << "\t- Central point: " << _d_lon_ref << "°, " << _d_lat_ref << "°, " << _d_depth_ref << "m" << std::endl;
    std::cout << "\t- Longitude: " << _d_lon_west << "m <---> " << _d_lon_east << "m" << std::endl;
    std::cout << "\t- Latitude: " << _d_lat_south << "m <---> " << _d_lat_north << "m" << std::endl;
    std::cout << "\t- Depth: " << _d_depth_up << "m <---> " << _d_depth_down << "m"<< std::endl;
}

/**
 * @brief Execute the selector from the cubic mode
 * @return <b>void</b>
 */
void selector::cubic() {
    check_longitude(_d_lon1);
    check_longitude(_d_lon2);
    check_latitude(_d_lat1);
    check_latitude(_d_lat2);

    std::cout << BOLD UNDERLINE "Selected zone:" RESET << std::endl;
    std::cout << "\t- Longitude: " << _d_lon1 << "° <---> " << _d_lon2 << "°" << std::endl;
    std::cout << "\t- Latitude: " << _d_lat1 << "° <---> " << _d_lat2 << "°" << std::endl;
    std::cout << "\t- Depth: " << _d_depth1 << "m <---> " << _d_depth2 << "m"<< std::endl;

    add_globals_attributes();
    copy_dimensions();
    copy_variables();
}
