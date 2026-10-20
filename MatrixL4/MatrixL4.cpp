/*******************************
 * Автор: Тенц Ангелина        *               
 * Вариант: 27                 *
 *Задание: Обработка массивов  *
 *******************************/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  constexpr int maxSize = 20;
  int rowCount, columnCount;
  int H[maxSize][maxSize];
  int resultH[maxSize][maxSize];
  int initialCharacteristics[maxSize];
  int sortedCharacteristics[maxSize];
  int currentSum;
  int tempCharacteristic, tempElement, minIndex;

  cout << "Enter number of rows: ";
  cin >> rowCount;

  cout << "Enter number of columns: ";
  cin >> columnCount;

  cout << "Enter matrix H elements: ";

  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      cin >> H[rowIndex][columnIndex];
      resultH[rowIndex][columnIndex] = H[rowIndex][columnIndex];
    }
  }

  for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
    currentSum = 0;
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
      if (H[rowIndex][columnIndex] < 0 && H[rowIndex][columnIndex] % 2 != 0) {
        currentSum += abs(H[rowIndex][columnIndex]);
      }
    }
    initialCharacteristics[columnIndex] = currentSum;
    sortedCharacteristics[columnIndex] = currentSum;
  }

  for (int outerColumnIndex = 0; outerColumnIndex < columnCount - 1; ++outerColumnIndex) {
    minIndex = outerColumnIndex;
    for (int innerColumnIndex = outerColumnIndex + 1; innerColumnIndex < columnCount; ++innerColumnIndex) {
      if (sortedCharacteristics[innerColumnIndex] < sortedCharacteristics[minIndex]) {
        minIndex = innerColumnIndex;
      }
    }
    if (minIndex != outerColumnIndex) {
      tempCharacteristic = sortedCharacteristics[outerColumnIndex];
      sortedCharacteristics[outerColumnIndex] = sortedCharacteristics[minIndex];
      sortedCharacteristics[minIndex] = tempCharacteristic;
      for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        tempElement = resultH[rowIndex][outerColumnIndex];
        resultH[rowIndex][outerColumnIndex] = resultH[rowIndex][minIndex];
        resultH[rowIndex][minIndex] = tempElement;
      }
    }
  }
  
  cout << "\nInitial H characteristics: ";
  for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
    cout << " " << initialCharacteristics[columnIndex];
  }

  cout << "\nInitial H: ";
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    cout << "\n";
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      cout << "\t" << H[rowIndex][columnIndex];
    }
  }

  cout << "\nResult H: ";
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    cout << "\n";
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      cout << "\t" << resultH[rowIndex][columnIndex];
    }
  }

  return 0;
}

