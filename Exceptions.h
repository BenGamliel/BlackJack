#ifndef MTM_EXCEPTIONS_H
#define MTM_EXCEPTIONS_H

namespace mtm {

    class MtmException {};

    class CardException : public MtmException {};
    class CardWrongArgsException : public CardException {};

    class DeckException : public MtmException {};
    class CardDeckIsEmptyException : public DeckException {};

    class MapException : public MtmException {};
    class MapElementNotFoundException : public MapException {};

    class BlackjackException : public MtmException {};
    class PlayerAlreadytExistException : public BlackjackException {};
    class PlayerDoesNotExistException : public BlackjackException {};
    class NotEnoughCardsException : public BlackjackException {};
    class NoPlayersException : public BlackjackException {};
}

#endif
