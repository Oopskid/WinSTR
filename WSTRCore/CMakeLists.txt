startLib(WSTRCore)

addIncludesAuto(${CMAKE_CURRENT_LIST_DIR}/src CMFT_SRC_c++ Source)
addIncludesAuto(${CMAKE_CURRENT_LIST_DIR}/include CMFT_HEADER_c++ Headers)

add_library(WSTRCore STATIC "${INCLUDES}")
bindIncludes(WSTRCore)

endLib(WSTRCore)