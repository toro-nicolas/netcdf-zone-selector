# 📚 netcdf-zone-selector 🗺️


## Table of contents 📑
- [Description](https://github.com/toro-nicolas/netcdf-zone-selector/blob/main/README.md#description-)
- [Usage](https://github.com/toro-nicolas/netcdf-zone-selector/blob/main/README.md#usage-%EF%B8%8F)
- [Compilation](https://github.com/toro-nicolas/netcdf-zone-selector/blob/main/README.md#compilation-%EF%B8%8F)
- [Documentation](https://github.com/toro-nicolas/netcdf-zone-selector/blob/main/README.md#documentation-)
- [Code mandatory](https://github.com/toro-nicolas/netcdf-zone-selector/blob/main/README.md#code-mandatory-)
- [Contributors](https://github.com/toro-nicolas/netcdf-zone-selector/blob/main/README.md#contributors-)


## Description 📝
The **netcdf-zone-selector** is a project from my internship at [Seagnal](https://www.seagnal.fr/), during my **2nd year** in [**EPITECH**](https://www.epitech.eu/) Grand Ecole program.  
Its purpose is to create in [**C++**](https://en.wikipedia.org/wiki/C%2B%2B) a program for extract a zone from a [NetCDF](https://en.wikipedia.org/wiki/NetCDF) (or [GRIB](https://en.wikipedia.org/wiki/GRIB)) file.


## Usage ⚔️
You can run netcdf-zone-selector like this :
```sh
./netcdf-zone-selector --input input_file.nc --output output_file.nc --mode range --lat_ref 0 --lon_ref 0 --lat_north 111000 --lat_north 111000 --lon_west 111000 --lon_east 111000
```

For more information, please see the help section.
```sh
> ./netcdf-zone-selector --help
Usage: ./netcdf-zone-selector [OPTIONS] ...

DESCRIPTION
        Extract a zone from a NetCDF or GRIB file.

OPTIONS
  -h [ --help ]         Show help section
  -i [ --input ] arg    The input NetCDF or GRIB file to extract zone
  -o [ --output ] arg   The output NetCDF file to save the zone
  -m [ --mode ] arg     Mode to select zone: 'range' or 'cubic'
  --lon_ref arg         Reference longitude [RANGE MODE]: central longitude of the zone
  --lat_ref arg         Reference latitude [RANGE MODE]: central latitude of the zone
  --depth_ref arg       Reference depth [RANGE MODE]: central depth of the zone
  --lon_east arg        Longitude east [RANGE MODE]: distance from the central longitude to the eastern longitude
  --lon_west arg        Longitude west [RANGE MODE]: distance from the central longitude to the western longitude
  --lat_north arg       Latitude north [RANGE MODE]: distance from the central latitude to the northern latitude
  --lat_south arg       Latitude south [RANGE MODE]: distance from the central latitude to the southern latitude
  --depth_up arg        Depth up [RANGE MODE]: distance from the central depth to the upper depth
  --depth_down arg      Depth down [RANGE MODE]: distance from the central depth to the lower depth
  --lat1 arg            Latitude 1 [CUBIC MODE]: latitude of the first corner of the cubic zone
  --lon1 arg            Longitude 1 [CUBIC MODE]: longitude of the first cornerof the cubic zone
  --depth1 arg          Depth 1 [CUBIC MODE]: depth of the first corner of the cubic zone
  --lat2 arg            Latitude 2 [CUBIC MODE]: latitude of the second corner of the cubic zone
  --lon2 arg            Longitude 2 [CUBIC MODE]: longitude of the second corner of the cubic zone
  --depth2 arg          Depth 2 [CUBIC MODE]: depth of the second corner of the cubic zone
```

Here is the list of default settings:
```sh
lon_ref = 0.0°
lat_ref = 0.0°
depth_ref = 0.0m
lon_east = 0.0m
lon_west = 0.0m
lat_north = 0.0m
lat_south = 0.0m
depth_up = max double
depth_down = min double
lon1 = -180.0°
lon2 = 180.0°
lat1 = -90.0°
lat2 = 90.0°
depth1 = max double
depth2 = min double
```


## Compilation 🛠️
[**NetCDF lib**](https://docs.unidata.ucar.edu/netcdf-c/current/) is required to compile the project.

You can compile the project with this command :
```sh
make
```

If you want to debug the program, you can compile the project with this :
```sh
make debug 
```

If you want clean the project, you can run this command :
```sh
make fclean
```

You can clean and compile the project with ```make re``` and for debugging ```make re_debug```


## Documentation 📚
The documentation is accessible [here](https://toro-nicolas.github.io/netcdf-zone-selector/html/).

You can generate the documentation with this command :
```sh
make doc
```
You need multiple package for generate them :
- doxygen
- doxygen-latex
- doxygen-doxywizard
- graphviz


## Code mandatory 📦
- You'll need to create a branch where you'll push your code. Once you've completed your tasks on this branch, we'll work together to merge it and check that everything works.
- Every function you add must be documented and code-style with Seagnal's coding style.
- If the github actions don't succeed, then ask yourself some questions
- Each commit will contain ```[+]``` or ```[-]``` or ```[~]``` followed by a message
    - ```[+]``` : Add feature
    - ```[-]``` : Delete feature
    - ```[~]``` : Edit feature

**Of course, in exceptional cases, we may depart from these rules.**


## Contributors 👤
This project was carried out alone by [**Nicolas TORO**](https://github.com/toro-nicolas).
