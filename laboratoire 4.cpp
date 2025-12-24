#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

// Функции
bool contientChiffre(const string& mot) {
    for(char c : mot) if(isdigit(c)) return true;
    return false;
}

void afficherMotsSansChiffres(const vector<string>& mots) {
    cout << "Слова без цифр : ";
    for(const auto& mot : mots) {
        if(!contientChiffre(mot)) cout << mot << " ";
    }
    cout << endl;
}

void deplacerChiffresALaFin(vector<string>& mots) {
    for(auto& mot : mots) {
        string lettres, chiffres;
        for(char c : mot) {
            if(isalpha(c)) lettres += c;
            else if(isdigit(c)) chiffres += c;
        }
        mot = lettres + chiffres;
    }
}

int rechercheLineaire(const string& texte, const string& motif) {
    for(size_t i = 0; i <= texte.length() - motif.length(); i++) {
        if(texte.substr(i, motif.length()) == motif) return i;
    }
    return -1;
}

int main() {
    cout << "=== ПРАКТИЧЕСКАЯ РАБОТА №4 ===" << endl;
    
    // ВАША ФРАЗА
    string phrase = "Dans moins de un an, ce sera la nouvelle annee \"2026\", bonne annee!.";
    cout << "Фраза : " << phrase << endl << endl;
    
    // 1. ОЧИСТКА
    cout << "1. ОЧИСТКА ТЕКСТА :" << endl;
    string propre;
    for(char c : phrase) {
        if(isalnum(c) || c == ' ' || c == '.' || c == '"') {
            if(isalpha(c)) propre += tolower(c);  // В нижний регистр
            else if(c == '"') propre += ' ';      // Заменяем кавычки на пробел
            else propre += c;
        }
    }
    cout << "Очищенный текст : " << propre << endl;
    
    // 2. РАЗДЕЛЕНИЕ НА СЛОВА
    cout << "\n2. РАЗДЕЛЕНИЕ НА СЛОВА :" << endl;
    vector<string> mots;
    string mot;
    for(char c : propre) {
        if(isalnum(c)) {
            mot += c;
        } else if(!mot.empty()) {
            mots.push_back(mot);
            mot.clear();
        }
    }
    if(!mot.empty()) mots.push_back(mot);
    
    cout << "Найдено слов (" << mots.size() << ") : ";
    for(const auto& m : mots) cout << m << " ";
    cout << endl;
    
    // 3. ЗАДАНИЕ 1 : СЛОВА БЕЗ ЦИФР
    cout << "\n3. ЗАДАНИЕ 1 - СЛОВА БЕЗ ЦИФР :" << endl;
    afficherMotsSansChiffres(mots);
    
    // 4. ЗАДАНИЕ 2 : ПЕРЕМЕСТИТЬ ЦИФРЫ В КОНЕЦ
    cout << "\n4. ЗАДАНИЕ 2 - ЦИФРЫ В КОНЦЕ :" << endl;
    deplacerChiffresALaFin(mots);
    cout << "Результат : ";
    for(const auto& m : mots) cout << m << " ";
    cout << endl;
    
    // 5. ПОИСК ПОДСТРОКИ
    cout << "\n5. ПОИСК ПОДСТРОКИ :" << endl;
    
    // Поиск "annee" в тексте
    string motif = "annee";
    cout << "Поиск \"" << motif << "\" : ";
    int pos = rechercheLineaire(propre, motif);
    if(pos != -1) {
        cout << "Найдено на позиции " << pos << endl;
        
        // Показать контекст
        int debut = max(0, pos - 10);
        int fin = min((int)propre.length(), pos + (int)motif.length() + 10);
        cout << "Контекст : ..." << propre.substr(debut, fin-debut) << "..." << endl;
    } else {
        cout << "Не найдено" << endl;
    }
    
    // Поиск "2026" (цифры)
    motif = "2026";
    cout << "Поиск \"" << motif << "\" : ";
    pos = rechercheLineaire(propre, motif);
    if(pos != -1) {
        cout << "Найдено на позиции " << pos << endl;
    } else {
        cout << "Не найдено" << endl;
    }
    
    return 0;
}