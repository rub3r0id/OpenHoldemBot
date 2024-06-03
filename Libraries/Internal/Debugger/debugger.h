//******************************************************************************
//
// This file is part of the OpenHoldem project
//    Source code:           https://github.com/OpenHoldem/openholdembot/
//    Forums:                http://www.maxinmontreal.com/forums/index.php
//    Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html
//
//******************************************************************************
//
// Purpose: Debug-DLL for OpenHoldem
//
//******************************************************************************

#pragma once
#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0501
#endif

#include <assert.h>
#ifdef LOGASSERT
#undef assert
#define assert(expression) (void)( \
			write_log_assert((!!(expression)), "[Assertion] %s:%s:%d is not (%s)\n", (const char*)(__FILE__), (const char*)(__FUNCTION__), (unsigned)(__LINE__), (const char*)(#expression)) \
        )
#undef AssertRange
#define AssertRange(/*double*/ value, /*double*/ lower_bound, /*double*/ upper_bound) \
    { assert((value) >= (lower_bound)); assert((value) <= (upper_bound)); }
#endif

void start_log(int current_session_iD, bool delete_old_log, const char* logFilePath);
void stop_log();
void clear_log();
void write_log(bool debug_settings_for_this_message, const char* fmt, ...);
void write_log_assert(bool is_expression, const char* fmt, ...);
void write_log_nostamp(bool debug_settings_for_this_message, const char* fmt, ...);
void write_log_vl(bool debug_settings_for_this_message, const char* fmt, va_list vl);
void write_log_separator(bool debug_settings_for_this_message, const char* header_message);
