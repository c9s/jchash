#ifndef PHP_JCHASH_H
#define PHP_JCHASH_H

#include "SAPI.h"
#include "zend_API.h"
#include "php.h"
#include "php_ini.h"
#include "zend_types.h"
#include "php_variables.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"
#include "ext/standard/html.h"

extern zend_module_entry jchash_module_entry;

#define GROUP_INIT_SIZE 16

#define phpext_jchash_ptr &jchash_module_entry

#ifdef ZTS
#include "TSRM.h"
#endif

#define PHP_JCHASH_VERSION "0.9.3"

PHP_MINIT_FUNCTION(jchash);
PHP_MSHUTDOWN_FUNCTION(jchash);
PHP_RINIT_FUNCTION(jchash);
PHP_RSHUTDOWN_FUNCTION(jchash);
PHP_MINFO_FUNCTION(jchash);

PHP_FUNCTION(jchash);

ZEND_BEGIN_MODULE_GLOBALS(jchash)

ZEND_END_MODULE_GLOBALS(jchash)

#if defined(COMPILE_DL_JCHASH) && defined(ZTS)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

// #define IF_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(jchash, v)

#endif
