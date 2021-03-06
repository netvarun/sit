#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <assert.h>
#include <stdbool.h>
#include "sit.h"

#define SET_ONCE(variable, value) ((variable && variable != value) ? assert(0) : (void)(variable = value))

#ifdef COMPILE_WITH_DEBUG
#define TEST_MODE (isTestMode())
#else
#define TEST_MODE false
#endif

bool
isTestMode();

void
setTestMode(bool val);

void
json_escape(pstring *target, pstring *pstr);

#endif
