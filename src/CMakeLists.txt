set(SOURCE_FILES
    main.cpp
)

add_subdirectory(rules)
add_subdirectory(viewer)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE rules viewer)
