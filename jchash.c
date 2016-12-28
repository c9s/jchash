#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_jchash.h"
#include "ext/standard/php_var.h"

ZEND_DECLARE_MODULE_GLOBALS(jchash)

ZEND_BEGIN_ARG_INFO_EX(arginfo_jchash, 0, 0, 1)
  ZEND_ARG_INFO(0, key)
  ZEND_ARG_INFO(0, num_buckets)
ZEND_END_ARG_INFO()

static const zend_function_entry jchash_functions[] = {
  PHP_FE(jchash,  arginfo_jchash)
  PHP_FE_END
};

zend_module_entry jchash_module_entry = {
	STANDARD_MODULE_HEADER,
	"jchash",
	jchash_functions,
	PHP_MINIT(jchash),
	PHP_MSHUTDOWN(jchash),
	NULL,
	PHP_RSHUTDOWN(jchash),
	PHP_MINFO(jchash),
	PHP_JCHASH_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_JCHASH
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(jchash)
#endif

#define JCHASH_HASH_ADD_NEW(ht, num_idx, str_idx, val) \
      (str_idx) \
      ? zend_hash_add_new(ht, str_idx, val) \
      : zend_hash_index_add_new(ht, num_idx, val)

#define JCHASH_HASH_UPDATE(ht, num_idx, str_idx, val) \
      (str_idx) \
      ? zend_hash_update(ht, str_idx, val) \
      : zend_hash_index_update(ht, num_idx, val)

#define JCHASH_HASH_FIND(ht, num_idx, str_idx) \
      (str_idx) \
      ? zend_hash_find(ht, str_idx) \
      : zend_hash_index_find(ht, num_idx)

PHP_INI_BEGIN()
    // STD_PHP_INI_ENTRY("jchash.default",   "unsafe_raw", PHP_INI_SYSTEM|PHP_INI_PERDIR, UpdateDefaultFilter, default_filter, zend_filter_globals, filter_globals)
    // PHP_INI_ENTRY("jchash.default_flags", NULL,     PHP_INI_SYSTEM|PHP_INI_PERDIR, OnUpdateFlags)
PHP_INI_END()

PHP_MINIT_FUNCTION(jchash)
{
    REGISTER_INI_ENTRIES();
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(jchash)
{
    UNREGISTER_INI_ENTRIES();
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(jchash)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(jchash)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "Version", PHP_JCHASH_VERSION);
    php_info_print_table_end();
    DISPLAY_INI_ENTRIES();
}

PHP_FUNCTION(jchash)
{
    zval *zvalkey;
    zend_long num_buckets;
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "zl", &zvalkey, &num_buckets) == FAILURE) {
        return;
    }




}
