/* -*- c++ -*- */
/* 
 * Copyright 2012 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_OFDM_MUX_H
#define INCLUDED_OFDM_MUX_H

#include <ofdm/api.h>
#include <gr_block.h>
#include <vector>

namespace gr {
  namespace ofdm {

    /*!
     * \brief Combines tagged streams.
     *
     * \description
     * Takes N streams as input.  Each stream is tagged with packet lengths.
     * Packets are output sequentially from each input stream.
     *
     * \ingroup block
     *
     */

    class OFDM_API tagged_stream_mux : virtual public gr_block
    {
    public:
       typedef boost::shared_ptr<tagged_stream_mux> sptr;
       static sptr make(size_t itemsize, unsigned int nstreams, std::string lengthtagname, long MTU);
    };

  } // namespace ofdm
} // namespace gr

#endif /* INCLUDED_OFDM_MUX_H */

