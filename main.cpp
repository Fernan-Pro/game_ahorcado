// Incluir las librerías necesarias
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Definir una constante para el número máximo de intentos
const int MAX_INTENTOS = 6;

// Definir una función que devuelve una palabra al azar de una lista
string palabra_aleatoria() {
  // Crear un vector con algunas palabras posibles
  vector<string> palabras = {"perro", "gato", "elefante", "Madrid", "París", "silla", "mesa", "cuchara", "oso", "león", "tigre", "Berlín", "Roma", "vaso", "plato", "cuchillo", "águila", "halcón", "Londres", "Dublín", "taza", "tenedor", "lobo", "zorro", "Viena", "Atenas", "botella", "cacerola", "ciervo", "ardilla", "Estocolmo", "Lisboa", "jarra", "sartén", "conejo", "ratón", "Oslo", "Helsinki", "tetera", "olla", "ganso", "pato", "Copenhague", "Ámsterdam", "cafetera", "cacerola", "pollo", "pavo", "Varsovia", "Praga", "exprimidor", "hervidor", "cuervo", "gorrión", "Budapest", "Bruselas", "tostadora", "batidora", "búho", "colibrí", "Bucarest", "Sofía", "microondas", "lavavajillas", "paloma", "cisne", "Zagreb", "Belgrado", "nevera", "congelador", "gorrión", "halcón", "Tallin", "Riga", "horno", "lavadora", "gaviota", "alondra", "Vilna", "Minsk", "secadora", "aspiradora", "cuervo", "mirlo", "Kiev", "Moscú", "plancha", "máquina de coser", "pardillo", "jilguero", "Ankara", "Estambul", "ventilador", "aire acondicionado", "petirrojo", "ruiseñor", "Teherán", "Bagdad", "calefactor", "radiador", "gorrión", "canario", "El Cairo", "Alejandría", "estufa", "chimenea", "colibrí", "papagayo", "Casablanca", "Rabat", "calefacción", "calentador", "pavo real", "flamenco", "Dakar", "Bamako", "frigorífico", "congelador", "águila", "halcón", "Adís Abeba", "Nairobi", "lavavajillas", "lavadora", "buitre", "cóndor", "Pretoria", "Ciudad del Cabo", "horno", "microondas", "cuervo", "urraca", "Harare", "Lusaka", "tostadora", "batidora", "gorrión", "jilguero", "Gaborone", "Windhoek", "exprimidor", "hervidor", "pardillo", "canario", "Maputo", "Antananarivo", "cafetera", "máquina de coser", "petirrojo", "ruiseñor", "Port Louis", "Victoria", "ventilador", "aire acondicionado", "colibrí", "papagayo", "Mogadiscio", "Djibouti", "calefactor", "radiador", "pavo real", "flamenco", "Kampala", "Kigali", "estufa", "chimenea", "águila", "halcón", "Dodoma", "Nairobi", "calefacción", "calentador", "cuervo", "urraca", "Lilongüe", "Harare", "frigorífico", "congelador", "gorrión", "jilguero", "Lusaka", "Gaborone", "lavavajillas", "lavadora", "pardillo", "canario", "Windhoek", "Maputo", "horno", "microondas", "petirrojo", "ruiseñor", "Antananarivo", "Port Louis", "tostadora", "batidora", "colibrí", "papagayo", "Victoria", "Mogadiscio", "exprimidor", "hervidor", "pavo real", "flamenco", "Djibouti", "Kampala", "cafetera", "máquina de coser", "águila", "halcón", "Kigali", "Dodoma", "ventilador", "aire acondicionado", "cuervo", "urraca", "Nairobi", "Lilongüe", "calefactor", "radiador", "gorrión", "jilguero", "Harare", "Lusaka", "estufa", "chimenea", "pardillo", "canario", "Gaborone", "Windhoek", "calefacción", "calentador", "petirrojo", "ruiseñor", "Maputo", "Antananarivo", "frigorífico", "congelador", "colibrí", "papagayo", "Port Louis", "Victoria", "lavavajillas", "lavadora", "pavo real", "flamenco", "Mogadiscio", "Djibouti", "horno", "microondas", "águila", "halcón", "Kampala", "Kigali", "tostadora", "batidora", "cuervo", "urraca", "Dodoma", "Nairobi", "exprimidor", "hervidor", "gorrión", "jilguero", "Lilongüe", "Harare", "cafetera", "máquina de coser", "pardillo", "canario", "Lusaka", "Gaborone", "ventilador", "aire acondicionado", "petirrojo", "ruiseñor", "Windhoek", "Maputo", "calefactor", "radiador", "colibrí", "papagayo", "Antananarivo", "Port Louis", "estufa", "chimenea", "pavo real", "flamenco", "Victoria", "Mog"};
  // Obtener el tamaño del vector
  int tamano = palabras.size();
  // Generar un número al azar entre 0 y el tamaño menos uno
  srand(time(NULL));
  int indice = rand() % tamano;
  // Devolver la palabra en el índice generado
  return palabras[indice];
}

