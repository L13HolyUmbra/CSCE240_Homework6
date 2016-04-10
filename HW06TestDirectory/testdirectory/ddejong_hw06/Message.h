/****************************************************************
 * Header file for a single message.
 *
 * Author/copyright:  Duncan Buell
 * Used by: Dion de Jong
 * Date: 3 November 2014
 *
**/

#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <map>
using namespace std;

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#include "Packet.h"

class Message
{
public:
  Message();
  virtual ~Message();

  bool contains(const Packet& p) const;
  int getMessageID() const;
  void insert(const Packet& p);
  bool isComplete() const;

  string toString() const;

private:
  int messageID;
  int packetCount;

  map<int, Packet> message;
};

#endif
