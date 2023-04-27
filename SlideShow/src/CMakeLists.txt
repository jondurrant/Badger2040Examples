add_executable(${NAME}
        main.cpp
        #badger2040_image.cpp
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} pico_stdlib badger2040 hardware_spi)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# enable usb output, disable uart output
pico_enable_stdio_usb(${NAME} 1)
pico_enable_stdio_uart(${NAME} 0)
