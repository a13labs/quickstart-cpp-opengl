# SDL - Simple DirectMedia Layer
# https://www.libsdl.org/
target_link_libraries( 
    ${APP_CURRENT_TARGET}
    PUBLIC
    SDL2::SDL2main SDL2::SDL2
)

# AppCore
target_link_libraries(
    ${APP_CURRENT_TARGET}
    PRIVATE
    ${MGL_CORE_LIB}
)

# mgl
target_link_libraries(
    ${APP_CURRENT_TARGET}
    PRIVATE
    ${MGL_LIB}
)

# Export library
set(MGL_WINDOW_LIB appwindow PARENT_SCOPE)
set(MGL_WINDOW_INCLUDE ${APP_CURRENT_SOURCE} PARENT_SCOPE)