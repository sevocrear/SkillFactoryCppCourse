// Мы предлагаем вам написать некоторый функционал для вендинговой машины (торговый автомат, со снеками (англ. snack — «лёгкая закуска») или чем-то еще), используя изученный в этом модуле материал.
#include <iostream>
#include "include/vending.hpp"

using namespace std;

int main(){
  Snack *bounty = new Snack("Bounty");
  Snack *snickers = new Snack("Snickers");
  SnackSlot *slot = new SnackSlot(10/*количество батончиков, которые помещаются в слот*/);
  slot->addSnack(bounty); //Добавляем батончик в слот
  slot->addSnack(snickers); 
  // slot->getSlot(); // Новая функция от себя (для дебага)
  VendingMachine* machine = new VendingMachine(7 /*Количество слотов для снеков*/);
  machine->addSlot(slot); // Помещаем слот обратно в аппарат
 
  cout << machine->getEmptySlotsCount(); // Должно выводить количество пустых слотов для снеков
  delete snickers;
  delete bounty;
}