add_executable(weathermap2fg
	logging.cxx
	main.cxx
	utils.cxx
)

target_include_directories(
	weathermap2fg
	PUBLIC
		argparse::argparse
)

install(TARGETS weathermap2fg RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

