PROJDIR := $(CURDIR)
SOURCEDIR := $(PROJDIR)/src
BUILDDIR := $(PROJDIR)/build
CXX = g++
CXXFLAGS = -std=c++2a -g -w

BOARD = $(BUILDDIR)/board
PIECE = $(BUILDDIR)/piece

chessengine.out: main.o board.o bitboard.o mailbox.o piece.o
	$(CXX) $(CXXFLAGS) $(BUILDDIR)/main.o $(BOARD)/*.o $(PIECE)/*.o -o chessengine.out

main.o: board.o bitboard.o mailbox.o piece.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/main.cpp $(BOARD)/*.o $(PIECE)/*.o -c -o $(BUILDDIR)/main.o

board.o: bitboard.o mailbox.o piece.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/board/board.cpp $(BOARD)/bitboard.o $(BOARD)/mailbox.o $(PIECE)/*.o -c -o $(BOARD)/board.o

bitboard.o: piece.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/board/bitboard.cpp $(PIECE)/*.o -c -o $(BOARD)/bitboard.o

mailbox.o: piece.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/board/mailbox.cpp $(PIECE)/*.o -c -o $(BOARD)/mailbox.o

piece.o: pawn.o rook.o knight.o bishop.o king.o queen.o empty.o piecehelpers.o
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/piece/piece.cpp -c -o $(PIECE)/piece.o

pawn.o:
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/piece/pawn.cpp -c -o $(PIECE)/pawn.o

rook.o:
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/piece/rook.cpp -c -o $(PIECE)/rook.o

knight.o:
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/piece/knight.cpp -c -o $(PIECE)/knight.o

bishop.o:
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/piece/bishop.cpp -c -o $(PIECE)/bishop.o

king.o:
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/piece/king.cpp -c -o $(PIECE)/king.o

queen.o:
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/piece/queen.cpp -c -o $(PIECE)/queen.o

empty.o:
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/piece/empty.cpp -c -o $(PIECE)/empty.o

piecehelpers.o:
	$(CXX) $(CXXFLAGS) $(SOURCEDIR)/piece/piecehelpers.cpp -c -o $(PIECE)/piecehelpers.o

clean:
	rm -rf $(BUILDDIR)/*.o
	rm -rf $(BOARD)/*.o
	rm -rf $(PIECE)/*.o

