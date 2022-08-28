add_executable(hello_async_await
	hello_async_await.cpp
)

target_compile_features(hello_async_await PUBLIC cxx_std_17)
target_link_libraries(hello_async_await Threads::Threads)
