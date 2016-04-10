import java.util.Scanner;
/*********************************************************************
 * Class for handling the individual fields in a packet.
 * This class is nothing more than a wrapper for the instance
 * variables, together with comparison, equals, the usual
 * <code>toString</code>, and a method for reading the data from
 * a <code>Scanner</code>.
 *
 * Copyright (C) 2013 by Duncan A. Buell.  All rights reserved.
 *
 * @author Duncan A. Buell
 * @version 1.00 2013-03-30
**/
public class Packet implements IPacket,Comparable<Packet>
{
/*********************************************************************
 * Instance variables for the class.
**/
  static private final Integer DUMMYINT = Integer.MIN_VALUE;
  static private final String DUMMYSTRING = "dummy";
  private Integer messageID;
  private Integer packetID;
  private Integer packetCount;
  private String payload;

/*********************************************************************
 * Constructor.
**/
  public Packet(Scanner inFile)
  {
    this.messageID = Packet.DUMMYINT;
    this.packetID = Packet.DUMMYINT;
    this.packetCount = Packet.DUMMYINT;
    this.payload = Packet.DUMMYSTRING;

    this.readPacket(inFile);
  } // public Packet(Scanner inFile)

/*********************************************************************
 * Accessors and mutators.
**/
/*********************************************************************
 * Method to get the <code>messageID</code>.
 *
 * @return the value of <code>messageID</code>.
**/
  public Integer getMessageID()
  {
    return this.messageID;
  } // public Integer getMessageID()

/*********************************************************************
 * Method to get the <code>packetID</code>.
 *
 * @return the value of <code>packetID</code>.
**/
  public Integer getPacketID()
  {
    return this.packetID;
  } // public Integer getPacketID()

/*********************************************************************
 * Method to get the <code>packetCount</code>.
 *
 * @return the value of <code>packetCount</code>.
**/
  public Integer getPacketCount()
  {
    return this.packetCount;
  } // public Integer getPacketCount()

/*********************************************************************
 * Method to get the <code>payload</code>.
 *
 * @return the value of <code>payload</code>.
**/
  public String getPayload()
  {
    return this.payload;
  } // public String getPayload()

/*********************************************************************
 * General methods.
**/

/*********************************************************************
 * Method to compare two <code>Packet</code> instances.
 *
 * @param that the 'Packet' to compare to
 * @return -1, 0, +1 as appropriate
**/
  public int compareTo(Packet that)
  {
    return this.getPacketID().compareTo(that.getPacketID());
  } // public int compareTo(Packet that)

/*********************************************************************
 * Method to test equals of two <code>Packet</code> instances.
 *
 * @param that the 'Packet' to test against
 * @return the answer to the question
**/
  public boolean equals(Packet that)
  {
    return (0 == this.getPacketID().compareTo(that.getPacketID()));
  } // public boolean equals(Packet that)

/*********************************************************************
 * Method to read the packets from an input <code>Scanner</code>.
 * Note that this is more or less hard coded. Also that we don't
 * bulletproof the input; among other things we assume that partial
 * records don't appear in the input data.
 *
 * @param inFile the 'Scanner' from which to read
 * @return the 'Packet' that was read
**/
  public Packet readPacket(Scanner inFile)
  {
    Integer inInt;
    String inString;

    inInt = inFile.nextInt(); // messageID
    this.messageID = inInt;

    inInt = inFile.nextInt(); // packetID
    this.packetID = inInt;

    inInt = inFile.nextInt(); // PacketCount
    this.packetCount = inInt;

    inString = inFile.nextLine(); // payload
    this.payload = inString;

    return this;
  } // public Packet readPacket(Scanner inFile)

/*********************************************************************
 * Usual <code>toString</code> method.
 *
 * @return the <code>toString</code> value of this packet.
**/
  public String toString()
  {
    String s;

    s = String.format("%5d %5d %5d %s",
               this.getMessageID(), this.getPacketID(),
               this.getPacketCount(), this.getPayload());

    return s;
  } // public String toString()

} // public class Packet implements IPacket
