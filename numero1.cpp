#include <iostream>
#include <vector>

int main()
{
  bool vdd = true;

  while (vdd)
  {

    double notas;
    int qntd;
    std::cout << "Digite a Qtd de provas: ";
    std::cin >> qntd;

    if (qntd > 10)
    {
      std::cout << "Erro: Quantidade impossível\n";
      break;;
    }

    float soma = 0.0;
    for (int i = 0; i < qntd; i++)
    {
      std::cout << "Nota " << i + 1 << ": ";
      std::cin >> notas;
      
      std::vector<double> lista;
      lista.push_back(notas);

      if (notas > 10.0)
      {
        std::cout << "Erro: Nota impossível\n";
        break;;
      }

      soma += notas;
      std::cout << lista[qntd];
    }

    double media = soma / qntd;
    std::cout << "A média desse aluno é: " << media << '\n';
    vdd = false;
  }
}