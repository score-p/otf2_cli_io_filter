# otf2_io_filter
This tool filters I/O events and definitions of selected files out of an OTF2 trace file.
Files are selected with shell glob patterns in a filter file.
After a successful execution, *otf2_io_filter* creates a new trace file without the filtered I/O events and definitions.

## Dependencies
* CMake >= 3.10
* Compiler that supports C++17
* OTF2 >= 2.1
* GNU C Library for pattern matching (`fnmatch`)

## Building
```sh
~> mkdir build && cd build
~> cmake .. -DCMAKE_INSTALL_PREFIX=/install/path
~> cmake --build . --target install
```

## Usage
Basically, the tool can be used as follows:
```sh
otf2_filter_io --input /input/trace.otf2 --output /output/folder --filter /path/to/filter_file
```
The number of threads can be set with `--threads` and the default is `2`.
The filter file should contain shell glob patterns for example:
```
/etc/foo.cfg
/proc/*
```
In this case, I/O events/definitions are filtered out which are connected to files in `/proc/`
and the single `foo.cfg` file.

## Developer's Corner
### Generate Reader/Write API
```sh
~> make generate
```

### Clean generated files
```sh
~> make clean-generated
```

### Format source code
```sh
~> make clangformat
```
### Tests
```sh
~> make test
```

## Todos
* `make clean` deletes generate files, it is better to create a new command for that
* log the filtered files

## Known issues
### I/O handle parent points to different file
If the parent of a filtered handle points to a different file,
the handle and their events are filtered out but the file definition still exists.

This could be fixed, when the filter callback is allowed to modify the arguments
which will be passed to the writer.
