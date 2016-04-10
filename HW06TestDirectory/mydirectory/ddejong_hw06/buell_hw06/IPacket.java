import java.util.Scanner;

/*********************************************************************
 * Interface for 'Packet' for handling a packet.
 * @author Duncan Buell
**/
public interface IPacket
{

  public int compareTo(Packet p);

  public boolean equals(Packet p);

  public Integer getMessageID();

  public Integer getPacketID();

  public Integer getPacketCount();

  public String getPayload();

  public Packet readPacket(Scanner inFile);

  public String toString();

} // public interface IPacket
