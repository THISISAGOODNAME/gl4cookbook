set(boilerplate_SOURCES main.cpp ${GLAD_FILES})

add_executable(boilerplate ${boilerplate_SOURCES})
target_link_libraries(boilerplate ${COMMON_LIBS})