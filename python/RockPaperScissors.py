import random
import math 

def play():
    choice=input("enter your choice as r for rock p for paper and s for scissors ")
    choice=choice.lower()
    computer=random.choice(['r','p','s'])
    if choice==computer:
        return (0,choice,computer)
    if is_win(choice,computer):
        return (1,choice,computer)
    else :
        return (-1,choice,computer)
def is_win(player, opponent):
    # return true is the player beats the opponent
    # winning conditions: r > s, s > p, p > r
    if (player == 'r' and opponent == 's') or (player == 's' and opponent == 'p') or (player == 'p' and opponent == 'r'):
        return True
    return False
def play_best_of(n):
    # play against the computer until someone wins best of n games
    # to win, you must win ceil(n/2) games (ie 2/3, 3/5, 4/7)
    player_wins = 0
    computer_wins = 0
    wins_necessary = math.ceil(n/2)
    while player_wins < wins_necessary and computer_wins < wins_necessary:
        result, choice, computer = play()
        # tie
        if result == 0:
            print('It is a tie. You and the computer have both chosen {}. \n'.format(computer))
        # you win
        elif result == 1:
            player_wins += 1
            print('You chose {} and the computer chose {}. You won!\n'.format(choice, computer))
        else:
            computer_wins += 1
            print('You chose {} and the computer chose {}. You lost :(\n'.format(choice, computer))

    if player_wins > computer_wins:
        print('You have won the best of {} games! What a champ :D'.format(n))
    else:
        print('Unfortunately, the computer has won the best of {} games. Better luck next time!'.format(n))


if __name__ == '__main__':

    play_best_of(3) # 2
