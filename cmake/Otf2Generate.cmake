add_custom_target(generate)
add_custom_target(clean-generated)

macro(generate_otf2_file target_name infile outfile)
    add_custom_target(${target_name}
                      COMMAND otf2-template ${infile} ${outfile})
endmacro(generate_otf2_file)

macro(add_genclean target_name file_path)
    add_custom_target("${target_name}"
                      COMMAND rm ${file_path})
endmacro(add_genclean)

macro(generate_otf2_files pattern substitute input_path output_path filelist)
    foreach(infilename ${filelist})
        string(REGEX REPLACE ${pattern} ${substitute} outfilename ${infilename})

        set(infile_path ${CMAKE_CURRENT_SOURCE_DIR}/${input_path}/${infilename})
        set(outfile_path ${CMAKE_CURRENT_SOURCE_DIR}/${output_path}/${outfilename})

        generate_otf2_file(${outfilename} ${infile_path} ${outfile_path})
        add_dependencies(generate ${outfilename})

        SET(clean_file_target "clean_${outfilename}")
        add_genclean(${clean_file_target} "${CMAKE_CURRENT_SOURCE_DIR}/${output_path}/${outfilename}")
        add_dependencies(clean-generated ${clean_file_target})
    endforeach()
endmacro(generate_otf2_files)

macro(generate_otf2_cpp input_path output_path filelist)
    generate_otf2_files(".tmpl.cpp\$" ".cpp" ${input_path} ${output_path} "${filelist}")
endmacro(generate_otf2_cpp)

macro(generate_otf2_hpp input_path output_path filelist)
    generate_otf2_files(".tmpl.hpp\$" ".hpp" ${input_path} ${output_path} "${filelist}")
endmacro(generate_otf2_hpp)
