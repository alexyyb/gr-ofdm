/* -*- c++ -*- */

#define OFDM_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "ofdm_swig_doc.i"

%{
#include "ofdm/crc32_bb.h"
#include "ofdm/tagged_stream_mux.h"
%}


%include "ofdm/crc32_bb.h"
GR_SWIG_BLOCK_MAGIC2(ofdm, crc32_bb);
%include "ofdm/tagged_stream_mux.h"
GR_SWIG_BLOCK_MAGIC2(ofdm, tagged_stream_mux);
