#include <iostream>
#include <fstream>
#include <iomanip>

// funzione che trasforma l'intervallo [1,5] in [-1,2]
double mappaintervallo(double valore){
    double valoremappato = ((valore-1.0)*(2.0+1.0))/(5.0-1.0)-1.0;
    return valoremappato;
}

int main()
{
    std::string nomeFile = "data.csv";
    std::ifstream ifstr(nomeFile);

    if(ifstr.fail())
    {
        std::cerr << "Il file non esiste" << std::endl;
        return 1;
    }

    std::ofstream outputFile("result.csv");

    //header
    outputFile << "#N Mean" << "\n";

    double valore = 0.0;
    double somma = 0.0;
    unsigned int n = 0;
    double media = 0.0;

    while (ifstr >> valore) {
        valore = mappaintervallo(valore);
        somma += valore;
        n++;
        media = somma/n;
        outputFile << n << " " << std::scientific << std::setprecision(16) << media << std::endl;
    }

    ifstr.close();
    outputFile.close();

    return 0;
}
