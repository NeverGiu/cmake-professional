
#ifndef API_MYTOOLS_H
#define API_MYTOOLS_H

#ifdef MYTOOLS_STATIC_DEFINE
#  define API_MYTOOLS
#  define REALLY_PRIVATE
#else
#  ifndef API_MYTOOLS
#    ifdef myTools_EXPORTS
        /* We are building this library */
#      define API_MYTOOLS __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define API_MYTOOLS __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef REALLY_PRIVATE
#    define REALLY_PRIVATE __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MYTOOLS_DEPRECATED
#  define MYTOOLS_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MYTOOLS_DEPRECATED_EXPORT
#  define MYTOOLS_DEPRECATED_EXPORT API_MYTOOLS MYTOOLS_DEPRECATED
#endif

#ifndef MYTOOLS_DEPRECATED_NO_EXPORT
#  define MYTOOLS_DEPRECATED_NO_EXPORT REALLY_PRIVATE MYTOOLS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef OMIT_DEPRECATED
#    define OMIT_DEPRECATED
#  endif
#endif

#endif /* API_MYTOOLS_H */
