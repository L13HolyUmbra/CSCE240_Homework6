#include "Packet.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'Packet' for a single packet.
 * This class defines a packet object which has 3 int variables and a string payload. 
 *
 * Author: Dion de Jong
 * Date last modified: 3 November 2014
**/

/******************************************************************************
 * Constructor
**/
Packet::Packet()
{
}

/******************************************************************************
 * Constructor with data supplied.
**/
Packet::Packet(Scanner& scanner)
{
  //To avoid losing the scanner when we want to read a packet in PacketAssembler,
  //we call readPacket in this constructor using the scanner as a parameter. 
  //this creates a packet with the data the scanner is taking in. 
  readPacket(scanner);
}

/******************************************************************************
 * Destructor
**/
Packet::~Packet()
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
int Packet::getMessageID() const
{
  return messageID; 
}

/******************************************************************************
 * Accessor 'getPacketCount'.
 *
 * Parameters: None 
 *
 * Returns:
 * the 'packetCount'
 *
 * Output: None 
**/
int Packet::getPacketCount() const
{
  return packetCount; 
}

/******************************************************************************
 * Accessor 'getPacketID'.
 * 
 * Parameters: None 
 *
 * Returns:
 * the 'packetID'
 * 
 * Output: None. 
**/
int Packet::getPacketID() const
{
  return packetID; 
}

/******************************************************************************
 * Accessor 'getPayload'.
 *
 * Parameters: None
 * 
 * Returns:
 * the 'payload'
 *
 * Output: None. 
**/
string Packet::getPayload() const
{
  return payload; 
}

/******************************************************************************
 * Method to test two packets for equality.
 *
 * Parameter:
 * that - the packet to be tested against 'this' packet
 *
 * Returns:
 * A boolean that says if the packets are equal. 
 *
 * Output: None
**/
bool Packet::equals(const Packet& that) const
{
  bool equals = false; 
  //simply compare PacketIDs
  if (this->packetID == that.getPacketID())
    {
      equals = true; 
    }
  return equals; 
}

/******************************************************************************
 * Method to read a packet 
 * Using a scanner, this function will read data from a file and assign the
 * values it reads to the different variables of the packet object. 
 *
 * Parameter:
 * scanner - the 'Scanner' to be read from
 *
 * Returns: None 
 *
 * Output: None. 
**/
void Packet::readPacket(Scanner& scanner)
{
  //This must be done using the scanLine Utility to account 
  //for payloads that are potentially blank spaces. 
  ScanLine scanLine; 
  int tempInt; 
  string tempString = ""; 
  
  //Open the ScanLine
  string Line = scanner.nextLine(); 
  scanLine.openString(Line);  
  
  tempInt = scanLine.nextInt(); 
  this->messageID = tempInt; 

  tempInt = scanLine.nextInt(); 
  this->packetID = tempInt; 

  tempInt = scanLine.nextInt(); 
  this->packetCount = tempInt; 
  
  //add any number of words (or lack thereof) in the payload to a string and 
  //set that as the payload of the packet. 
  while (scanLine.hasMoreData())
  {
    tempString += scanLine.next(); 
    tempString += " ";  
  } 
  this->payload = tempString;  
} 


/******************************************************************************
 * Function 'toString'.
 * 
 * Parameter: None 
 * 
 * Returns:
 * the 'toString' of the class, that is, of the variables in this packet
 * 
 * Output: None. 
**/
string Packet::toString() const
{
  string packetString = ""; 
  packetString += Utils::Format(messageID); 
  packetString += Utils::Format(packetID, 4);
  packetString += Utils::Format(packetCount, 4);
  packetString += " "; 
  packetString += payload; 
  packetString += "\n"; 

  return packetString;  
}
