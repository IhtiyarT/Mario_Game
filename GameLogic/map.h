#ifndef MARIO_GAME_MAP_H
#define MARIO_GAME_MAP_H
#include <SFML/Graphics.hpp>

#define Height 25
#define Width 82

inline std::string TileMap[Height] {
        "W                                                                              B BB",
        "W          C                                BBBBBBB                            B BB",
        "W                        0                                                   BBB BB",
        "W                     BBBBB                                                      BB",
        "W                                                                               BB",
        "W               B              BBBBBB                                            BB",
        "W              B          00                          BBBBBBBBB                  BB",
        "W                                                                                BB",
        "W                            B                                                   BB",
        "W                B                           BBBBB                               BB",
        "W                             BBBBB                  B                           BB",
        "W                           BBBBBBB      B           B                           BB",
        "W    K                    BBBBBBBBB                  B                           BB",
        "W                        BBBBBBBBBB                  B                           BB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};


#endif //MARIO_GAME_MAP_H
