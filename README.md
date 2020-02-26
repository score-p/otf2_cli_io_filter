# TODOs
* Add source code generation to build
```sh
otf2-template src/templates/definition_callbacks.tmpl.cpp src/definition_callbacks.cpp
otf2-template src/templates/definition_callbacks.tmpl.hpp src/include/definition_callbacks.hpp
otf2-template src/templates/otf2_writer.tmpl.hpp src/include/otf2_writer.hpp
otf2-template src/templates/trace_writer.tmpl.hpp src/include/trace_writer.hpp
otf2-template src/templates/trace_writer.tmpl.cpp src/trace_writer.cpp
otf2-template src/templates/trace_reader.tmpl.cpp src/trace_reader.cpp
```
* Add source code formating to build in case of generating
```sh
clang-format -i *.cpp *.hpp
```