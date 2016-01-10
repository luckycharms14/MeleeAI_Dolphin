#include "CharacterInfo.hpp"

namespace CharacterInfo {

  int LedgeDashTiming(int id) {
    switch (id) {
      case 10: //Fox
        return 2;
        break;
      case 23: //Marth
        return 13;
        break;
      default:
        //TODO: add error report in here
        return 0;
        break;
    }
  }

}
