import java.io.PrintWriter;
import java.util.Scanner;
/*********************************************************************
 * Homework 6:  Assemble packets from a message using a BST.
 *
 * Copyright(C) 2012 Duncan A. Buell.  All rights reserved.
 *
 * @author Duncan Buell
 * @version 1.00 2012-12-30
**/
public class Driver
{
/*********************************************************************
 * main method
**/
  public static void main (String[] args)
  {
    int messageID;
    Scanner inFile = null;
    PrintWriter outFile = null;
    PacketAssembler assembler = null;

    FileUtils.SetLogFile("zlog.txt");
    FileUtils.logFile.printf("beginning execution%n");
    FileUtils.logFile.flush();
    
    inFile = FileUtils.ScannerOpen("zin.txt");
    outFile = FileUtils.PrintWriterOpen("zout.txt");

    // This is intended more or less to simulate running forever,
    // which is what a packet handler would be doing.
    messageID = -99; // yes, this is a magic number
    assembler = new PacketAssembler();
    while(inFile.hasNext())
    {
      messageID = assembler.readPacket(inFile);
      if(messageID >= 0)
      {
        outFile.printf("Message is\n%s\n", assembler.dumpMessage(messageID));
//        assembler = new PacketAssembler();
      }
    }

    FileUtils.CloseFile(inFile);
    FileUtils.CloseFile(outFile);

    FileUtils.logFile.printf("ending execution%n");
    FileUtils.logFile.flush();
    
    FileUtils.CloseLogFile();
  }
} // public class Main





