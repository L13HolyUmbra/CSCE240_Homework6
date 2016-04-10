// import java.util.TreeMap;
import java.util.Scanner;

public interface IPacketAssembler
{
  public int readPacket(Scanner inFile);

  public String dumpMessage(int messageID);

} // public interface PacketAssembler
