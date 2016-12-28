dnl $Id$
dnl config.m4 for extension jchash

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(jchash, for jchash support,
dnl Make sure that the comment is aligned:
dnl [  --with-jchash             Include jchash support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(jchash, whether to enable jchash support,
dnl Make sure that the comment is aligned:
[  --enable-jchash           Enable jchash support])

if test "$PHP_JCHASH" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-jchash -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/jchash.h"  # you most likely want to change this
  dnl if test -r $PHP_JCHASH/$SEARCH_FOR; then # path given as parameter
  dnl   JCHASH_DIR=$PHP_JCHASH
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for jchash files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       JCHASH_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$JCHASH_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the jchash distribution])
  dnl fi

  dnl # --with-jchash -> add include path
  dnl PHP_ADD_INCLUDE($JCHASH_DIR/include)

  dnl # --with-jchash -> check for lib and symbol presence
  dnl LIBNAME=jchash # you may want to change this
  dnl LIBSYMBOL=jchash # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $JCHASH_DIR/$PHP_LIBDIR, JCHASH_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_JCHASHLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong jchash lib version or lib not found])
  dnl ],[
  dnl   -L$JCHASH_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(JCHASH_SHARED_LIBADD)

  PHP_NEW_EXTENSION(jchash, jchash.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
