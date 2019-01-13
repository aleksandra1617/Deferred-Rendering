/**
 * @file
 * @author  Tyrone Davison <t.p.davison@tees.ac.uk>
 * @date    September 2016
 * @version 2.16.4
 *
 * @section DESCRIPTION
 *
 * TGL: A small C API of OpenGL utility functions, especially loading GL
 * functions (upto 4.5) without involving windows.h, whilst hiding
 * prototypes for GL versions other than that which is desired.
 *
 * Usage: Define the desired version of GL and then include this header, e.g.
 * #define TGL_TARGET_GL_3_3
 * #include <tgl/tgl.h>
 * Also ensure tgl.c is compiled and linked into the final binary
 *
 * @section LICENSE
 *
 * Copyright (c) 2016 Tyrone Davison <t.p.davison@tees.ac.uk>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#pragma once
#ifndef __TGL__
#define __TGL__


#define TGL_MAJOR_VERSION 4
#define TGL_MINOR_VERSION 5

#define TGL_VERSION_1_0  1
#define TGL_VERSION_1_1  2
#define TGL_VERSION_1_2  3
#define TGL_VERSION_1_3  4
#define TGL_VERSION_1_4  5
#define TGL_VERSION_1_5  6
#define TGL_VERSION_2_0  7
#define TGL_VERSION_2_1  8
#define TGL_VERSION_3_0  9
#define TGL_VERSION_3_1 10
#define TGL_VERSION_3_2 11
#define TGL_VERSION_3_3 12
#define TGL_VERSION_4_0 13
#define TGL_VERSION_4_1 14
#define TGL_VERSION_4_2 15
#define TGL_VERSION_4_3 16
#define TGL_VERSION_4_4 17
#define TGL_VERSION_4_5 18

#if defined(TGL_TARGET_GL_4_5)
#define TGL_TARGET TGL_VERSION_4_5
#elif defined(TGL_TARGET_GL_4_4)
#define TGL_TARGET TGL_VERSION_4_4
#elif defined(TGL_TARGET_GL_4_3)
#define TGL_TARGET TGL_VERSION_4_3
#elif defined(TGL_TARGET_GL_4_2)
#define TGL_TARGET TGL_VERSION_4_2
#elif defined(TGL_TARGET_GL_4_1)
#define TGL_TARGET TGL_VERSION_4_1
#elif defined(TGL_TARGET_GL_4_0)
#define TGL_TARGET TGL_VERSION_4_0
#elif defined(TGL_TARGET_GL_3_3)
#define TGL_TARGET TGL_VERSION_3_3
#elif defined(TGL_TARGET_GL_3_2)
#define TGL_TARGET TGL_VERSION_3_2
#elif defined(TGL_TARGET_GL_3_1)
#define TGL_TARGET TGL_VERSION_3_1
#elif defined(TGL_TARGET_GL_3_0)
#define TGL_TARGET TGL_VERSION_3_0
#elif defined(TGL_TARGET_GL_2_1)
#define TGL_TARGET TGL_VERSION_2_1
#elif defined(TGL_TARGET_GL_2_0)
#define TGL_TARGET TGL_VERSION_2_0
#elif defined(TGL_TARGET_GL_1_5)
#define TGL_TARGET TGL_VERSION_1_5
#elif defined(TGL_TARGET_GL_1_4)
#define TGL_TARGET TGL_VERSION_1_4
#elif defined(TGL_TARGET_GL_1_3)
#define TGL_TARGET TGL_VERSION_1_3
#elif defined(TGL_TARGET_GL_1_2)
#define TGL_TARGET TGL_VERSION_1_2
#elif defined(TGL_TARGET_GL_1_1)
#define TGL_TARGET TGL_VERSION_1_1
#elif defined(TGL_TARGET_GL_1_0)
#define TGL_TARGET TGL_VERSION_1_0
#else
#pragma message("No target GL version declared, defaulting to GL 3.3")
#pragma message("For example, use #define TGL_TARGET_GL_4_1 before " \
                "including tgl.h to specify OpenGL 4.1")
#define TGL_TARGET TGL_VERSION_3_3
#endif

#if TGL_TARGET >= TGL_VERSION_1_0
#define TGL_DECLARE_CORE_GL_1_0
#endif
#if TGL_TARGET >= TGL_VERSION_1_1
#define TGL_DECLARE_CORE_GL_1_1
#endif
#if TGL_TARGET >= TGL_VERSION_1_2
#define TGL_DECLARE_CORE_GL_1_2
#endif
#if TGL_TARGET >= TGL_VERSION_1_3
#define TGL_DECLARE_CORE_GL_1_3
#endif
#if TGL_TARGET >= TGL_VERSION_1_4
#define TGL_DECLARE_CORE_GL_1_4
#endif
#if TGL_TARGET >= TGL_VERSION_1_5
#define TGL_DECLARE_CORE_GL_1_5
#endif
#if TGL_TARGET >= TGL_VERSION_2_0
#define TGL_DECLARE_CORE_GL_2_0
#endif
#if TGL_TARGET >= TGL_VERSION_2_1
#define TGL_DECLARE_CORE_GL_2_1
#endif
#if TGL_TARGET >= TGL_VERSION_3_0
#define TGL_DECLARE_CORE_GL_3_0
#endif
#if TGL_TARGET >= TGL_VERSION_3_1
#define TGL_DECLARE_CORE_GL_3_1
#endif
#if TGL_TARGET >= TGL_VERSION_3_2
#define TGL_DECLARE_CORE_GL_3_2
#endif
#if TGL_TARGET >= TGL_VERSION_3_3
#define TGL_DECLARE_CORE_GL_3_3
#endif
#if TGL_TARGET >= TGL_VERSION_4_0
#define TGL_DECLARE_CORE_GL_4_0
#endif
#if TGL_TARGET >= TGL_VERSION_4_1
#define TGL_DECLARE_CORE_GL_4_1
#endif
#if TGL_TARGET >= TGL_VERSION_4_2
#define TGL_DECLARE_CORE_GL_4_2
#endif
#if TGL_TARGET >= TGL_VERSION_4_3
#define TGL_DECLARE_CORE_GL_4_3
#endif
#if TGL_TARGET >= TGL_VERSION_4_4
#define TGL_DECLARE_CORE_GL_4_4
#endif
#if TGL_TARGET >= TGL_VERSION_4_5
#define TGL_DECLARE_CORE_GL_4_5
#endif

#if TGL_TARGET < TGL_VERSION_3_3
#define TGL_DECLARE_COMPATIBLE_GL
#endif

#if defined(__APPLE_CC__)
#define TGL_PLATFORM_COCOA
#elif defined(_WIN32)
#define TGL_PLATFORM_WIN32
#else
#error TGL does not recognise the build platform
#endif

#if defined(DEBUG) || defined(_DEBUG)
#define TGL_DEBUG
#endif


/*
 * The following section is lifted directly from glfw.h
 * This is included to avoid needing windows.h on win32 platforms
 * (see http://www.glfw.org/)
 */

#ifndef APIENTRY
#ifdef _WIN32
#define APIENTRY __stdcall
#else
#define APIENTRY
#endif
#define GL_APIENTRY_DEFINED
#endif /* APIENTRY */

/* Under Windows, we need WINGDIAPI defined */
#if !defined(WINGDIAPI) && defined(_WIN32)
#if defined(_MSC_VER) || defined(__BORLANDC__) || defined(__POCC__)
/* Microsoft Visual C++, Borland C++ Builder and Pelles C */
#define WINGDIAPI __declspec(dllimport)
#elif defined(__LCC__)
/* LCC-Win32 */
#define WINGDIAPI __stdcall
#else
/* Others (e.g. MinGW, Cygwin) */
#define WINGDIAPI extern
#endif
#define GL_WINGDIAPI_DEFINED
#endif /* WINGDIAPI */

/* Microsoft Visual C++, Borland C++ and Pelles C <GL*glu.h> needs wchar_t */
#if defined(_WIN32) && (defined(_MSC_VER) || defined(__BORLANDC__) || defined(__POCC__)) && !defined(_WCHAR_T_DEFINED)
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif /* _WCHAR_T_DEFINED */

/*
* End section from glfw.h
*/


/* Supports GLU.h */
#ifndef CALLBACK
#define CALLBACK APIENTRY
#endif


