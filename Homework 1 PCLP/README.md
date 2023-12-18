Task 1
Am alocat unei matrici noi numita "flipped_orizontal" cele 3 marimi necesare: numarul de linii N, numarul de coloane M, si cele 3 ce reprezinta indicii RGB ai fiecarui pixel. Mai apoi am trecut prin toata matricea si am trecut prin ea luand coloanele de la ultima la prima.

Task 2
Ca la taskul anterior am alocat marimile necesare matricii modificate acum denumate "flipped_stanga". Aceasta operatie de rotire la stanga transforma vechile linii in coloane asa ca la trecerea a 2a prin matrice coordonatele vechilor linii sunt alocate noilor coloane iar noile linii sunt vechile coloane luate de la final la inceput.

Task 3
Dupa alocarea matricei, am transferat toate elementele incepand de la coordonatele date in variabilele x si y si de acolo am trasferat in noua matrice toate liniile si toate coloanele incepand de la coordonatele oferite.

Task 4
Dupa alocarea matricii extinse cu 2*numerul de coloane si linii pt a lasa spatiu pt numarul bonus de linii si coloane cerute. Elementele din bucata extinsa se transforma in culoarea oferita de program iar elementele din mijloc sunt copiate din matricea initiala.

Task 5
Am parcurs matricea si am copiat element cu element de la pozitia x si y pt linii si coloane in matricea destinatie elementele matricei initiale.

Task 6
Se aloca memorie pentru noua matrice numita "filter applied"ca mai apoi sa se aplice filtrul prin calculul oferit de cerinta, prin adunarea tuturor vecinilor cu reprezentantul lor in matricea filtru.

Task 7
Dupa alocarea memoriei pt o colectie de imagini si filtre cu dimensiunea maxima specificata, se utilizeaza o bucla infinita pentru a citi si procesa comenzile pana cand e introdusa comanda ce sfarseste programul. Fiecare comanda introdusa efectueaza actiunile cerute ce includ incarcarea salvarea manipularea si aplicarea de filtre a unor imagini.

Comanda "e" opreste programul

Comanda "l" aloca o noua matrice cu marimile maxime date ca mai apoi sa citeasca din BMP o imagine si a o stoca acolo.

Comanda "s" doar citeste o imagine si o salveaza in INDEX.

Comanda "ah" actioneaza functia de flip_horizontal asupra matricei din index

Comanda "ar" face acelasi lucru ca cea anterioara dar o roteste la stanga si mai apoi schimba valorile nr de linii cu cel ce rep nr de coloane pt posibilitatea de manipulare ulterioara fara probleme.

Comanda "ac" efectuzeaza un crop asupra matricei din index dupa informatiile date de user. Transforma imputul userului din string in int format pentru utilizare si apoi modifica valorile de nr de linii si coloane cu valorile noi.

Comanda "ae" dupa transferul inputului ca la comanda anterioara aplica comanda de extend a matricei si ii actualizeaza marimile cu valorile noi.

Comanda "ap" face exact acolasi lucru dar ii da paste matricei vechi in cea nou conform informatiilor date de user.

Comanda "cf" dupa alocarea metricei ce reprezinta filtrul de marime size*size. Pentru fiecare rand al matricei se aloca memoriei un vector de coeficienti 'float' iar imputul este salvat in matricea filtru. La final filtrul este adaugat intr-o colectie de filtre pentru utilizare ulterioara.

Comanda "af" aplica un filtru din cele create la comanda anterioara.

Comanda "df" este o functie ce dealoca filtrul si decrementeaza numarul acestora dupa fiecare utilizare.

Comanda "di" este o functie ce dealoca imaginea de pe indexul dat de user si muta toate matricile pentru cu un loc pentru a acoperi lipsul creat.

