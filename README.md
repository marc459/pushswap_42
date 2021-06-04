Pushswap includes two programs:

Checker - this program test the funcionality of the operations used for pushswap for sort a list of numbers.
It recieves a list of arguments which have to be sorted manually by the user. While user writes the operations name's
the program has to apply this change.Therefore, when user finally stops writing operations , program will show if numbers had been sorted or not.('OK' or 'KO'). If a mischance occurss while running the programs it will show ('Error');

Pushswap - 



// LINKED LISTS
https://www.youtube.com/watch?v=ABZIs-lMSlA&ab_channel=AsaelHern%C3%A1ndez

//CREATE RANDOM PARAMS

ARG=$(ruby -e "puts (0..100).to_a.shuffle.join(' ')");  ./push_swap $ARG | ./checker $ARG

//LEAK
while true:do leaks checker;sleep 1;done

//CHECK LINES PUSHSWAP
make && ARG=$(ruby -e "puts (0..99).to_a.shuffle.join(' ')");  ./push_swap $ARG | wc -l