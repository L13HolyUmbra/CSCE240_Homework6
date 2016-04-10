GPP = g++ -O3 -Wall

UTILS = ../../Utilities

A = Main.o
P = PacketAssembler.o
M = Message.o
PACKET = Packet.o
S = Scanner.o
SL = ScanLine.o
U = Utils.o

Aprog: $A $P $M $(PACKET) $S $(SL) $U
	$(GPP) -o Aprog $A $P $M $(PACKET) $S $(SL) $U

Main.o: Main.h Main.cpp
	$(GPP) -c Main.cpp

PacketAssembler.o: PacketAssembler.h PacketAssembler.cpp
	$(GPP) -c PacketAssembler.cpp

Message.o: Message.h Message.cpp
	$(GPP) -c Message.cpp

Packet.o: Packet.h Packet.cpp
	$(GPP) -c Packet.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -c $(UTILS)/Scanner.cpp

ScanLine.o: $(UTILS)/ScanLine.h $(UTILS)/ScanLine.cpp
	$(GPP) -c $(UTILS)/ScanLine.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -c $(UTILS)/Utils.cpp
