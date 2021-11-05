
#ifndef MINE_EXPORT_H
#define MINE_EXPORT_H

#ifdef MYSHARED_STATIC_DEFINE
#  define MINE_EXPORT
#  define MYSHARED_NO_EXPORT
#else
#  ifndef MINE_EXPORT
#    ifdef myShared_EXPORTS
        /* We are building this library */
#      define MINE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define MINE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MYSHARED_NO_EXPORT
#    define MYSHARED_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MYSHARED_DEPRECATED
#  define MYSHARED_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MYSHARED_DEPRECATED_EXPORT
#  define MYSHARED_DEPRECATED_EXPORT MINE_EXPORT MYSHARED_DEPRECATED
#endif

#ifndef MYSHARED_DEPRECATED_NO_EXPORT
#  define MYSHARED_DEPRECATED_NO_EXPORT MYSHARED_NO_EXPORT MYSHARED_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MYSHARED_NO_DEPRECATED
#    define MYSHARED_NO_DEPRECATED
#  endif
#endif

#endif /* MINE_EXPORT_H */
