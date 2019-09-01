cmake_minimum_required(VERSION 3.14)
project(redoBlackJack)

set(CMAKE_CXX_STANDARD 11)

add_executable(redoBlackJack main.cpp
        MtmTst.cpp MtmTst.h
        Card.cpp Card.h
        CardDeck.cpp CardDeck.h
        Players.cpp Players.h
        BlackJack.cpp BlackJack.h
        Exceptions.h)