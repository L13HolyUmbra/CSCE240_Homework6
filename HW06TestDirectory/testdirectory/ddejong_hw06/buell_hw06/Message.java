import java.util.TreeMap;
/*********************************************************************
 * Message class for Homework 06.
 *
 * This class has instance variables for message-centric data as
 * well as an <code>ArrayList</code> for the packets inside a message.
 *
 * Copyright(C) 2013 Duncan A. Buell.  All rights reserved.
 *
 * @author Duncan Buell
 * @version 1.00 2013-02-17 
 *
**/
public class Message<T extends Comparable<T>> implements IMessage
{
  private final int DUMMYINT = -999;
  private int messageID;
  private int packetCount;
  private TreeMap<Integer, Packet> packetMap;

/*********************************************************************
 * Constructor
**/
  public Message()
  {
    this.messageID = DUMMYINT;
    this.packetCount = DUMMYINT;
    packetMap = new TreeMap<Integer, Packet>();
  } // public Message()

/*********************************************************************
 * Accessors and Mutators.
**/

/*********************************************************************
 * Accessor for <code>messageID</code>.
 *
 * @return the message ID
**/
  public int getMessageID()
  {
    return this.messageID;
  } // public int getMessageID()

/*********************************************************************
 * General methods
**/

/*********************************************************************
 * Method to test if the message contains a given packet.
 *
 * @param p the packet to test
 * @return the answer to the question.
**/
  public boolean contains(Packet p)
  {
    Packet packetToFind = this.packetMap.get(p.getPacketID());

    if(null != packetToFind)
      return true;
    else
      return false;
  } // public boolean contains(Packet p)

/*********************************************************************
 * Method to insert a packet into this message.
 *
 * @param p the packet to insert into this message
**/
  public void insert(Packet p)
  {
    this.packetMap.put(p.getPacketID(), p);
    this.messageID = p.getMessageID();
    this.packetCount = p.getPacketCount();
  } // public void insert(Packet p)

/*********************************************************************
 * Method to test if the message is complete.
 *
 * @return the answer to the question.
**/
  public boolean isComplete()
  {
    if(this.packetCount == this.packetMap.size())
      return true;
    else
      return false;
  } // public boolean isComplete()

/*********************************************************************
 * Usual <code>toString</code> method.
 *
 * @param messageID the id of the message to be written.
 * @return a 'String' version of the message
**/
  public String toString()
  {
    String s = "";

    s += String.format("ID: %4d%n", this.messageID);
    s += String.format("PacketCount: %4d%n", this.packetCount);
    s += String.format("Nodes:      %d%n", this.packetMap.size());

    for(Integer packetID : this.packetMap.keySet())
    {
      s += String.format("%s%n", this.packetMap.get(packetID));
    }

    return s;
  } // public String toString()

} // public class Message implements IMessage
