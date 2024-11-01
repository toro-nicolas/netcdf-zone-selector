import argparse
import xarray as xr
import sys

def grib_to_netcdf(grib_file, nc_file):
    ds = xr.open_dataset(grib_file, engine='cfgrib')

    lat_name = ""
    if "latitude" in ds:
        lat_name = "latitude"
    elif "lat" in ds:
        lat_name = "lat"
    if lat_name != "" and ds[lat_name][0] > ds[lat_name][-1]:
        ds = ds.sortby(lat_name)

    lon_name = ""
    if "longitude" in ds:
        lon_name = "longitude"
    elif "lon" in ds:
        lon_name = "lon"
    if lon_name != "" and ds[lon_name][0] > ds[lon_name][-1]:
        ds = ds.sortby(lon_name)

    ds.to_netcdf(nc_file)
    print(f"\n{grib_file} ---> {nc_file}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Convert GRIB file to a NetCDF file")
    parser.add_argument('input', type=str, help='The GRIB file to convert.')
    parser.add_argument('output', type=str, help='The path to the NetCDF converted file.')
    args = parser.parse_args()
    try:
        grib_to_netcdf(args.input, args.output)
    except:
        print("Cannot convert GRIB to NetCDF. File is not in a valid GRIB format.", file=sys.stderr)