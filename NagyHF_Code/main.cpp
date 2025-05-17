#include <iostream>
#include <fstream>
#include <cstdlib>
#include "NewsPortal.h"

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;

//ASCII art-ban kiírja a címképet
void showTitle (string filename){
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Hiba a fájl megnyitásakor: " << filename << std::endl;
    }
    string line;
    while (std::getline(file, line))
        cout << line << endl;
    file.close();
};

int main() {
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                  Bejelentkezés
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    #ifdef _WIN32
        system("chcp 65001");
        system("cls");
    #endif // _WIN32

    showTitle("Belepes.txt");
    //Newsportal létrehozása és az emberek meg a meglévő újságcikkek beolvasása
    NewsPortal portal;
    portal.readUsersFromFile("users.txt");
    portal.readArticlesFromFile("articles.txt");
    portal.readCommentsFromFile("comments.txt");

    string username, password;
    cout << "Felhasználónév: ";
    cin >> username;
    cout << "Jelszó: ";
    cin >> password;


    if (!portal.authenticateUser(username, password)) {
        cerr << "Sikertelen bejelentkezés!" << endl;
        return -1;
    }
    cout << "Sikeres bejelentkezés! Üdv, " << username << "!" << endl;

    User* belepett = portal.getUserByName(username);

    #ifdef _WIN32
        system("chcp 65001");
        system("cls");
    #endif // _WIN32

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                      Menü
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    showTitle("Fokepernyo.txt");
    int choice;

    do {
        cout << "\nVálassz egy opciót (0-6): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 0: {
                // Az előző képernyőt letörli és feldobja az adott használandó képernyőt
                #ifdef _WIN32
                    system("chcp 65001");
                    system("cls");
                #endif // _WIN32
                showTitle("Fokepernyo.txt");
                cout << "Kilépés...\n";
                break;
            }
            case 1: {
                // Az előző képernyőt letörli és feldobja az adott használandó képernyőt
                #ifdef _WIN32
                    system("chcp 65001");
                    system("cls");
                #endif // _WIN32
                showTitle("Fokepernyo.txt");
                cout << "Választás: 1" << endl;

                // A függvény, ami kilistázza nekünk az összes article-t
                portal.listArticles();
                break;
            }

            case 2: {
                // Az előző képernyőt letörli és feldobja az adott használandó képernyőt
                #ifdef _WIN32
                    system("chcp 65001");
                    system("cls");
                #endif // _WIN32
                showTitle("Fokepernyo.txt");
                cout << "Választás: 2" << endl;

                // Felhasználók kiírása, az összes adattal, ezt csak admin csinálhatja

                if(belepett->isAdmin())
                    portal.listUsers();
                else
                    cout << "Nincs hozzá jogosultságod!" << endl;
                break;
            }

            case 3: {
                // Az előző képernyőt letörli és feldobja az adott használandó képernyőt
                #ifdef _WIN32
                    system("chcp 65001");
                    system("cls");
                #endif // _WIN32
                showTitle("Fokepernyo.txt");
                cout << "Választás: 3" << endl;

                // Hozzáadunk egy Cikket az eddigiekhez, illetve leellenőrizzük, hogy adott-e user cikket írni
                string title, content;
                if (belepett->canPost()) {
                    cout << "Cikk címe: ";
                    getline(cin, title);
                    cout << "Tartalom: ";
                    getline(cin, content);
                    portal.addArticle(title, content, username);
                    cout << "Cikk sikeresen hozzáadva.\n";
                } else {
                    cout << "Nincs jogosultságod cikket írni.\n";
                }
                break;
            }

            case 4: {
                // Az előző képernyőt letörli és feldobja az adott használandó képernyőt
                #ifdef _WIN32
                    system("chcp 65001");
                    system("cls");
                #endif // _WIN32
                showTitle("Fokepernyo.txt");
                cout << "Választás: 4" << endl;

                // Hozzáadunk egy Commentet valamilyen Article-höz
                string article, comment;
                cout << "Melyik cikkhez (címmel): ";
                getline(cin, article);
                cout << "Komment szövege: ";
                getline(cin, comment);
                int igazsagtevo = portal.getArticles().size();
                for (int i = 0; i < portal.getArticles().size(); i ++){
                    if((portal.getArticles())[i].getTitle() == article){
                        portal.addComment(comment, username, article);
                        portal.writeAllCommentsToFile(portal.getComments(),"comments.txt");
                        cout << "Komment hozzáadva.\n" << endl;
                        igazsagtevo = 0;
                        break;
                    }
                }
                if(igazsagtevo > 0){
                    cerr<< "Nincs ilyen újság!" << endl;
                }
                break;
            }

            case 5: {
                // Az előző képernyőt letörli és feldobja az adott használandó képernyőt
                #ifdef _WIN32
                    system("chcp 65001");
                    system("cls");
                #endif // _WIN32
                showTitle("Fokepernyo.txt");
                cout << "Választás: 5" << endl;

                // Az összes commentet kiiratjuk az adott című article-höz
                string title;
                cout << "Cikk címe: ";
                getline(cin, title);
                portal.listCommentsForArticle(title);
                break;
            }
            case 6: {
                // Az előző képernyőt letörli és feldobja az adott használandó képernyőt
                #ifdef _WIN32
                    system("chcp 65001");
                    system("cls");
                #endif // _WIN32
                showTitle("Fokepernyo.txt");
                cout << "Választás: 6" << endl;

                //Egy adott felhasználóhoz tartozó cikk megkeresése
                Article tmp("tmp","tmp","tmp");
                cout << "Szerző Neve: ";
                getline(cin, username);
                cout << endl;
                for(int i = 0; i < portal.searchByAuthor(username).size(); i ++)
                cout << portal.searchByAuthor(username)[i] << endl;
                break;
            }


            default:
                cout << "Érvénytelen választás.\n";
        }

    } while (choice != 0); // Addig fut, amíg a felhasználó nem választ 6-ot

    return 0;
}
