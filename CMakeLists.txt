zephyr_library_include_directories(.)
FILE(GLOB app_sources *.c)
target_sources(app PRIVATE
  ${app_sources}
  )
