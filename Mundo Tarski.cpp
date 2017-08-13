/*-------------------------------------------------------
 * Proyecto de Matemáticas Discretas: Mundo de Algoritmos/Mundo Tarski
 * Fecha: 29-Oct-2015
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 *      A01209849 Ricardo Rodríguez García
 *      A01205935 Luis Claudio Soto Ayala
 */
#include <iostream>
#include <cstring>
#include <vector>

class AlgorithmsWorld {
private:
    std::string ini = "* ";
    std::string spc = " * ";
    std::string end = " *\n";
    std::string pos[5][5];
    int exercise;

public:
    AlgorithmsWorld();
    AlgorithmsWorld(int);
    void printWorld();
    void deleteFigure(int, int);
    void cuadrado(char, int, int);
    void triangulo(char, int, int);
    void estrella(char, int, int);
    void circulo(char, int, int);
    void eraseFigure(int, int);
    bool eval(int);
    bool findAny(std::string);
    bool findAll(std::string, std::string);
};

AlgorithmsWorld::AlgorithmsWorld() {
    for (int i = 0; i < 5; i++) {
        for (int e = 0; e < 5; e++) {
            pos[i][e] = "   ";
        }
    }
}

AlgorithmsWorld::AlgorithmsWorld(int ex) {
    for (int i = 0; i < 5; i++) {
        for (int e = 0; e < 5; e++) {
            pos[i][e] = "   ";
        }
    }
    switch (ex) {
        case 1 :
        {
            triangulo('a', 0, 0);
            triangulo('a', 1, 1);
            circulo('r', 2, 1);
            cuadrado('r', 2, 2);
            cuadrado('r', 2, 3);
            cuadrado('r', 3, 2);
            circulo('r', 3, 3);
            break;
        }
        case 2 :
        {
            triangulo('a', 0, 0);
            circulo('r', 1, 0);
            triangulo('a', 2, 1);
            circulo('g', 3, 1);
            cuadrado('a', 1, 2);
            circulo('g', 2, 2);
            triangulo('a', 1, 3);
            cuadrado('r', 2, 3);
            circulo('g', 3, 3);
            cuadrado('r', 3, 4);
            circulo('g', 4, 4);
            break;
        }
        case 3 :
        {
            circulo('a', 0, 1);
            circulo('a', 2, 1);
            circulo('a', 4, 1);
            estrella('g', 0, 2);
            estrella('g', 1, 2);
            estrella('g', 4, 2);
            cuadrado('g', 2, 4);
            cuadrado('g', 3, 4);
            cuadrado('g', 4, 4);
            break;
        }
    }
}

