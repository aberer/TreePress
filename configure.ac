#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([TreePress],[0.0.1],[bla@bla.org])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([src/config.h])

AM_INIT_AUTOMAKE(TreePress, 0.0.1)

AM_SILENT_RULES([yes])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [main])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset])


AC_ARG_ENABLE(debug,
  [ --enable-debug    compile with debug information and  less optimization ],
  [case "${enableval}" in
     yes | no ) WITH_DEBUG="${enableval}" ;;
     *) AC_MSG_ERROR(bad value ${enableval} for --enable-debug) ;;
   esac],
  [WITH_DEBUG="no"]
)
AM_CONDITIONAL([WITH_DEBUG], [test  "x$WITH_DEBUG" = "xyes"])


AC_CONFIG_FILES([Makefile])
AC_OUTPUT
