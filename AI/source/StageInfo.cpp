#include "StageInfo.hpp"

namespace StageInfo {
    double Limit(int id) {
        switch (id) {
            case 6: //Yoshi's Story
            return 58.91;
            break;
            case 8: //Fountain of Dreams
            return 66.26;
            break;
            case 18: //Pokemon Stadium
            return 90.66;
            break;
            case 24: //Battlefield
            return 70.32;
            break;
            case 25: //Final Destination
            return 88.47;
            break;
            case 26: //Dreamland
            return 80.18;
            break;
            default:
            //TODO: add error report in here
            return 0;
            break;
        }
    }

    double SidePlatHeight(int id) {
        switch (id) {
            case 6: //Yoshi's Story
            return 23.45;
            break;
            case 8: //Fountain of Dreams
            return 0; //how to handle this? mem address for height?
            break;
            case 18: //Pokemon Stadium
            return 25.0;
            break;
            case 24: //Battlefield
            return 27.2;
            break;
            case 25: //Final Destination
            return 0.0;
            break;
            case 26: //Dreamland
            return 30.24;
            break;
            default:
            //TODO: add error report in here
            return 0;
            break;
        }
    }

    double TopPlatHeight(int id) {
        switch (id) {
            case 6: //Yoshi's Story
            return 42.0;
            break;
            case 8: //Fountain of Dreams
            return 42.75;
            break;
            case 18: //Pokemon Stadium
            return 0;
            break;
            case 24: //Battlefield
            return 54.4;
            break;
            case 25: //Final Destination
            return 0;
            break;
            case 26: //Dreamland
            return 51.43;
            break;
            default:
            //TODO: add error report in here
            return 0;
            break;
        }
    }
}