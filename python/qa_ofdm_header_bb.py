#!/usr/bin/env python
# 
# Copyright 2012 <+YOU OR YOUR COMPANY+>.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gruel import pmt
import ofdm_swig as ofdm

class qa_ofdm_header_bb (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        data = (0, 1, 2, 3)
        tag_name = "length"
        tag = gr.gr_tag_t()
        tag.offset = 0
        tag.key = pmt.pmt_string_to_symbol(tag_name)
        tag.value = pmt.pmt_from_long(len(data))
        src = gr.vector_source_b(data, (tag,), False, 1)
        header = ofdm.ofdm_header_bb(16)
        sink = gr.vector_sink_b()
        self.tb.connect(src, header, sink)
        self.tb.run ()
        # check data
        print sink.data()
        expected_hdr = (0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0)
        self.assertEqual(sink.data(), expected_hdr)


if __name__ == '__main__':
    gr_unittest.run(qa_ofdm_header_bb, "qa_ofdm_header_bb.xml")
