<h3>HOW TO</h3>
To compile do : make

<p>Execute the 'Pushswap' program and introduce some arguments: ./push_swap "7 9 5 3"</p>
Pushswap sort all nums and will bring youu back the name of the operations it used.

<p>Execute the 'checker' program and introduce some arguments: ./checker "7 9 5 3" </p>
Checker check if the arguments received are nums and if they are sorted after recieve some operation from keyboard. If they are it will bring us back a OK if not KO.

<p>To execute checker over pushswap return just use a pipeline:  ./push_swap "7 9 5 3" | ./checker "7 9 5 3"</p>

<h3>FUNCTIONALITY</h3>
Pushswap includes two programs:
Pushswap - 

Checker - this program test the funcionality of the operations used for pushswap for sort a list of numbers.
It recieves a list of arguments which have to be sorted manually by the user. While user writes the operations name's
the program has to apply this change.Therefore, when user finally stops writing operations , program will show if numbers had been sorted or not.('OK' or 'KO'). If a mischance occurss while running the programs it will show ('Error');

//LEAK
tty
while true;do leaks checker;sleep 1;done > /dev/ttys001

//TEST
for i in {1..10};do ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l ; done
