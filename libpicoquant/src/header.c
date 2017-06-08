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

#include "header.h"

#include "error.h"

int pq_header_read(FILE *stream_in, pq_header_t *pq_header) {
	size_t n_read;

	n_read = fread(pq_header, sizeof(pq_header_t), 1, stream_in);
	if ( n_read == 1 ) {
		return(PQ_SUCCESS);
	} else {
		return(PQ_ERROR_IO);
	}
}

void pq_header_printf(FILE *stream_out, pq_header_t *pq_header) {
	fprintf(stream_out, "Ident = %.*s\n", 
			(int)sizeof(pq_header->Ident), pq_header->Ident);
	fprintf(stream_out, "FormatVersion = %.*s\n", 
			(int)sizeof(pq_header->Ident), pq_header->FormatVersion);
}


void pq_header_fwrite(FILE *stream_out, pq_header_t *pq_header) {
	fwrite(pq_header, sizeof(pq_header_t), 1, stream_out);
}

void ptu_header_fwrite(FILE *stream_out, ptu_header_t *ptu_header, pq_header_t *pq_header){
	fwrite(ptu_header, sizeof(ptu_header_t), 1, stream_out);
	fwrite(pq_header, sizeof(pq_header_t), 1, stream_out);
}