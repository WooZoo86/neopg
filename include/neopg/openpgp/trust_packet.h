/* OpenPGP format
   Copyright 2017 The NeoPG developers

   NeoPG is released under the Simplified BSD License (see license.txt)
*/

#pragma once

#include <neopg/openpgp/packet.h>
#include <vector>

namespace NeoPG {
namespace OpenPGP {

struct NEOPG_UNSTABLE_API TrustPacket : Packet {
  std::vector<uint8_t> m_data;

  void write_body(std::ostream& out) const override;
  PacketType type() const override;
};

}  // namespace OpenPGP
}  // namespace NeoPG
