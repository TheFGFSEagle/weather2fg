add_executable(weather2fg
	logging.cxx
	main.cxx
	utils.cxx
)

target_link_libraries(
	weather2fg
	argparse::argparse
)

install(TARGETS weather2fg RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

