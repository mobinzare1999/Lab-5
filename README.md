# Lab-5
Lab 05 Exercise 2  of ProgrammingTechniques Politecnico Di Torino
Re
encoding of a text based on a conversion table
A file (source.txt) contains text made up of an indefinite number of lines, each with a maximum length of 200 characters. A second file (dictionary.txt) is organized as follows:
- in the first line there is a positive integer number S (≤ 30), which indicates the number of possible re-encodings (i.e., string replacements) that are contained in the dictionary
- in the following S lines of the file, one per line, there is a <replaced> <original> pair, representing a possible re-encoding: more specifically, <original> is the original sequence of characters and <replaced> the corresponding replacement, in a $<integer>$ format.
The purpose of the program is to re-encode the first text file (source.txt), by replacing the original sequences of characters with the corresponding replacements, based on the conversion table specified by dictionary.txt. In case there is more than one replacement possible for a given sequence of characters, the program should apply the first replacement that is found in the dictionary file. The result of the re-encoding should be saved on a third file, output.txt.
Example
Content of the file
source.txt
apelle figlio di apollo
fece una palla di pelle
di pollo
tutti i pesci vennero a galla
per vedere la palla di pelle di pollo
fatta da apelle figlio di apollo
Content of the file dictionary.txt txt:
9
$11$ pelle
$2$ pollo
$333$ palla
$41$alla
$5078$ tta
$6tti
$7$ ll
$81$ er
$900$ ere
The file output.txt should be:
a$11$ figlio di a $2$ fece una
$333$ di $11$ di $2$ tu $6$
i pesci venn $81$ oag $41$
p$81$ ved$81$e la $333$ di  $11$ di $2$
fa$5078$ da a$11$ figlio di a$2$
