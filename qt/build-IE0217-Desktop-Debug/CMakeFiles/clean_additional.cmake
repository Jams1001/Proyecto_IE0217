# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/IE0217_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/IE0217_autogen.dir/ParseCache.txt"
  "IE0217_autogen"
  )
endif()
