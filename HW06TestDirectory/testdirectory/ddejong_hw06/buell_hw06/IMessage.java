public interface IMessage {

  public int getMessageID();

  public boolean contains(Packet p);

  public void insert(Packet p);

  public boolean isComplete();
}
