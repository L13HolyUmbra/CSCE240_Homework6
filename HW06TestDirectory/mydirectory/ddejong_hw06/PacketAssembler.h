/****************************************************************
 * Header file for the class to assemble packets into messages.
 *
 * Author/copyright:  Dion de Jong 
 * Date: 3 November 2014
 *
**/

#ifndef PACKETASSEMBLER_H
#define PACKETASSEMBLER_H

#include <iostream>
#include <map>
using namespace std;

#include "Message.h"

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

class PacketAssembler
{
public:
  PacketAssembler();
  virtual ~PacketAssembler();

  void runForever(Scanner& scanner, ofstream& outStream);

private:
  map<int, Message> messagesMap;

  bool messagesMapContains(int messageID) const;
  string dumpMessage(int messageID);
  int readPacket(Scanner& scanner, ofstream& outStream);


};

#endif
