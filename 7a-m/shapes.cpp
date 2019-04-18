#include <fstream>
#include "shape_atd.h"

using namespace std;

namespace simple_shapes {
  // Сигнатуры требуемых внешних функций 
  void In(box &r, ifstream &ist);
  void In(share  &t, ifstream &ist);

  // Ввод параметров обобщенной фигуры из файла
  shape* In(ifstream &ifst)
  {
    shape *sp;
    int k;
    ifst >> k;
    switch(k) {
    case 1:
      sp = new shape;
      sp->k = shape::key::BOX;
      In(sp->r, ifst);
      return sp;
    case 2:
      sp = new shape;
      sp->k = shape::key::SHERE;
      In(sp->t, ifst);
      return sp;
    default:
      return 0;
    }
  }

  void Out(box &r, ofstream &ofst);
  void Out(share  &t, ofstream &ofst);

  // Вывод параметров текущей фигуры в поток
  void Out(shape &s, ofstream &ofst) {
    switch(s.k) {
    case shape::key::BOX:
      Out(s.r, ofst);
      break;
    case shape::key::SHERE:
      Out(s.t, ofst);
      break;
    default:
      ofst << "Incorrect figure!" << endl;
    }
  }
} // end simple_shapes namespace


