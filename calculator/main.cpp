#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cstdlib> 

void printUsage() { 
    std::cout << "Статистический калькулятор\n" 
              << "Поддерживаемые операции: \n" 
              << "-o summa (среднее арифметическое)\n" 
              << "-o median (медиана)\n" 
              << "Количество операндов: от 7 до 9\n" 
              << "Пример:\n" 
              << "./calculator -o summa 45 13 -2 10 5 8 6\n"; 
} 

double calculateMean(const std::vector<int>& numbers) { 
    double sum = 0; 
    for (int num : numbers) { 
        sum += num; 
    } 
    return sum / numbers.size(); 
} 

double calculateMedian(std::vector<int>& numbers) { 
    std::sort(numbers.begin(), numbers.end()); 
    size_t size = numbers.size(); 
    if (size % 2 == 0) { 
        return (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0; 
    } else { 
        return numbers[size / 2]; 
    } 
} 

int main(int argc, char* argv[]) { 
    if (argc < 9 || argc > 11) { // Проверка на количество аргументов 
        printUsage(); 
        return 1; 
    } 

    std::string operation; 
    std::vector<int> numbers; 

    // Обработка параметров командной строки 
    for (int i = 1; i < argc; ++i) { 
        if (std::string(argv[i]) == "-o" || std::string(argv[i]) == "--operation") { 
            if (i + 1 < argc) { 
                operation = argv[++i]; 
            } else { 
                printUsage(); 
                return 1; 
            } 
        } else { 
            numbers.push_back(std::atoi(argv[i])); 
        } 
    } 

    if (numbers.size() < 7 || numbers.size() > 9) { 
        printUsage(); 
        return 1; 
    } 

    if (operation == "summa") { 
        std::cout << "Среднее арифметическое: " << calculateMean(numbers) << "\n"; 
    } else if (operation == "median") { 
        std::cout << "Медиана: " << calculateMedian(numbers) << "\n"; 
    } else { 
        printUsage(); 
        return 1; 
    } 

    return 0; 
}
