CXX = g++
CFLAGS = -c -Wall -Wextra -pedantic -std=c++11

OBJECTS = build/MeleeAI.o build/GameState.o build/PipeController.o build/MoveSet.o build/AI.o build/StageInfo.o build/DefensiveAI.o build/RecoveryBot.o build/RecoveryFox.o build/LedgeBot.o build/MemReader.o build/DIBot.o

BOOST_OBJECTS = $(OBJECTS) build/MemShareController.o

GS_TEST_OBJECTS = build/GameState_test.o build/MemReader.o build/GameState.o

MeleeAI: $(OBJECTS)
	$(CXX) -L /lib32 -pthread $(OBJECTS) -lrt -o MeleeAI

GameState_test: $(GS_TEST_OBJECTS)
	$(CXX) -L /lib32 -pthread $(GS_TEST_OBJECTS) -o GameState_test
	
boost_MeleeAI: $(BOOST_OBJECTS)
	$(CXX) -L /lib32 -pthread $(BOOST_OBJECTS) -lrt -o MeleeAI

build/MeleeAI.o: source/MeleeAI.cpp
	$(CXX) $(CFLAGS) source/MeleeAI.cpp -o build/MeleeAI.o

build/GameState_test.o: source/GameState_test.cpp
	$(CXX) $(CFLAGS) source/GameState_test.cpp -o build/GameState_test.o

build/GameState.o: source/GameState.cpp
	$(CXX) $(CFLAGS) source/GameState.cpp -o build/GameState.o

build/MemShareController.o: source/MemShareController.cpp
	$(CXX) $(CFLAGS) source/MemShareController.cpp -o build/MemShareController.o

build/PipeController.o: source/PipeController.cpp
	$(CXX) $(CFLAGS) source/PipeController.cpp -o build/PipeController.o
	
build/MoveSet.o: source/AI/MoveSet.cpp
	$(CXX) $(CFLAGS) source/AI/MoveSet.cpp -o build/MoveSet.o

build/AI.o: source/AI/AI.cpp
	$(CXX) $(CFLAGS) source/AI/AI.cpp -o build/AI.o

build/StageInfo.o: source/StageInfo.cpp
	$(CXX) $(CFLAGS) source/StageInfo.cpp -o build/StageInfo.o

build/DefensiveAI.o: source/AI/DefensiveAI.cpp
	$(CXX) $(CFLAGS) source/AI/DefensiveAI.cpp -o build/DefensiveAI.o

build/RecoveryBot.o: source/AI/RecoveryBot/RecoveryBot.cpp
	$(CXX) $(CFLAGS) source/AI/RecoveryBot/RecoveryBot.cpp -o build/RecoveryBot.o

build/RecoveryFox.o: source/AI/RecoveryBot/RecoveryFox.cpp
	$(CXX) $(CFLAGS) source/AI/RecoveryBot/RecoveryFox.cpp -o build/RecoveryFox.o

build/LedgeBot.o: source/AI/LedgeBot.cpp
	$(CXX) $(CFLAGS) source/AI/LedgeBot.cpp -o build/LedgeBot.o

build/MemReader.o: source/MemReader.cpp
	$(CXX) $(CFLAGS) source/MemReader.cpp -o build/MemReader.o

build/DIBot.o: source/AI/DIBot.cpp
	$(CXX) $(CFLAGS) source/AI/DIBot.cpp -o build/DIBot.o

clean:
	rm build/*.o

ListTodo:
	grep -r TODO source/*.[ch]pp source/AI/*.[ch]pp source/AI/RecoveryBot/*.[ch]pp