// Definir una función que muestra el estado del juego
void mostrar_estado(string palabra, string oculta, int intentos) {
  // Mostrar la palabra oculta con guiones bajos y espacios
  cout << "Palabra: " << oculta << "\n";
  // Mostrar el número de intentos restantes
  cout << "Intentos: " << intentos << "\n";
  // Mostrar el dibujo del ahorcado según el número de intentos
  cout << "  +---+\n";
  cout << "  |   |\n";
  if (intentos <= 5) cout << "  O   |\n";
  else cout << "      |\n";
  if (intentos <= 4) {
    if (intentos == 4) cout << "  |   |\n";
    if (intentos == 3) cout << " /|   |\n";
    if (intentos <= 2) cout << " /|\\  |\n";
  }
  else cout << "      |\n";
  if (intentos <= 1) cout << " /    |\n";
  else cout << "      |\n";
  if (intentos == 0) cout << " / \\  |\n";
  else cout << "      |\n";
  cout << "      |\n";
  cout << "=========\n\n";
}

// Definir una función que pide al usuario que ingrese una letra y la valida
char pedir_letra() {
  // Declarar una variable para guardar la letra
  char letra;
  // Pedir al usuario que ingrese una letra
  cout << "Ingrese una letra: ";
  cin >> letra;
  // Convertir la letra a minúscula
  letra = tolower(letra);
  // Validar que la letra sea un carácter alfabético
  while (!isalpha(letra)) {
    cout << "Ingrese una letra válida: ";
    cin >> letra;
    letra = tolower(letra);
  }
  // Devolver la letra
  return letra;
}

// Definir una función que verifica si la letra ingresada está en la palabra y actualiza la palabra oculta
bool verificar_letra(char letra, string palabra, string& oculta) {
  // Declarar una variable para guardar si la letra está o no
  bool esta = false;
  // Recorrer la palabra letra por letra
  for (int i = 0; i < palabra.length(); i++) {
    // Si la letra coincide con la letra de la palabra en la posición i
    if (letra == palabra[i]) {
      // Actualizar la palabra oculta en la posición i con la letra
      oculta[i] = letra;
      // Cambiar el valor de la variable a verdadero
      esta = true;
    }
  }
  // Devolver el valor de la variable
  return esta;
}

// Definir la función principal
int main() {
  // Obtener una palabra al azar
  string palabra = palabra_aleatoria();
  // Crear una palabra oculta con el mismo tamaño que la palabra, pero con guiones bajos
  string oculta(palabra.length(), '_');
  // Declarar una variable para guardar el número de intentos
  int intentos = MAX_INTENTOS;
  // Declarar una variable para guardar si el juego terminó o no
  bool terminado = false;
  // Mostrar un mensaje de bienvenida
  cout << "Bienvenido al juego del ahorcado\n";
  // Mostrar el estado inicial del juego
  mostrar_estado(palabra, oculta, intentos);
  // Mientras el juego no haya terminado
  while (!terminado) {
    // Pedir al usuario que ingrese una letra
    char letra = pedir_letra();
    // Verificar si la letra está en la palabra y actualizar la palabra oculta
    bool esta = verificar_letra(letra, palabra, oculta);
    // Si la letra no está en la palabra
    if (!esta) {
      // Reducir el número de intentos en uno
      intentos--;
      // Mostrar un mensaje de que la letra no está
      cout << "La letra " << letra << " no está en la palabra\n";
    }
    // Si la letra está en la palabra
    else {
      // Mostrar un mensaje de que la letra está
      cout << "La letra " << letra << " está en la palabra\n";
    }
    // Mostrar el estado actual del juego
    mostrar_estado(palabra, oculta, intentos);
    // Si la palabra oculta es igual a la palabra
    if (oculta == palabra) {
      // Mostrar un mensaje de que el usuario ganó
      cout << "Felicidades, has adivinado la palabra\n";
      // Cambiar el valor de la variable a verdadero
      terminado = true;
    }
    // Si el número de intentos es cero
    if (intentos == 0) {
      // Mostrar un mensaje de que el usuario perdió
      cout << "Lo siento, has perdido. La palabra era " << palabra << "\n";
      // Cambiar el valor de la variable a verdadero
      terminado = true;
    }
  }
  // Mostrar un mensaje de despedida
  cout << "Gracias por jugar. Hasta la próxima\n";
  // Terminar el programa
  return 0;
}
