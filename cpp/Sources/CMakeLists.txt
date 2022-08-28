add_executable(hello_async_await
	hello_async_await.cpp
)
target_compile_features(hello_async_await PUBLIC cxx_std_17)
target_link_libraries(hello_async_await Threads::Threads)

# スレッドプール
add_executable(thread_pool
	thread_pool.cpp
)
target_compile_features(thread_pool PUBLIC cxx_std_17)
target_include_directories(thread_pool PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/asio/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/assert/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/bind/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/config/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/core/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/date_time/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/mpl/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/numeric/conversion/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/preprocessor/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/predef/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/regex/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/smart_ptr/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/static_assert/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/system/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/throw_exception/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/type_traits/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/utility/include
)
target_link_libraries(thread_pool Threads::Threads)

# promise
add_executable(promise_simple
	promise_simple.cpp
)
target_compile_features(promise_simple PUBLIC cxx_std_17)
target_include_directories(promise_simple PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/asio/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/assert/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/bind/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/config/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/core/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/date_time/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/mpl/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/numeric/conversion/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/preprocessor/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/predef/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/regex/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/smart_ptr/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/static_assert/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/system/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/throw_exception/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/type_traits/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/utility/include
)
target_link_libraries(promise_simple Threads::Threads)

# promise thread pool
add_executable(promise_with_thread_pool
	promise_with_thread_pool.cpp
)
target_compile_features(promise_with_thread_pool PUBLIC cxx_std_17)
target_include_directories(promise_with_thread_pool PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/asio/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/assert/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/bind/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/config/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/core/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/date_time/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/mpl/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/numeric/conversion/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/preprocessor/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/predef/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/regex/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/smart_ptr/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/static_assert/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/system/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/throw_exception/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/type_traits/include
	${CMAKE_CURRENT_SOURCE_DIR}/../Externals/boost/utility/include
)
target_link_libraries(promise_with_thread_pool Threads::Threads)