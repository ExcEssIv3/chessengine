PROJDIR := $(CURDIR)
SOURCEDIR := $(PROJDIR)/src
BUILDDIR := $(PROJDIR)/build
CXX = g++
CXXFLAGS = -std=c++2a

BOARD = $(BUILDDIR)/board

# chessengine.out: $(SOURCEDIR)/main.o, $(SOURCEDIR)/board/bitboard.o, $(SOURCEDIR)/board/mailbox.o $(SOURCEDIR)/board/board.o
chessengine.out: main.o board.o bitboard.o mailbox.o
	$(CXX) $(CXXFLAGS) $(BUILDDIR)/main.o $(BOARD)/*.o -o chessengine.out

main.o: board.o bitboard.o mailbox.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/main.cpp $(BOARD)/*.o -c -o $(BUILDDIR)/main.o

bitboard.o: board.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/board/bitboard.cpp $(BOARD)/board.o -c -o $(BOARD)/bitboard.o

mailbox.o: board.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/board/mailbox.cpp $(BOARD)/board.o -c -o $(BOARD)/mailbox.o

board.o:
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/board/board.cpp -c -o $(BOARD)/board.o

clean:
	rm -rf $(BUILDDIR)/*.o
	rm -rf $(BOARD)/*.o

