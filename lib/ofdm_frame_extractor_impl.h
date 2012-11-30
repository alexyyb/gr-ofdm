/* -*- c++ -*- */
/* Copyright 2012 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_OFDM_OFDM_FRAME_EXTRACTOR_IMPL_H
#define INCLUDED_OFDM_OFDM_FRAME_EXTRACTOR_IMPL_H

#include <ofdm/ofdm_frame_extractor.h>

namespace gr {
  namespace ofdm {

    class ofdm_frame_extractor_impl : public ofdm_frame_extractor
    {
    private:
      // Nothing to declare in this block.

    public:
      ofdm_frame_extractor_impl(int fftlen, int cplen);
      ~ofdm_frame_extractor_impl();

      // Where all the action really happens
      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);
    };

  } // namespace ofdm
} // namespace gr

#endif /* INCLUDED_OFDM_OFDM_FRAME_EXTRACTOR_IMPL_H */

