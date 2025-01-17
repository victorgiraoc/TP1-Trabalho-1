#include "dominios.hpp"
#include <set>

bool Avaliacao::validar(uint8_t nota){
    if((nota < 0) || (nota > 5)){
        return false;
    }
    return true;
}

bool Codigo::validar(string codigo){
    string valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"; // Characteres válidos.
    if(codigo.length() > 6){
        return false;
    }
    for(int i = 0; i < codigo.length(); i++){
        bool flag = false;
        for(int j = 0; j < valid.length(); j++){ // Eu sei que é O(n^2), mas isso roda no máximo 6*63 vezes no total (codigo.length() <= 6).
            if(codigo[i] == valid[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            return false; // Se loopar em todos e flag
        }
    }
    return true;
}

bool Data::validar(uint8_t DD, uint8_t MM, uint16_t AA){
    if(DD < 1 || DD > 31 || MM > 12 || MM < 1 || (DD > 30 && ((MM%2 == 0 && MM < 8) || (MM%2 && MM > 7))) || (AA%4 == 0 && MM == 2 && DD > 29)){
        return false;
    }
    return true;
}

bool Dinheiro::validar(double m){
    if(m > 200000 || m < 0){
        return false;
    }
    return true;
}

bool Duracao::validar(uint16_t d){
    if(d > 360 || d < 0){
        return false;
    }
    return true;
}

bool Horario::validar(uint8_t HH, uint8_t MM) {
    if (HH > 23 || MM > 59) {
        return false;
    }
    return true;
}

bool Nome::validar(char* nome) {
    size_t length = strlen(nome);
    if (length == 0 || length > 30) {
        return false;
    }
    for (size_t i = 0; i < length; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool Senha::validar(unsigned int senha) {
    string senha_str = to_string(senha);
    int counter_d = 1, counter_c = 1; //comecar no 1 para comparar com o digito anterior

    if (senha_str.length() != 5) {
        return false;
    }

    set<char> dig_unicos;
    for (char c : senha_str) {
        if (!isdigit(c) || dig_unicos.count(c) > 0) {
            return false;
        }
        dig_unicos.insert(c);
    }

    for (size_t i = 1; i < senha_str.length(); ++i) {
        if (senha_str[i] < senha_str[i-1]) {
            counter_d++;
        } else if (senha_str[i] == senha_str[i+1]) {
            counter_c++;
        }
    }

    if (counter_c == 5 || counter_d == 5) { //senha tem 5 digitos
        return false;
    }

    return true;
}
