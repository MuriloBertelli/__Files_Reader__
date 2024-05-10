#Header 1
# __Files_Reader__
=================================================================================================
███████╗██╗██╗     ███████╗     ██████╗ ███████╗ █████╗ ██████╗ ███████╗███████╗███████╗██████╗ 
██╔════╝██║██║     ██╔════╝    ██╔════╝ ██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗
█████╗  ██║██║     █████╗      ██║  ███╗█████╗  ███████║██████╔╝█████╗  ███████╗███████╗██████╔╝
██╔══╝  ██║██║     ██╔══╝      ██║   ██║██╔══╝  ██╔══██║██╔═══╝ ██╔══╝  ╚════██║╚════██║██╔═══╝ 
██║     ██║███████╗███████╗    ╚██████╔╝███████╗██║  ██║██║     ███████╗███████║███████║██║     
╚═╝     ╚═╝╚══════╝╚══════╝     ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝     ╚══════╝╚══════╝╚══════╝╚═╝     
=================================================================================================

This project involves creating a program in C that reads a sequence of integers from a file named dados.txt and stores them in an array to produce the following results:
#---#---#---#---#---#---#---#---#---#-----#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#-

estatisticas.txt: Contains:
Count of positive numbers
Count of negative numbers
Count of zeroes
Count of even numbers
Count of odd numbers
distintos.txt: Contains all distinct numbers from the input sequence.
ordenado.txt: Contains the entire input sequence, sorted in non-decreasing order.
distintos_ordenado.txt: Contains distinct numbers sorted in non-decreasing order.

#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#---#----#--

Notes:

The first number in dados.txt specifies the number of integers to be read.
The array size is defined by a constant (#define).
If the number of integers exceeds the array capacity, the program should terminate without producing any output.

