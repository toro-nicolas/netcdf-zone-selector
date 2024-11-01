/*
** SEAGNAL PROJECT, 2024
** netcdf-zone-selector
** File description:
** The file containing the NetCDF file functions
*/
/**
 * @file file.cc
 * @brief The file containing the NetCDF file functions
 * @author Nicolas TORO
 */

#include "../include/nc_zone_selector.hh"

/**
 * @brief Open a NetCDF or a GRIB file
 * @param in_s_file_info The file information
 * @param in_i_mode The mode to open the file
 * @return <b>void</b>
 */
void open_file(file_information_t & in_s_file_info, int in_i_mode)
{
    int32_t ec = nc_open(in_s_file_info.ac_path, in_i_mode, &in_s_file_info.i_file_id);

    if (ec != 0) {
        char ac_exe_path[PATH_MAX] = {0};
        int32_t i_len = readlink("/proc/self/exe", ac_exe_path, sizeof(ac_exe_path) - 1);
        if (i_len == -1) {
            fprintf(stderr, RED BOLD "Error: " RESET RED " Cannot find grib_to_netcdf.py\n" RESET);
            std::exit(1);
        }
        for (int32_t i_index = i_len; i_index > -1; i_index--) {
            if (ac_exe_path[i_index] != '/')
                ac_exe_path[i_index] = '\0';
            else
                break;
        }
        strcat(ac_exe_path, "grib_to_netcdf.py");
        int32_t i_file_name_index = 0;
        for (int32_t i_index = 0; in_s_file_info.ac_path[i_index] != 0; i_index++) {
            if (in_s_file_info.ac_path[i_index] == '/')
                i_file_name_index = i_index + 1;
        }
        std::string str_output = "/tmp/" + std::string(in_s_file_info.ac_path + i_file_name_index) + ".nc";
        const char *astr_convert_args[] = {"/usr/bin/python3", ac_exe_path, in_s_file_info.ac_path, (char *)str_output.c_str(), NULL};
        int32_t i_status = 0;
        pid_t i_pid = fork();
        char **astr_env = environ;

        if (i_pid == -1) {
            fprintf(stderr, RED BOLD "Error:" RESET RED " Cannot execute grib_to_netcdf.py\n" RESET);
            std::exit(1);
        }
        if (i_pid == 0) {
            if (execve(astr_convert_args[0], (char *const *)astr_convert_args, astr_env) == -1) {
                fprintf(stderr, RED BOLD "Error: Conversion to GRIB:" RESET RED " %s\n" RESET, strerror(errno));
                std::exit(errno);
            }
            std::exit(0);
        }
        waitpid(i_pid, &i_status, 0);
        if (WIFSIGNALED(i_status))
            fprintf(stderr, RED BOLD "Error: Conversion to GRIB:" RESET RED " %s\n" RESET, strsignal(WTERMSIG(i_status)));
        if (i_status != 0)
            std::exit(WEXITSTATUS(i_status));
        ec = nc_open(str_output.c_str(), in_i_mode, &in_s_file_info.i_file_id);
        if (ec != 0) {
            DEBUG;
            fprintf(stderr, RED BOLD "Open file:" RESET RED " %s: %s\n" RESET, in_s_file_info.ac_path, nc_strerror(ec));
            std::exit(EXIT_FAILURE);
        }
    }
}

/**
 * @brief Create a NetCDF file
 * @param in_s_file_info The file information
 * @param in_i_mode The mode to open the file
 * @return <b>void</b>
 */
void create_file(file_information_t & in_s_file_info, int in_i_mode)
{
    int32_t ec = nc_create(in_s_file_info.ac_path, in_i_mode, &in_s_file_info.i_file_id);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Create file:" RESET RED " %s: %s\n" RESET, in_s_file_info.ac_path, nc_strerror(ec));
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Get the file information
 * @param in_s_file_info The file information
 * @return <b>void</b>
 */
void get_info(file_information_t & in_s_file_info)
{
    int32_t ec = nc_inq(in_s_file_info.i_file_id, &in_s_file_info.i_nb_dimensions,
        &in_s_file_info.i_nb_variables, &in_s_file_info.i_nb_attributes,
        &in_s_file_info.i_first_unlimited_dimensions_id);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Get file information:" RESET RED " %s: %s\n" RESET, in_s_file_info.ac_path, nc_strerror(ec));
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief Close a NetCDF file
 * @param in_s_file_info The file information
 * @return <b>void</b>
 */
void close_file(file_information_t & in_s_file_info)
{
    int32_t ec = nc_close(in_s_file_info.i_file_id);
    if (ec != 0) {
        DEBUG;
        fprintf(stderr, RED BOLD "Close file:" RESET RED " %s: %s\n" RESET, in_s_file_info.ac_path, nc_strerror(ec));
        std::exit(EXIT_FAILURE);
    }
}
