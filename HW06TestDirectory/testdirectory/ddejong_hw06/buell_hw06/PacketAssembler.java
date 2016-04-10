import java.util.Scanner;
import java.util.TreeMap;
/*********************************************************************
 * PacketAssembler for Homework 6.
 *
 * This class is what does the work of assembling packets and then
 * dumping them when all the packets for a message have arrived.
 *
 * Copyright(C) 2013 Duncan A. Buell.  All rights reserved.
 *
 * @author Duncan Buell
 * @version 1.00 2013-03-30 
 *
**/
public class PacketAssembler implements IPacketAssembler
{
  private final int DUMMYID = -999;
  private TreeMap<Integer, Message<Packet>> messages;

/*********************************************************************
 * Constructor
**/
  public PacketAssembler()
  {
    messages = new TreeMap<Integer, Message<Packet>>();
  } // public PacketAssembler()

/*********************************************************************
 * Accessors and Mutators.
**/

/*********************************************************************
 * General methods
**/

/*********************************************************************
 * Method to dump the message.
 *
 * @param messageID the id of the message to be written.
 * @return a 'String' version of the message
**/
  public String dumpMessage(int messageID)
  {
    String s = "";

    Message<Packet> msg = this.messages.get(messageID);
    if(null != msg)
    {
      s += String.format("%s%n", msg);
      this.messages.remove(messageID);
    }
    else
    {
      s += String.format("No message exists with ID %d%n", messageID);
    }

    return s;
  } // public String dumpMessage(int messageID)

/*********************************************************************
 * read method
 *
 * @param inFile the input file from which to read.
 * @return if positive, the message id of the message just completed,
 *         else a negative number.
**/
  public int readPacket(Scanner inFile)
  {
    int messageID;
    int returnValue;
    Packet p;
    Message<Packet> msg = null;

    p = new Packet(inFile);

    FileUtils.logFile.printf("newpacket %s%n", p);
    FileUtils.logFile.flush();

    messageID = p.getMessageID();
    msg = this.messages.get(messageID);

    FileUtils.logFile.printf("message found: %s%n", msg);
    FileUtils.logFile.flush();

    if(null == msg)
    {
      FileUtils.logFile.printf("null message found: %s%n", msg);
      FileUtils.logFile.flush();

      msg = new Message<Packet>();
      msg.insert(p);
      this.messages.put(messageID, msg);

      FileUtils.logFile.printf("new message created: %s%n", msg);
      FileUtils.logFile.flush();

    }
    else
    {
      if(!msg.contains(p))
      {
        msg.insert(p);

        FileUtils.logFile.printf("packet inserted: %s%n", msg);
        FileUtils.logFile.flush();

      }
    }

    returnValue = this.DUMMYID;
    if(msg.isComplete())
    {
      returnValue = messageID;

      FileUtils.logFile.printf("donemessage %s%n", messageID);
      FileUtils.logFile.flush();

    }

    return returnValue;
  } // public int readPacket(Scanner inFile)

} // public class PacketAssembler implements IPacketAssembler
