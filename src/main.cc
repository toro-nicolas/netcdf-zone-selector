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

/**
 * @brief Check if there is an error
 * @param in_i_error The error code
 * @param in_ac_file The file name
 * @param in_i_line The line number
 * @param in_ac_func The function name
 * @return <b>void</b>
 */
void check_error(int in_i_error, const char *in_ac_file,
                 const int in_i_line, const char *in_ac_func)
{
    if (in_i_error != 0) {
        #ifdef DEBUG_MODE
        std::cerr << RED BOLD "ERROR: " RESET RED << in_ac_file << ":" << in_i_line << ": " << in_ac_func << RESET << std::endl;
        #endif
        std::cerr << RED BOLD "Error information: " RESET RED << nc_strerror(in_i_error) << RESET << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Display the help message
 * @param argv The program arguments
 * @param c_desc The program options description
 * @return <b>void</b>
 */
void display_help(char **argv, boost::program_options::options_description &c_desc)
{
    std::cout << BOLD "Usage: " RESET << argv[0] << " [OPTIONS] ..." << std::endl << std::endl;
    std::cout << BOLD UNDERLINE "DESCRIPTION" RESET << std::endl;
    std::cout << "\tExtract a zone from a NetCDF or GRIB file." << std::endl << std::endl;
    std::cout << BOLD UNDERLINE "OPTIONS" RESET << std::endl;
    std::cout << c_desc;
}

int main(int argc, char **argv) {
    boost::program_options::options_description c_desc("");
    c_desc.add_options()
        ("help,h", "Show help section")
        ("input,i", boost::program_options::value<std::string>()->required(),
         "The input NetCDF or GRIB file to extract zone")
        ("output,o", boost::program_options::value<std::string>()->required(),
         "The output NetCDF file to save the zone")
        ("mode,m", boost::program_options::value<std::string>()->required(),
         "Mode to select zone: 'range' or 'cubic'")
        ("lon_ref", boost::program_options::value<double>(),
        "Reference longitude [RANGE MODE]: central longitude of the zone")
        ("lat_ref", boost::program_options::value<double>(),
        "Reference latitude [RANGE MODE]: central latitude of the zone")
        ("depth_ref", boost::program_options::value<double>(),
        "Reference depth [RANGE MODE]: central depth of the zone")
        ("lon_east", boost::program_options::value<double>(),
        "Longitude east [RANGE MODE]: distance from the central longitude to the eastern longitude")
        ("lon_west", boost::program_options::value<double>(),
        "Longitude west [RANGE MODE]: distance from the central longitude to the western longitude")
        ("lat_north", boost::program_options::value<double>(),
        "Latitude north [RANGE MODE]: distance from the central latitude to the northern latitude")
        ("lat_south", boost::program_options::value<double>(),
        "Latitude south [RANGE MODE]: distance from the central latitude to the southern latitude")
        ("depth_up", boost::program_options::value<double>(),
        "Depth up [RANGE MODE]: distance from the central depth to the upper depth")
        ("depth_down", boost::program_options::value<double>(),
        "Depth down [RANGE MODE]: distance from the central depth to the lower depth")
        ("lat1", boost::program_options::value<double>(),
        "Latitude 1 [CUBIC MODE]: latitude of the first corner of the cubic zone")
        ("lon1", boost::program_options::value<double>(),
        "Longitude 1 [CUBIC MODE]: longitude of the first corner of the cubic zone")
        ("depth1", boost::program_options::value<double>(),
        "Depth 1 [CUBIC MODE]: depth of the first corner of the cubic zone")
        ("lat2", boost::program_options::value<double>(),
        "Latitude 2 [CUBIC MODE]: latitude of the second corner of the cubic zone")
        ("lon2", boost::program_options::value<double>(),
        "Longitude 2 [CUBIC MODE]: longitude of the second corner of the cubic zone")
        ("depth2", boost::program_options::value<double>(),
        "Depth 2 [CUBIC MODE]: depth of the second corner of the cubic zone");
    boost::program_options::variables_map c_variables_map;

    try {
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, c_desc), c_variables_map);

        if (c_variables_map.count("help")) {
            display_help(argv, c_desc);
            return EXIT_SUCCESS;
        } else if (c_variables_map.count("mode")) {
            std::string mode = c_variables_map["mode"].as<std::string>();
            if (mode != "range" && mode != "cubic") {
                throw boost::program_options::validation_error(
                    boost::program_options::validation_error::invalid_option_value,
                    "mode", mode);
            }
        }

        boost::program_options::notify(c_variables_map);
    } catch (const boost::program_options::error &e) {
        std::cerr << RED BOLD "ERROR: " RESET RED << e.what() << RESET
                  << std::endl;
        display_help(argv, c_desc);
        return EXIT_FAILURE;
    }

    selector c_selector(c_variables_map);
    if (c_variables_map["mode"].as<std::string>() == "range")
        c_selector.range();
    c_selector.cubic();
    return EXIT_SUCCESS;
}
