#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <vector>

std::string contarPalabras(std::string mensaje) {
    std::transform(mensaje.begin(), mensaje.end(), mensaje.begin(), ::tolower);
    std::istringstream ss(mensaje);
    std::string palabra;
    std::map<std::string, int> contador;
    std::vector<std::string> orden;

    while (ss >> palabra) {
        if (contador.find(palabra) == contador.end()) {
            orden.push_back(palabra);
        }
        contador[palabra]++;
    }

    std::string resultado = "";
    for (auto const& x : orden) {
        resultado += x + std::to_string(contador[x]);
    }

    return resultado;
}

int main() {
    std::ifstream archivo("data.txt");
    std::string mensaje((std::istreambuf_iterator<char>(archivo)), std::istreambuf_iterator<char>());
    std::cout << contarPalabras(mensaje) << std::endl;
    return 0;
}
