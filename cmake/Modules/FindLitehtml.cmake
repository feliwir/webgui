# - Try to find LiteHTML
# Once done this will define
#  LiteHTML_FOUND - System has LiteHTML
#  LiteHTML_INCLUDE_DIRS - The LiteHTML include directories
#  LiteHTML_LIBRARIES - The libraries needed to use LiteHTML

find_path(LiteHTML_INCLUDE_DIR litehtml.h
          PATH_SUFFIXES liblitehtml)

find_library(LiteHTML_LIBRARY NAMES litehtml liblitehtml)

set(LiteHTML_LIBRARIES ${LiteHTML_LIBRARY} )
set(LiteHTML_INCLUDE_DIRS ${LiteHTML_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LiteHTML_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(LiteHTML DEFAULT_MSG
                                  LiteHTML_LIBRARY LiteHTML_INCLUDE_DIR)

mark_as_advanced(LiteHTML_INCLUDE_DIR LiteHTML_LIBRARY )