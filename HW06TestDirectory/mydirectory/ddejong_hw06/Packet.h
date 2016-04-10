/****************************************************************
 * Header file for a single packet.
 *
 * Author/copyright:  Duncan Buell
 * Date: 15 July 2014
 *
**/

#ifndef PACKET_H
#define PACKET_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#define DUMMYPACKETCOUNT -11
#define DUMMYPACKETID -222
#define DUMMYMESSAGEID -3333
#define DUMMYPAYLOAD "dummypayload"

class Packet
{
public:
  Packet();
  Packet(Scanner& scanner);
  virtual ~Packet();

  bool equals(const Packet& p) const;
  int getMessageID() const;
  int getPacketID() const;
  int getPacketCount() const;
  string getPayload() const;
  void readPacket(Scanner& scanner);

  string toString() const;

private:
  int messageID;
  int packetCount;
  int packetID;
  string payload;
};

#endif
