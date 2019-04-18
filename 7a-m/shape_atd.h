#ifndef __shape_atd__
#define __shape_atd__
// Подключение необходимых типов данных
#include "box_atd.h"
#include "share_atd.h"
namespace simple_shapes {
  // структура, обобщающая все имеющиеся фигуры
  struct shape {
    // значения ключей для каждой из фигур
    enum key {BOX, SHERE};
    key k; // ключ
    // используемые альтернативы
    union { // используем включение
      box r;
      share t;
    };
  };
} // end simple_shapes namespace
#endif
