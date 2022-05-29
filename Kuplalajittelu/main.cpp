//
//  main.cpp
//  Kuplalajittelu
//
//  Created by Evgeniy Mikhaylov on 29.05.2022.
//

//  Yhdistän kirjaston. Jotta pystyy syöttämään ja tulostamaan tietoa näytölle ja näppäimistöltä.
#include <iostream>

//Käytä nimiavaruutta. Jos poistat sen, sinun täytyy kirjoittaa: std:: cout. Voit kirjoittaa ilman std::
using namespace std;

//ohjelman päätehtävä (ja itse ohjelma, ohjelma alkaa "main")
int main()
{
    int *array; //Varataan muistia taulukolle
    int arraySize; //Taulukon koko
    int temp; //Väliaikainen muuttuja
    
    //Syötä taulukon elementtien lukumäärä
    cout << "n = "; //Näytä näytöllä
    cin >> arraySize; //Syötä taulukon koko näppäimistöltä

    if (arraySize <= 0) {
        //Virhe! Taulukon koon on oltava positiivinen!
        cerr << "ERROR" << endl;
        return 1;
    }

    array = new int[arraySize]; //Muistin varaaminen taulukolle

    //Taulukon täyttö
    for (int i = 0; i < arraySize; i++) {
        cout << "array[" << i << "] = "; //Näytä näytöllä
        cin >> array[i]; //Taulukon elementtisyöttö
    }

    //Kuplalajittelu (bubble sort). Vertailen naapurielementtien arvoja (j ja j+1) ja vaihdan,
    //jos ensimmäinen on suurempi kuin toinen. Lopulta isot numerot päätyvät
    //joukon päähän ja pienet jäävät alkuun.

    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                //Paikkojen vaihtaminen
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    //Näytä uusi taulukko näytöllä
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << "  ";
    }
    cout << endl; //Rivin lopussa näytöllä

    delete [] array; //Vapauta muistia;
    
    return 0;
}

