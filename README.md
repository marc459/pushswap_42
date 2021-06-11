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
while true;do leaks checker;sleep 1;done

//CHECK LINES PUSHSWAP
make && ARG=$(ruby -e "puts (0..99).to_a.shuffle.join(' ')");  ./push_swap $ARG | wc -l

//TEST
ARG="12113 23087 20055 25526 29731 14297 3957 1815 18124 12241 11360 26917 28050 16757 1095 271 10290 246 1014 17000 12142 1333 30563 3739 2623 32665 2638 6039 2628 6337 1435 1092 1244 4810 294 60 854 5292 2871 1018 8908 8689 335 613 15611 15367 795 5053 4088 5498 9858 27368 2881 88 8538 12396 10864 6036 29694 7779 19984 18835 15624 30149 9601 19599 28220 27515 4258 20491 1836 22665 30005 5836 17310 6485 6490 6364 1966 23940 10703 29462 20261 5130 26601 17264 32117 2736 15185 1650 4076 16850 9087 1788 16780 24751 17656 7384 4267 8408" && ./push_swap $ARG | wc -l