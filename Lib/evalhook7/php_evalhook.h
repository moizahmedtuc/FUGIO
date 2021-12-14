/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2010 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 297205 2010-03-30 21:09:07Z johannes $ */

#ifndef PHP_EVALHOOK_H
#define PHP_EVALHOOK_H

extern zend_module_entry evalhook_module_entry;
#define phpext_evalhook_ptr &evalhook_module_entry

#ifdef PHP_WIN32
#	define PHP_EVALHOOK_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_EVALHOOK_API __attribute__ ((visibility("default")))
#else
#	define PHP_EVALHOOK_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(evalhook);
PHP_MSHUTDOWN_FUNCTION(evalhook);
PHP_RINIT_FUNCTION(evalhook);
PHP_RSHUTDOWN_FUNCTION(evalhook);
PHP_MINFO_FUNCTION(evalhook);

#ifdef ZTS
#define EVALHOOK_G(v) TSRMG(evalhook_globals_id, zend_evalhook_globals *, v)
#else
#define EVALHOOK_G(v) (evalhook_globals.v)
#endif

#endif	/* PHP_EVALHOOK_H */
