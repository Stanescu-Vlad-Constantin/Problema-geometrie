# Problema-geometrie
(~80%) În aplicații de grafică computerizată, este necesară recunoașterea de forme și aproximarea dimensiunii lor.

Cerințe pentru punctaj maxim
Să se creeze o clasă cu numele Point cu următoarele specificații:
- clasa trebuie să conțină 2 atribute private numite x și y, ambele numere fractionare in dublă precizie;
- clasa trebuie sa contina un constructor cu 0 parametri. Acesta va initializa pe x si pe y cu 0;
- clasa trebuie sa contina un constructor cu 2 parametri, ce va initializa pe x si pe y cu cei 2 parametri dati;
- clasa trebuie sa contina metodele getX si getY, declarate const qualified, ce vor returna cele 2 coordonate ale punctului;
- clasa trebuie sa contina metodele setX si setY ce vor seta cele 2 coordonate;
- clasa trebuie sa supraincarce operatorul -, declarat const qualified, ce va lua ca parametru un const Point&, si sa returneze un Point ce are drept coordonate valoarea absoluta obtinuta prin scaderea din punctul curent, punctul dat ca parametru


Să se creeze o clasă cu numele Shape cu următoarele specificații:
- clasa trebuie să conțină 3 atribute protected, mFirst, mSecond, mName, unde mFirst si mSecond sunt 2 campuri de tip Point, iar mName este un std::string;
- clasa trebuie sa contina un constructor cu 0 parametri. Acesta va initializa pe mFirst si pe mSecond cu valorile (0,0);
- clasa trebuie sa contina un constructor cu 2 parametri, de tip Point. Acesta va initializa pe mFirst cu primul punct, iar pe mSecond cu cel de-al doilea punct;
- clasa trebuie sa contina metodele getFirst si getSecond, declarate const qualified, ce vor returna cele 2 puncte;
- clasa trebuie sa contina metodele setFirst si setSecond, ce vor seta cele 2 puncte;
- clasa trebuie să conțină metoda getName, declarată const qualified, ce va returna numele formei.
- clasa trebuie sa contina metoda setName, care seteaza numele formei;
- clasa trebuie sa fie abstracta si sa contina metodele pur virtuale getPerimeter si getArea, declarate const qualified, ce vor intoarce aria și perimetrul ca numere fractionare in dubla precizie;


Să se creeze o clasă cu numele Quadrilateral cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Shape;
- clasa trebuie să conțină un constructor cu 0 parametri, ce initializeaza punctele din clasa de bază cu valorile (0,0), iar mName va fi initializat cu valoarea "Unknown";
- clasa trebuie sa contina un constructor cu 3 parametri, ce initializeaza cele 2 puncte din clasa de bază cu cele 2 puncte date ca parametri și numele formei cu numele dat ca parametru;
- metoda getLength, declatată const qualified, ce calculeaza lungimea pe axa Ox dintre cele 2 puncte;
- metoda getWidth, declarată const qulaified, ce calculeaza lungimea pe axa Oy dintre cele 2 puncte;
Indicatie: pentru scrierea metodelor getLength si getWidth este recomandata folosirea operatorului supraincarcat din clasa Point;
- implementarea metodelor virtuale din clasa de bază;

Să se creeze o clasă cu numele Circle cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Shape;
- clasa trebuie să conțină un atribut private numit mRadius, de tip fracționar in dubla precizie;
- clasa trebuie să conțină un constructor public cu 0 parametri, care să inițializeze punctele din clasa mama cu valorile (0,0), campul mRadius cu 0, iar mName va fi initializat cu valoarea "Unknown";
- clasa trebuie sa contina un constructor cu 2 parametri, unul dintre ele sa fie un Point, centrul cercului, iar cel de-al doilea parametru sa fie de tip double, reprezentand raza cercului. Acest constructor va inițializa atributul mFirst cu centrul cercului, iar atributul mSecond cu un punct gol, care nu va fi folosit pentru un cerc. De asemenea, atributul mName va fi inițializat cu valoarea "cerc".
- clasa trebuie sa implementeze cele doua metode virtuale din clasa de bază;
- clasa trebuie sa contina metoda setRadius() care seteaza valoarea razei cercului;
- clasa trebuie sa contina metoda getRadius, declarată const qualified, care seteaza valoarea razei cercului;

Dându-se o listă de forme de tip cerc, pătrat sau dreptunghi împreună cu mărimile de definiție (pentru cerc, coordonata centrului și raza iar pentru pătrat și dreptunghi coordonatele punctelor din stânga sus și dreapta jos), să se ordoneze acestea crescător în funcție de arie. 

Datele de intrare sunt date astfel: pe prima linie se află numărul de forme n, urmat de două valori min, max, fracționare, toate separate prin spațiu Pe următoarele n linii se află definițiile fomelor în următorul format: numele formei (cerc, patrat sau dreptunghi), urmat de mărimile caracteristice (pentru cerc, coordonata centrului și raza iar pentru pătrat și dreptunghi coordonatele punctelor din stânga sus și dreapta jos). n este în intervalul [1, 500], coordonatele sunt în intevalul [-1000, 1000] și razele în (0; 1000]. min și max sunt valori de tip floating point pozitive. cu observația că min <= max.

NB: Efectuati calculele in dubla precizie si afisati cu 6 zecimale exacte.
La ieșire se cer formele ordonate crescător în funcție de arie. Pentru fiecare formă se cere tipul ei, urmată de arie, urmată de perimetru.

(~10%) Dacă n este în afara intervalului de definiție, sau oricare din coordonate sau raze sunt în afara domeniului de  definiție, sau min > max, se va afișa “Valoare de intrare invalida” (fără ghilimele) și programul se va încheia. 

(~10%) Dacă există forme care au aceeași arie, atunci ele se vor ordona în funcție de perimetru.
