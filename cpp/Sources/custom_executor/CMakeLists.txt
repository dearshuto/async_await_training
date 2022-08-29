add_executable(custom_executor
    Main.cpp
)
target_compile_features(custom_executor PUBLIC cxx_std_17)
target_include_directories(custom_executor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/asio/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/assert/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/bind/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/config/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/core/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/date_time/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/mpl/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/numeric/conversion/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/preprocessor/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/predef/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/regex/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/smart_ptr/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/static_assert/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/system/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/throw_exception/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/type_traits/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/boost/utility/include
)
target_link_libraries(custom_executor Threads::Threads)