#ifndef TGL_DECLARE_CORE_GL_1_0
#define GL_VERSION_1_0
#endif
#ifndef TGL_DECLARE_CORE_GL_1_1
#define GL_VERSION_1_1
#endif
#ifndef TGL_DECLARE_CORE_GL_1_2
#define GL_VERSION_1_2
#endif
#ifndef TGL_DECLARE_CORE_GL_1_3
#define GL_VERSION_1_3
#endif
#ifndef TGL_DECLARE_CORE_GL_1_4
#define GL_VERSION_1_4
#endif
#ifndef TGL_DECLARE_CORE_GL_1_5
#define GL_VERSION_1_5
#endif
#ifndef TGL_DECLARE_CORE_GL_2_0
#define GL_VERSION_2_0
#endif
#ifndef TGL_DECLARE_CORE_GL_2_1
#define GL_VERSION_2_1
#endif
#ifndef TGL_DECLARE_CORE_GL_3_0
#define GL_VERSION_3_0
#endif
#ifndef TGL_DECLARE_CORE_GL_3_1
#define GL_VERSION_3_1
#endif
#ifndef TGL_DECLARE_CORE_GL_3_2
#define GL_VERSION_3_2
#endif
#ifndef TGL_DECLARE_CORE_GL_3_3
#define GL_VERSION_3_3
#endif
#ifndef TGL_DECLARE_CORE_GL_4_0
#define GL_VERSION_4_0
#endif
#ifndef TGL_DECLARE_CORE_GL_4_1
#define GL_VERSION_4_1
#endif
#ifndef TGL_DECLARE_CORE_GL_4_2
#define GL_VERSION_4_2
#endif
#ifndef TGL_DECLARE_CORE_GL_4_3
#define GL_VERSION_4_3
#endif
#ifndef TGL_DECLARE_CORE_GL_4_4
#define GL_VERSION_4_4
#endif
#ifndef TGL_DECLARE_CORE_GL_4_5
#define GL_VERSION_4_5
#endif

// TODO: all prototypes can be removed from rest of header for non win32 builds
#ifdef TGL_DECLARE_COMPATIBLE_GL
#include <GL/GL.h>
/* The section of code is lifted from various parts of glext.h to define types
   needed for extentions */
#include <stddef.h>
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;
typedef char GLchar;
typedef unsigned short GLhalf;
typedef struct __GLsync *GLsync;
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
typedef uint64_t GLuint64;
typedef int64_t GLint64;
/* end of glext.h code */
#include <GL/glext.h>
#ifdef TGL_PLATFORM_WIN32
#undef TGL_DECLARE_CORE_GL_1_0
#undef TGL_DECLARE_CORE_GL_1_1
#endif
#else
#include <GL/glcorearb.h>
#endif

#ifndef TGL_DECLARE_CORE_GL_1_0
#undef GL_VERSION_1_0
#endif
#ifndef TGL_DECLARE_CORE_GL_1_1
#undef GL_VERSION_1_1
#endif
#ifndef TGL_DECLARE_CORE_GL_1_2
#undef GL_VERSION_1_2
#endif
#ifndef TGL_DECLARE_CORE_GL_1_3
#undef GL_VERSION_1_3
#endif
#ifndef TGL_DECLARE_CORE_GL_1_4
#undef GL_VERSION_1_4
#endif
#ifndef TGL_DECLARE_CORE_GL_1_5
#undef GL_VERSION_1_5
#endif
#ifndef TGL_DECLARE_CORE_GL_2_0
#undef GL_VERSION_2_0
#endif
#ifndef TGL_DECLARE_CORE_GL_2_1
#undef GL_VERSION_2_1
#endif
#ifndef TGL_DECLARE_CORE_GL_3_0
#undef GL_VERSION_3_0
#endif
#ifndef TGL_DECLARE_CORE_GL_3_1
#undef GL_VERSION_3_1
#endif
#ifndef TGL_DECLARE_CORE_GL_3_2
#undef GL_VERSION_3_2
#endif
#ifndef TGL_DECLARE_CORE_GL_3_3
#undef GL_VERSION_3_3
#endif
#ifndef TGL_DECLARE_CORE_GL_4_0
#undef GL_VERSION_4_0
#endif
#ifndef TGL_DECLARE_CORE_GL_4_1
#undef GL_VERSION_4_1
#endif
#ifndef TGL_DECLARE_CORE_GL_4_2
#undef GL_VERSION_4_2
#endif
#ifndef TGL_DECLARE_CORE_GL_4_3
#undef GL_VERSION_4_3
#endif
#ifndef TGL_DECLARE_CORE_GL_4_4
#undef GL_VERSION_4_4
#endif
#ifndef TGL_DECLARE_CORE_GL_4_5
#undef GL_VERSION_4_5
#endif

