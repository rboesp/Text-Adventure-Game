#got help from class video http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall 
#CXXFLAGS += -Werror 
CXXFLAGS += -Wno-unused 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = CopyRoom.o Game.o MailRoom.o Main.o MeetingRoom.o Player.o ReceptionRoom.o Room.o SecurityRoom.o StorageRoom.o Validation.o

SRCS = CopyRoom.cpp Game.cpp MailRoom.cpp Main.cpp MeetingRoom.cpp Player.cpp ReceptionRoom.cpp Room.cpp SecurityRoom.cpp StorageRoom.cpp Validation.cpp

HEADERS = CopyRoom.hpp Game.hpp MailRoom.hpp MeetingRoom.hpp Player.hpp ReceptionRoom.hpp Room.hpp SecurityRoom.hpp StorageRoom.hpp Validation.hpp 

final: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o final

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o final
