/*
 * Copyright (c) 2011-2014, Thomas Bischof
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice, 
 *    this list of conditions and the following disclaimer in the documentation 
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the Massachusetts Institute of Technology nor the 
 *    names of its contributors may be used to endorse or promote products 
 *    derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <stdio.h>
#include <stdarg.h>

#include "options.h"

// Mode codes
#define PQ_USAGE                        1
#define PQ_HEADER                       2
#define PQ_VERSION                      3
#define PQ_RESOLUTION                   4
#define PQ_DATA                         5
#define PQ_RECORD_INTERACTIVE           6
#define PQ_RECORD_CONTINUOUS            7
#define PQ_RECORD_T2                    8
#define PQ_RECORD_T3                    9
#define PQ_RECORD_MARKER               10
#define PQ_RECORD_OVERFLOW             11


// Error codes
#define	PQ_SUCCESS	                    0
#define PQ_ERROR_OPTIONS               -1
#define PQ_ERROR_IO                    -2
#define PQ_ERROR_VERSION               -3
#define PQ_ERROR_EOF                   -4
#define PQ_ERROR_UNKNOWN_DATA          -5
#define PQ_ERROR_MODE                  -6
#define PQ_ERROR_MEM                   -7

extern int verbose;

void debug(char *message, ...);
void error(char *message, ...);
void warn(char *message, ...);

int pq_check(int status);
void pq_record_status_print(char *name, uint64_t count, options_t *options);

#endif
