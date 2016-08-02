#include <util.hpp>

#include <GL/glew.h>
#include <iostream>

void printGLErrorLog()
{
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL error " << error << ": ";
        const char *e =
            error == GL_INVALID_OPERATION             ? "GL_INVALID_OPERATION" :
            error == GL_INVALID_ENUM                  ? "GL_INVALID_ENUM" :
            error == GL_INVALID_VALUE                 ? "GL_INVALID_VALUE" :
            error == GL_INVALID_INDEX                 ? "GL_INVALID_INDEX" :
            "unknown";
        std::cerr << e << std::endl;

        // Throwing here allows us to use the debugger stack trace to track
        // down the error.
#ifndef __APPLE__
        // But don't do this on OS X. It might cause a premature crash.
        // http://lists.apple.com/archives/mac-opengl/2012/Jul/msg00038.html
        throw;
#endif
    }
}
