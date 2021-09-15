PROJDIR := $(CURDIR)
SOURCEDIR := $(PROJDIR)/src
BUILDDIR := $(PROJDIR)/build
CXX = g++
CXXFLAGS = -std=c++2a -g

BOARD = $(BUILDDIR)/board

# chessengine.out: $(SOURCEDIR)/main.o, $(SOURCEDIR)/board/bitboard.o, $(SOURCEDIR)/board/mailbox.o $(SOURCEDIR)/board/board.o
chessengine.out: main.o board.o bitboard.o mailbox.o piece.o
	$(CXX) $(CXXFLAGS) $(BUILDDIR)/main.o $(BOARD)/*.o -o chessengine.out

main.o: board.o bitboard.o mailbox.o piece.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/main.cpp $(BOARD)/*.o -c -o $(BUILDDIR)/main.o

board.o: bitboard.o mailbox.o piece.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/board/board.cpp $(BOARD)/bitboard.o $(BOARD)/mailbox.o $(BOARD)/piece.o -c -o $(BOARD)/board.o

bitboard.o: piece.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/board/bitboard.cpp $(BOARD)/piece.o -c -o $(BOARD)/bitboard.o

mailbox.o: piece.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/board/mailbox.cpp $(BOARD)/piece.o -c -o $(BOARD)/mailbox.o

piece.o:
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/board/piece.cpp -c -o $(BOARD)/piece.o

clean:
	rm -rf $(BUILDDIR)/*.o
	rm -rf $(BOARD)/*.o

