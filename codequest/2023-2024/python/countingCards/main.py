"""
3
ACE_OF_DIAMONDS 10_OF_DIAMONDS
QUEEN_OF_HEARTS ACE_OF_HEARTS
5_OF_HEARTS KING_OF_DIAMONDS QUEEN_OF_DIAMONDS
8_OF_CLUBS JACK_OF_HEARTS
7_OF_CLUBS 10_OF_CLUBS
6_OF_HEARTS JACK_OF_HEARTS KING_OF_HEARTS
"""

"""
Player Score: 21 Dealer Score: 21 Tie!
Player Score: 25 Dealer Score: 18 Dealer Wins!
Player Score: 17 Dealer Score: 26 Player Wins!
"""

# BlackJack
for i in range(int(input())):
    value = {
        "ACE": 11,
        "KING": 10,
        "QUEEN": 10,
        "JACK": 10,
    }

    def det(card: str) -> int:
        x, *_ = card.split("_")
        if x.isdigit():
            return int(x)
        else:
            return value[x]

    def dets(cards: str) -> int:
        pt = 0
        num_aces = 0
        for card in cards.split():
            if card.startswith("ACE"):
                num_aces += 1
                pt += 11
            else:
                pt += det(card)

        while num_aces > 0 and pt > 21:
            pt -= 10
            num_aces -= 1

        return pt

    player = dets(input())
    dealer = dets(input())
    print(f"Player Score: {player} Dealer Score: {dealer}", end=" ")
    if player == 21 and dealer == 21:
        print("Tie!")
    elif player == 21:
        print("Player Wins!")
    elif dealer == 21:
        print("Dealer Wins!")
    elif player > 21:
        print("Dealer Wins!")
    elif dealer > 21:
        print("Player Wins!")
    elif player == dealer:
        print("Tie!")
    elif player > dealer:
        print("Player Wins!")
    else:
        print("Dealer Wins!")
