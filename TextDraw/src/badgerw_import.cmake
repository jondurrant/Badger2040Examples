if (NOT DEFINED PIMORONI_DIR)
    set(PIMORONI_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/pimoroni-pico/")
endif()

include_directories(
  ${PIMORONI_DIR}/
)
include(${PIMORONI_DIR}/common/pimoroni_i2c.cmake)
include(${PIMORONI_DIR}/common/pimoroni_bus.cmake)
include(${PIMORONI_DIR}/drivers/uc8151_legacy/uc8151_legacy.cmake)
include(${PIMORONI_DIR}/libraries/badger2040/badger2040.cmake)
include(${PIMORONI_DIR}/libraries/bitmap_fonts/bitmap_fonts.cmake)
include(${PIMORONI_DIR}/libraries/hershey_fonts/hershey_fonts.cmake)
