/* Tests for stream functions
   Copyright 2017 The NeoPG developers

   NeoPG is released under the Simplified BSD License (see license.txt)
*/

#include <neopg/utils/stream.h>
#include "gtest/gtest.h"

using namespace NeoPG;

namespace NeoPG {

TEST(NeoPGTest, utils_stream_test) {
  {
    CountingStreamBuf::int_type result;
    CountingStreamBuf buf;
    ASSERT_EQ(buf.bytes_written(), 0);
    result = buf.overflow(0x41);
    ASSERT_EQ(result, 1);
    ASSERT_EQ(buf.bytes_written(), 1);
    result = buf.xsputn("Test", 4);
    ASSERT_EQ(result, 4);
    ASSERT_EQ(buf.bytes_written(), 5);
  }
  {
    CountingStream out;
    ASSERT_EQ(out.bytes_written(), 0);
    out.put(0x41);
    ASSERT_EQ(out.bytes_written(), 1);
    out << (uint8_t)0x42;
    ASSERT_EQ(out.bytes_written(), 2);
    out << "NeoPG";
    ASSERT_EQ(out.bytes_written(), 7);
    out.write("Test", 4);
    ASSERT_EQ(out.bytes_written(), 11);
  }
}
}