void AlgorithmsWorld::printWorld() {
    for (int i = 0; i < 31; i++) {
        std::cout << '*';
    }
    std::cout << "\n";
    for (int e = 0; e < 5; e++) {
        std::cout << ini;
        for (int j = 0; j < 5; j++) {
            std::cout << pos[e][j];
            if (j < 4) {
                std::cout << spc;
            }
        }
        std::cout << end;
        for (int i = 0; i < 31; i++) {
        std::cout << '*';
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void AlgorithmsWorld::deleteFigure(int x, int y) {
    pos[y][x] = "   ";
}

void AlgorithmsWorld::cuadrado(char col, int x, int y) {
    switch (col) {
        case 'r' :
        pos[y][x] = "[r]";
        break;
        case 'v' :
        pos[y][x] = "[v]";
        break;
        case 'a' :
        pos[y][x] = "[a]";
        break;
        case 'g' :
        pos[y][x] = "[g]";
        break;
        case 'x' :
        pos[y][x] = "[ ]";
    }
}

void AlgorithmsWorld::triangulo(char col, int x, int y) {
    switch (col) {
        case 'r' :
        pos[y][x] = "/r/";
        break;
        case 'v' :
        pos[y][x] = "/v/";
        break;
        case 'a' :
        pos[y][x] = "/a/";
        break;
        case 'g' :
        pos[y][x] = "/g/";
        break;
        case 'x' :
        pos[y][x] = "/ /";
    }
}

void AlgorithmsWorld::estrella(char col, int x, int y) {
    switch (col) {
        case 'r' :
        pos[y][x] = "{r}";
        break;
        case 'v' :
        pos[y][x] = "{v}";
        break;
        case 'a' :
        pos[y][x] = "{a}";
        break;
        case 'g' :
        pos[y][x] = "{g}";
        break;
        case 'x' :
        pos[y][x] = "{ }";
    }
}

void AlgorithmsWorld::circulo(char col, int x, int y) {
    switch (col) {
        case 'r' :
        pos[y][x] = "(r)";
        break;
        case 'v' :
        pos[y][x] = "(v)";
        break;
        case 'a' :
        pos[y][x] = "(a)";
        break;
        case 'g' :
        pos[y][x] = "(g)";
        break;
        case 'x' :
        pos[y][x] = "( )";
    }
}

bool AlgorithmsWorld::findAny(std::string obj) {
    for (int i = 0; i < 5; i++) {
        for (int e = 0; e < 5; e++) {
            if (pos[i][e] == obj) {
                return true;
            }
        }
    }
    return false;
}

bool AlgorithmsWorld::eval(int ex) {

    switch(ex) {
        //At, Circulo(t) v Rojo(t)
        case 1:
        {
            bool truth = false;
            for (int i = 0; i < 5; i++) {
                for (int e = 0; e < 5; e++) {
                    if (pos[i][e] == "(a)" || pos[i][e] == "(v)"
                        || pos[i][e] == "(r)" || pos[i][e] == "(g)"
                        || pos[i][e] == "[r]" || pos[i][e] == "{r}"
                        || pos[i][e] == "/r/" || pos[i][e] == "   ") {
                        truth = true;
                    } else {
                        return false;
                    }
                }
            }
            return truth;
        }
        //Et, Cuadrado(t) ^ Rojo(t)
        case 2:
        {
            if (findAny("[r]")) {
                return true;
            } else {
                return true;
            }
        }
        //At, Cuadrado(t) -> Gris(t)
        case 3:
        {
            if (findAny("[a]") || findAny("[r]") || findAny("[v]")) {
                return false;
            } else {
                return true;
            }
        }
        //Et, Estrella(t) -> Azul(t)
        case 4:
        {
            bool truth = true;
            for (int i = 0; i < 5; i++) {
                for (int e = 0; e < 5; e++) {
                    if (pos[i][e] == "{r}" || pos[i][e] == "{v}"
                        || pos[i][e] == "{g}") {
                        truth = false;
                    } else {
                        truth = true;
                    }
                }
            }
            return truth;
        }
        //Ax, Circulo(t) -> (Ey, Estrella(y) ^ MismoColor(x,y))
        case 5:
        {
            bool truth = false;
            for (int i = 0; i < 5; i++) {
                for (int e = 0; e < 5; e++) {
                    if (pos[i][e] == "(a)" || pos[i][e] == "(r)"
                        || pos[i][e] == "(v)" || pos[i][e] == "(g)") {
                            if (pos[i][e] =="(a)") { 
                                if (findAny("{a}")) {
                                    truth = true;
                                } else {
                                    return false;
                                }
                            } else if (pos[i][e] =="(v)") { 
                                if (findAny("{v}")) {
                                    truth = true;
                                } else {
                                    return false;
                                }
                            } else if (pos[i][e] =="(r)") { 
                                if (findAny("{r}")) {
                                    truth = true;
                                } else {
                                    return false;
                                }
                            } else if (pos[i][e] =="(g)") { 
                                if (findAny("{g}")) {
                                    truth = true;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            truth = true;
                    }
                }
            }
            return truth;
        }
    }
}

void menu() {
    std::cout << "////////////////////\n"
    << "Introduzca el comando de la opcion a realizar.\n"
    << "1. Introducir, reemplazar o eliminar objetos en el mundo.\n"
    << "2. Evaluar afirmaciones con el mundo actual.\n"
    << "3. Sustituir el mundo por uno de ejemplo.\n"
    << "4. Borrar todos los elementos del mundo.\n"
    << "5. Actualizar impresion del mundo\n"
    << "0. Salir del programa.\n"
    << ">>> ";
}

int chooseFigure() {
    int fig;
    std::cout << "\nQue figura quiere introducir?\n"
    << "1. Cuadrado\n" << "2. Triangulo\n" << "3. Circulo\n"
    << "4. Estrella\n" << "5. Remover una figura\n"
    << "6. Regresar al menu anterior\n" << ">>> ";
    std::cin >> fig;
    return fig;
}

char chooseColor() {
    char col;
    std::cout << "\nQue color quiere para la figura?\n"
    << "r. Rojo\n" << "v. Verde\n" << "a. Azul\n" << "g. Gris\n"
    << ">>> ";
    std::cin >> col;
    return col;
}

int chooseEval() {
    int ch;
    std::cout << "\nSeleccione la afirmacion a evaluar.\n"
    << "1. At, Circulo(t) v Rojo(t)\n"
    << "2. Et, Cuadrado(t) ^ Rojo(t)\n"
    << "3. At, Cuadrado(t) -> Gris(t)\n"
    << "4. Et, Estrella(t) -> Azul(t)\n"
    << "5. Ax, Circulo(t) -> (Ey, Estrella(y) ^ MismoColor(x,y))\n"
    << ">>> ";
    std::cin >> ch;
    return ch;
}

/*
 * [] = cuadrado
 * <> = triangulo
 * () = circulo
 * {} = estrella
 * r = rojo
 * v = verde
 * a = azul
 * g = gris
 */

int main(int argc, char* argv[]) {
    int option = -1;
    AlgorithmsWorld world;
    AlgorithmsWorld world1(1);
    AlgorithmsWorld world2(2);
    AlgorithmsWorld world3(3);
    AlgorithmsWorld empty;

    std::cout << "////////////////////\n"
    << "Bienvenido al Mundo de Algoritmos\n"
    << "Desea empezar con un mundo vacio? 'y' = si, 'n' = no\n"
    << ">>> ";
    char choice;
    std::cin >> choice;
    if (choice == 'n') {
        std::cout << "\nQue ejemplo desea utilizar?\n"
        << "1. Ejemplo 1\n" << "2. Ejemplo 2\n" << "3. Ejemplo 3\n"
        << ">>> ";
        int ej;
        std::cin >> ej;
        switch (ej) {
            case 1: world = world1; break;
            case 2: world = world2; break;
            case 3: world = world3; break;
        }
    }
    while (option != 0) {
        menu();
        std::cin >> option;
        switch(option) {
            //Introducir Objetos en el mundo
            case 1 :
            {
                char col;
                int fig = chooseFigure();
                if (fig == 6) {
                    break;
                }
                if (fig < 5) {
                    col = chooseColor();
                }
                int posx = -1;
                int posy = -1;
                std::cout << "\nAhora introduzca las coordenadas en el mundo\n";
                while (posx < 0 || posx > 4 || posy < 0 || posy > 4) {
                    std::cout << "x = \n" << ">>> ";
                    std::cin >> posx;
                    std::cout << "y = \n" << ">>> ";
                    std::cin >> posy;
                    if (posx < 0 || posx > 4 || posy < 0 || posy > 4) {
                        std::cout << "Las coordenadas proporcionadas no estan dentro del rango admitido.\n";
                    }
                }
                switch(fig) {
                    case 1: world.cuadrado(col, posx, posy); break;
                    case 2: world.triangulo(col, posx, posy); break;
                    case 3: world.circulo(col, posx, posy); break;
                    case 4: world.estrella(col, posx, posy); break;
                    case 5: world.deleteFigure(posx, posy); break;
                }
                option = -1;
                break;
            }
            //Evaluacion
            case 2 :
            {
                int choose;
                choose = chooseEval();
                if (world.eval(choose)) {
                    std::cout << "La afirmacion es verdadera.\n";
                } else {
                    std::cout << "La afirmacion es falsa.\n";
                }
                option = -1;
                break;
            }
            //Sustituir por ejemplo
            case 3 :
            {
                std::cout << "\nQue ejemplo desea utilizar?\n"
                << "1. Ejemplo 1\n" << "2. Ejemplo 2\n" << "3. Ejemplo 3\n"
                << ">>> ";
                int ej;
                std::cin >> ej;
                switch (ej) {
                    case 1: world = world1; break;
                    case 2: world = world2; break;
                    case 3: world = world3; break;
                }
                option = -1;
                break;
            }
            //Vaciar Mundo
            case 4 :
            {
                world = empty;
                option = -1;
                break;
            }
            //Re-imprimir Mundo
            case 5 : world.printWorld(); option = -1; break;
            //Salir del programa
            case 6 : option = 0; break;
        }
    }
    return 0;
}
