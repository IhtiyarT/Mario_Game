#ifndef MARIO_GAME_MAP_H
#define MARIO_GAME_MAP_H
#include <SFML/Graphics.hpp>

#define Height 25
#define Width 82

inline std::string TileMap[Height] {
        "W                                                                                BB",
        "W                                                                                BB",
        "W                                                                                BB",
        "W                                                                                BB",
        "W                                                                                BB",
        "W                  000                                                           BB",
        "W                          BBBBBB                                                BB",
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
        "W                             BBBBB                                              BB",
        "W                           BBBBBBB      B                                       BB",
        "W    K                    BBBBBBBBB                                              BB",
        "W                        BBBBBBBBBB                                              BB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};


#endif //MARIO_GAME_MAP_H
