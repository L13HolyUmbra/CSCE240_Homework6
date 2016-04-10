#include "PacketAssembler.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'PacketAssembler' for assembling packets.
 * This class will put together packets as they come in from in put files and 
 * attach these packets to messages (which are maps). It then adds these 
 * messages to the MessagesMap. Lastly, once a message is completed it will be 
 * removed from the messagesMap and output. 
 *
 * Author: Dion de Jong 
 * Date last modified: 3 November 2014
**/

/******************************************************************************
 * Constructor
**/
PacketAssembler::PacketAssembler()
{
}

/******************************************************************************
 * Destructor
**/
PacketAssembler::~PacketAssembler()
{
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'dumpMessage' 
 * This function will toString a message with the message ID used 
 * as the parameter and remove it from the messagesMap. 
 *
 * Parameter:
 * messageID - the ID of the message to be dumped
 *
 * Returns:
 * the string of the dumped message
 *
 * Output: None
**/
string PacketAssembler::dumpMessage(int messageID)
{
#ifdef EBUG
  Utils::logStream << "enter dumpMessage\n"; 
  Utils::logStream.flush();
#endif

  string DumpMessage = ""; 
  Message DumpedMessage; 

  //run through the MessagesMap
  for (map<int, Message>::const_iterator iter = messagesMap.begin(); iter!=messagesMap.end(); iter++)
  {
    //Test if a message matches the messageID used as a parameter 
    //This would be the message that is completed, based on how this function is called)  
    DumpedMessage = iter->second; 
    if (messageID == DumpedMessage.getMessageID())
    { 
      //toString that message and erase it from the map.
      DumpMessage += DumpedMessage.toString(); 
      DumpMessage += "\n"; 
      //erasing here allows for a message of the same ID to be added again. 
      messagesMap.erase(messageID); 
    } 
  }

  return DumpMessage; 

#ifdef EBUG
  Utils::logStream << "leave dumpMessage\n"; 
  Utils::logStream.flush();
#endif
}

/******************************************************************************
 * Function 'messagesMapContains' 
 * This function will test if the MessageMap contains a message with a specific
 * MessageID so that we can add a packet to it.  
 *
 * Parameter:
 * messageID - the ID of the message to be tested
 *
 * Returns:
 * a boolean that says if the MessageMap contains the message. 
 * 
 * Output: None
**/
bool PacketAssembler::messagesMapContains(int messageID) const
{
#ifdef EBUG
  Utils::logStream << "enter messagesMapContains\n"; 
#endif

  Message tempMessage; 
  bool contains = false; 
  
  //run through the Messages Map
  for (map<int, Message>::const_iterator iter = messagesMap.begin(); iter !=messagesMap.end(); iter++)
  {
    //compare the IDs of each message to the one of the message you would like to add
    tempMessage = iter->second; 
    if (messageID == tempMessage.getMessageID()) 
    {
      contains = true; 
    }
  }

  return contains; 
#ifdef EBUG
  Utils::logStream << "leave messagesMapContains\n"; 
#endif
}

/******************************************************************************
 * Function 'readPacket' 
 * This function will take in packets from an input file and assign them values. 
 *
 * Parameters:
 * scanner - the 'Scanner' from which to read 
 * outStream - the stream to which to write
 *
 * Returns:
 * the 'packetID' of the packet read, or else the dummy value 
 *
 * Output: None
*/
int PacketAssembler::readPacket(Scanner& scanner, ofstream& outStream)
{
#ifdef EBUG
  Utils::logStream << "enter readPacket\n"; 
#endif

  Packet tempPacket; 
  //jump to the read created in the Packet class
  tempPacket.readPacket(scanner); 
  //test output: 
  //cout << tempPacket.toString();  

#ifdef EBUG
  Utils::logStream << "leave readPacket\n"; 
#endif
return tempPacket.getPacketID(); 
}

/******************************************************************************
 * Function 'runForever' 
 * This function will do most of the programs work. It will take in all the packets
 * (which realistically, should make this a continuously running function) and call
 * the function for them to be read. It will take these read packets and add them to
 * messages and then add these messages to the  MessagesMap. It will test if a message
 * has been completed upon the addition of a packet and call the messageDump function 
 * to remove and output a message if it is done. In the scale of this program, this function
 * runs until all the messages are complete and there are no more packets to take in.
 *
 * Parameters:
 * scanner - the 'Scanner' from which to read 
 * outStream - the stream to which to write
 *
 * Returns: None
 *
 * Output: Adds each completed message to the OutStream. 
**/
void PacketAssembler::runForever(Scanner& scanner, ofstream& outStream)
{
#ifdef EBUG
  Utils::logStream << "enter runForever\n"; 
#endif

  Packet tempPacket; 
  int tempMessageID; 
  
  //run as long as there are more packets to take in. 
  while(scanner.hasNext()) 
  {
    //create a temporary packet and call the read from the Packet class to assign it values
    tempPacket = Packet(scanner);
    tempMessageID = tempPacket.getMessageID(); 
    //using this packets MessageID, check if we already have this message
    if (messagesMapContains(tempMessageID) == false)
    {
      //if not create a new Message and push it into the messagesMap
      Message tempMessage;
      tempMessage.insert(tempPacket); 
      messagesMap.insert(std::pair<int, Message>(tempMessageID, tempMessage));   
    } 
   
    //otherwise, this message is in the Messages map and we should just add the new
    //packet to the message already in the messages map. 
    else 
    {
      if(messagesMapContains(tempMessageID))
      {
        messagesMap[tempMessageID].insert(tempPacket); 
      }
    }  
  
    //after adding each packet, we should check if that packet completed a message
    if (messagesMap[tempMessageID].isComplete() == true)
    {
      //if it did, dump it and outStream the data. 
      outStream << "The Completed message is: ";
      outStream << "\n";  
      outStream << dumpMessage(tempMessageID); 
    }
  } 

#ifdef EBUG
  Utils::logStream << "leave runForever\n"; 
#endif
}
