if(WIN32)
    add_definitions(-DMGL_WGL)
elseif (UNIX)
    if (OpenGL_EGL_FOUND)
        add_definitions(-DMGL_EGL)
    endif()
    if (OpenGL_GLX_FOUND)
        add_definitions(-DMGL_GLX)
    endif()
endif()

# GLM Library setup
# https://github.com/g-truc/glm
target_link_libraries( 
    ${MGL_CURRENT_TARGET}
    PUBLIC
    glm::glm
)

# OpenGL Support
# https://www.opengl.org/
target_link_libraries(
    ${MGL_CURRENT_TARGET}
    PUBLIC
    OpenGL::OpenGL
)

# AppCore
target_link_libraries(
    ${MGL_CURRENT_TARGET}
    PRIVATE
    mgl_core::mgl_core
)

# Export library
set(MGL_LIB mgl PARENT_SCOPE)
set(MGL_INCLUDE ${MGL_CURRENT_SOURCE} PARENT_SCOPE)