#ifdef __cplusplus
extern "C" {
#endif


/** Enumeration of supported OpenGL extensions */
typedef enum _TGLEXTENTION {
    TGL_EXTENSION_GL_1_0,
    TGL_EXTENSION_GL_1_1,
    TGL_EXTENSION_GL_1_2,
    TGL_EXTENSION_GL_1_3,
    TGL_EXTENSION_GL_1_4,
    TGL_EXTENSION_GL_1_5,
    TGL_EXTENSION_GL_2_0,
    TGL_EXTENSION_GL_2_1,
    TGL_EXTENSION_GL_3_0,
    TGL_EXTENSION_GL_3_1,
    TGL_EXTENSION_GL_3_2,
    TGL_EXTENSION_GL_3_3,
    TGL_EXTENSION_GL_4_0,
    TGL_EXTENSION_GL_4_1,
    TGL_EXTENSION_GL_4_2,
    TGL_EXTENSION_GL_4_3,
    TGL_EXTENSION_GL_4_4,
    TGL_EXTENSION_GL_4_5,
    TGL_EXTENSION_ARB_DEBUG_OUTPUT,
    TGL_EXTENSION_AMD_DEBUG_OUTPUT,
    TGL_EXTENSION_MAX
} TGLEXTENSION;

/** The recommended method to create vertex buffer offsets. */
#define TGL_BUFFER_OFFSET(i) ((char *)NULL + (i))

/** A variant of TGL_BUFFER_OFFSET based upon stddef's offsetof. */
#define TGL_BUFFER_OFFSET_OF(s,m) ((char*)&(((s*)0)->m))

/** Initialise GL function hooks for all supported extensions. */
void tglInit(void);

/** Query if all functions hooks for a given extension were loaded. */
GLboolean tglIsAvailable(TGLEXTENSION);

/** Log a debug message */
void tglDebugMessage(GLenum severity, const char *msg);

/* GL_version_1_0 */
#ifdef TGL_DECLARE_CORE_GL_1_0
#if defined(TGL_PLATFORM_COCOA) || defined(TGL_PLATFORM_WIN32)
GLAPI void APIENTRY glCullFace(GLenum mode);
GLAPI void APIENTRY glFrontFace(GLenum mode);
GLAPI void APIENTRY glHint(GLenum target, GLenum mode);
GLAPI void APIENTRY glLineWidth(GLfloat width);
GLAPI void APIENTRY glPointSize(GLfloat size);
GLAPI void APIENTRY glPolygonMode(GLenum face, GLenum mode);
GLAPI void APIENTRY glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexParameterf(GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glTexParameteri(GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glTexParameteriv(GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void APIENTRY glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void APIENTRY glDrawBuffer(GLenum mode);
GLAPI void APIENTRY glClear(GLbitfield mask);
GLAPI void APIENTRY glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void APIENTRY glClearStencil(GLint s);
GLAPI void APIENTRY glClearDepth(GLdouble depth);
GLAPI void APIENTRY glStencilMask(GLuint mask);
GLAPI void APIENTRY glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI void APIENTRY glDepthMask(GLboolean flag);
GLAPI void APIENTRY glDisable(GLenum cap);
GLAPI void APIENTRY glEnable(GLenum cap);
GLAPI void APIENTRY glFinish(void);
GLAPI void APIENTRY glFlush(void);
GLAPI void APIENTRY glBlendFunc(GLenum sfactor, GLenum dfactor);
GLAPI void APIENTRY glLogicOp(GLenum opcode);
GLAPI void APIENTRY glStencilFunc(GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void APIENTRY glDepthFunc(GLenum func);
GLAPI void APIENTRY glPixelStoref(GLenum pname, GLfloat param);
GLAPI void APIENTRY glPixelStorei(GLenum pname, GLint param);
GLAPI void APIENTRY glReadBuffer(GLenum mode);
GLAPI void APIENTRY glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
GLAPI void APIENTRY glGetBooleanv(GLenum pname, GLboolean *params);
GLAPI void APIENTRY glGetDoublev(GLenum pname, GLdouble *params);
GLAPI GLenum APIENTRY glGetError(void);
GLAPI void APIENTRY glGetFloatv(GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetIntegerv(GLenum pname, GLint *params);
GLAPI const GLubyte * APIENTRY glGetString(GLenum name);
GLAPI void APIENTRY glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
GLAPI void APIENTRY glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexParameteriv(GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI GLboolean APIENTRY glIsEnabled(GLenum cap);
GLAPI void APIENTRY glDepthRange(GLdouble near, GLdouble far);
GLAPI void APIENTRY glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
#else
#define TGL_DEFINE_CORE_GL_1_0
extern PFNGLCULLFACEPROC glCullFace;
extern PFNGLFRONTFACEPROC glFrontFace;
extern PFNGLHINTPROC glHint;
extern PFNGLLINEWIDTHPROC glLineWidth;
extern PFNGLPOINTSIZEPROC glPointSize;
extern PFNGLPOLYGONMODEPROC glPolygonMode;
extern PFNGLSCISSORPROC glScissor;
extern PFNGLTEXPARAMETERFPROC glTexParameterf;
extern PFNGLTEXPARAMETERFVPROC glTexParameterfv;
extern PFNGLTEXPARAMETERIPROC glTexParameteri;
extern PFNGLTEXPARAMETERIVPROC glTexParameteriv;
extern PFNGLTEXIMAGE1DPROC glTexImage1D;
extern PFNGLTEXIMAGE2DPROC glTexImage2D;
extern PFNGLDRAWBUFFERPROC glDrawBuffer;
extern PFNGLCLEARPROC glClear;
extern PFNGLCLEARCOLORPROC glClearColor;
extern PFNGLCLEARSTENCILPROC glClearStencil;
extern PFNGLCLEARDEPTHPROC glClearDepth;
extern PFNGLSTENCILMASKPROC glStencilMask;
extern PFNGLCOLORMASKPROC glColorMask;
extern PFNGLDEPTHMASKPROC glDepthMask;
extern PFNGLDISABLEPROC glDisable;
extern PFNGLENABLEPROC glEnable;
extern PFNGLFINISHPROC glFinish;
extern PFNGLFLUSHPROC glFlush;
extern PFNGLBLENDFUNCPROC glBlendFunc;
extern PFNGLLOGICOPPROC glLogicOp;
extern PFNGLSTENCILFUNCPROC glStencilFunc;
extern PFNGLSTENCILOPPROC glStencilOp;
extern PFNGLDEPTHFUNCPROC glDepthFunc;
extern PFNGLPIXELSTOREFPROC glPixelStoref;
extern PFNGLPIXELSTOREIPROC glPixelStorei;
extern PFNGLREADBUFFERPROC glReadBuffer;
extern PFNGLREADPIXELSPROC glReadPixels;
extern PFNGLGETBOOLEANVPROC glGetBooleanv;
extern PFNGLGETDOUBLEVPROC glGetDoublev;
extern PFNGLGETERRORPROC glGetError;
extern PFNGLGETFLOATVPROC glGetFloatv;
extern PFNGLGETINTEGERVPROC glGetIntegerv;
extern PFNGLGETSTRINGPROC glGetString;
extern PFNGLGETTEXIMAGEPROC glGetTexImage;
extern PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv;
extern PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv;
extern PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv;
extern PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv;
extern PFNGLISENABLEDPROC glIsEnabled;
extern PFNGLDEPTHRANGEPROC glDepthRange;
extern PFNGLVIEWPORTPROC glViewport;
#endif
#endif /* TGL_DECLARE_CORE_GL_1_0 */

/* GL_version_1_1 */
#ifdef TGL_DECLARE_CORE_GL_1_1
#if defined(TGL_PLATFORM_WIN32) || defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glDrawArrays(GLenum mode, GLint first, GLsizei count);
GLAPI void APIENTRY glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
GLAPI void APIENTRY glGetPointerv(GLenum pname, GLvoid* *params);
GLAPI void APIENTRY glPolygonOffset(GLfloat factor, GLfloat units);
GLAPI void APIENTRY glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void APIENTRY glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void APIENTRY glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void APIENTRY glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void APIENTRY glBindTexture(GLenum target, GLuint texture);
GLAPI void APIENTRY glDeleteTextures(GLsizei n, const GLuint *textures);
GLAPI void APIENTRY glGenTextures(GLsizei n, GLuint *textures);
GLAPI GLboolean APIENTRY glIsTexture(GLuint texture);
#else
#define TGL_DEFINE_CORE_GL_1_1
extern PFNGLDRAWARRAYSPROC glDrawArrays;
extern PFNGLDRAWELEMENTSPROC glDrawElements;
extern PFNGLGETPOINTERVPROC glGetPointerv;
extern PFNGLPOLYGONOFFSETPROC glPolygonOffset;
extern PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D;
extern PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D;
extern PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D;
extern PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D;
extern PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D;
extern PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D;
extern PFNGLBINDTEXTUREPROC glBindTexture;
extern PFNGLDELETETEXTURESPROC glDeleteTextures;
extern PFNGLGENTEXTURESPROC glGenTextures;
extern PFNGLISTEXTUREPROC glIsTexture;
#endif
#endif /* TGL_DECLARE_CORE_GL_1_1 */

/* GL_version_1_2 */
#ifdef TGL_DECLARE_CORE_GL_1_2
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLAPI void APIENTRY glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#else
#define TGL_DEFINE_CORE_GL_1_2
extern PFNGLBLENDCOLORPROC glBlendColor;
extern PFNGLBLENDEQUATIONPROC glBlendEquation;
extern PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
extern PFNGLTEXIMAGE3DPROC glTexImage3D;
extern PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
extern PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;
#endif
#endif /* TGL_DECLARE_CORE_GL_1_2 */

/* GL_version_1_3 */
#ifdef TGL_DECLARE_CORE_GL_1_3
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glActiveTexture(GLenum texture);
GLAPI void APIENTRY glSampleCoverage(GLfloat value, GLboolean invert);
GLAPI void APIENTRY glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glGetCompressedTexImage(GLenum target, GLint level, void *img);
#else
#define TGL_DEFINE_CORE_GL_1_3
extern PFNGLACTIVETEXTUREPROC glActiveTexture;
extern PFNGLSAMPLECOVERAGEPROC glSampleCoverage;
extern PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
extern PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
extern PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
extern PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;
#endif
#endif /* TGL_DECLARE_CORE_GL_1_3 */

/* GL_version_1_4 */
#ifdef TGL_DECLARE_CORE_GL_1_4
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI void APIENTRY glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
GLAPI void APIENTRY glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
GLAPI void APIENTRY glPointParameterf(GLenum pname, GLfloat param);
GLAPI void APIENTRY glPointParameterfv(GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glPointParameteri(GLenum pname, GLint param);
GLAPI void APIENTRY glPointParameteriv(GLenum pname, const GLint *params);
GLAPI void APIENTRY glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void APIENTRY glBlendEquation(GLenum mode);
#else
#define TGL_DEFINE_CORE_GL_1_4
extern PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
extern PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
extern PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
extern PFNGLPOINTPARAMETERFPROC glPointParameterf;
extern PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
extern PFNGLPOINTPARAMETERIPROC glPointParameteri;
extern PFNGLPOINTPARAMETERIVPROC glPointParameteriv;
#endif
#endif /* TGL_DECLARE_CORE_GL_1_4 */


/* GL_version_1_5 */
#ifdef TGL_DECLARE_CORE_GL_1_5
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glGenQueries(GLsizei n, GLuint *ids);
GLAPI void APIENTRY glDeleteQueries(GLsizei n, const GLuint *ids);
GLAPI GLboolean APIENTRY glIsQuery(GLuint id);
GLAPI void APIENTRY glBeginQuery(GLenum target, GLuint id);
GLAPI void APIENTRY glEndQuery(GLenum target);
GLAPI void APIENTRY glGetQueryiv(GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params);
GLAPI void APIENTRY glBindBuffer(GLenum target, GLuint buffer);
GLAPI void APIENTRY glDeleteBuffers(GLsizei n, const GLuint *buffers);
GLAPI void APIENTRY glGenBuffers(GLsizei n, GLuint *buffers);
GLAPI GLboolean APIENTRY glIsBuffer(GLuint buffer);
GLAPI void APIENTRY glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void APIENTRY glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void APIENTRY glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void *APIENTRY glMapBuffer(GLenum target, GLenum access);
GLAPI GLboolean APIENTRY glUnmapBuffer(GLenum target);
GLAPI void APIENTRY glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetBufferPointerv(GLenum target, GLenum pname, void **params);
#else
#define TGL_DEFINE_CORE_GL_1_5
extern PFNGLGENQUERIESPROC glGenQueries;
extern PFNGLDELETEQUERIESPROC glDeleteQueries;
extern PFNGLISQUERYPROC glIsQuery;
extern PFNGLBEGINQUERYPROC glBeginQuery;
extern PFNGLENDQUERYPROC glEndQuery;
extern PFNGLGETQUERYIVPROC glGetQueryiv;
extern PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;
extern PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLISBUFFERPROC glIsBuffer;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLBUFFERSUBDATAPROC glBufferSubData;
extern PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
extern PFNGLMAPBUFFERPROC glMapBuffer;
extern PFNGLUNMAPBUFFERPROC glUnmapBuffer;
extern PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
extern PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;
#endif
#endif /* TGL_DECLARE_CORE_GL_1_5 */

/* GL_version_2_0 */
#ifdef TGL_DECLARE_CORE_GL_2_0
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glDrawBuffers(GLsizei n, const GLenum *bufs);
GLAPI void APIENTRY glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLAPI void APIENTRY glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glStencilMaskSeparate(GLenum face, GLuint mask);
GLAPI void APIENTRY glAttachShader(GLuint program, GLuint shader);
GLAPI void APIENTRY glBindAttribLocation(GLuint program, GLuint index, const GLchar *name);
GLAPI void APIENTRY glCompileShader(GLuint shader);
GLAPI GLuint APIENTRY glCreateProgram(void);
GLAPI GLuint APIENTRY glCreateShader(GLenum type);
GLAPI void APIENTRY glDeleteProgram(GLuint program);
GLAPI void APIENTRY glDeleteShader(GLuint shader);
GLAPI void APIENTRY glDetachShader(GLuint program, GLuint shader);
GLAPI void APIENTRY glDisableVertexAttribArray(GLuint index);
GLAPI void APIENTRY glEnableVertexAttribArray(GLuint index);
GLAPI void APIENTRY glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLAPI GLint APIENTRY glGetAttribLocation(GLuint program, const GLchar *name);
GLAPI void APIENTRY glGetProgramiv(GLuint program, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glGetShaderiv(GLuint shader, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLAPI GLint APIENTRY glGetUniformLocation(GLuint program, const GLchar *name);
GLAPI void APIENTRY glGetUniformfv(GLuint program, GLint location, GLfloat *params);
GLAPI void APIENTRY glGetUniformiv(GLuint program, GLint location, GLint *params);
GLAPI void APIENTRY glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params);
GLAPI void APIENTRY glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer);
GLAPI GLboolean APIENTRY glIsProgram(GLuint program);
GLAPI GLboolean APIENTRY glIsShader(GLuint shader);
GLAPI void APIENTRY glLinkProgram(GLuint program);
GLAPI void APIENTRY glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GLAPI void APIENTRY glUseProgram(GLuint program);
GLAPI void APIENTRY glUniform1f(GLint location, GLfloat v0);
GLAPI void APIENTRY glUniform2f(GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glUniform1i(GLint location, GLint v0);
GLAPI void APIENTRY glUniform2i(GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glUniform1fv(GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform2fv(GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform3fv(GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform4fv(GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform1iv(GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform2iv(GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform3iv(GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform4iv(GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glValidateProgram(GLuint program);
GLAPI void APIENTRY glVertexAttrib1d(GLuint index, GLdouble x);
GLAPI void APIENTRY glVertexAttrib1dv(GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib1f(GLuint index, GLfloat x);
GLAPI void APIENTRY glVertexAttrib1fv(GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib1s(GLuint index, GLshort x);
GLAPI void APIENTRY glVertexAttrib1sv(GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
GLAPI void APIENTRY glVertexAttrib2dv(GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
GLAPI void APIENTRY glVertexAttrib2fv(GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
GLAPI void APIENTRY glVertexAttrib2sv(GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glVertexAttrib3dv(GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glVertexAttrib3fv(GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void APIENTRY glVertexAttrib3sv(GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4Nbv(GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttrib4Niv(GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttrib4Nsv(GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void APIENTRY glVertexAttrib4Nubv(GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttrib4Nuiv(GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttrib4Nusv(GLuint index, const GLushort *v);
GLAPI void APIENTRY glVertexAttrib4bv(GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glVertexAttrib4dv(GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void APIENTRY glVertexAttrib4fv(GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib4iv(GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void APIENTRY glVertexAttrib4sv(GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4ubv(GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttrib4uiv(GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttrib4usv(GLuint index, const GLushort *v);
GLAPI void APIENTRY glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
#else
#define TGL_DEFINE_CORE_GL_2_0
extern PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
extern PFNGLDRAWBUFFERSPROC glDrawBuffers;
extern PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate;
extern PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate;
extern PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate;
extern PFNGLATTACHSHADERPROC glAttachShader;
extern PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
extern PFNGLCOMPILESHADERPROC glCompileShader;
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
extern PFNGLCREATESHADERPROC glCreateShader;
extern PFNGLDELETEPROGRAMPROC glDeleteProgram;
extern PFNGLDELETESHADERPROC glDeleteShader;
extern PFNGLDETACHSHADERPROC glDetachShader;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
extern PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
extern PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;
extern PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders;
extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
extern PFNGLGETSHADERIVPROC glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
extern PFNGLGETSHADERSOURCEPROC glGetShaderSource;
extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
extern PFNGLGETUNIFORMFVPROC glGetUniformfv;
extern PFNGLGETUNIFORMIVPROC glGetUniformiv;
extern PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
extern PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
extern PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
extern PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
extern PFNGLISPROGRAMPROC glIsProgram;
extern PFNGLISSHADERPROC glIsShader;
extern PFNGLLINKPROGRAMPROC glLinkProgram;
extern PFNGLSHADERSOURCEPROC glShaderSource;
extern PFNGLUSEPROGRAMPROC glUseProgram;
extern PFNGLUNIFORM1FPROC glUniform1f;
extern PFNGLUNIFORM2FPROC glUniform2f;
extern PFNGLUNIFORM3FPROC glUniform3f;
extern PFNGLUNIFORM4FPROC glUniform4f;
extern PFNGLUNIFORM1IPROC glUniform1i;
extern PFNGLUNIFORM2IPROC glUniform2i;
extern PFNGLUNIFORM3IPROC glUniform3i;
extern PFNGLUNIFORM4IPROC glUniform4i;
extern PFNGLUNIFORM1FVPROC glUniform1fv;
extern PFNGLUNIFORM2FVPROC glUniform2fv;
extern PFNGLUNIFORM3FVPROC glUniform3fv;
extern PFNGLUNIFORM4FVPROC glUniform4fv;
extern PFNGLUNIFORM1IVPROC glUniform1iv;
extern PFNGLUNIFORM2IVPROC glUniform2iv;
extern PFNGLUNIFORM3IVPROC glUniform3iv;
extern PFNGLUNIFORM4IVPROC glUniform4iv;
extern PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
extern PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
extern PFNGLVALIDATEPROGRAMPROC glValidateProgram;
extern PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d;
extern PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv;
extern PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f;
extern PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv;
extern PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s;
extern PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv;
extern PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d;
extern PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv;
extern PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f;
extern PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
extern PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s;
extern PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv;
extern PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d;
extern PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv;
extern PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f;
extern PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
extern PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s;
extern PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv;
extern PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv;
extern PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv;
extern PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv;
extern PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub;
extern PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv;
extern PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv;
extern PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv;
extern PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv;
extern PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d;
extern PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv;
extern PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f;
extern PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv;
extern PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv;
extern PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s;
extern PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv;
extern PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv;
extern PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv;
extern PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv;
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
#endif
#endif /* TGL_DECLARE_CORE_GL_2_0 */

/* GL_version_2_1 */
#ifdef TGL_DECLARE_CORE_GL_2_1
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#else
#define TGL_DEFINE_CORE_GL_2_1
extern PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
extern PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
extern PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
extern PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
extern PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
extern PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;
#endif
#endif /* TGL_DECLARE_CORE_GL_2_1 */

/* GL_version_3_0 */
#ifdef TGL_DECLARE_CORE_GL_3_0
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI void APIENTRY glGetBooleani_v(GLenum target, GLuint index, GLboolean *data);
GLAPI void APIENTRY glGetIntegeri_v(GLenum target, GLuint index, GLint *data);
GLAPI void APIENTRY glEnablei(GLenum target, GLuint index);
GLAPI void APIENTRY glDisablei(GLenum target, GLuint index);
GLAPI GLboolean APIENTRY glIsEnabledi(GLenum target, GLuint index);
GLAPI void APIENTRY glBeginTransformFeedback(GLenum primitiveMode);
GLAPI void APIENTRY glEndTransformFeedback(void);
GLAPI void APIENTRY glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
GLAPI void APIENTRY glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
GLAPI void APIENTRY glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glClampColor(GLenum target, GLenum clamp);
GLAPI void APIENTRY glBeginConditionalRender(GLuint id, GLenum mode);
GLAPI void APIENTRY glEndConditionalRender(void);
GLAPI void APIENTRY glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params);
GLAPI void APIENTRY glVertexAttribI1i(GLuint index, GLint x);
GLAPI void APIENTRY glVertexAttribI2i(GLuint index, GLint x, GLint y);
GLAPI void APIENTRY glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
GLAPI void APIENTRY glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void APIENTRY glVertexAttribI1ui(GLuint index, GLuint x);
GLAPI void APIENTRY glVertexAttribI2ui(GLuint index, GLuint x, GLuint y);
GLAPI void APIENTRY glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI void APIENTRY glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void APIENTRY glVertexAttribI1iv(GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI2iv(GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI3iv(GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI4iv(GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI1uiv(GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI2uiv(GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI3uiv(GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI4uiv(GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI4bv(GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttribI4sv(GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttribI4ubv(GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttribI4usv(GLuint index, const GLushort *v);
GLAPI void APIENTRY glGetUniformuiv(GLuint program, GLint location, GLuint *params);
GLAPI void APIENTRY glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name);
GLAPI GLint APIENTRY glGetFragDataLocation(GLuint program, const GLchar *name);
GLAPI void APIENTRY glUniform1ui(GLint location, GLuint v0);
GLAPI void APIENTRY glUniform2ui(GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glUniform1uiv(GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform2uiv(GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform3uiv(GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform4uiv(GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glTexParameterIiv(GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params);
GLAPI void APIENTRY glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params);
GLAPI void APIENTRY glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void APIENTRY glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void APIENTRY glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void APIENTRY glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI const GLubyte *APIENTRY glGetStringi(GLenum name, GLuint index);
GLAPI GLboolean APIENTRY glIsRenderbuffer(GLuint renderbuffer);
GLAPI void APIENTRY glBindRenderbuffer(GLenum target, GLuint renderbuffer);
GLAPI void APIENTRY glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers);
GLAPI void APIENTRY glGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
GLAPI void APIENTRY glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params);
GLAPI GLboolean APIENTRY glIsFramebuffer(GLuint framebuffer);
GLAPI void APIENTRY glBindFramebuffer(GLenum target, GLuint framebuffer);
GLAPI void APIENTRY glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers);
GLAPI void APIENTRY glGenFramebuffers(GLsizei n, GLuint *framebuffers);
GLAPI GLenum APIENTRY glCheckFramebufferStatus(GLenum target);
GLAPI void APIENTRY glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void APIENTRY glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void APIENTRY glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLAPI void APIENTRY glGenerateMipmap(GLenum target);
GLAPI void APIENTRY glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI void APIENTRY glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void *APIENTRY glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void APIENTRY glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glBindVertexArray(GLuint array);
GLAPI void APIENTRY glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
GLAPI void APIENTRY glGenVertexArrays(GLsizei n, GLuint *arrays);
GLAPI GLboolean APIENTRY glIsVertexArray(GLuint array);
#else
#define TGL_DEFINE_CORE_GL_3_0
extern PFNGLCOLORMASKIPROC glColorMaski;
extern PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
extern PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
extern PFNGLENABLEIPROC glEnablei;
extern PFNGLDISABLEIPROC glDisablei;
extern PFNGLISENABLEDIPROC glIsEnabledi;
extern PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
extern PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
extern PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
extern PFNGLBINDBUFFERBASEPROC glBindBufferBase;
extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
extern PFNGLCLAMPCOLORPROC glClampColor;
extern PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
extern PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
extern PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
extern PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
extern PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
extern PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
extern PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
extern PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
extern PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
extern PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
extern PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
extern PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
extern PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
extern PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
extern PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
extern PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
extern PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
extern PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
extern PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
extern PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
extern PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
extern PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
extern PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
extern PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
extern PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
extern PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
extern PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
extern PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
extern PFNGLUNIFORM1UIPROC glUniform1ui;
extern PFNGLUNIFORM2UIPROC glUniform2ui;
extern PFNGLUNIFORM3UIPROC glUniform3ui;
extern PFNGLUNIFORM4UIPROC glUniform4ui;
extern PFNGLUNIFORM1UIVPROC glUniform1uiv;
extern PFNGLUNIFORM2UIVPROC glUniform2uiv;
extern PFNGLUNIFORM3UIVPROC glUniform3uiv;
extern PFNGLUNIFORM4UIVPROC glUniform4uiv;
extern PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
extern PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
extern PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
extern PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
extern PFNGLCLEARBUFFERIVPROC glClearBufferiv;
extern PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
extern PFNGLCLEARBUFFERFVPROC glClearBufferfv;
extern PFNGLCLEARBUFFERFIPROC glClearBufferfi;
extern PFNGLGETSTRINGIPROC glGetStringi;
/* ARB_framebuffer_object */
extern PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
extern PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
extern PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
extern PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
extern PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
extern PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
extern PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
extern PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
extern PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
extern PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
extern PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
extern PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
extern PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
extern PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
extern PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
/* ARB_map_buffer_range */
extern PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
/* ARB_vertex_array_object */
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
extern PFNGLISVERTEXARRAYPROC glIsVertexArray;
#endif
#endif /* TGL_DECLARE_CORE_GL_3_0 */

/* GL_version_3_1 */
#ifdef TGL_DECLARE_CORE_GL_3_1
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLAPI void APIENTRY glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
GLAPI void APIENTRY glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glPrimitiveRestartIndex(GLuint index);
GLAPI void APIENTRY glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void APIENTRY glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
GLAPI void APIENTRY glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLAPI GLuint APIENTRY glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName);
GLAPI void APIENTRY glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
GLAPI void APIENTRY glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#else
#define TGL_DEFINE_CORE_GL_3_1
extern PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
extern PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
extern PFNGLTEXBUFFERPROC glTexBuffer;
extern PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
/* ARB_copy_buffer */
extern PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
/* ARB_uniform_buffer_object */
extern PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
extern PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
extern PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
extern PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
extern PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;
#endif
#endif /* TGL_DECLARE_CORE_GL_3_1 */

/* GL_version_3_2 */
#ifdef TGL_DECLARE_CORE_GL_3_2
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI void APIENTRY glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
GLAPI void APIENTRY glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
GLAPI void APIENTRY glProvokingVertex(GLenum mode);
GLAPI GLsync APIENTRY glFenceSync(GLenum condition, GLbitfield flags);
GLAPI GLboolean APIENTRY glIsSync(GLsync sync);
GLAPI void APIENTRY glDeleteSync(GLsync sync);
GLAPI GLenum APIENTRY glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void APIENTRY glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void APIENTRY glGetInteger64v(GLenum pname, GLint64 *data);
GLAPI void APIENTRY glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
GLAPI void APIENTRY glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data);
GLAPI void APIENTRY glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val);
GLAPI void APIENTRY glSampleMaski(GLuint maskNumber, GLbitfield mask);
#else
#define TGL_DEFINE_CORE_GL_3_2
extern PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
extern PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
extern PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;
/* ARB_draw_elements_base_vertex */
extern PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;
/* ARB_provoking_vertex */
extern PFNGLPROVOKINGVERTEXPROC glProvokingVertex;
/* ARB_sync */
extern PFNGLFENCESYNCPROC glFenceSync;
extern PFNGLISSYNCPROC glIsSync;
extern PFNGLDELETESYNCPROC glDeleteSync;
extern PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
extern PFNGLWAITSYNCPROC glWaitSync;
extern PFNGLGETINTEGER64VPROC glGetInteger64v;
extern PFNGLGETSYNCIVPROC glGetSynciv;
/* ARB_texture_multisample */
extern PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
extern PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;
extern PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
extern PFNGLSAMPLEMASKIPROC glSampleMaski;
#endif
#endif /* TGL_DECLARE_CORE_GL_3_2 */

/* GL_version_3_3 */
#ifdef TGL_DECLARE_CORE_GL_3_3
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
GLAPI GLint APIENTRY glGetFragDataIndex(GLuint program, const GLchar *name);
GLAPI void APIENTRY glGenSamplers(GLsizei count, GLuint *samplers);
GLAPI void APIENTRY glDeleteSamplers(GLsizei count, const GLuint *samplers);
GLAPI GLboolean APIENTRY glIsSampler(GLuint sampler);
GLAPI void APIENTRY glBindSampler(GLuint unit, GLuint sampler);
GLAPI void APIENTRY glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
GLAPI void APIENTRY glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param);
GLAPI void APIENTRY glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
GLAPI void APIENTRY glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param);
GLAPI void APIENTRY glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param);
GLAPI void APIENTRY glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param);
GLAPI void APIENTRY glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params);
GLAPI void APIENTRY glQueryCounter(GLuint id, GLenum target);
GLAPI void APIENTRY glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params);
GLAPI void APIENTRY glVertexAttribDivisor(GLuint index, GLuint divisor);
GLAPI void APIENTRY glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
#else
#define TGL_DEFINE_CORE_GL_3_3
extern PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
/* ARB_blend_func_extended */
extern PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed;
extern PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex;
/* ARB_sampler_objects */
extern PFNGLGENSAMPLERSPROC glGenSamplers;
extern PFNGLDELETESAMPLERSPROC glDeleteSamplers;
extern PFNGLISSAMPLERPROC glIsSampler;
extern PFNGLBINDSAMPLERPROC glBindSampler;
extern PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;
extern PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;
extern PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;
extern PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;
extern PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;
extern PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;
extern PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;
extern PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;
extern PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;
extern PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;
/* ARB_timer_query */
extern PFNGLQUERYCOUNTERPROC glQueryCounter;
extern PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v;
extern PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v;
/* ARB_vertex_type_2_10_10_10_rev */
//extern PFNGLVERTEXP2UIPROC glVertexP2ui;
//extern PFNGLVERTEXP2UIVPROC glVertexP2uiv;
//extern PFNGLVERTEXP3UIPROC glVertexP3ui;
//extern PFNGLVERTEXP3UIVPROC glVertexP3uiv;
//extern PFNGLVERTEXP4UIPROC glVertexP4ui;
//extern PFNGLVERTEXP4UIVPROC glVertexP4uiv;
//extern PFNGLTEXCOORDP1UIPROC glTexCoordP1ui;
//extern PFNGLTEXCOORDP1UIVPROC glTexCoordP1uiv;
//extern PFNGLTEXCOORDP2UIPROC glTexCoordP2ui;
//extern PFNGLTEXCOORDP2UIVPROC glTexCoordP2uiv;
//extern PFNGLTEXCOORDP3UIPROC glTexCoordP3ui;
//extern PFNGLTEXCOORDP3UIVPROC glTexCoordP3uiv;
//extern PFNGLTEXCOORDP4UIPROC glTexCoordP4ui;
//extern PFNGLTEXCOORDP4UIVPROC glTexCoordP4uiv;
//extern PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1ui;
//extern PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uiv;
//extern PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2ui;
//extern PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uiv;
//extern PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3ui;
//extern PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uiv;
//extern PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4ui;
//extern PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uiv;
//extern PFNGLNORMALP3UIPROC glNormalP3ui;
//extern PFNGLNORMALP3UIVPROC glNormalP3uiv;
//extern PFNGLCOLORP3UIPROC glColorP3ui;
//extern PFNGLCOLORP3UIVPROC glColorP3uiv;
//extern PFNGLCOLORP4UIPROC glColorP4ui;
//extern PFNGLCOLORP4UIVPROC glColorP4uiv;
//extern PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3ui;
//extern PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uiv;
extern PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui;
extern PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv;
extern PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui;
extern PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv;
extern PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui;
extern PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv;
extern PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui;
extern PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv;
#endif
#endif /* TGL_DECLARE_CORE_GL_3_3 */

/* GL_version_4_0 */
#ifdef TGL_DECLARE_CORE_GL_4_0
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glMinSampleShading(GLfloat value);
GLAPI void APIENTRY glBlendEquationi(GLuint buf, GLenum mode);
GLAPI void APIENTRY glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glBlendFunci(GLuint buf, GLenum src, GLenum dst);
GLAPI void APIENTRY glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLAPI void APIENTRY glDrawArraysIndirect(GLenum mode, const void *indirect);
GLAPI void APIENTRY glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect);
GLAPI void APIENTRY glUniform1d(GLint location, GLdouble x);
GLAPI void APIENTRY glUniform2d(GLint location, GLdouble x, GLdouble y);
GLAPI void APIENTRY glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glUniform1dv(GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform2dv(GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform3dv(GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform4dv(GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glGetUniformdv(GLuint program, GLint location, GLdouble *params);
GLAPI GLint APIENTRY glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name);
GLAPI GLuint APIENTRY glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name);
GLAPI void APIENTRY glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
GLAPI void APIENTRY glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices);
GLAPI void APIENTRY glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *params);
GLAPI void APIENTRY glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
GLAPI void APIENTRY glPatchParameteri(GLenum pname, GLint value);
GLAPI void APIENTRY glPatchParameterfv(GLenum pname, const GLfloat *values);
GLAPI void APIENTRY glBindTransformFeedback(GLenum target, GLuint id);
GLAPI void APIENTRY glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids);
GLAPI void APIENTRY glGenTransformFeedbacks(GLsizei n, GLuint *ids);
GLAPI GLboolean APIENTRY glIsTransformFeedback(GLuint id);
GLAPI void APIENTRY glPauseTransformFeedback(void);
GLAPI void APIENTRY glResumeTransformFeedback(void);
GLAPI void APIENTRY glDrawTransformFeedback(GLenum mode, GLuint id);
GLAPI void APIENTRY glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
GLAPI void APIENTRY glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
GLAPI void APIENTRY glEndQueryIndexed(GLenum target, GLuint index);
GLAPI void APIENTRY glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint *params);
#else
#define TGL_DEFINE_CORE_GL_4_0
extern PFNGLMINSAMPLESHADINGPROC glMinSampleShading;
extern PFNGLBLENDEQUATIONIPROC glBlendEquationi;
extern PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
extern PFNGLBLENDFUNCIPROC glBlendFunci;
extern PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;
extern PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
extern PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
extern PFNGLUNIFORM1DPROC glUniform1d;
extern PFNGLUNIFORM2DPROC glUniform2d;
extern PFNGLUNIFORM3DPROC glUniform3d;
extern PFNGLUNIFORM4DPROC glUniform4d;
extern PFNGLUNIFORM1DVPROC glUniform1dv;
extern PFNGLUNIFORM2DVPROC glUniform2dv;
extern PFNGLUNIFORM3DVPROC glUniform3dv;
extern PFNGLUNIFORM4DVPROC glUniform4dv;
extern PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;
extern PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;
extern PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;
extern PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;
extern PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;
extern PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;
extern PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;
extern PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;
extern PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;
extern PFNGLGETUNIFORMDVPROC glGetUniformdv;
extern PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;
extern PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;
extern PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;
extern PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;
extern PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;
extern PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;
extern PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;
extern PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;
extern PFNGLPATCHPARAMETERIPROC glPatchParameteri;
extern PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;
extern PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;
extern PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;
extern PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;
extern PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;
extern PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;
extern PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;
extern PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;
extern PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;
extern PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;
#endif
#endif /* TGL_DECLARE_CORE_GL_4_0 */

/* GL_version_4_1 */
#ifdef TGL_DECLARE_CORE_GL_4_1
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glReleaseShaderCompiler(void);
GLAPI void APIENTRY glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
GLAPI void APIENTRY glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GLAPI void APIENTRY glDepthRangef(GLfloat n, GLfloat f);
GLAPI void APIENTRY glClearDepthf(GLfloat d);
GLAPI void APIENTRY glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
GLAPI void APIENTRY glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
GLAPI void APIENTRY glProgramParameteri(GLuint program, GLenum pname, GLint value);
GLAPI void APIENTRY glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
GLAPI void APIENTRY glActiveShaderProgram(GLuint pipeline, GLuint program);
GLAPI GLuint APIENTRY glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings);
GLAPI void APIENTRY glBindProgramPipeline(GLuint pipeline);
GLAPI void APIENTRY glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines);
GLAPI void APIENTRY glGenProgramPipelines(GLsizei n, GLuint *pipelines);
GLAPI GLboolean APIENTRY glIsProgramPipeline(GLuint pipeline);
GLAPI void APIENTRY glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params);
GLAPI void APIENTRY glProgramUniform1i(GLuint program, GLint location, GLint v0);
GLAPI void APIENTRY glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
GLAPI void APIENTRY glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform1d(GLuint program, GLint location, GLdouble v0);
GLAPI void APIENTRY glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
GLAPI void APIENTRY glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1);
GLAPI void APIENTRY glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
GLAPI void APIENTRY glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
GLAPI void APIENTRY glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glValidateProgramPipeline(GLuint pipeline);
GLAPI void APIENTRY glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glVertexAttribL1d(GLuint index, GLdouble x);
GLAPI void APIENTRY glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y);
GLAPI void APIENTRY glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glVertexAttribL1dv(GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL2dv(GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL3dv(GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL4dv(GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params);
GLAPI void APIENTRY glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v);
GLAPI void APIENTRY glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLAPI void APIENTRY glViewportIndexedfv(GLuint index, const GLfloat *v);
GLAPI void APIENTRY glScissorArrayv(GLuint first, GLsizei count, const GLint *v);
GLAPI void APIENTRY glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
GLAPI void APIENTRY glScissorIndexedv(GLuint index, const GLint *v);
GLAPI void APIENTRY glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v);
GLAPI void APIENTRY glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f);
GLAPI void APIENTRY glGetFloati_v(GLenum target, GLuint index, GLfloat *data);
GLAPI void APIENTRY glGetDoublei_v(GLenum target, GLuint index, GLdouble *data);
#else
#define TGL_DEFINE_CORE_GL_4_1
extern PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
extern PFNGLSHADERBINARYPROC glShaderBinary;
extern PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
extern PFNGLDEPTHRANGEFPROC glDepthRangef;
extern PFNGLCLEARDEPTHFPROC glClearDepthf;
extern PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
extern PFNGLPROGRAMBINARYPROC glProgramBinary;
extern PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
extern PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
extern PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
extern PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
extern PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
extern PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
extern PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
extern PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
extern PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
extern PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
extern PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
extern PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
extern PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
extern PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
extern PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
extern PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
extern PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
extern PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
extern PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
extern PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
extern PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
extern PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
extern PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
extern PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
extern PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
extern PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
extern PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
extern PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
extern PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
extern PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
extern PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
extern PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
extern PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
extern PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
extern PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
extern PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
extern PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
extern PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
extern PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
extern PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
extern PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
extern PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
extern PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;
extern PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
extern PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
extern PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
extern PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
extern PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
extern PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
extern PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
extern PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
extern PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
extern PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;
extern PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
extern PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
extern PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
extern PFNGLSCISSORARRAYVPROC glScissorArrayv;
extern PFNGLSCISSORINDEXEDPROC glScissorIndexed;
extern PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
extern PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
extern PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
extern PFNGLGETFLOATI_VPROC glGetFloati_v;
extern PFNGLGETDOUBLEI_VPROC glGetDoublei_v;
#endif
#endif /* TGL_DECLARE_CORE_GL_4_1 */

/* GL_version_4_2 */
#ifdef TGL_DECLARE_CORE_GL_4_2
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
GLAPI void APIENTRY glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
GLAPI void APIENTRY glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
GLAPI void APIENTRY glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLAPI void APIENTRY glMemoryBarrier(GLbitfield barriers);
GLAPI void APIENTRY glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount);
GLAPI void APIENTRY glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#else
#define TGL_DEFINE_CORE_GL_4_2
extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;
extern PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;
extern PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;
extern PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
extern PFNGLMEMORYBARRIERPROC glMemoryBarrier;
extern PFNGLTEXSTORAGE1DPROC glTexStorage1D;
extern PFNGLTEXSTORAGE2DPROC glTexStorage2D;
extern PFNGLTEXSTORAGE3DPROC glTexStorage3D;
extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;
#endif
#endif /* TGL_DECLARE_CORE_GL_4_2 */

/* GL_version_4_3 */
#ifdef TGL_DECLARE_CORE_GL_4_3
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLAPI void APIENTRY glDispatchComputeIndirect(GLintptr indirect);
GLAPI void APIENTRY glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
GLAPI void APIENTRY glFramebufferParameteri(GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
GLAPI void APIENTRY glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glInvalidateTexImage(GLuint texture, GLint level);
GLAPI void APIENTRY glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glInvalidateBufferData(GLuint buffer);
GLAPI void APIENTRY glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments);
GLAPI void APIENTRY glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glMultiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI void APIENTRY glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI void APIENTRY glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
GLAPI GLuint APIENTRY glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name);
GLAPI void APIENTRY glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
GLAPI GLint APIENTRY glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name);
GLAPI GLint APIENTRY glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar *name);
GLAPI void APIENTRY glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
GLAPI void APIENTRY glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
GLAPI void APIENTRY glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribBinding(GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexBindingDivisor(GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI void APIENTRY glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI void APIENTRY glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam);
GLAPI GLuint APIENTRY glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLAPI void APIENTRY glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message);
GLAPI void APIENTRY glPopDebugGroup(void);
GLAPI void APIENTRY glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
GLAPI void APIENTRY glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
GLAPI void APIENTRY glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label);
GLAPI void APIENTRY glGetObjectPtrLabel(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
#else
#define TGL_DEFINE_CORE_GL_4_3
extern PFNGLCLEARBUFFERDATAPROC glClearBufferData;
extern PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
extern PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
extern PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;
extern PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;
extern PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;
extern PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;
extern PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v;
extern PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;
extern PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;
extern PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;
extern PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;
extern PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;
extern PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;
extern PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;
extern PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
extern PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
extern PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
extern PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
extern PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
extern PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;
extern PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;
extern PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
extern PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample;
extern PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample;
extern PFNGLTEXTUREVIEWPROC glTextureView;
extern PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;
extern PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;
extern PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;
extern PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;
extern PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;
extern PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;
extern PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
extern PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
extern PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
extern PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
extern PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
extern PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
extern PFNGLOBJECTLABELPROC glObjectLabel;
extern PFNGLGETOBJECTLABELPROC glGetObjectLabel;
extern PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
extern PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;
#endif
#endif /* TGL_DECLARE_CORE_GL_4_3 */

/* GL_version_4_4 */
#ifdef TGL_DECLARE_CORE_GL_4_4
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glBufferStorage(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void APIENTRY glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
GLAPI void APIENTRY glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
GLAPI void APIENTRY glBindTextures(GLuint first, GLsizei count, const GLuint *textures);
GLAPI void APIENTRY glBindSamplers(GLuint first, GLsizei count, const GLuint *samplers);
GLAPI void APIENTRY glBindImageTextures(GLuint first, GLsizei count, const GLuint *textures);
GLAPI void APIENTRY glBindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
#else
#define TGL_DEFINE_CORE_GL_4_4
extern PFNGLBUFFERSTORAGEPROC glBufferStorage;
extern PFNGLCLEARTEXIMAGEPROC glClearTexImage;
extern PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
extern PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
extern PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
extern PFNGLBINDTEXTURESPROC glBindTextures;
extern PFNGLBINDSAMPLERSPROC glBindSamplers;
extern PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
extern PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;
#endif
#endif /* TGL_DECLARE_CORE_GL_4_4 */

/* GL_version_4_5 */
#ifdef TGL_DECLARE_CORE_GL_4_5
#if defined(TGL_PLATFORM_COCOA)
GLAPI void APIENTRY glClipControl(GLenum origin, GLenum depth);
GLAPI void APIENTRY glCreateTransformFeedbacks(GLsizei n, GLuint *ids);
GLAPI void APIENTRY glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer);
GLAPI void APIENTRY glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint *param);
GLAPI void APIENTRY glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
GLAPI void APIENTRY glCreateBuffers(GLsizei n, GLuint *buffers);
GLAPI void APIENTRY glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void APIENTRY glNamedBufferData(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void APIENTRY glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void APIENTRY glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void APIENTRY glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void *APIENTRY glMapNamedBuffer(GLuint buffer, GLenum access);
GLAPI void *APIENTRY glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI GLboolean APIENTRY glUnmapNamedBuffer(GLuint buffer);
GLAPI void APIENTRY glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void **params);
GLAPI void APIENTRY glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void APIENTRY glCreateFramebuffers(GLsizei n, GLuint *framebuffers);
GLAPI void APIENTRY glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void APIENTRY glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param);
GLAPI void APIENTRY glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void APIENTRY glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf);
GLAPI void APIENTRY glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLAPI void APIENTRY glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src);
GLAPI void APIENTRY glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
GLAPI void APIENTRY glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void APIENTRY glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void APIENTRY glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void APIENTRY glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, const GLfloat depth, GLint stencil);
GLAPI void APIENTRY glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI GLenum APIENTRY glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target);
GLAPI void APIENTRY glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateRenderbuffers(GLsizei n, GLuint *renderbuffers);
GLAPI void APIENTRY glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateTextures(GLenum target, GLsizei n, GLuint *textures);
GLAPI void APIENTRY glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTextureParameterf(GLuint texture, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat *param);
GLAPI void APIENTRY glTextureParameteri(GLuint texture, GLenum pname, GLint param);
GLAPI void APIENTRY glTextureParameterIiv(GLuint texture, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint *params);
GLAPI void APIENTRY glTextureParameteriv(GLuint texture, GLenum pname, const GLint *param);
GLAPI void APIENTRY glGenerateTextureMipmap(GLuint texture);
GLAPI void APIENTRY glBindTextureUnit(GLuint unit, GLuint texture);
GLAPI void APIENTRY glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint *params);
GLAPI void APIENTRY glGetTextureParameteriv(GLuint texture, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateVertexArrays(GLsizei n, GLuint *arrays);
GLAPI void APIENTRY glDisableVertexArrayAttrib(GLuint vaobj, GLuint index);
GLAPI void APIENTRY glEnableVertexArrayAttrib(GLuint vaobj, GLuint index);
GLAPI void APIENTRY glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer);
GLAPI void APIENTRY glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
GLAPI void APIENTRY glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
GLAPI void APIENTRY glCreateSamplers(GLsizei n, GLuint *samplers);
GLAPI void APIENTRY glCreateProgramPipelines(GLsizei n, GLuint *pipelines);
GLAPI void APIENTRY glCreateQueries(GLenum target, GLsizei n, GLuint *ids);
GLAPI void APIENTRY glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glMemoryBarrierByRegion(GLbitfield barriers);
GLAPI void APIENTRY glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
GLAPI GLenum APIENTRY glGetGraphicsResetStatus(void);
GLAPI void APIENTRY glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
GLAPI void APIENTRY glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI void APIENTRY glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI void APIENTRY glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI void APIENTRY glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI void APIENTRY glTextureBarrier(void);
#else
#define TGL_DEFINE_CORE_GL_4_5
extern PFNGLCLIPCONTROLPROC glClipControl;
extern PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks;
extern PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase;
extern PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange;
extern PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv;
extern PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v;
extern PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v;
extern PFNGLCREATEBUFFERSPROC glCreateBuffers;
extern PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;
extern PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;
extern PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;
extern PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData;
extern PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData;
extern PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData;
extern PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer;
extern PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;
extern PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer;
extern PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;
extern PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv;
extern PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v;
extern PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv;
extern PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;
extern PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers;
extern PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;
extern PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri;
extern PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;
extern PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer;
extern PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer;
extern PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers;
extern PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer;
extern PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData;
extern PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData;
extern PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv;
extern PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv;
extern PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv;
extern PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi;
extern PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;
extern PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;
extern PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;
extern PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;
extern PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers;
extern PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;
extern PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;
extern PFNGLCREATETEXTURESPROC glCreateTextures;
extern PFNGLTEXTUREBUFFERPROC glTextureBuffer;
extern PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange;
extern PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D;
extern PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D;
extern PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D;
extern PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample;
extern PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample;
extern PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D;
extern PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D;
extern PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D;
extern PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D;
extern PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D;
extern PFNGLTEXTUREPARAMETERFPROC glTextureParameterf;
extern PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv;
extern PFNGLTEXTUREPARAMETERIPROC glTextureParameteri;
extern PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv;
extern PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv;
extern PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv;
extern PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap;
extern PFNGLBINDTEXTUREUNITPROC glBindTextureUnit;
extern PFNGLGETTEXTUREIMAGEPROC glGetTextureImage;
extern PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage;
extern PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv;
extern PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv;
extern PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv;
extern PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv;
extern PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv;
extern PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv;
extern PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays;
extern PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib;
extern PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib;
extern PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer;
extern PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer;
extern PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers;
extern PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding;
extern PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat;
extern PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat;
extern PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat;
extern PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor;
extern PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv;
extern PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv;
extern PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv;
extern PFNGLCREATESAMPLERSPROC glCreateSamplers;
extern PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines;
extern PFNGLCREATEQUERIESPROC glCreateQueries;
extern PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v;
extern PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv;
extern PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v;
extern PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv;
extern PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion;
extern PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage;
extern PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage;
extern PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus;
extern PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage;
extern PFNGLGETNTEXIMAGEPROC glGetnTexImage;
extern PFNGLGETNUNIFORMDVPROC glGetnUniformdv;
extern PFNGLGETNUNIFORMFVPROC glGetnUniformfv;
extern PFNGLGETNUNIFORMIVPROC glGetnUniformiv;
extern PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv;
extern PFNGLREADNPIXELSPROC glReadnPixels;
extern PFNGLTEXTUREBARRIERPROC glTextureBarrier;
#endif
#endif /* TGL_DECLARE_CORE_GL_4_5 */

/* ARB_debug_output */
#if 1
#define TGL_DEFINE_ARB_DEBUG_OUTPUT
extern PFNGLDEBUGMESSAGECONTROLARBPROC glDebugMessageControlARB;
extern PFNGLDEBUGMESSAGEINSERTARBPROC glDebugMessageInsertARB;
extern PFNGLDEBUGMESSAGECALLBACKARBPROC glDebugMessageCallbackARB;
extern PFNGLGETDEBUGMESSAGELOGARBPROC glGetDebugMessageLogARB;
#endif

/* AMD_debug_output - copied from glext.h available from opengl.org */
#ifndef GL_AMD_debug_output
#define GL_AMD_debug_output
#define GL_MAX_DEBUG_LOGGED_MESSAGES_AMD  0x9144
#define GL_DEBUG_LOGGED_MESSAGES_AMD      0x9145
#define GL_DEBUG_SEVERITY_HIGH_AMD        0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_AMD      0x9147
#define GL_DEBUG_SEVERITY_LOW_AMD         0x9148
#define GL_DEBUG_CATEGORY_API_ERROR_AMD   0x9149
#define GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD 0x914A
#define GL_DEBUG_CATEGORY_DEPRECATION_AMD 0x914B
#define GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD 0x914C
#define GL_DEBUG_CATEGORY_PERFORMANCE_AMD 0x914D
#define GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD 0x914E
#define GL_DEBUG_CATEGORY_APPLICATION_AMD 0x914F
#define GL_DEBUG_CATEGORY_OTHER_AMD       0x9150
typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id, GLenum category, GLenum severity, GLsizei length, const GLchar *message, GLvoid *userParam);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEENABLEAMDPROC) (GLenum category, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTAMDPROC) (GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKAMDPROC) (GLDEBUGPROCAMD callback, GLvoid *userParam);
typedef GLuint(APIENTRYP PFNGLGETDEBUGMESSAGELOGAMDPROC) (GLuint count, GLsizei bufsize, GLenum *categories, GLuint *severities, GLuint *ids, GLsizei *lengths, GLchar *message);
#endif /* AMD_debug_output */
#if 1
#define TGL_DEFINE_AMD_DEBUG_OUTPUT
extern PFNGLDEBUGMESSAGEENABLEAMDPROC glDebugMessageEnableAMD;
extern PFNGLDEBUGMESSAGEINSERTAMDPROC glDebugMessageInsertAMD;
extern PFNGLDEBUGMESSAGECALLBACKAMDPROC glDebugMessageCallbackAMD;
extern PFNGLGETDEBUGMESSAGELOGAMDPROC glGetDebugMessageLogAMD;
#endif


#ifdef __cplusplus
}
#endif


#endif // __TGL__
