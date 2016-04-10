#include "Message.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'Message' for a single message (similar to a map). 
 * This class defines a message, which is essentially a map.  
 *
 * Author: Dion de Jong
 * Date last modified: 3 November 2014
**/

/******************************************************************************
 * Constructor
**/
Message::Message()
{
}

/******************************************************************************
 * Destructor
**/
Message::~Message()
{
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * Accessor 'getMessageID'.
 * 
 * Parameters: None
 * 
 * Returns:
 * the 'messageID'
 * 
 * Output: None. 
**/
int Message::getMessageID() const
{
  return messageID; 
}

/******************************************************************************
 * General functions.
**/
/******************************************************************************
 * Function to test if a message contains a given packet. 
 * 
 * Parameters:
 * p - the 'Packet' to be tested
 *
 * Returns:
 * A boolean that answers if the packet is in the message. 
 * 
 * Output: None. 
**/
bool Message::contains(const Packet& p) const
{
  bool contained = false;   
  //run through the message
  for (std::map<int, Packet>::const_iterator iter = message.begin(); iter!=message.end(); ++iter)
  {
    //Compare each Packet's PacketID to the one you are testing
    if ((iter->second).getPacketID() == p.getPacketID()) 
    {
      contained = true; 
    }  
  }
  return contained; 
}

/******************************************************************************
 * Method to insert a packet into a message.
 *
 * Parameters:
 * p - the 'Packet' to be inserted
 *
 * Returns: None.  
 *
 * Output: None
**/
void Message::insert(const Packet& p)
{
  //should account for duplicate packets and overwrite them. 
  message[p.getPacketID()] = p;  
  //message ID & packetCount are given to the Message. 
  messageID = p.getMessageID(); 
  packetCount = p.getPacketCount(); 
}

/******************************************************************************
 * Method to test whether a message is complete (has all of it's packets) 
 * 
 * Parameters: None. 
 * 
 * Returns:
 * A boolean that says if the message is complete. 
 * 
 * Output: None. 
**/
bool Message::isComplete() const
{
  bool complete = false; 
  //Simply compare the packetCount of a message to it's current size. 
  if (message.size() == packetCount)
  {
    complete = true; 
  }
  return complete; 
}

/******************************************************************************
 * Function 'toString' that will push a message to a String. 
 * 
 * Parameters: None 
 * 
 * Returns:
 * the 'toString' of the message as a 'vector' of packets. 
 *
 * Output: None. 
**/
string Message::toString() const
{
  string mapString = ""; 
  //run through message
  for (std::map<int, Packet>::const_iterator iter = message.begin(); iter!=message.end(); ++iter)
  {
    //call the toString function from Packet class on each packet in the message. 
    mapString += iter->second.toString();
  }
  return mapString;
}
